#include "client.h"

ThetaClient::ThetaClient(
        std::string username, 
        std::string passwd)
{
    /*
     * Construct a client instance to interact with market datao
     *
     * @param username: ThetaData email. Can be 'default' if using free data
     * @param passwd:   ThetaData password. Can be 'default' if using free data
     */

    this->client_username = username;
    this->client_passwd = passwd;
    this->curl = curl_easy_init();
}

int ThetaClient::get_hist_stock(
        std::string req,
        std::string root,
        std::string startDate,
        std::string endDate)
{
    /*
     * Get historical stock data
     *
     * @param req:       The request type
     * @param root:      The root symbol
     * @param startDate: The start date range
     * @param endDate:   The end date range
     */

    CURLcode res;
    std::string tags = "hist/stock/eod";

    // format data
    std::string rootTag         = "root=" + root;
    std::string startDateTag    = "start_date=" + startDate;
    std::string endDateTag      = "end_date=" + endDate;
    std::string endpoint        = this->endpoint +
        tags          + "?" +
        rootTag       + "&" +
        startDateTag  + "&" +
        endDateTag;
    std::cout << endpoint << std::endl;

    // send request
    if(this->curl) {
        curl_easy_setopt(this->curl, CURLOPT_CUSTOMREQUEST, "GET");
        curl_easy_setopt(this->curl, CURLOPT_URL, endpoint.c_str());

        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Accept: application/json");
        curl_easy_setopt(this->curl, CURLOPT_HTTPHEADER, headers);

        res = curl_easy_perform(this->curl);
        
        // always cleanup
        curl_easy_cleanup(this->curl);

        if (res == CURLE_OK){
            return 0;
        }
    }
    return 1;
}

int ThetaClient::get_hist_option(
        std::string req,
        std::string root,
        std::string exp,
        int strike,
        std::string right,
        std::string startDate,
        std::string endDate)
{
    /*
     * Get historical option data
     *
     * @param req:       The request type
     * @param root:      The root symbol
     * @param exp:       The expiration of the option
     * @param strike:    The strike price 
     * @param right:     Call or Put, "C" or "P"
     * @param startDate: The start date range as YYYYMMDD
     * @param endDate:   The end date range as YYYYMMDD
     */

    std::string tags = "hist/option/eod";

    // format data
    std::string rootTag         = "root=" + root;
    std::string expTag          = "exp=" + exp;
    std::string strikeTag       = "strike=" + std::to_string(int(strike / 0.001)); // per docs. 1/10th of a cent
    std::string rightTag        = "right=" + right;
    std::string startDateTag    = "start_date=" + startDate;
    std::string endDateTag      = "end_date=" + endDate;
    std::string endpoint        = this->endpoint +
        tags          + "?" +
        rootTag       + "&" +
        expTag        + "&" +
        rightTag      + "&" +
        strikeTag     + "&" +
        startDateTag  + "&" +
        endDateTag;
    std::cout << endpoint << std::endl;

    // send request
    if(this->curl) {
        CURLcode res;
        curl_easy_setopt(this->curl, CURLOPT_CUSTOMREQUEST, "GET");
        curl_easy_setopt(this->curl, CURLOPT_URL, endpoint.c_str());

        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Accept: application/json");
        curl_easy_setopt(this->curl, CURLOPT_HTTPHEADER, headers);

        res = curl_easy_perform(this->curl);

        // always cleanup
        curl_easy_cleanup(this->curl);
        
        if (res == CURLE_OK){
            return 0;
        }

    }
    return 1;
}
