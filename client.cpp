#include "client.h"

#include <thread>

ThetaClient::ThetaClient(
        std::string username, 
        std::string passwd)
{
    /*
     * Construct a client instance to interact with market data
     *
     * @param username: ThetaData email. Can be 'default' if using free data
     * @param passwd:   ThetaData password. Can be 'default' if using free data
     */

    this->client_username = username;
    this->client_passwd = passwd;

    // Start ThetaTerminal
    //std::cout << "starting thread" << std::endl;
    //std::thread thread_obj(&ThetaClient::start, this); 
    //thread_obj.detach();

    // Awaiting 5 seconds
    //std::this_thread::sleep_for(std::chrono::seconds(5));
    //thread_obj.join();

    //std::cout << "killing thread" << std::endl;
    //std::terminate();
}

ThetaClient::~ThetaClient(){}

void ThetaClient::start(){
    /*
     * Start ThetaTerminal thread
     */

    std::cout << "starting ThetaTerminal" << std::endl;
    std::string cmd = "java -jar ../ThetaTerminal.jar " + this->client_username + " " + this->client_passwd; 
    system(cmd.c_str());
}

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    /*
     * Callback function passed to curl function to store data into readBuffer string
     * https://stackoverflow.com/questions/9786150/save-curl-content-result-into-a-string-in-c
     */
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int ThetaClient::send_curl_request(CURL *curl, std::string &endpoint, std::string &readBuffer)
{
    /*
     * Sends the curl request to the endpoint and saves data to readBuffer
     *
     * @param curl:         pointer to curl_easy_init()
     * @param endpoint:     endpoint to send request
     * @param readBuffer:   reference to string to save data
     */

    // Send request
    if(curl) {
        // Set GET request to endpoint
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
        curl_easy_setopt(curl, CURLOPT_URL, endpoint.c_str());
        
        // Feed headers into request
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Accept: application/json");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        
        // Feed callback function
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        // Feed string to save data to
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        // Perform the request
        CURLcode res = curl_easy_perform(curl);

        // Always cleanup
        curl_easy_cleanup(curl);
        
        if (res == CURLE_OK){
            return 0;
        }

    }
    return 1;

}

int ThetaClient::list_roots(std::string sec, std::string& readBuffer)
{
    /*
     * List roots (symbols, tickers, etc.) 
     * Returns all traded roots for a given security type (i.e. stock or option)
     *
     * @param sec:          security type -- "Stock" or "Option"
     * @param readBuffer:   reference to save data
     */

    std::string tags = "list/roots";

    // format data
    std::string secTag      = "sec=" + sec;
    std::string endpoint    = this->endpoint +
        tags + "?" +
        secTag;
    std::cout << endpoint << std::endl;
    
    CURL *curl = curl_easy_init();
    return send_curl_request(curl, endpoint, readBuffer); 
}

int ThetaClient::list_expirations(std::string root, std::string& readBuffer)
{
    /*
     * List expirations for a specific root (symbol, ticker, etc.) 
     * Returns all expirations for an underlying root.
     *
     * @param root:         the root symbol (ticker)        
     * @param readBuffer:   reference to save data
     */

    std::string tags = "list/expirations";

    // format data
    std::string rootTag     = "root=" + root;
    std::string endpoint    = this->endpoint +
        tags + "?" +
        rootTag;
    std::cout << endpoint << std::endl;
    
    CURL *curl = curl_easy_init();
    return send_curl_request(curl, endpoint, readBuffer); 
}

int ThetaClient::list_strikes(std::string root, std::string exp, std::string& readBuffer)
{
    /*
     * List all strike prices that are traded on for an underlying root on a certain expiration date.
     *
     * @param root:         the root symbol (ticker)         
     * @param exp:          expiration date to list strikes for
     * @param readBuffer:   reference to save data
     */

    std::string tags = "list/strikes";

    // format data
    std::string rootTag     = "root=" + root;
    std::string expTag      = "exp=" + exp;
    std::string endpoint    = this->endpoint +
        tags    + "?" +
        rootTag + "&" +
        expTag;
    std::cout << endpoint << std::endl;
    
    CURL *curl = curl_easy_init();
    return send_curl_request(curl, endpoint, readBuffer); 
}

int ThetaClient::get_hist_stock(
        std::string req,
        std::string root,
        std::string startDate,
        std::string endDate,
        std::string &readBuffer)
{
    /*
     * Get historical stock data
     *
     * @param req:          The request type
     * @param root:         The root symbol
     * @param startDate:    The start date range
     * @param endDate:      The end date range
     * @param readBuffer:   reference to save data
     */

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

    CURL *curl = curl_easy_init();
    return send_curl_request(curl, endpoint, readBuffer); 
}

int ThetaClient::get_hist_option(
        std::string req,
        std::string root,
        std::string exp,
        int strike,
        std::string right,
        std::string startDate,
        std::string endDate,
        std::string &readBuffer)
{
    /*
     * Get historical option data
     *
     * @param req:          The request type
     * @param root:         The root symbol
     * @param exp:          The expiration of the option
     * @param strike:       The strike price 
     * @param right:        Call or Put, "C" or "P"
     * @param startDate:    The start date range as YYYYMMDD
     * @param endDate:      The end date range as YYYYMMDD
     * @param readBuffer:   reference to save data
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

    CURL *curl = curl_easy_init();
    return send_curl_request(curl, endpoint, readBuffer);

}

