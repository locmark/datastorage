#ifndef __DS
#define __DS

#include "Property.hpp"

#define GLOBAL_POSITIONING 		0
#define LOCAL_POSITIONING 		1
#define FREEFALL_POSITIONING 	2
#define DEEP_MODE 				0
#define ROBOT_ARM_MODE 			1

#define ARM_DISABLED			0
#define ARM_ENABLED				1

#define ARM_ENGINE_1			1
#define ARM_ENGINE_2			2
#define ARM_ENGINE_3			3
#define ARM_ENGINE_4			4
#define ARM_CLOSE				5
#define ARM_OPEN				6
#define ARM_ENABLE				65

class DataStorage {
    public:
    Property<int> engine1_speed;
    Property<int> engine2_speed;
    Property<int> engine3_speed;
    Property<int> engine4_speed;
    Property<int> engine5_speed;
    Property<int> engine6_speed;

    Property<float> current_pos_x;
    Property<float> current_pos_y;
    Property<float> current_pos_z;
    Property<float> current_pos_pitch;
    Property<float> current_pos_roll;
    Property<float> current_pos_yaw;

    Property<float> dest_pos_x;
    Property<float> dest_pos_y;
    Property<float> dest_pos_z;
    Property<float> dest_pos_pitch;
    Property<float> dest_pos_roll;
    Property<float> dest_pos_yaw;

    Property<int> positioning_mode;
    Property<bool> robot_arm_mode;
    Property<bool> joy_active;
    Property<bool> arm_enable;

    Property<bool> module1_power_switch;
    Property<bool> module2_power_switch;
    Property<bool> module3_power_switch;
    Property<bool> module4_power_switch;
    Property<bool> module5_power_switch;
    Property<bool> module6_power_switch;
    Property<bool> module7_power_switch;
    Property<bool> module8_power_switch;

    Property<float> module1_current;
    Property<float> module2_current;
    Property<float> module3_current;
    Property<float> module4_current;
    Property<float> module5_current;
    Property<float> module6_current;
    Property<float> module7_current;
    Property<float> module8_current;

    Property<float> PID1_P;
    Property<float> PID1_I;
    Property<float> PID1_D;
    Property<float> PID2_P;
    Property<float> PID2_I;
    Property<float> PID2_D;
    Property<float> PID3_P;
    Property<float> PID3_I;
    Property<float> PID3_D;
    Property<float> PID4_P;
    Property<float> PID4_I;
    Property<float> PID4_D;
    Property<float> PID5_P;
    Property<float> PID5_I;
    Property<float> PID5_D;
    Property<float> PID6_P;
    Property<float> PID6_I;
    Property<float> PID6_D;

    Property<float> mag_field;

    //robot arm
    Property<int> arm_engine_1;
    Property<int> arm_engine_2;
    Property<int> arm_engine_3;
    Property<int> arm_engine_4;
    Property<int> arm_close;
    Property<int> arm_open;

};

extern DataStorage* DS;

#endif


