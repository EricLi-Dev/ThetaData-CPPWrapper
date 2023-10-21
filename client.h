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
        CURL *curl;

    public:
        ThetaClient(std::string username, std::string passwd);
        /*
         * Construct a client instance to interact with market datao
         *
         * @param username: ThetaData email. Can be 'default' if using free data
         * @param passwd:   ThetaData password. Can be 'default' if using free data
         */

        int get_hist_stock(
                std::string req,
                std::string root,
                std::string startDate,
                std::string endDate);
        /*
         * Get historical stock data
         *
         * @param req:       The request type
         * @param root:      The root symbol
         * @param startDate: The start date range
         * @param endDate:   The end date range
         */

};

