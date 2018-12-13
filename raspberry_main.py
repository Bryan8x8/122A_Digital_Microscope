from picamera import PiCamera
from guizero import App, PushButton, Text, Picture
from time import gmtime, strftime
import RPi.GPIO as GPIO
import time

#Camera Section
camera = PiCamera()
#camera.resolution = (800,400) #this resolution value can be changed later

#this is the address the image file will be saved to
output = strftime("/home/pi/Documents/Digital_Microscope_Images/image-%d-%m %H:%M:%S.png", gmtime())

app = App("Digital Mircroscope", height = 500, width = 400, layout = "grid" )

GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)
GPIO.setup(17,GPIO.OUT)
GPIO.setup(18,GPIO.OUT)
GPIO.setup(22,GPIO.OUT)
GPIO.setup(23,GPIO.OUT)
GPIO.setup(25,GPIO.OUT)

def take_picture():
    camera.capture(output)
    camera.stop_preview()
    camera.start_preview(fullscreen=False, window = (100,100,1000,800),rotation= 90)


def new_picture():
    camera.start_preview(fullscreen=False, window = (100,100,1000,800),rotation= 90)
    preview_overlay(camera, overlay)
    
def move_up():
    #GPIO.output(17,1)
    #GPIO.output(23,1)
    chan_list = (17,23)
    GPIO.output(chan_list, GPIO.HIGH)
    time.sleep(.25)
    GPIO.output(chan_list, GPIO.LOW)
    #GPIO.output(25,0)
    #GPIO.output(17,0)
    #GPIO.output(23,0)
    
def move_down():
    GPIO.output(17,1)
    GPIO.output(23,0)
    GPIO.output(25,1)
    time.sleep(.25)
    GPIO.output(25,0)
    GPIO.output(17,0)
    GPIO.output(23,0)
    
def move_left():
    #GPIO.output(18,1)
    #GPIO.output(23,1)
    #GPIO.output(25,1)
    chan_list = (18, 23)
    GPIO.output(chan_list, GPIO.HIGH)
    time.sleep(.25)
    GPIO.output(chan_list, GPIO.LOW)
    #GPIO.output(25,0)
    #GPIO.output(18,0)
    #GPIO.output(23,0)
    
def move_right():
    GPIO.output(18,1)
    GPIO.output(23,0)
    GPIO.output(25,1)
    time.sleep(.25)
    GPIO.output(25,0)
    GPIO.output(18,0)
    GPIO.output(23,0)
   
    
def zoom_in():
    #GPIO.output(22,1)
    #GPIO.output(23,1)
    #GPIO.output(25,1)
    chan_list = (22,23)
    GPIO.output(chan_list, GPIO.HIGH)
    time.sleep(.25)
    GPIO.output(chan_list, GPIO.LOW)
    #GPIO.output(25,0)
    #GPIO.output(22,0)
    #GPIO.output(23,0)
    
def zoom_out():
    GPIO.output(22,1)
    GPIO.output(23,0)
    GPIO.output(25,1)
    time.sleep(.25)
    GPIO.output(25,0)
    GPIO.output(22,0)
    GPIO.output(23,0) 
    

new_pic = PushButton(app, command=new_picture, text="Initiate Imaging", grid=[0,0])

take_pic = PushButton(app,command=take_picture, text="Capture Image", grid=[0,1] )

zoom_out = PushButton(app,command=zoom_out, text="Zoom In", width = 5, grid=[4,1])

zoom_in = PushButton(app,command=zoom_in, text="Zoom Out", width = 5, grid=[6,1])

move_up = PushButton(app,command=move_up, text="Up", width = 5, grid=[7,3])

move_down = PushButton(app,command=move_down, text="Down", width = 5, grid=[7,5])

move_left = PushButton(app,command=move_left, text="Left", width = 5, grid=[6,4])

move_right = PushButton(app,command=move_right, text="Right", width = 5, grid=[8,4])




app.display()

