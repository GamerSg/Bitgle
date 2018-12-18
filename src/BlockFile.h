#ifndef BLOCKFILE_H
#define BLOCKFILE_H
#include <string>

class BlockFile
{
    public:
        BlockFile();
        virtual ~BlockFile();
        void readBlockFile(const std::string& filename);

    protected:

    private:
};

#endif // BLOCKFILE_H
