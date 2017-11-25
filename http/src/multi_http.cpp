#include <iostream>
#include "param.hpp"
#include "../../socket/src/unix_client.hpp"

class HTTP {
        public:
         std::string get(std::string url, std::string query_s);
         std::string post(std::string url, std::string query_s);
};

std::string HTTP::get(std::string url, std::string query_s){
    Client c(url, 80, 2048);
    std::string request = "GET " + query_s + " HTTP/1.1";
    std::cout << request << std::endl;
    c.send(request);
    return c.recv(true);
}

std::string HTTP::post(std::string url, std::string query_s){
    Client c(url, 80, 2048);
    std::string request = "POST " + query_s + " HTTP/1.1";
    std::cout << request << std::endl;
    c.send(request);
    return c.recv(true);
}

int main(){
    HTTP http;
    std::cout << http.get("https://google.com", "/index.html") << std::endl;
}