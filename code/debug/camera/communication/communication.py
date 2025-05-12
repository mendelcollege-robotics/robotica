# Untitled - By: abel - Mon May 12 2025

import pyb

uart = pyb.UART(3, 9600, timeout_char = 1000)

for i in range(0,999):
    print(f"Testing no: {i}")
    uart.write(f"Testing no: {i}\n")
