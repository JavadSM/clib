/*
A bunch of random tools
*/

#include <ctime>
#include <string>
#include <stdio.h>

//generate random string
std::string getUid(){
    std::string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    std::string uid="";
    int length = characters.size();
    for(int i=0 ; i<10 ; i++){
        uid += characters[rand() % length];
    }
    return uid;
}