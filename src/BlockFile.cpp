#include <iostream>
#include <iomanip>
#include "BlockFile.h"

BlockFile::BlockFile()
{
    //ctor
}

BlockFile::~BlockFile()
{
    //dtor
}

void BlockFile::readBlockFile(const std::string& filename)
{
    unsigned int INT = 0;
    fi.open(filename, std::ios::binary);
    //read magic bytes
    readMem(INT);
    std::cout<<std::hex<<INT<<std::endl;
    //read size
    readMem(INT);
    std::cout<<std::hex<<INT<<std::endl;
    //read version
    readMem(INT);
    std::cout<<INT<<std::endl;

    //read prevHash
    unsigned char prevH[32];
    readMem(prevH);
    std::cout<<std::hex;
    for(int i = 0; i < 32; ++i)
    {
        std::cout<<static_cast<int>(prevH[i]);
    }
    //read merkleRoot
    readMem(prevH);
    std::cout<<std::endl<<std::hex;
    for(int i = 0; i < 32; ++i)
    {
        std::cout<<static_cast<int>(prevH[i]);
    }
    readMem(INT);  //read timestamp
    std::cout<<std::endl<<std::dec<<INT<<std::endl;
    readMem(INT);  //read target difficulty
    std::cout<<INT<<std::endl;
    readMem(INT);  //read nonce
    std::cout<<INT<<std::endl;

    char num = 0xfd;
    readMem(num);  //TODO: Change to CompactSize
    std::cout<<static_cast<int>(num)<<" "<<std::hex<<static_cast<int>(num)<<std::endl;
    if(num > 0xfd)
    {
        std::cout<<"Not implemented yet, cant read block";
    }
    else
    {
        readMem(INT);  //read version
        std::cout<<std::endl<<std::dec<<INT<<std::endl;
        char numInputs = 0;
        readMem(numInputs); //read numTxns //TODO: Change to CompactSize
        std::cout<<static_cast<int>(numInputs)<<" "<<std::hex<<static_cast<int>(numInputs)<<std::endl;

        readMem(prevH);  //read inputHash
        std::cout<<std::hex;
        for(int i = 0; i < 32; ++i)
        {
            std::cout<<static_cast<int>(prevH[i]);
        }
        readMem(INT);  //readIndex
        std::cout<<std::endl<<INT<<std::endl;
        readMem(num); //readScriptLength //TODO: Change to CompactSize
        std::cout<<std::dec<<static_cast<int>(num)<<" "<<std::hex<<static_cast<int>(num)<<std::endl;
    }
    fi.close();
}
