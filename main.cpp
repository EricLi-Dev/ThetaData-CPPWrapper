#include <iostream>
#include <string>
#include <curl/curl.h>

#include "client.h"

int main(void)
{
    ThetaClient client = ThetaClient("", "");
    int res;
    std::string dataBuffer;
    std::string data2Buffer;
    res = client.get_hist_stock("EOD", "AAPL", "20220901", "20220915", dataBuffer);
    res = client.get_hist_option("EOD", "AAPL", "20220930", 150, "C", "20220901", "20220915", data2Buffer);
    res = client.list_roots("Option", data2Buffer);

    std::cout << dataBuffer << std::endl;
    std::cout << data2Buffer << std::endl;
    return 0;
}
