#ifndef BYGLOSBE_H
#define BYGLOSBE_H

#include "dictionaryInterface.h"
#include <regex>

class ByGlosbe: public DictionaryInterface
{
public:
  //ByGlosbe();
  std::vector<std::string> getTranslation();
  std::vector<std::string> getYouMean();
  std::vector<std::string> getPronunciation();
  std::vector<std::string> getExamples();
  std::vector<std::string> getDefinition();
  std::vector<std::string> getListOfLanguages();
};

#endif // BYGLOSBE_H
