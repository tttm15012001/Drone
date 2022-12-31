#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/tttm/catkin_ws/src/mavros/mavros"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/tttm/catkin_ws/install/lib/python3/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/tttm/catkin_ws/install/lib/python3/dist-packages:/home/tttm/catkin_ws/build/mavros/lib/python3/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/tttm/catkin_ws/build/mavros" \
    "/usr/bin/python3" \
    "/home/tttm/catkin_ws/src/mavros/mavros/setup.py" \
     \
    build --build-base "/home/tttm/catkin_ws/build/mavros" \
    install \
    --root="${DESTDIR-/}" \
    --install-layout=deb --prefix="/home/tttm/catkin_ws/install" --install-scripts="/home/tttm/catkin_ws/install/bin"
