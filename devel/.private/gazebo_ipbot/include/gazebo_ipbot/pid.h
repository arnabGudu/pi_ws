// Generated by gencpp from file gazebo_ipbot/pid.msg
// DO NOT EDIT!


#ifndef GAZEBO_IPBOT_MESSAGE_PID_H
#define GAZEBO_IPBOT_MESSAGE_PID_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Int16.h>
#include <std_msgs/Int16.h>

namespace gazebo_ipbot
{
template <class ContainerAllocator>
struct pid_
{
  typedef pid_<ContainerAllocator> Type;

  pid_()
    : linear()
    , angular()  {
    }
  pid_(const ContainerAllocator& _alloc)
    : linear(_alloc)
    , angular(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Int16_<ContainerAllocator>  _linear_type;
  _linear_type linear;

   typedef  ::std_msgs::Int16_<ContainerAllocator>  _angular_type;
  _angular_type angular;





  typedef boost::shared_ptr< ::gazebo_ipbot::pid_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::gazebo_ipbot::pid_<ContainerAllocator> const> ConstPtr;

}; // struct pid_

typedef ::gazebo_ipbot::pid_<std::allocator<void> > pid;

typedef boost::shared_ptr< ::gazebo_ipbot::pid > pidPtr;
typedef boost::shared_ptr< ::gazebo_ipbot::pid const> pidConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::gazebo_ipbot::pid_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::gazebo_ipbot::pid_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace gazebo_ipbot

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'gazebo_ipbot': ['/home/iarc/pi_ws/src/gazebo_ipbot/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::gazebo_ipbot::pid_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::gazebo_ipbot::pid_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::gazebo_ipbot::pid_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::gazebo_ipbot::pid_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::gazebo_ipbot::pid_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::gazebo_ipbot::pid_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::gazebo_ipbot::pid_<ContainerAllocator> >
{
  static const char* value()
  {
    return "daee48bdd9b022a2534221391301bf32";
  }

  static const char* value(const ::gazebo_ipbot::pid_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xdaee48bdd9b022a2ULL;
  static const uint64_t static_value2 = 0x534221391301bf32ULL;
};

template<class ContainerAllocator>
struct DataType< ::gazebo_ipbot::pid_<ContainerAllocator> >
{
  static const char* value()
  {
    return "gazebo_ipbot/pid";
  }

  static const char* value(const ::gazebo_ipbot::pid_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::gazebo_ipbot::pid_<ContainerAllocator> >
{
  static const char* value()
  {
    return "std_msgs/Int16 linear\n\
std_msgs/Int16 angular\n\
\n\
================================================================================\n\
MSG: std_msgs/Int16\n\
int16 data\n\
";
  }

  static const char* value(const ::gazebo_ipbot::pid_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::gazebo_ipbot::pid_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.linear);
      stream.next(m.angular);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct pid_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::gazebo_ipbot::pid_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::gazebo_ipbot::pid_<ContainerAllocator>& v)
  {
    s << indent << "linear: ";
    s << std::endl;
    Printer< ::std_msgs::Int16_<ContainerAllocator> >::stream(s, indent + "  ", v.linear);
    s << indent << "angular: ";
    s << std::endl;
    Printer< ::std_msgs::Int16_<ContainerAllocator> >::stream(s, indent + "  ", v.angular);
  }
};

} // namespace message_operations
} // namespace ros

#endif // GAZEBO_IPBOT_MESSAGE_PID_H
