#ifndef BYGLOSBE_H
#define BYGLOSBE_H

#include "dictionaryInterface.h"
#include "wiByCurl.h"
#include <regex>

class DiByGlosbe: public DictionaryInterface
{
public:
  DiByGlosbe();
  std::vector<std::string>& getTranslation();
  std::vector<std::string>& getYouMean();
  std::vector<std::string>& getPronunciation();
  std::vector<std::string>& getExamples();
  std::vector<std::string>& getDefinition();
  std::map<std::string, std::string>& getListOfLanguages();
};

#endif // BYGLOSBE_H
