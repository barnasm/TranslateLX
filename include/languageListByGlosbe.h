#pragma once

#include <iostream>
#include <map>
#include <string>
#include <regex>
#include "getWebPageContent.h"

class LanguageListByGlosbe: public GetWebPageContent
{
public:
  std::map<std::string, std::string> getData(){
    //return getContent(code, "<strong class=\" phr\">(.*?)</strong>");

    std::string code = webInterface->getWebPageCode("https://glosbe.com/");

    std::regex expr("/option><option value=\"(.*?)\">(.*?)<");
    std::map<std::string, std::string> res;
    std::smatch match;
    while (std::regex_search (code, match, expr))
      {
	      //for(auto &a: match)
	      //  std::cout << " #" << &a-&match[0] << "# " << a << std::endl;
	      res[match[2]] = match[1];
	      code = match.suffix().str();
      }
    
    return res;
  }
};
