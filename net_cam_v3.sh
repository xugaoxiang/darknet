#rm test_dnn_out.avi

./darknet detector demo ./cfg/coco.data ./cfg/yolov3.cfg ./yolov3.weights rtsp://admin:lj12345678@192.168.2.130:554/ISAPI/streaming/channels/102 -i 0 -thresh 0.25
