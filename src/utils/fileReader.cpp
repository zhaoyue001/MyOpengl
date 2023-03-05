#include "fileReader.h"
#include <fstream>
#include "iostream"

bool fileReader::readFile() {
  std::ifstream inputFile(filePath);
  if (!inputFile.is_open())
    return false;

  std::string Content((std::istreambuf_iterator<char>(inputFile)),
                      (std::istreambuf_iterator<char>()));

  fileContent = std::move(Content);
  inputFile.close();
  return true;
}

std::string fileReader::getContent() {
    bool ret = readFile();
    if (!ret)
        assert(0 && "Failed to get the file content");
    return fileContent;
}