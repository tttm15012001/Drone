;; Auto-generated. Do not edit!


(when (boundp 'diagnostic_msgs::AddDiagnostics)
  (if (not (find-package "DIAGNOSTIC_MSGS"))
    (make-package "DIAGNOSTIC_MSGS"))
  (shadow 'AddDiagnostics (find-package "DIAGNOSTIC_MSGS")))
(unless (find-package "DIAGNOSTIC_MSGS::ADDDIAGNOSTICS")
  (make-package "DIAGNOSTIC_MSGS::ADDDIAGNOSTICS"))
(unless (find-package "DIAGNOSTIC_MSGS::ADDDIAGNOSTICSREQUEST")
  (make-package "DIAGNOSTIC_MSGS::ADDDIAGNOSTICSREQUEST"))
(unless (find-package "DIAGNOSTIC_MSGS::ADDDIAGNOSTICSRESPONSE")
  (make-package "DIAGNOSTIC_MSGS::ADDDIAGNOSTICSRESPONSE"))

(in-package "ROS")





(defclass diagnostic_msgs::AddDiagnosticsRequest
  :super ros::object
  :slots (_load_namespace ))

(defmethod diagnostic_msgs::AddDiagnosticsRequest
  (:init
   (&key
    ((:load_namespace __load_namespace) "")
    )
   (send-super :init)
   (setq _load_namespace (string __load_namespace))
   self)
  (:load_namespace
   (&optional __load_namespace)
   (if __load_namespace (setq _load_namespace __load_namespace)) _load_namespace)
  (:serialization-length
   ()
   (+
    ;; string _load_namespace
    4 (length _load_namespace)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _load_namespace
       (write-long (length _load_namespace) s) (princ _load_namespace s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _load_namespace
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _load_namespace (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass diagnostic_msgs::AddDiagnosticsResponse
  :super ros::object
  :slots (_success _message ))

(defmethod diagnostic_msgs::AddDiagnosticsResponse
  (:init
   (&key
    ((:success __success) nil)
    ((:message __message) "")
    )
   (send-super :init)
   (setq _success __success)
   (setq _message (string __message))
   self)
  (:success
   (&optional (__success :null))
   (if (not (eq __success :null)) (setq _success __success)) _success)
  (:message
   (&optional __message)
   (if __message (setq _message __message)) _message)
  (:serialization-length
   ()
   (+
    ;; bool _success
    1
    ;; string _message
    4 (length _message)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _success
       (if _success (write-byte -1 s) (write-byte 0 s))
     ;; string _message
       (write-long (length _message) s) (princ _message s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _success
     (setq _success (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; string _message
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _message (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass diagnostic_msgs::AddDiagnostics
  :super ros::object
  :slots ())

(setf (get diagnostic_msgs::AddDiagnostics :md5sum-) "e6ac9bbde83d0d3186523c3687aecaee")
(setf (get diagnostic_msgs::AddDiagnostics :datatype-) "diagnostic_msgs/AddDiagnostics")
(setf (get diagnostic_msgs::AddDiagnostics :request) diagnostic_msgs::AddDiagnosticsRequest)
(setf (get diagnostic_msgs::AddDiagnostics :response) diagnostic_msgs::AddDiagnosticsResponse)

(defmethod diagnostic_msgs::AddDiagnosticsRequest
  (:response () (instance diagnostic_msgs::AddDiagnosticsResponse :init)))

(setf (get diagnostic_msgs::AddDiagnosticsRequest :md5sum-) "e6ac9bbde83d0d3186523c3687aecaee")
(setf (get diagnostic_msgs::AddDiagnosticsRequest :datatype-) "diagnostic_msgs/AddDiagnosticsRequest")
(setf (get diagnostic_msgs::AddDiagnosticsRequest :definition-)
      "# This service is used as part of the process for loading analyzers at runtime,
# and should be used by a loader script or program, not as a standalone service.
# Information about dynamic addition of analyzers can be found at
# http://wiki.ros.org/diagnostics/Tutorials/Adding%20Analyzers%20at%20Runtime

# The load_namespace parameter defines the namespace where parameters for the
# initialization of analyzers in the diagnostic aggregator have been loaded. The
# value should be a global name (i.e. /my/name/space), not a relative
# (my/name/space) or private (~my/name/space) name. Analyzers will not be added
# if a non-global name is used. The call will also fail if the namespace
# contains parameters that follow a namespace structure that does not conform to
# that expected by the analyzer definitions. See
# http://wiki.ros.org/diagnostics/Tutorials/Configuring%20Diagnostic%20Aggregators
# and http://wiki.ros.org/diagnostics/Tutorials/Using%20the%20GenericAnalyzer
# for examples of the structure of yaml files which are expected to have been
# loaded into the namespace.
string load_namespace
---

# True if diagnostic aggregator was updated with new diagnostics, False
# otherwise. A false return value means that either there is a bond in the
# aggregator which already used the requested namespace, or the initialization
# of analyzers failed.
bool success

# Message with additional information about the success or failure
string message

")

(setf (get diagnostic_msgs::AddDiagnosticsResponse :md5sum-) "e6ac9bbde83d0d3186523c3687aecaee")
(setf (get diagnostic_msgs::AddDiagnosticsResponse :datatype-) "diagnostic_msgs/AddDiagnosticsResponse")
(setf (get diagnostic_msgs::AddDiagnosticsResponse :definition-)
      "# This service is used as part of the process for loading analyzers at runtime,
# and should be used by a loader script or program, not as a standalone service.
# Information about dynamic addition of analyzers can be found at
# http://wiki.ros.org/diagnostics/Tutorials/Adding%20Analyzers%20at%20Runtime

# The load_namespace parameter defines the namespace where parameters for the
# initialization of analyzers in the diagnostic aggregator have been loaded. The
# value should be a global name (i.e. /my/name/space), not a relative
# (my/name/space) or private (~my/name/space) name. Analyzers will not be added
# if a non-global name is used. The call will also fail if the namespace
# contains parameters that follow a namespace structure that does not conform to
# that expected by the analyzer definitions. See
# http://wiki.ros.org/diagnostics/Tutorials/Configuring%20Diagnostic%20Aggregators
# and http://wiki.ros.org/diagnostics/Tutorials/Using%20the%20GenericAnalyzer
# for examples of the structure of yaml files which are expected to have been
# loaded into the namespace.
string load_namespace
---

# True if diagnostic aggregator was updated with new diagnostics, False
# otherwise. A false return value means that either there is a bond in the
# aggregator which already used the requested namespace, or the initialization
# of analyzers failed.
bool success

# Message with additional information about the success or failure
string message

")



(provide :diagnostic_msgs/AddDiagnostics "e6ac9bbde83d0d3186523c3687aecaee")


