;; Auto-generated. Do not edit!


(when (boundp 'beginner::test)
  (if (not (find-package "BEGINNER"))
    (make-package "BEGINNER"))
  (shadow 'test (find-package "BEGINNER")))
(unless (find-package "BEGINNER::TEST")
  (make-package "BEGINNER::TEST"))

(in-package "ROS")
;;//! \htmlinclude test.msg.html


(defclass beginner::test
  :super ros::object
  :slots (_years _age ))

(defmethod beginner::test
  (:init
   (&key
    ((:years __years) 0.0)
    ((:age __age) 0)
    )
   (send-super :init)
   (setq _years (float __years))
   (setq _age (round __age))
   self)
  (:years
   (&optional __years)
   (if __years (setq _years __years)) _years)
  (:age
   (&optional __age)
   (if __age (setq _age __age)) _age)
  (:serialization-length
   ()
   (+
    ;; float32 _years
    4
    ;; uint8 _age
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _years
       (sys::poke _years (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; uint8 _age
       (write-byte _age s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _years
     (setq _years (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; uint8 _age
     (setq _age (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(setf (get beginner::test :md5sum-) "6616f4f93356a20eba531c90e0875eb4")
(setf (get beginner::test :datatype-) "beginner/test")
(setf (get beginner::test :definition-)
      "float32 years
uint8 age

")



(provide :beginner/test "6616f4f93356a20eba531c90e0875eb4")


