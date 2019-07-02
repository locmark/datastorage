#ifndef __PROP
#define __PROP

#include "../udp/Udp.hpp"

#include <functional>
#include <iostream>

using namespace std;

#define NULL_FUNCTION [](type value)->void{}

template <typename type> class Property {
    private:
        type value;
        function<void(type)> OnChange = NULL_FUNCTION;
        uint8_t udpId = 250;    // not important value, if not changed => error (for deugging)
    public:
        Property() {
            function<void(void*)> UdpCallback = [this](void* value)->void{
                this->value = *( (type*) value );
                OnChange(this->value);
            };

            udpId = udp->RegisterNewDataToSyncAndReturnID(UdpCallback);
        }

        inline type Get() {
            return value;
        }

        void Set(type val) {
            value = val;
            OnChange(value);        // e.g. send value to I2C or show in GUI
            SyncViaUdp();
        }

        inline void operator= (type val) { this->Set(val); }

        void SyncViaUdp() {
            udp->SyncProperty(udpId, (void*)&value, sizeof(type));
        }
};

#endif