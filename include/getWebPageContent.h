#pragma once

#include "wiCurl.h"
#include <vector>
#include <string>
#include <regex>

class GetWebPageContent
{
    
public:
  WebInterface *webInterface;
  GetWebPageContent(){
    webInterface = new WiCurl;
  }
  
  std::vector<std::string> getContent(const std::string &code, const std::string&& e)
  {
    //std::string code = webInterface->getWebPageCode(addr);
    std::regex expr(e);
    std::smatch match;
    std::vector<std::string> res;

    auto it = code.begin();
    
    while (std::regex_search (it, code.end(), match, expr))
      {
	//for(auto &a: match)
	//std::cout << " #" << &a-&match[0] << "# " << a << std::endl;
	res.push_back(match[1]);
	//code = match.suffix().str();
        it = code.end()-match.suffix().str().size();
      }
    return res;
  }  
};


