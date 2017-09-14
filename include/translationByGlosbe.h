#pragma once

#include "dictionaryDataInterface.h"
#include "getWebPageContent.h"

class TranslationByGlosbe: public DictionaryDataInterface, GetWebPageContent
{
  std::vector<std::string> getData(const std::string &addr){
    if(lastAddr == addr)
      return res;
    lastAddr = addr;
          
	  return res = getContent(webInterface->getWebPageCode(addr),
			                      "<strong class=\" phr\">(.*?)</strong>");
  }
};


