import serial
import time
from simple_pid import PID
import matplotlib.pyplot as plt
from matplotlib.widgets import Slider, Button

# Initialize serial communication
arduino = serial.Serial(port='/dev/ttyACM0', baudrate=115200, timeout=.1)

# Function to write to and read from Arduino
def write_read(x):
    arduino.write(bytes(x, 'utf-8'))
    time.sleep(0.05)
    data = arduino.readline().decode().strip()
    return data

# Real-time plotting setup
fig, (ax1, ax2) = plt.subplots(2, 1)
feedback_list = []
control_list = []
setpoint_list = []

def clamp(feedback, min_value, max_value):
    return max(min(feedback, max_value), min_value)

def update_plot(feedback, control, setpoint):
    feedback_clamped = clamp(feedback, 0, 1000)  # Clamp feedback value between 0 and 1000
    feedback_list.append(feedback_clamped)
    control_list.append(control)
    setpoint_list.append(setpoint)

    # Limit lists to 50 items for smoother plotting
    if len(feedback_list) > 50:
        feedback_list.pop(0)
        control_list.pop(0)
        setpoint_list.pop(0)

    ax1.clear()
    ax2.clear()

    ax1.plot(feedback_list, label="Feedback")
    ax1.plot(setpoint_list, label="Setpoint")
    ax1.legend()

    ax2.plot(control_list, label="Control")
    ax2.legend()

    ax1.set_ylabel('RPM')
    ax2.set_ylabel('Control Signal')
    ax2.set_xlabel('Time')

    plt.tight_layout()
    plt.pause(0.05)  # Pause to allow plot to update

# Initialize PID controller with output limits
initial_setpoint = 500  # Initial setpoint
pid = PID(0, 0, 0, output_limits=(0, 1000))
pid.setpoint = initial_setpoint

# Initialize PID parameters (preserved across resets)
preserved_parameters = {
    'Kp': 0,
    'Ki': 0,
    'Kd': 0,
    'setpoint': initial_setpoint
}

# Function to update PID parameters
def update_pid(val):
    pid.Kp = s_kp.val
    pid.Ki = s_ki.val
    pid.Kd = s_kd.val
    preserved_parameters['Kp'] = s_kp.val
    preserved_parameters['Ki'] = s_ki.val
    preserved_parameters['Kd'] = s_kd.val
    setpoint = s_setpoint.val
    pid.setpoint = setpoint
    preserved_parameters['setpoint'] = setpoint
    print(f"Setpoint: {setpoint}, Kp: {pid.Kp}, Ki: {pid.Ki}, Kd: {pid.Kd}")

# Create sliders for PID parameters and setpoint
axcolor = 'lightgoldenrodyellow'
ax_setpoint = plt.axes([0.15, 0.1, 0.65, 0.03], facecolor=axcolor)
ax_kp = plt.axes([0.15, 0.15, 0.65, 0.03], facecolor=axcolor)
ax_ki = plt.axes([0.15, 0.2, 0.65, 0.03], facecolor=axcolor)
ax_kd = plt.axes([0.15, 0.25, 0.65, 0.03], facecolor=axcolor)

s_setpoint = Slider(ax_setpoint, 'Setpoint', 0, 1000, valinit=initial_setpoint)
s_kp = Slider(ax_kp, 'Kp', 0, 10, valinit=preserved_parameters['Kp'])
s_ki = Slider(ax_ki, 'Ki', 0, 10, valinit=preserved_parameters['Ki'])
s_kd = Slider(ax_kd, 'Kd', 0, 10, valinit=preserved_parameters['Kd'])

s_setpoint.on_changed(update_pid)
s_kp.on_changed(update_pid)
s_ki.on_changed(update_pid)
s_kd.on_changed(update_pid)

# Function to reset algorithm and set speed to zero
def reset_algorithm(event):
    global feedback_list, control_list, setpoint_list
    feedback_list.clear()
    control_list.clear()
    setpoint_list.clear()
    pid.reset()
    s_setpoint.set_val(preserved_parameters['setpoint'])
    s_kp.set_val(preserved_parameters['Kp'])
    s_ki.set_val(preserved_parameters['Ki'])
    s_kd.set_val(preserved_parameters['Kd'])
    print("Algorithm reset")
    time.sleep(1)  # Delay of 1 second after reset

# Create reset button
ax_reset = plt.axes([0.8, 0.02, 0.1, 0.05])
btn_reset = Button(ax_reset, 'Reset')
btn_reset.on_clicked(reset_algorithm)

# Function to update Arduino with clamped control signal
def update_arduino_control(control):
    control_clamped = clamp(control, 0, 1000)
    write_read(str(control_clamped))

# Control loop
while True:
    feedback = float(write_read(str(pid.setpoint)))
    feedback_clamped = clamp(feedback, 0, 1000)  # Clamp feedback value between 0 and 1000
    control = pid(feedback_clamped)
    update_arduino_control(control)
    update_plot(feedback_clamped, control, pid.setpoint)

# Keep plot open
plt.show()
