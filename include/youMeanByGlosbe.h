#pragma once

#include "dictionaryDataInterface.h"
#include "getWebPageContent.h"

class YouMeanByGlosbe: public DictionaryDataInterface, GetWebPageContent
{
  std::vector<std::string> getData(const std::string &addr){
    if(lastAddr == addr)
      return res;
    lastAddr = addr;
          
    return res = getContent(webInterface->getWebPageCode(addr), "<li><a title=.*?>(.*?)</a>");
  }
};

