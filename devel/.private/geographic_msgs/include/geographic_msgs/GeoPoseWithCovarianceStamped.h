// Generated by gencpp from file geographic_msgs/GeoPoseWithCovarianceStamped.msg
// DO NOT EDIT!


#ifndef GEOGRAPHIC_MSGS_MESSAGE_GEOPOSEWITHCOVARIANCESTAMPED_H
#define GEOGRAPHIC_MSGS_MESSAGE_GEOPOSEWITHCOVARIANCESTAMPED_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <geographic_msgs/GeoPoseWithCovariance.h>

namespace geographic_msgs
{
template <class ContainerAllocator>
struct GeoPoseWithCovarianceStamped_
{
  typedef GeoPoseWithCovarianceStamped_<ContainerAllocator> Type;

  GeoPoseWithCovarianceStamped_()
    : header()
    , pose()  {
    }
  GeoPoseWithCovarianceStamped_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , pose(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef  ::geographic_msgs::GeoPoseWithCovariance_<ContainerAllocator>  _pose_type;
  _pose_type pose;





  typedef boost::shared_ptr< ::geographic_msgs::GeoPoseWithCovarianceStamped_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::geographic_msgs::GeoPoseWithCovarianceStamped_<ContainerAllocator> const> ConstPtr;

}; // struct GeoPoseWithCovarianceStamped_

typedef ::geographic_msgs::GeoPoseWithCovarianceStamped_<std::allocator<void> > GeoPoseWithCovarianceStamped;

typedef boost::shared_ptr< ::geographic_msgs::GeoPoseWithCovarianceStamped > GeoPoseWithCovarianceStampedPtr;
typedef boost::shared_ptr< ::geographic_msgs::GeoPoseWithCovarianceStamped const> GeoPoseWithCovarianceStampedConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::geographic_msgs::GeoPoseWithCovarianceStamped_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::geographic_msgs::GeoPoseWithCovarianceStamped_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::geographic_msgs::GeoPoseWithCovarianceStamped_<ContainerAllocator1> & lhs, const ::geographic_msgs::GeoPoseWithCovarianceStamped_<ContainerAllocator2> & rhs)
{
  return lhs.header == rhs.header &&
    lhs.pose == rhs.pose;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::geographic_msgs::GeoPoseWithCovarianceStamped_<ContainerAllocator1> & lhs, const ::geographic_msgs::GeoPoseWithCovarianceStamped_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace geographic_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::geographic_msgs::GeoPoseWithCovarianceStamped_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::geographic_msgs::GeoPoseWithCovarianceStamped_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::geographic_msgs::GeoPoseWithCovarianceStamped_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::geographic_msgs::GeoPoseWithCovarianceStamped_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::geographic_msgs::GeoPoseWithCovarianceStamped_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::geographic_msgs::GeoPoseWithCovarianceStamped_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::geographic_msgs::GeoPoseWithCovarianceStamped_<ContainerAllocator> >
{
  static const char* value()
  {
    return "2cc818b24aae5ffa4fd33f5ee0bb5421";
  }

  static const char* value(const ::geographic_msgs::GeoPoseWithCovarianceStamped_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x2cc818b24aae5ffaULL;
  static const uint64_t static_value2 = 0x4fd33f5ee0bb5421ULL;
};

template<class ContainerAllocator>
struct DataType< ::geographic_msgs::GeoPoseWithCovarianceStamped_<ContainerAllocator> >
{
  static const char* value()
  {
    return "geographic_msgs/GeoPoseWithCovarianceStamped";
  }

  static const char* value(const ::geographic_msgs::GeoPoseWithCovarianceStamped_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::geographic_msgs::GeoPoseWithCovarianceStamped_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n"
"geographic_msgs/GeoPoseWithCovariance pose\n"
"\n"
"================================================================================\n"
"MSG: std_msgs/Header\n"
"# Standard metadata for higher-level stamped data types.\n"
"# This is generally used to communicate timestamped data \n"
"# in a particular coordinate frame.\n"
"# \n"
"# sequence ID: consecutively increasing ID \n"
"uint32 seq\n"
"#Two-integer timestamp that is expressed as:\n"
"# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n"
"# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n"
"# time-handling sugar is provided by the client library\n"
"time stamp\n"
"#Frame this data is associated with\n"
"string frame_id\n"
"\n"
"================================================================================\n"
"MSG: geographic_msgs/GeoPoseWithCovariance\n"
"# Geographic pose, using the WGS 84 reference ellipsoid.\n"
"#\n"
"# Orientation uses the East-North-Up (ENU) frame of reference.\n"
"# (But, what about singularities at the poles?)\n"
"\n"
"GeoPose pose\n"
"\n"
"# Row-major representation of the 6x6 covariance matrix\n"
"# The orientation parameters use a fixed-axis representation.\n"
"# In order, the parameters are:\n"
"# (Lat, Lon, Alt, rotation about E (East) axis, rotation about N (North) axis, rotation about U (Up) axis)\n"
"float64[36] covariance\n"
"\n"
"================================================================================\n"
"MSG: geographic_msgs/GeoPose\n"
"# Geographic pose, using the WGS 84 reference ellipsoid.\n"
"#\n"
"# Orientation uses the East-North-Up (ENU) frame of reference.\n"
"# (But, what about singularities at the poles?)\n"
"\n"
"GeoPoint position\n"
"geometry_msgs/Quaternion orientation\n"
"\n"
"================================================================================\n"
"MSG: geographic_msgs/GeoPoint\n"
"# Geographic point, using the WGS 84 reference ellipsoid.\n"
"\n"
"# Latitude [degrees]. Positive is north of equator; negative is south\n"
"# (-90 <= latitude <= +90).\n"
"float64 latitude\n"
"\n"
"# Longitude [degrees]. Positive is east of prime meridian; negative is\n"
"# west (-180 <= longitude <= +180). At the poles, latitude is -90 or\n"
"# +90, and longitude is irrelevant, but must be in range.\n"
"float64 longitude\n"
"\n"
"# Altitude [m]. Positive is above the WGS 84 ellipsoid (NaN if unspecified).\n"
"float64 altitude\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Quaternion\n"
"# This represents an orientation in free space in quaternion form.\n"
"\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
"float64 w\n"
;
  }

  static const char* value(const ::geographic_msgs::GeoPoseWithCovarianceStamped_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::geographic_msgs::GeoPoseWithCovarianceStamped_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.pose);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct GeoPoseWithCovarianceStamped_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::geographic_msgs::GeoPoseWithCovarianceStamped_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::geographic_msgs::GeoPoseWithCovarianceStamped_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "pose: ";
    s << std::endl;
    Printer< ::geographic_msgs::GeoPoseWithCovariance_<ContainerAllocator> >::stream(s, indent + "  ", v.pose);
  }
};

} // namespace message_operations
} // namespace ros

#endif // GEOGRAPHIC_MSGS_MESSAGE_GEOPOSEWITHCOVARIANCESTAMPED_H
