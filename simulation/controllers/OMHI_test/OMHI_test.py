from controller import Robot
import math

# Create the Robot instance.
robot = Robot()

# Get the time step of the current world.
timestep = int(robot.getBasicTimeStep())

# Print all available device names for debugging
device_count = robot.getNumberOfDevices()
print("Number of devices:", device_count)
for i in range(device_count):
    device = robot.getDeviceByIndex(i)
    print("Device", i, ":", device.getName())

# Get the wheel motors
wheel_1 = robot.getDevice("wheel1")
wheel_2 = robot.getDevice("wheel2")
wheel_3 = robot.getDevice("wheel3")

# Check if the devices are found
if wheel_1 is None:
    print("Device 'wheel1' not found")
if wheel_2 is None:
    print("Device 'wheel2' not found")
if wheel_3 is None:
    print("Device 'wheel3' not found")

# Set the position to infinity to control velocity
wheel_1.setPosition(float('inf'))
wheel_2.setPosition(float('inf'))
wheel_3.setPosition(float('inf'))

# Set the initial velocity to 0
wheel_1.setVelocity(0)
wheel_2.setVelocity(0)
wheel_3.setVelocity(0)


def set_wheel_velocities(velocity1, velocity2, velocity3):
    wheel_1.setVelocity(velocity1)
    wheel_2.setVelocity(velocity2)
    wheel_3.setVelocity(velocity3)
    

def omhidrive(V, D, R, radius):
    """
    Calculate the speeds of three motors for a three-wheeled omnidirectional robot.
    
    :param V: Linear velocity magnitude
    :param D: Direction of the velocity in degrees
    :param R: Angular velocity (rotation speed)
    :param radius: Distance from the center of the robot to the wheels
    :return: Speeds of the three motors
    """
    # Convert direction to radians
    dirrad = math.radians(D)
    
    # Calculate the components of the velocity
    V_x = V * math.cos(dirrad)
    V_y = V * math.sin(dirrad)
    print(f"V x speed: {V_x}")
    print(f"V y speed: {V_y}")
    
    # Wheel angles (in radians)
    angles = [math.radians(0), math.radians(120), math.radians(240)]
    
    # Calculate motor speeds using the provided formulas
    spdeA = V_x * math.cos(angles[0]) + V_y * math.sin(angles[0]) + R * radius
    spdeB = V_x * math.cos(angles[1]) + V_y * math.sin(angles[1]) + R * radius
    spdeC = V_x * math.cos(angles[2]) + V_y * math.sin(angles[2]) + R * radius
    
    print(f"Motor A speed: {spdeA}")
    print(f"Motor B speed: {spdeB}")
    print(f"Motor C speed: {spdeC}")
    
    # Assuming set_wheel_velocities is a function to set the speeds of the motors
    set_wheel_velocities(spdeA, spdeB, spdeC)

# Main loop:
while robot.step(timestep) != -1:

    omhidrive(5, 0, 0, 0.188)