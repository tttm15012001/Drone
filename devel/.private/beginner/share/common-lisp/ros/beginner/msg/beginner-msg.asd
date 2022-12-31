
(cl:in-package :asdf)

(defsystem "beginner-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "Num" :depends-on ("_package_Num"))
    (:file "_package_Num" :depends-on ("_package"))
    (:file "test" :depends-on ("_package_test"))
    (:file "_package_test" :depends-on ("_package"))
  ))