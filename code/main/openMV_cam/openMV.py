import sensor, image, time

thresholds =  [(37, 69, -7, 20, -52, -35),# Thresholds for blue
               (50, 68, -9, 7, 50, 63)]# Thresholds for yellow
x_data=0
y_data=0

sensor.reset()
sensor.set_pixformat(sensor.RGB565)
sensor.set_framesize(sensor.QVGA)
sensor.skip_frames(time = 2000)

clock = time.clock()

while(True):
    clock.tick()
    img = sensor.snapshot()
    for blob in img.find_blobs(thresholds, pixels_threshold=200, area_threshold=200):
        img.draw_rectangle(blob.rect())
        img.draw_cross(blob.cx(), blob.cy())
        x_data=blob.cx()
        y_data=blob.cy()
    print("fps=%d" % clock.fps()),
    print(" x=%d" % x_data),
    print(" y=%d" % y_data)
