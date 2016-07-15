#ifndef DISTIONATYINTERFACE_H
#define DISTIONATYINTERFACE_H

#include "dictionaryInterface.h"
#include "webInterface.h"
#include <vector>
#include <string>
#include <map>

class DictionaryInterface
{
public:
  WebInterface *webInterface;
  std::string htmlCode;
  
  std::vector<std::string> translation;
  std::vector<std::string> youMean;
  std::vector<std::string> pronunciation;
  std::vector<std::string> examples;
  std::vector<std::string> definition;
  std::map<std::string, std::string> listOfLanguages;
  //voice

  //  DictionaryInterface( std::vector<std::string> code): htmlCode(code){}
  
  void setSourceCode(std::string code){
    htmlCode = code;
  }

  virtual std::vector<std::string>& getTranslation() = 0;
  virtual std::vector<std::string>& getYouMean()=0;
  virtual std::vector<std::string>& getPronunciation()=0;
  virtual std::vector<std::string>& getExamples()=0;
  virtual std::vector<std::string>& getDefinition()=0;
  virtual std::map<std::string, std::string>& getListOfLanguages()=0;
  //getVoice();
};

#endif
