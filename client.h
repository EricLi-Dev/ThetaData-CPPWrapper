#include <iostream>
#include <string>
#include <curl/curl.h>

class ThetaClient{
    /*
     * Instantiating this class runs a Java background process, 
     * which is responsible for heavy lifting of market data communication.
     * Java 11 or higher is required.
     */
    private:
        std::string client_username;
        std::string client_passwd;
        std::string endpoint = "http://127.0.0.1:25510/";

    public:
        ThetaClient(std::string username, std::string passwd);
        /*
         * Construct a client instance to interact with market datao
         *
         * @param username: ThetaData email. Can be 'default' if using free data
         * @param passwd:   ThetaData password. Can be 'default' if using free data
         */

        ~ThetaClient();
        /*
         * Destructor of object
         */

        int send_curl_request(CURL *curl,
                std::string &endpoint,
                std::string &readBuffer);
        /*
         * Sends the curl request to the endpoint and saves data to readBuffer
         *
         * @param curl:         pointer to curl_easy_init()
         * @param endpoint:     endpoint to send request
         * @param readBuffer:   reference to string to save data
         */

        void start();
        /*
         * Start ThetaTerminal on separate thread
         */

        int list_roots(std::string sec, std::string &readBuffer);
        /*
         * List roots (symbols, tickers, etc.) 
         * Returns all traded roots for a given security type (i.e. stock or option)
         *
         * @param sec:      security type -- "Stock" or "Option"
         */

        int list_expirations(std::string root, std::string& readBuffer);
        /*
         * List expirations for a specific root (symbol, ticker, etc.) 
         * Returns all expirations for an underlying root.
         *
         * @param root:          security type -- "Stock" or "Option"
         * @param readBuffer:   reference to save data
         */

        int list_strikes(std::string root, std::string exp, std::string& readBuffer);
        /*
         * List all strike prices that are traded on for an underlying root on a certain expiration date.
         *
         * @param root:         security type -- "Stock" or "Option"
         * @param exp:          expiration date to list strikes for
         * @param readBuffer:   reference to save data
         */


        int get_hist_stock(
                std::string req,
                std::string root,
                std::string startDate,
                std::string endDate,
                std::string &readBuffer);
        /*
         * Get historical stock data
         *
         * @param req:       The request type
         * @param root:      The root symbol
         * @param startDate: The start date range as YYYYMMDD
         * @param endDate:   The end date range as YYYYMMDD
         */

        int get_hist_option(
                std::string req,
                std::string root,
                std::string exp,
                int strike,
                std::string right,
                std::string startDate,
                std::string endDate,
                std::string &readBuffer);
        /*
         * Get historical option data
         *
         * @param req:       The request type
         * @param root:      The root symbol
         * @param exp:       The expiration of the option
         * @param strike:    The strike price 
         * @param startDate: The start date range as YYYYMMDD
         * @param endDate:   The end date range as YYYYMMDD
         */
};

