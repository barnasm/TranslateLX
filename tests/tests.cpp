//#define BOOST_TEST_ALTERNATIVE_INIT_API
#define BOOST_TEST_MODULE ByGlosbe tester
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_COLOR_OUTPUT = true
#include <boost/test/included/unit_test.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <curl/curl.h>
#include <gtk/gtk.h>
#include <X11/Xlib.h>
#include <sstream>
#include <utility>
#include "../include/diGlosbe.h"
#include "../include/wiCurl.h"
#include <functional>
#include <utility>
//#include "../include/clipboardService.h"

#define PRINT_DATA true

BOOST_AUTO_TEST_CASE(TestCurlExample)
{
  WebInterface *wiCurl = new WiCurl;
  std::string str = wiCurl->getWebPageCode("https://glosbe.com/en/pl/example");
  //std::cout << str;
}

void printData(std::vector<std::string> &data){
  if(PRINT_DATA)
    for(auto a: data) 
      std::cout << a << std::endl;
}

/***************************** TRANSLATION **************************************/
BOOST_AUTO_TEST_CASE(ByGlosbeGettingTranslationOfExampleFromWeb)
{
BOOST_TEST_MESSAGE("translation correct:");
DictionaryInterface *di = new DiGlosbe;
auto data = di->getTranslation( "example" );

  printData(data);
  
  BOOST_TEST_CHECKPOINT( "checking data returned by translation (test)" << "test" );
  BOOST_TEST( (std::find( data.begin(), data.end(), std::string("przykład")) != data.end()));
}
#if 1
BOOST_AUTO_TEST_CASE(ByGlosbeGettingTranslationOfIncorrectWordExemple)
{
  BOOST_TEST_MESSAGE("translation incorrect:");
  DictionaryInterface *di = new DiGlosbe;
  auto data = di->getTranslation( "exemple" );
  printData(data);
  BOOST_TEST((data.empty() || (std::find( data.begin(), data.end(), std::string("przykład")) != data.end()) ));
}


BOOST_AUTO_TEST_CASE(ByGlosbeGettingTranslationOfFakeWord)
{
  BOOST_TEST_MESSAGE("translation fake:");
  DictionaryInterface *di = new DiGlosbe;
  auto data = di->getTranslation( "lawiuefliuher" );
  printData(data);  
  BOOST_TEST(data.empty());
}
/***************************** YOU MEAN **************************************/

BOOST_AUTO_TEST_CASE(ByGlosbeGettingYouMeanOfExampleFromWeb)
{
BOOST_TEST_MESSAGE("you mean corrent:");
DictionaryInterface *di = new DiGlosbe;
 auto data = di->getYouMean( "example" );
printData(data);
BOOST_TEST((data.empty() || (std::find( data.begin(), data.end(), std::string("example")) != data.end())));
}

BOOST_AUTO_TEST_CASE(ByGlosbeGettingYouMeanOfIncorrectWordExemple)
{
  BOOST_TEST_MESSAGE("you mean incorrect:");
  DictionaryInterface *di = new DiGlosbe;
  auto data = di->getYouMean( "exemple" );
  printData(data);
  BOOST_TEST((std::find( data.begin(), data.end(), std::string("example")) != data.end()) );
}
BOOST_AUTO_TEST_CASE(ByGlosbeGettingYouMeanOfFakeWord)
{
  BOOST_TEST_MESSAGE("you mean fake:");
  DictionaryInterface *di = new DiGlosbe;
  auto data = di->getYouMean( "lawiuefliuher" );
  printData(data);
  BOOST_TEST(data.empty());
}
/***************************** PRONUNCIATION **************************************/
BOOST_AUTO_TEST_CASE(ByGlosbeGettingPronunciationOfExampleFromWeb)
{
  BOOST_TEST_MESSAGE("pronunciation correct:");
  DictionaryInterface *di = new DiGlosbe;
  auto data = di->getPronunciation( ("example") );
  printData(data);
  BOOST_TEST( (std::find( data.begin(), data.end(), std::string("ɪɡˈzɑːmpəl")) != data.end()));
}

BOOST_AUTO_TEST_CASE(ByGlosbeGettingPronunciationOfIncorrentWorldExemple)
{
  BOOST_TEST_MESSAGE("pronunciation incorrect:");
  DictionaryInterface *di = new DiGlosbe;
  auto data = di->getPronunciation( "exemple" );
  printData(data);
  BOOST_TEST((data.empty() || (std::find( data.begin(), data.end(), std::string("ɪɡˈzɑːmpəl")) != data.end())));
}

BOOST_AUTO_TEST_CASE(ByGlosbeGettingPronunciationOfFakeWord)
{
  BOOST_TEST_MESSAGE("pronunciation fake:");
  DictionaryInterface *di = new DiGlosbe;
  auto data = di->getPronunciation( "lawiuefliuher" );
  printData(data);
  BOOST_TEST( data.empty() );
}

/***************************** LANGUAGE LIST **************************************/
BOOST_AUTO_TEST_CASE(ByGlosbeGettingLanguageList)
{
  BOOST_TEST_MESSAGE("language list:");
  DictionaryInterface *di = new DiGlosbe;
  
  auto data = di->getLanguageList();
  //for(auto a: data)
    //std::cout << a.first << "  " << a.second << std::endl;
  //BOOST_TEST( (di->listOfLanguages.find("Polish") != di->listOfLanguages.end() ) );
  BOOST_TEST( (std::find_if (data.begin(), data.end(),
			     [](std::pair<std::string, std::string> s) {return (s.second == "pl")?true: false;}) != data.end()) );
 }
#endif


