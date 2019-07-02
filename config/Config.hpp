#ifndef __CONFIG
#define __CONFIG

#include "pugixml.hpp"
#include "../logger/Logger.hpp"

using namespace std;

class Config
{
private:
    pugi::xml_document doc;
public:
    Config(){
        pugi::xml_parse_result result = doc.load_file("DataStorage/config.xml");
        logger->Log("config", result.description());
    }
    
    ~Config(){

    }

    int GetUdpPort() {
        return doc.child("deep").child("udp").attribute("port").as_int();
    }

    char* GetUdpCyklopIp() {
        return (char*) doc.child("deep").child("udp").attribute("cyklop").as_string();
    }

    char* GetUdpDeepIp() {
        return (char*) doc.child("deep").child("udp").attribute("deep").as_string();
    }
};

extern Config* config;
#endif