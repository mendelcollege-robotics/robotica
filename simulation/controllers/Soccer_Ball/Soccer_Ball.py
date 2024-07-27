from controller import Robot, Emitter
import time

robot = Robot()
emitter = robot.getDevice("emitter")

# Time step of the simulation
timestep = int(robot.getBasicTimeStep())

# Pulse emission interval (e.g., 1 pulse per second)
pulse_interval = 1.0

# Main loop
while robot.step(timestep) != -1:
    current_time = robot.getTime()
    if int(current_time) % pulse_interval == 0:
        emitter.send(b'\x01')  # Emit a single byte pulse
    time.sleep(1.0 / pulse_interval)
