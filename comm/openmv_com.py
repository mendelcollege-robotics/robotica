import time
from pyb import UART

# UART 3, and baudrate.
uart = UART(3, 19200, timeout_char=200)
location = "40"  #place to put the goal location
while True:
    uart.write("s")
    uart.write(location)
    uart.write("e")
    if uart.any():
        print(uart.read())
    time.sleep_ms(1000)
