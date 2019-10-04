; Auto-generated. Do not edit!


(cl:in-package gazebo_ipbot-msg)


;//! \htmlinclude pid.msg.html

(cl:defclass <pid> (roslisp-msg-protocol:ros-message)
  ((linear
    :reader linear
    :initarg :linear
    :type std_msgs-msg:Int16
    :initform (cl:make-instance 'std_msgs-msg:Int16))
   (angular
    :reader angular
    :initarg :angular
    :type std_msgs-msg:Int16
    :initform (cl:make-instance 'std_msgs-msg:Int16)))
)

(cl:defclass pid (<pid>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <pid>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'pid)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name gazebo_ipbot-msg:<pid> is deprecated: use gazebo_ipbot-msg:pid instead.")))

(cl:ensure-generic-function 'linear-val :lambda-list '(m))
(cl:defmethod linear-val ((m <pid>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader gazebo_ipbot-msg:linear-val is deprecated.  Use gazebo_ipbot-msg:linear instead.")
  (linear m))

(cl:ensure-generic-function 'angular-val :lambda-list '(m))
(cl:defmethod angular-val ((m <pid>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader gazebo_ipbot-msg:angular-val is deprecated.  Use gazebo_ipbot-msg:angular instead.")
  (angular m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <pid>) ostream)
  "Serializes a message object of type '<pid>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'linear) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'angular) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <pid>) istream)
  "Deserializes a message object of type '<pid>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'linear) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'angular) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<pid>)))
  "Returns string type for a message object of type '<pid>"
  "gazebo_ipbot/pid")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'pid)))
  "Returns string type for a message object of type 'pid"
  "gazebo_ipbot/pid")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<pid>)))
  "Returns md5sum for a message object of type '<pid>"
  "daee48bdd9b022a2534221391301bf32")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'pid)))
  "Returns md5sum for a message object of type 'pid"
  "daee48bdd9b022a2534221391301bf32")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<pid>)))
  "Returns full string definition for message of type '<pid>"
  (cl:format cl:nil "std_msgs/Int16 linear~%std_msgs/Int16 angular~%~%================================================================================~%MSG: std_msgs/Int16~%int16 data~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'pid)))
  "Returns full string definition for message of type 'pid"
  (cl:format cl:nil "std_msgs/Int16 linear~%std_msgs/Int16 angular~%~%================================================================================~%MSG: std_msgs/Int16~%int16 data~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <pid>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'linear))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'angular))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <pid>))
  "Converts a ROS message object to a list"
  (cl:list 'pid
    (cl:cons ':linear (linear msg))
    (cl:cons ':angular (angular msg))
))
