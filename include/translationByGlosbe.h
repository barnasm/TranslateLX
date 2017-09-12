#pragma once

#include "dictionaryDataInterface.h"
#include "getWebPageContent.h"
#include "makeAddressGlosbe.h"

class TranslationByGlosbe: public DictionaryDataInterface, GetWebPageContent, MakeAddressGlosbe
{
    std::vector<std::string> getData(const std::string &sentence){
	return getContent(webInterface->getWebPageCode(makeAddress(sentence)),
			  "<strong class=\" phr\">(.*?)</strong>");
  }
};


