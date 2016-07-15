#pragma once

#include "webInterface.h"
#include <string>
#include <sstream>
#include <curl/curl.h>

class WiByCurl: public WebInterface
{
  std::string getWebPageCode(const std::string &addr);
};
