#ifndef FILE_WRITER_H
#define FILE_WRITER_H
#include "string"
#include "assert.h"
class fileReader
{
private:
    std::string filePath;
    std::string fileContent;

    bool readFile();

public:
    fileReader(const std::string filePath) : filePath(filePath) {};
    fileReader () = delete;
    ~fileReader() {};
    std::string getContent();
};

#endif