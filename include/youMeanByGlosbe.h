#pragma once

#include "dictionaryDataInterface.h"
#include "getWebPageContent.h"
#include "makeAddressGlosbe.h"

class YouMeanByGlosbe: public DictionaryDataInterface, GetWebPageContent, MakeAddressGlosbe
{
  std::vector<std::string> getData(const std::string &sentence){
    if(lastAddr == makeAddress(sentence))
      return res;
      
    return res = getContent(webInterface->getWebPageCode(makeAddress(sentence)), "<li><a title=.*?>(.*?)</a>");
  }
};
