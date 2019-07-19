#ifndef __DS
#define __DS

#include "Property.hpp"

// buttons on controller
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
    //PID ENGINES TEST
    Property<int> engine_fl_speed_requested;
    Property<int> engine_fr_speed_requested;
    Property<int> engine_rl_speed_requested;
    Property<int> engine_rr_speed_requested;
    Property<int> engine_tl_speed_requested;
    Property<int> engine_tr_speed_requested;
	
    Property<int> engine_fl_speed;
    Property<int> engine_fr_speed;
    Property<int> engine_rl_speed;
    Property<int> engine_rr_speed;
    Property<int> engine_tl_speed;
    Property<int> engine_tr_speed;

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
    Property<bool> PID_enable;

    Property<bool> engine_fl_power_switch;
    Property<bool> engine_fr_power_switch;
    Property<bool> engine_rl_power_switch;
    Property<bool> engine_rr_power_switch;
    Property<bool> engine_tl_power_switch;
    Property<bool> engine_tr_power_switch;
    Property<bool> arm_power_switch;
    Property<bool> magnetometer_power_switch;

    Property<float> engine_fl_current;
    Property<float> engine_fr_current;
    Property<float> engine_rl_current;
    Property<float> engine_rr_current;
    Property<float> engine_tl_current;
    Property<float> engine_tr_current;
    Property<float> arm_current;
    Property<float> magnetometer_current;

    Property<float> engine_fl_current_limit;
	Property<float> engine_fr_current_limit;
	Property<float> engine_rl_current_limit;
	Property<float> engine_rr_current_limit;
	Property<float> engine_tl_current_limit;
	Property<float> engine_tr_current_limit;
	Property<float> arm_current_limit;
	Property<float> magnetometer_current_limit;

    Property<float> PID_x_P;
    Property<float> PID_x_I;
    Property<float> PID_x_D;
    Property<float> PID_y_P;
    Property<float> PID_y_I;
    Property<float> PID_y_D;
    Property<float> PID_z_P;
    Property<float> PID_z_I;
    Property<float> PID_z_D;
    Property<float> PID_pitch_P;
    Property<float> PID_pitch_I;
    Property<float> PID_pitch_D;
    Property<float> PID_roll_P;
    Property<float> PID_roll_I;
    Property<float> PID_roll_D;
    Property<float> PID_yaw_P;
    Property<float> PID_yaw_I;
    Property<float> PID_yaw_D;

    Property<float> mag_1_x;
    Property<float> mag_1_y;
    Property<float> mag_1_z;
    Property<float> mag_2_x;
    Property<float> mag_2_y;
    Property<float> mag_2_z;
    Property<float> mag_3_x;
    Property<float> mag_3_y;
    Property<float> mag_3_z;
    Property<float> mag_4_x;
    Property<float> mag_4_y;
    Property<float> mag_4_z;
	
    Property<float> mag_1_t;
    Property<float> mag_2_t;
    Property<float> mag_3_t;
    Property<float> mag_4_t;
	
    //robot arm
    Property<int> arm_engine_1;
    Property<int> arm_engine_2;
    Property<int> arm_engine_3;
    Property<int> arm_engine_4;
    Property<int> arm_close;
    Property<int> arm_open;
    Property<float> arm_grip_current;

};

extern DataStorage* DS;

#endif


