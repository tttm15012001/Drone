; Auto-generated. Do not edit!


(cl:in-package beginner-msg)


;//! \htmlinclude test.msg.html

(cl:defclass <test> (roslisp-msg-protocol:ros-message)
  ((years
    :reader years
    :initarg :years
    :type cl:float
    :initform 0.0)
   (age
    :reader age
    :initarg :age
    :type cl:fixnum
    :initform 0))
)

(cl:defclass test (<test>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <test>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'test)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name beginner-msg:<test> is deprecated: use beginner-msg:test instead.")))

(cl:ensure-generic-function 'years-val :lambda-list '(m))
(cl:defmethod years-val ((m <test>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader beginner-msg:years-val is deprecated.  Use beginner-msg:years instead.")
  (years m))

(cl:ensure-generic-function 'age-val :lambda-list '(m))
(cl:defmethod age-val ((m <test>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader beginner-msg:age-val is deprecated.  Use beginner-msg:age instead.")
  (age m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <test>) ostream)
  "Serializes a message object of type '<test>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'years))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'age)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <test>) istream)
  "Deserializes a message object of type '<test>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'years) (roslisp-utils:decode-single-float-bits bits)))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'age)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<test>)))
  "Returns string type for a message object of type '<test>"
  "beginner/test")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'test)))
  "Returns string type for a message object of type 'test"
  "beginner/test")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<test>)))
  "Returns md5sum for a message object of type '<test>"
  "6616f4f93356a20eba531c90e0875eb4")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'test)))
  "Returns md5sum for a message object of type 'test"
  "6616f4f93356a20eba531c90e0875eb4")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<test>)))
  "Returns full string definition for message of type '<test>"
  (cl:format cl:nil "float32 years~%uint8 age~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'test)))
  "Returns full string definition for message of type 'test"
  (cl:format cl:nil "float32 years~%uint8 age~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <test>))
  (cl:+ 0
     4
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <test>))
  "Converts a ROS message object to a list"
  (cl:list 'test
    (cl:cons ':years (years msg))
    (cl:cons ':age (age msg))
))
