#pragma once

#include "dictionaryDataInterface.h"
#include "getWebPageContent.h"
#include "makeAddressGlosbe.h"

class PronunciationByGlosbe: public DictionaryDataInterface, GetWebPageContent, MakeAddressGlosbe
{
  std::vector<std::string> getData(const std::string &sentence){
    if(lastAddr == makeAddress(sentence))//check performance without this if(also in translation and youMean)
      return res;  
  
    auto tmp = getContent(webInterface->getWebPageCode(makeAddress(sentence)),
			   "IPA:</span><span> (.*?)</span");

    if(!tmp.empty())
      return res = getContent(tmp[0], "/?(.+?)/?[,|;] ");    
    return res = {};
  }
};
