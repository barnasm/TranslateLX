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
  DictionaryDataInterface *pva;
  
public:
  std::string baseAddr;
  std::string langFromShort;
  std::string langToShort;
  
  DictionaryInterface(const std::string addr): baseAddr(addr){};
  
  virtual const std::string makeAddress(const std::string &sentence){
    return baseAddr +"/" + langFromShort + "/" + langToShort + "/" + sentence;
  }

  virtual std::vector<std::string> getTranslation(const std::string& sentence){
    return translation->getData( makeAddress(sentence) );
  }
  virtual std::vector<std::string> getYouMean(const std::string& sentence){
    return youMean->getData(makeAddress(sentence));
  }
  virtual std::vector<std::string> getPronunciation(const std::string& sentence){
    return pronunciation->getData(makeAddress(sentence));
  }
  //virtual std::vector<std::string> getExamples()=0;
  //virtual std::vector<std::string> getDefinition()=0;
  virtual std::map<std::string, std::string> getLanguageList(){
    return languageList->getData(baseAddr);
  }
  virtual std::vector<std::string> getPronunciationVoiceAddr(const std::string& sentence){
    return pva->getData(makeAddress(sentence));
  }
  
  virtual std::vector<std::string> getTranslation(){
    return translation->getData();
  }
  virtual std::vector<std::string> getYouMean(){
    return youMean->getData();
  }
  virtual std::vector<std::string> getPronunciation(){
    return pronunciation->getData();
  }
  virtual std::vector<std::string> getPronunciationVoiceAddr(){
    return pva->getData();
  }
};

#endif
