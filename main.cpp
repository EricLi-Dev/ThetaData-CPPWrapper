#include <iostream>
#include <string>
#include <curl/curl.h>

#include "client.h"

int main(void)
{
    ThetaClient client = ThetaClient("default", "default");
    int res;
    std::string dataBuffer;

    res = client.list_roots("Option", dataBuffer);
    res = client.list_expirations("AAPL", dataBuffer);
    res = client.list_strikes("AAPL", "20220930", dataBuffer);
    res = client.get_hist_stock("EOD", "AAPL", "20220901", "20220915", dataBuffer);
    res = client.get_hist_option("EOD", "AAPL", "20220930", 150, "C", "20220901", "20220915", dataBuffer);

    std::cout << dataBuffer << std::endl;
    return 0;
}
