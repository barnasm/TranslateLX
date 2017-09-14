#ifndef BYGLOSBE_H
#define BYGLOSBE_H

#include "dictionaryInterface.h"
#include "translationByGlosbe.h"
#include "pronunciationByGlosbe.h"
#include "youMeanByGlosbe.h"
#include "languageListByGlosbe.h"
#include "pronunciationVoiceAddrByGlosbe.h"
#include "wiCurl.h"

class DiGlosbe: public DictionaryInterface
{
public:
  DiGlosbe(){
    translation = new TranslationByGlosbe;
    youMean = new YouMeanByGlosbe;
    pronunciation = new PronunciationByGlosbe;
    languageList = new LanguageListByGlosbe;
    pva = new PronunciationVoiceAddrByGlosbe;
  }
};

#endif // BYGLOSBE_H
