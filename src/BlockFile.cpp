#include <iostream>
#include <fstream>
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
    std::ifstream fi;
    unsigned int size = 0;
    fi.open(filename, std::ios::binary);
    fi.read(reinterpret_cast<char*>(&size), sizeof(size));  //read magic bytes
    std::cout<<std::hex<<size<<std::endl;
    fi.read(reinterpret_cast<char*>(&size), sizeof(size));  //read size
    std::cout<<std::dec<<size<<std::endl;
    fi.read(reinterpret_cast<char*>(&size), sizeof(size));  //read version
    std::cout<<size<<std::endl;

    unsigned char prevH[32];
    fi.read(reinterpret_cast<char*>(prevH), sizeof(prevH));  //read prevHash
    fi.read(reinterpret_cast<char*>(prevH), sizeof(prevH));  //read merkleRoot
    std::cout<<std::hex;
    for(int i = 0; i < 32; ++i)
    {
        std::cout<<static_cast<int>(prevH[i]);
    }

    fi.close();
}
