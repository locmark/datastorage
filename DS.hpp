#ifndef __DS
#define __DS

#include "Property.hpp"

class DataStorage {
    public:
    Property<int> engine1;
    Property<int> engine2;
    Property<int> engine3;
    Property<int> engine4;
    Property<int> engine5;
    Property<int> engine6;

    Property<float> roll;
    Property<float> pitch;
    Property<float> yaw;

    Property<float> accX;
    Property<float> accY;
    Property<float> accZ;

    Property<float> accRoll;
    Property<float> accPitch;
    Property<float> accYaw;
};

extern DataStorage* DS;

#endif


