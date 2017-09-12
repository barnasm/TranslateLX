#pragma once

#include <string>

class WebInterface{
public:
  std::string htmlCode;
  std::string lastAddr;

  virtual std::string& getWebPageCode(const std::string &addr)=0;
};
