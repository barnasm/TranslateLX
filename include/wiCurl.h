#pragma once

#include "webInterface.h"
#include <string>
#include <sstream>
#include <curl/curl.h>

class WiCurl: public WebInterface
{
public:
  std::string& getWebPageCode(const std::string &addr);
};
