;; Auto-generated. Do not edit!


(when (boundp 'gazebo_ipbot::pid)
  (if (not (find-package "GAZEBO_IPBOT"))
    (make-package "GAZEBO_IPBOT"))
  (shadow 'pid (find-package "GAZEBO_IPBOT")))
(unless (find-package "GAZEBO_IPBOT::PID")
  (make-package "GAZEBO_IPBOT::PID"))

(in-package "ROS")
;;//! \htmlinclude pid.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass gazebo_ipbot::pid
  :super ros::object
  :slots (_linear _angular ))

(defmethod gazebo_ipbot::pid
  (:init
   (&key
    ((:linear __linear) (instance std_msgs::Int16 :init))
    ((:angular __angular) (instance std_msgs::Int16 :init))
    )
   (send-super :init)
   (setq _linear __linear)
   (setq _angular __angular)
   self)
  (:linear
   (&rest __linear)
   (if (keywordp (car __linear))
       (send* _linear __linear)
     (progn
       (if __linear (setq _linear (car __linear)))
       _linear)))
  (:angular
   (&rest __angular)
   (if (keywordp (car __angular))
       (send* _angular __angular)
     (progn
       (if __angular (setq _angular (car __angular)))
       _angular)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/Int16 _linear
    (send _linear :serialization-length)
    ;; std_msgs/Int16 _angular
    (send _angular :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Int16 _linear
       (send _linear :serialize s)
     ;; std_msgs/Int16 _angular
       (send _angular :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Int16 _linear
     (send _linear :deserialize buf ptr-) (incf ptr- (send _linear :serialization-length))
   ;; std_msgs/Int16 _angular
     (send _angular :deserialize buf ptr-) (incf ptr- (send _angular :serialization-length))
   ;;
   self)
  )

(setf (get gazebo_ipbot::pid :md5sum-) "daee48bdd9b022a2534221391301bf32")
(setf (get gazebo_ipbot::pid :datatype-) "gazebo_ipbot/pid")
(setf (get gazebo_ipbot::pid :definition-)
      "std_msgs/Int16 linear
std_msgs/Int16 angular

================================================================================
MSG: std_msgs/Int16
int16 data

")



(provide :gazebo_ipbot/pid "daee48bdd9b022a2534221391301bf32")


