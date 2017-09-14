#pragma once

#include "dictionaryDataInterface.h"
#include "getWebPageContent.h"

class PronunciationByGlosbe: public DictionaryDataInterface, GetWebPageContent
{
  std::vector<std::string> getData(const std::string &addr){
    if(lastAddr == addr)//check performance without this if(also in translation and youMean)
      return res;  
    lastAddr = addr;
      
    auto tmp = getContent(webInterface->getWebPageCode(addr),
			   "IPA:</span><span> (.*?)</span");

    if(!tmp.empty())
      return res = getContent(tmp[0], "/?(.+?)/?[,|;] ");    
    return res = {};
  }
};
