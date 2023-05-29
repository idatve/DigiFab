import RPi.GPIO as GPIO
import time

# Kamera:

from picamera import PiCamera

camera = PiCamera()

# Setter kamera sin opplosning
camera.resolution = (1280, 960)

# Starter live sending
camera.start_preview()

# Venter i 10 sekunder
time.sleep(10)

# Servo motorer:

GPIO.setmode(GPIO.BCM)

# Setter GPIO pins til servonene
servo_pin_1 = 19
servo_pin_2 = 26

# Setter GPIO pinsene til aa vere output
GPIO.setup(servo_pin_1, GPIO.OUT)
GPIO.setup(servo_pin_2, GPIO.OUT)

pwm_1 = GPIO.PWM(servo_pin_1, 50)  # 50 Hz frequency
pwm_2 = GPIO.PWM(servo_pin_2, 50)  # 50 Hz frequency

pwm_1.start(0)
pwm_2.start(0)

# Flytter begge servoene 90 grader
def move_servos_to_90():
    duty_cycle = 90 / 18 + 2
    pwm_1.ChangeDutyCycle(duty_cycle)
    pwm_2.ChangeDutyCycle(duty_cycle)
    time.sleep(2)

# Flytter begge servoene tilbake til 0 grader
def move_servos_to_0():
    duty_cycle = 0 / 18 + 2
    pwm_1.ChangeDutyCycle(duty_cycle)
    pwm_2.ChangeDutyCycle(duty_cycle)
    time.sleep(2)

move_servos_to_90()

move_servos_to_0()

# Avslutter programmet
pwm_1.stop()
pwm_2.stop()
GPIO.cleanup()