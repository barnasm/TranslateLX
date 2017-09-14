#pragma once

class MakeAddressGlosbe{
public:
  const std::string makeAddress(const std::string &sentence,
                                const std::string &langFrom = "en", 
                                const std::string &langTo = "pl"){
       //std::cout << "https://glosbe.com/" + langFrom + "/" + langTo + "/" + sentence << "\n";
       return "https://glosbe.com/" + langFrom + "/" + langTo + "/" + sentence;
  }
};
