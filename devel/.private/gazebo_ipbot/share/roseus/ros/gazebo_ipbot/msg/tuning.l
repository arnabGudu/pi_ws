;; Auto-generated. Do not edit!


(when (boundp 'gazebo_ipbot::tuning)
  (if (not (find-package "GAZEBO_IPBOT"))
    (make-package "GAZEBO_IPBOT"))
  (shadow 'tuning (find-package "GAZEBO_IPBOT")))
(unless (find-package "GAZEBO_IPBOT::TUNING")
  (make-package "GAZEBO_IPBOT::TUNING"))

(in-package "ROS")
;;//! \htmlinclude tuning.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass gazebo_ipbot::tuning
  :super ros::object
  :slots (_lkp _lkd _lki _akp _akd _aki _vel ))

(defmethod gazebo_ipbot::tuning
  (:init
   (&key
    ((:lkp __lkp) (instance std_msgs::Int16 :init))
    ((:lkd __lkd) (instance std_msgs::Int16 :init))
    ((:lki __lki) (instance std_msgs::Int16 :init))
    ((:akp __akp) (instance std_msgs::Int16 :init))
    ((:akd __akd) (instance std_msgs::Int16 :init))
    ((:aki __aki) (instance std_msgs::Int16 :init))
    ((:vel __vel) (instance std_msgs::Int16 :init))
    )
   (send-super :init)
   (setq _lkp __lkp)
   (setq _lkd __lkd)
   (setq _lki __lki)
   (setq _akp __akp)
   (setq _akd __akd)
   (setq _aki __aki)
   (setq _vel __vel)
   self)
  (:lkp
   (&rest __lkp)
   (if (keywordp (car __lkp))
       (send* _lkp __lkp)
     (progn
       (if __lkp (setq _lkp (car __lkp)))
       _lkp)))
  (:lkd
   (&rest __lkd)
   (if (keywordp (car __lkd))
       (send* _lkd __lkd)
     (progn
       (if __lkd (setq _lkd (car __lkd)))
       _lkd)))
  (:lki
   (&rest __lki)
   (if (keywordp (car __lki))
       (send* _lki __lki)
     (progn
       (if __lki (setq _lki (car __lki)))
       _lki)))
  (:akp
   (&rest __akp)
   (if (keywordp (car __akp))
       (send* _akp __akp)
     (progn
       (if __akp (setq _akp (car __akp)))
       _akp)))
  (:akd
   (&rest __akd)
   (if (keywordp (car __akd))
       (send* _akd __akd)
     (progn
       (if __akd (setq _akd (car __akd)))
       _akd)))
  (:aki
   (&rest __aki)
   (if (keywordp (car __aki))
       (send* _aki __aki)
     (progn
       (if __aki (setq _aki (car __aki)))
       _aki)))
  (:vel
   (&rest __vel)
   (if (keywordp (car __vel))
       (send* _vel __vel)
     (progn
       (if __vel (setq _vel (car __vel)))
       _vel)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/Int16 _lkp
    (send _lkp :serialization-length)
    ;; std_msgs/Int16 _lkd
    (send _lkd :serialization-length)
    ;; std_msgs/Int16 _lki
    (send _lki :serialization-length)
    ;; std_msgs/Int16 _akp
    (send _akp :serialization-length)
    ;; std_msgs/Int16 _akd
    (send _akd :serialization-length)
    ;; std_msgs/Int16 _aki
    (send _aki :serialization-length)
    ;; std_msgs/Int16 _vel
    (send _vel :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Int16 _lkp
       (send _lkp :serialize s)
     ;; std_msgs/Int16 _lkd
       (send _lkd :serialize s)
     ;; std_msgs/Int16 _lki
       (send _lki :serialize s)
     ;; std_msgs/Int16 _akp
       (send _akp :serialize s)
     ;; std_msgs/Int16 _akd
       (send _akd :serialize s)
     ;; std_msgs/Int16 _aki
       (send _aki :serialize s)
     ;; std_msgs/Int16 _vel
       (send _vel :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Int16 _lkp
     (send _lkp :deserialize buf ptr-) (incf ptr- (send _lkp :serialization-length))
   ;; std_msgs/Int16 _lkd
     (send _lkd :deserialize buf ptr-) (incf ptr- (send _lkd :serialization-length))
   ;; std_msgs/Int16 _lki
     (send _lki :deserialize buf ptr-) (incf ptr- (send _lki :serialization-length))
   ;; std_msgs/Int16 _akp
     (send _akp :deserialize buf ptr-) (incf ptr- (send _akp :serialization-length))
   ;; std_msgs/Int16 _akd
     (send _akd :deserialize buf ptr-) (incf ptr- (send _akd :serialization-length))
   ;; std_msgs/Int16 _aki
     (send _aki :deserialize buf ptr-) (incf ptr- (send _aki :serialization-length))
   ;; std_msgs/Int16 _vel
     (send _vel :deserialize buf ptr-) (incf ptr- (send _vel :serialization-length))
   ;;
   self)
  )

(setf (get gazebo_ipbot::tuning :md5sum-) "8cd8aa6abc2468ca69bf190c916f0446")
(setf (get gazebo_ipbot::tuning :datatype-) "gazebo_ipbot/tuning")
(setf (get gazebo_ipbot::tuning :definition-)
      "std_msgs/Int16 lkp
std_msgs/Int16 lkd
std_msgs/Int16 lki
std_msgs/Int16 akp
std_msgs/Int16 akd
std_msgs/Int16 aki
std_msgs/Int16 vel

================================================================================
MSG: std_msgs/Int16
int16 data

")



(provide :gazebo_ipbot/tuning "8cd8aa6abc2468ca69bf190c916f0446")


