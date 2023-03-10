// Generated by gencpp from file shape_msgs/Mesh.msg
// DO NOT EDIT!


#ifndef SHAPE_MSGS_MESSAGE_MESH_H
#define SHAPE_MSGS_MESSAGE_MESH_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <shape_msgs/MeshTriangle.h>
#include <geometry_msgs/Point.h>

namespace shape_msgs
{
template <class ContainerAllocator>
struct Mesh_
{
  typedef Mesh_<ContainerAllocator> Type;

  Mesh_()
    : triangles()
    , vertices()  {
    }
  Mesh_(const ContainerAllocator& _alloc)
    : triangles(_alloc)
    , vertices(_alloc)  {
  (void)_alloc;
    }



   typedef std::vector< ::shape_msgs::MeshTriangle_<ContainerAllocator> , typename std::allocator_traits<ContainerAllocator>::template rebind_alloc< ::shape_msgs::MeshTriangle_<ContainerAllocator> >> _triangles_type;
  _triangles_type triangles;

   typedef std::vector< ::geometry_msgs::Point_<ContainerAllocator> , typename std::allocator_traits<ContainerAllocator>::template rebind_alloc< ::geometry_msgs::Point_<ContainerAllocator> >> _vertices_type;
  _vertices_type vertices;





  typedef boost::shared_ptr< ::shape_msgs::Mesh_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::shape_msgs::Mesh_<ContainerAllocator> const> ConstPtr;

}; // struct Mesh_

typedef ::shape_msgs::Mesh_<std::allocator<void> > Mesh;

typedef boost::shared_ptr< ::shape_msgs::Mesh > MeshPtr;
typedef boost::shared_ptr< ::shape_msgs::Mesh const> MeshConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::shape_msgs::Mesh_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::shape_msgs::Mesh_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::shape_msgs::Mesh_<ContainerAllocator1> & lhs, const ::shape_msgs::Mesh_<ContainerAllocator2> & rhs)
{
  return lhs.triangles == rhs.triangles &&
    lhs.vertices == rhs.vertices;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::shape_msgs::Mesh_<ContainerAllocator1> & lhs, const ::shape_msgs::Mesh_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace shape_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::shape_msgs::Mesh_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::shape_msgs::Mesh_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::shape_msgs::Mesh_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::shape_msgs::Mesh_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::shape_msgs::Mesh_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::shape_msgs::Mesh_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::shape_msgs::Mesh_<ContainerAllocator> >
{
  static const char* value()
  {
    return "1ffdae9486cd3316a121c578b47a85cc";
  }

  static const char* value(const ::shape_msgs::Mesh_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x1ffdae9486cd3316ULL;
  static const uint64_t static_value2 = 0xa121c578b47a85ccULL;
};

template<class ContainerAllocator>
struct DataType< ::shape_msgs::Mesh_<ContainerAllocator> >
{
  static const char* value()
  {
    return "shape_msgs/Mesh";
  }

  static const char* value(const ::shape_msgs::Mesh_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::shape_msgs::Mesh_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# Definition of a mesh\n"
"\n"
"# list of triangles; the index values refer to positions in vertices[]\n"
"MeshTriangle[] triangles\n"
"\n"
"# the actual vertices that make up the mesh\n"
"geometry_msgs/Point[] vertices\n"
"\n"
"================================================================================\n"
"MSG: shape_msgs/MeshTriangle\n"
"# Definition of a triangle's vertices\n"
"uint32[3] vertex_indices\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Point\n"
"# This contains the position of a point in free space\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
;
  }

  static const char* value(const ::shape_msgs::Mesh_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::shape_msgs::Mesh_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.triangles);
      stream.next(m.vertices);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Mesh_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::shape_msgs::Mesh_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::shape_msgs::Mesh_<ContainerAllocator>& v)
  {
    s << indent << "triangles[]" << std::endl;
    for (size_t i = 0; i < v.triangles.size(); ++i)
    {
      s << indent << "  triangles[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::shape_msgs::MeshTriangle_<ContainerAllocator> >::stream(s, indent + "    ", v.triangles[i]);
    }
    s << indent << "vertices[]" << std::endl;
    for (size_t i = 0; i < v.vertices.size(); ++i)
    {
      s << indent << "  vertices[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::geometry_msgs::Point_<ContainerAllocator> >::stream(s, indent + "    ", v.vertices[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // SHAPE_MSGS_MESSAGE_MESH_H
