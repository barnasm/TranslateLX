#include "byGlosbe.h"
#include <iostream>
#include <regex>

std::vector<std::string> getDataFromCode(std::string &code, const std::string &e){
  std::regex expr(e);
  std::smatch match;
  std::vector<std::string> res;
  while (std::regex_search (code, match, expr))
    {
      for(auto &a: match)
	std::cout << " #" << &a-&match[0] << "# " << a << std::endl;
      res.push_back(match[1]);
      code = match.suffix().str();
    }
  return res;
}

std::vector<std::string> ByGlosbe::getTranslation(){
  translation = getDataFromCode(htmlCode, "phr</a>\"&gt;</span><span>(.*?)</span>");
  translation.push_back("test");
  return translation;
}
std::vector<std::string> ByGlosbe::getYouMean(){
  //getDataFromCode(htmlCode, "", youMean);
  //return youMean;
}
std::vector<std::string> ByGlosbe::getPronunciation(){
  auto tmp = getDataFromCode(htmlCode, "<span>IPA:((.|\n)*?)</span><span>&lt;<span class=\"start-tag\">");
  pronunciation = getDataFromCode(tmp[0], ".*span>\t*(.*)?");
  return pronunciation;
}
std::vector<std::string> ByGlosbe::getExamples(){
  //getDataFromCode(htmlCode, "", examples);
  //return examples;
}
std::vector<std::string> ByGlosbe::getDefinition(){
  //getDataFromCode(htmlCode, "", definition);
  //return definition;
}
std::vector<std::string> ByGlosbe::getListOfLanguages(){}
