#pragma once

#include <vector>
#include <string>

class DictionaryDataInterface{
protected:
  std::string lastAddr;
  std::vector<std::string> res;
public:
  virtual std::vector<std::string> getData(){
    return res;
  }
  virtual std::vector<std::string> getData(const std::string &addr)=0;
};
