#include "wiCurl.h"
#include <iostream>

size_t write_data(char *ptr, size_t size, size_t nmemb, void *userdata) {
    std::ostringstream *stream = (std::ostringstream*)userdata;
    size_t count = size * nmemb;
    stream->write(ptr, count);
    return count;
}

std::string downloadHtml(const std::string &addr){
  CURL *curl;
  CURLcode res;

  std::ostringstream stream;
  
  curl_global_init(CURL_GLOBAL_DEFAULT);
 
  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, addr.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &stream);
    //curl_easy_setopt(curl, CURLOPT_TIMEOUT, 2); 
    
#ifdef SKIP_PEER_VERIFICATION
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
#endif
 
#ifdef SKIP_HOSTNAME_VERIFICATION
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
#endif
 
    res = curl_easy_perform(curl);
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
	      curl_easy_strerror(res));
 
    curl_easy_cleanup(curl);
  }
 
  curl_global_cleanup();
  //std::cout << stream.str();
  return stream.str();
}

std::string& WiCurl::getWebPageCode(const std::string &addr){
  if(lastAddr != addr){
    //std::cout << "last from: " << lastAddr << std::endl;
    std::cout << "download from: " << addr << std::endl;
    htmlCode = downloadHtml(addr);
    lastAddr = addr;
  }
  return htmlCode;      
}
