
(cl:in-package :asdf)

(defsystem "gazebo_ipbot-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "pid" :depends-on ("_package_pid"))
    (:file "_package_pid" :depends-on ("_package"))
    (:file "tuning" :depends-on ("_package_tuning"))
    (:file "_package_tuning" :depends-on ("_package"))
  ))