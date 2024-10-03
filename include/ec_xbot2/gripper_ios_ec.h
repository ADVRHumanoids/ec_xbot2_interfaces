#ifndef GRIPPER_IOS_EC_H
#define GRIPPER_IOS_EC_H

#include <xbot2/hal/device.h>
#include <bitset>

namespace XBot { namespace Hal {

class GripperIosEc : public virtual DeviceBase
{

public:

    virtual double get_pos() const = 0;
    virtual double get_analog_out() const = 0;
    virtual std::bitset<2> get_digital_out() const = 0;

    virtual void set_pos_ref(double q) = 0;
    virtual void set_gains(double kp, double kd) = 0;
    virtual void set_max_voltage(double vmax) = 0;
    virtual void set_voltage_ref(double vref) = 0;

};

} }

#endif // GRIPPER_IOS_EC_H
