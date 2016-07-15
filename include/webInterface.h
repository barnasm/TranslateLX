#pragma once

#include <string>

class WebInterface{
public:
  virtual std::string getWebPageCode(const std::string &addr)=0;
};
