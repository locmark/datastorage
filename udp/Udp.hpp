#ifndef __UDP
#define __UDP

#include <iostream>
#include <thread>
#include <unistd.h>
#include <vector>
#include <functional>
#include <string>

#include "udp-lib.h"
#include "../logger/Logger.hpp"
#include "../config/Config.hpp"

#define DataSyncChar 'D'

using namespace std;

class Udp {
    private:
        udp_client_server::udp_server* udpServer = 0;
        udp_client_server::udp_client* udpClient = 0;
        thread* daemonThread;
        vector< function<void(void* value)> > propertiesCallbacks;
    public:
        Udp() {
            TryInit();
        }

        void TryInit() {
            try {
                udpServer = new udp_client_server::udp_server("0.0.0.0", config->GetUdpPort());
                udpClient = new udp_client_server::udp_client(config->GetUdpCyklopIp(), config->GetUdpPort());
                // udpClient = new udp_client_server::udp_client(config->GetUdpCyklopIp(), 5556);  // for testing

                // start deamon thread
                daemonThread = new thread(&Udp::DaemonLoop, this);
                logger->Log("UDP", "Init complete");
            }
            catch(const std::exception& e) {
                logger->Error("UDP", e.what());
                logger->Error("UDP", "Trying again in 2 seconds");
                delete this->udpServer;
                delete this->udpClient;
                sleep(2);
                new thread(&Udp::TryInit, this);    // try to init in separate thread
            }
        }

        void DaemonLoop() {
            char msg[100];
            while(1) {
                memset(msg, 0, sizeof msg); //clear buffer
                udpServer->recv(msg, 100);  // waits until msg arrives
                ParseUdpResponse(msg);
            }
        }

        void ParseUdpResponse(char* msg) {
            switch (msg[0]) 
            {
                case DataSyncChar:
                    if ((int)msg[1] <= size(propertiesCallbacks)) {     // if property of id = msg[1] was registered
                        void* value = (void*)(msg + 2);
                        propertiesCallbacks[(int)msg[1]](value);    // update property value
                    } else {
                        logger->Error("udp", msg);
                    }
                    break;
            
                default:
                    logger->Error("udp", msg);
                    break;
            }
        }

        // properties call this method when are created to register themselves.
        uint8_t RegisterNewDataToSyncAndReturnID(function<void(void* value)> property) {
            propertiesCallbacks.push_back(property);
            return (uint8_t) propertiesCallbacks.size() - 1;    // id will be position in callbacks vector
        }

        // Property call this, when they were changed
        void SyncProperty(uint8_t udpId, void* value, int size) {
            string msg;

            msg += DataSyncChar;
            msg += (char)udpId;

            for(size_t i = 0; i < size; i++)
            {
                msg += *((char*)value + i);
            }
            
            SendMsg(msg);
        }

        void SendMsg(const string& msg) {
            if (udpClient != 0)  // if udp is initialized
                udpClient->send((msg).c_str(), msg.size());
        }
};

extern Udp* udp;

#endif