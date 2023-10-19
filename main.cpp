#include <iostream>
#include <string>
#include <curl/curl.h>


static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int main(void)
{
  CURL *curl;
  CURLcode res;
  std::string readBuffer;

  curl = curl_easy_init();
  //std::string *url = "http://127.0.0.1:25510/hist/stock/eod?root=AAPL&start_date=20220901&end_date=20220915";
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
    curl_easy_setopt(curl, CURLOPT_URL, "http://127.0.0.1:25510/hist/stock/eod?root=AAPL&start_date=20220901&end_date=20220915");

    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "Accept: application/json");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

    res = curl_easy_perform(curl);
    //curl_easy_setopt(curl, CURLOPT_URL, "http://www.google.com");
    //curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    //curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
    //res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);

    //std::cout << readBuffer << std::endl;
  }
  return 0;
}
