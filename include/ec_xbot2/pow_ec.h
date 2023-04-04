#ifndef XBOT2_POW_EC_H
#define XBOT2_POW_EC_H

#include <xbot2/hal/device_common.h>

namespace XBot { namespace Hal {

class PowerBoardEc : public virtual DeviceBase
{

public:

    virtual float get_battery_voltage() const = 0;

    virtual float get_load_voltage() const = 0;

    virtual float get_load_current() const = 0;


};


} }

#endif // POW_EC_H
