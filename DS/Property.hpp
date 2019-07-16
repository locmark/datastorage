#ifndef __PROP
#define __PROP

#include "../udp/Udp.hpp"
#include "../fileLogger/FileLogger.hpp"

#include <functional>
#include <string>
#include <iostream>

using namespace std;

#define NULL_FUNCTION [](type value)->void{}

template <typename type> class Property {
    private:
        type value;
        function<void(type)> OnLocalChange = NULL_FUNCTION;
        function<void(type)> OnRemoteChange = NULL_FUNCTION;
        uint8_t udpId = 250;    // not important value, if not changed => error (for deugging)
        inline void LogToFile(type value) {
            if(value != this->value)
                fileLogger->Log(to_string(udpId).c_str(), to_string(value).c_str());
        }
    public:
        Property() {
            function<void(void*)> UdpCallback = [this](void* value)->void{
                LogToFile(*( (type*) value ));
                this->value = *( (type*) value );
                OnRemoteChange(this->value);
            };

            udpId = udp->RegisterNewDataToSyncAndReturnID(UdpCallback);
        }

        inline type Get() {
            return value;
        }

        void Set(type val) {
            LogToFile(val);
            value = val;
            OnLocalChange(value);        // e.g. send value to I2C or show in GUI
            SyncViaUdp();
        }

        inline void operator= (type val) { this->Set(val); }

        void SyncViaUdp() {
            udp->SyncProperty(udpId, (void*)&value, sizeof(type));
        }

        void SetOnLocalChangeFunction(function<void(type)> fnc) {
            OnLocalChange = fnc;
        }

        void SetOnRemoteChangeFunction(function<void(type)> fnc) {
            OnRemoteChange = fnc;
        }
};

#endif