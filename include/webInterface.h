#pragma once

#include <string>

class WebInterface{
public:
  static std::string htmlCode;
  static std::string lastAddr;

  virtual std::string& getWebPageCode(const std::string &addr)=0;
};
