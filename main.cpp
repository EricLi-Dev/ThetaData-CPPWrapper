#include <iostream>
#include <string>
#include <curl/curl.h>

#include "client.h"

int main(void)
{
    ThetaClient client = ThetaClient("", "");
    int res;
    //res = client.get_hist_stock("EOD", "AAPL", "20220901", "20220915");
    //res = client.get_hist_option("EOD", "AAPL", "20220930", 150, "C", "20220901", "20220915");
    res = client.list_roots("Option");
//    CURL *curl;
//    CURLcode res;
//    std::string readBuffer;
//
//    curl = curl_easy_init();
//    if(curl) {
//        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
//        curl_easy_setopt(curl, CURLOPT_URL, "http://127.0.0.1:25510/hist/stock/eod?root=AAPL&start_date=20220901&end_date=20220915");
//
//        struct curl_slist *headers = NULL;
//        headers = curl_slist_append(headers, "Accept: application/json");
//        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
//
//        res = curl_easy_perform(curl);
//        curl_easy_cleanup(curl);
//
//    }
    return 0;
}
