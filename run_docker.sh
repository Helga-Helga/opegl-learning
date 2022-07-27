DRI_FILE="/dev/dri/card0"
if [ -c "$DRI_FILE" ]; then
   DRI_STRING="--device=$DRI_FILE:$DRI_FILE"
fi

docker run \
    --rm \
    -it \
    $DRI_STRING \
    -u $UID:$UID \
    -v $(pwd):$(pwd) \
    -w $(pwd) \
    -v /tmp/.X11-unix:/tmp/.X11-unix \
    -e DISPLAY \
    glfw-cpp \
    bash
