from machine import SPI, Pin
deg = 40
binary = format(deg, 'b')
print(binary)

spi = SPI(0, baudrate=400000)           # Create SPI peripheral 0 at frequency of 400kHz.
                                        # Depending on the use case, extra parameters may be required
                                        # to select the bus characteristics and/or pins to use.
cs = Pin(4, mode=Pin.OUT, value=1)      # Create chip-select on pin 4.

try:
    cs(0)                               # Select peripheral.
    spi.write(b"12345678")              # Write 8 bytes, and don't care about received data.
finally:
    cs(1)                               # Deselect peripheral.

try:
    cs(0)                               # Select peripheral.
    rxdata = spi.read(8, 0x42)          # Read 8 bytes while writing 0x42 for each byte.
finally:
    cs(1)                               # Deselect peripheral.

rxdata = bytearray(8)
try:
    cs(0)                               # Select peripheral.
    spi.readinto(rxdata, 0x42)          # Read 8 bytes inplace while writing 0x42 for each byte.
finally:
    cs(1)                               # Deselect peripheral.

txdata = b"12345678"
rxdata = bytearray(len(txdata))
try:
    cs(0)                               # Select peripheral.
    spi.write_readinto(txdata, rxdata)  # Simultaneously write and read bytes.
finally:
    cs(1)                               # Deselect peripheral.
