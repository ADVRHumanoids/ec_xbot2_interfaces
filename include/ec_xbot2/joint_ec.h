#ifndef JOINT_EC_H
#define JOINT_EC_H

#include <xbot2/hal/dev_joint.h>

namespace XBot { namespace Hal {

/**
 * @brief The JointEc class is the base class for Ecat joints.
 * It adds on top of the default JointBase an aux (read only) and fault API.
 */
class JointEc : public virtual JointBase
{

public:

    /**
     * @brief setFrictionCompensation
     * @param fc must be 0 < fc < 1
     */
    virtual void setFrictionCompensation(float fc) = 0;

    /**
     * @brief getFrictionCompensation
     */
    virtual float getFrictionCompensation() const = 0;

    /**
     * @brief get_aux_type_names returns all valid read aux types
     */
    virtual std::set<std::string> get_aux_type_names() = 0;

    /**
     * @brief set_aux_rd_type allows to asynchronously set a desired
     * read aux type
     * @param aux_type is one of the entries returned by get_aux_type_names()
     * @return true on success
     *
     * note: the operation is carried out asynchronously
     *
     */
    virtual bool set_aux_rd_type(const std::vector<std::string>& aux_types) = 0;

};


/**
 * @brief The JointEcAux struct is sent over internal topics by the JointEc
 * driver component
 */
struct JointEcAux
{
    XBot::chrono::system_clock::time_point stamp;
    std::vector<std::string> name;
    std::vector<std::string> aux_type;
    std::vector<double> aux_value;
};


/**
 * @brief The JointEcFault struct is sent over internal topics by the JointEc
 * driver component
 */
struct JointEcFault
{
    XBot::chrono::system_clock::time_point stamp;
    std::vector<std::string> name;
    std::vector<std::string> fault;
};

} }


#endif // JOINT_EC_H
