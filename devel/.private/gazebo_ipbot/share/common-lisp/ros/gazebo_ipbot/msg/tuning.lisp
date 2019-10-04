; Auto-generated. Do not edit!


(cl:in-package gazebo_ipbot-msg)


;//! \htmlinclude tuning.msg.html

(cl:defclass <tuning> (roslisp-msg-protocol:ros-message)
  ((lkp
    :reader lkp
    :initarg :lkp
    :type std_msgs-msg:Int16
    :initform (cl:make-instance 'std_msgs-msg:Int16))
   (lkd
    :reader lkd
    :initarg :lkd
    :type std_msgs-msg:Int16
    :initform (cl:make-instance 'std_msgs-msg:Int16))
   (lki
    :reader lki
    :initarg :lki
    :type std_msgs-msg:Int16
    :initform (cl:make-instance 'std_msgs-msg:Int16))
   (akp
    :reader akp
    :initarg :akp
    :type std_msgs-msg:Int16
    :initform (cl:make-instance 'std_msgs-msg:Int16))
   (akd
    :reader akd
    :initarg :akd
    :type std_msgs-msg:Int16
    :initform (cl:make-instance 'std_msgs-msg:Int16))
   (aki
    :reader aki
    :initarg :aki
    :type std_msgs-msg:Int16
    :initform (cl:make-instance 'std_msgs-msg:Int16))
   (vel
    :reader vel
    :initarg :vel
    :type std_msgs-msg:Int16
    :initform (cl:make-instance 'std_msgs-msg:Int16)))
)

(cl:defclass tuning (<tuning>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <tuning>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'tuning)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name gazebo_ipbot-msg:<tuning> is deprecated: use gazebo_ipbot-msg:tuning instead.")))

(cl:ensure-generic-function 'lkp-val :lambda-list '(m))
(cl:defmethod lkp-val ((m <tuning>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader gazebo_ipbot-msg:lkp-val is deprecated.  Use gazebo_ipbot-msg:lkp instead.")
  (lkp m))

(cl:ensure-generic-function 'lkd-val :lambda-list '(m))
(cl:defmethod lkd-val ((m <tuning>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader gazebo_ipbot-msg:lkd-val is deprecated.  Use gazebo_ipbot-msg:lkd instead.")
  (lkd m))

(cl:ensure-generic-function 'lki-val :lambda-list '(m))
(cl:defmethod lki-val ((m <tuning>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader gazebo_ipbot-msg:lki-val is deprecated.  Use gazebo_ipbot-msg:lki instead.")
  (lki m))

(cl:ensure-generic-function 'akp-val :lambda-list '(m))
(cl:defmethod akp-val ((m <tuning>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader gazebo_ipbot-msg:akp-val is deprecated.  Use gazebo_ipbot-msg:akp instead.")
  (akp m))

(cl:ensure-generic-function 'akd-val :lambda-list '(m))
(cl:defmethod akd-val ((m <tuning>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader gazebo_ipbot-msg:akd-val is deprecated.  Use gazebo_ipbot-msg:akd instead.")
  (akd m))

(cl:ensure-generic-function 'aki-val :lambda-list '(m))
(cl:defmethod aki-val ((m <tuning>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader gazebo_ipbot-msg:aki-val is deprecated.  Use gazebo_ipbot-msg:aki instead.")
  (aki m))

(cl:ensure-generic-function 'vel-val :lambda-list '(m))
(cl:defmethod vel-val ((m <tuning>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader gazebo_ipbot-msg:vel-val is deprecated.  Use gazebo_ipbot-msg:vel instead.")
  (vel m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <tuning>) ostream)
  "Serializes a message object of type '<tuning>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'lkp) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'lkd) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'lki) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'akp) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'akd) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'aki) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'vel) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <tuning>) istream)
  "Deserializes a message object of type '<tuning>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'lkp) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'lkd) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'lki) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'akp) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'akd) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'aki) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'vel) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<tuning>)))
  "Returns string type for a message object of type '<tuning>"
  "gazebo_ipbot/tuning")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'tuning)))
  "Returns string type for a message object of type 'tuning"
  "gazebo_ipbot/tuning")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<tuning>)))
  "Returns md5sum for a message object of type '<tuning>"
  "8cd8aa6abc2468ca69bf190c916f0446")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'tuning)))
  "Returns md5sum for a message object of type 'tuning"
  "8cd8aa6abc2468ca69bf190c916f0446")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<tuning>)))
  "Returns full string definition for message of type '<tuning>"
  (cl:format cl:nil "std_msgs/Int16 lkp~%std_msgs/Int16 lkd~%std_msgs/Int16 lki~%std_msgs/Int16 akp~%std_msgs/Int16 akd~%std_msgs/Int16 aki~%std_msgs/Int16 vel~%~%================================================================================~%MSG: std_msgs/Int16~%int16 data~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'tuning)))
  "Returns full string definition for message of type 'tuning"
  (cl:format cl:nil "std_msgs/Int16 lkp~%std_msgs/Int16 lkd~%std_msgs/Int16 lki~%std_msgs/Int16 akp~%std_msgs/Int16 akd~%std_msgs/Int16 aki~%std_msgs/Int16 vel~%~%================================================================================~%MSG: std_msgs/Int16~%int16 data~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <tuning>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'lkp))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'lkd))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'lki))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'akp))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'akd))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'aki))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'vel))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <tuning>))
  "Converts a ROS message object to a list"
  (cl:list 'tuning
    (cl:cons ':lkp (lkp msg))
    (cl:cons ':lkd (lkd msg))
    (cl:cons ':lki (lki msg))
    (cl:cons ':akp (akp msg))
    (cl:cons ':akd (akd msg))
    (cl:cons ':aki (aki msg))
    (cl:cons ':vel (vel msg))
))
