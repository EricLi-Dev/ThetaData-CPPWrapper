#include <string>
#include <vector>
#include "curl_easy.h"

using curl::curl_easy;

int main(){
    curl_easy easy;

    easy.add(curl::curl_pair<CURLoption, std::string>(CURLOPT_URL, "http://www.google.it"));
    easy.add(curl::curl_pair<CURLoption, long>(CURLOPT_FOLLOWLOCATION, 1L));

    try {
        easy.perform();

    } catch (curl::curl_easy_exception error){
        //to get the entire error stack:
        //std::vector<std::pair<std::string, std::string>> errors = error.what();
        //print the stack
        error.print_traceback();
    }
    return 0;
}
