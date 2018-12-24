#ifndef BLOCKFILE_H
#define BLOCKFILE_H
#include <string>
#include <fstream>

class BlockFile
{
    public:
        BlockFile();
        virtual ~BlockFile();
        void readBlockFile(const std::string& filename);
        void readCompactSize(unsigned int& a);
        template<typename T>
        inline void readMem(T& a)
        {
            fi.read(reinterpret_cast<char*>(&a), sizeof(a));  //read numTxns
        }
    protected:

    private:
        std::ifstream fi;
};

#endif // BLOCKFILE_H
