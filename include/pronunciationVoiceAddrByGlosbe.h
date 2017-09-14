#pragma once

#include <string>
#include <regex>
#include "getWebPageContent.h"

class PronunciationVoiceAddrByGlosbe: public DictionaryDataInterface, GetWebPageContent
{
  std::vector<std::string> getData(const std::string &addr){
    if(lastAddr == addr)
      return res; 
    lastAddr = addr;
    
    //there are also .mp3 voices
	  return res = getContent(webInterface->getWebPageCode(addr),
			                      "<span class=\"audioPlayer-container\"><span.+?data-url-ogg=\"(.+?)\".+?class=\"audioPlayer\"></span");
  }
};
