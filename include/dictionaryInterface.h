#ifndef DISTIONATYINTERFACE_H
#define DISTIONATYINTERFACE_H

#include "dictionaryDataInterface.h"
#include "languageListByGlosbe.h"
#include <vector>

#include <string>
#include <map>

class DictionaryInterface
{
protected:
  DictionaryDataInterface *translation;
  DictionaryDataInterface *youMean;
  DictionaryDataInterface *pronunciation;
  //DictionaryDataInterface *example;
  //DictionaryDataInterface *definition;
  LanguageListByGlosbe *languageList;
  //voice
  
public:
  virtual std::vector<std::string> getTranslation(const std::string& sentence){
    return translation->getData( sentence );
  }
  virtual std::vector<std::string> getYouMean(const std::string& sentence){
    return youMean->getData(sentence );
  }
  virtual std::vector<std::string> getPronunciation(const std::string& sentence){
    return pronunciation->getData( sentence );
  }
  //virtual std::vector<std::string> getExamples()=0;
  //virtual std::vector<std::string> getDefinition()=0;
  virtual std::map<std::string, std::string> getLanguageList(){
    return languageList->getData();
  }
  //getVoice();
  
  virtual std::vector<std::string> getTranslation(){
    return translation->getData();
  }
  virtual std::vector<std::string> getYouMean(){
    return youMean->getData();
  }
  virtual std::vector<std::string> getPronunciation(){
    return pronunciation->getData();
  }
};

#endif
