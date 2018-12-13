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



def take_picture():
    camera.capture(output)
    camera.stop_preview()
    camera.start_preview(fullscreen=False, window = (100,100,1000,800),rotation= 90)


def new_picture():
    camera.start_preview(fullscreen=False, window = (100,100,1000,800),rotation= 90)
    preview_overlay(camera, overlay)
    

    

new_pic = PushButton(app, command=new_picture, text="Initiate Imaging", grid=[0,0])

take_pic = PushButton(app,command=take_picture, text="Capture Image", grid=[0,1] )

zoom_out = PushButton(app,command=take_picture, text="Zoom In", width = 5, grid=[4,1])

zoom_in = PushButton(app,command=take_picture, text="Zoom Out", width = 5, grid=[6,1])

move_up = PushButton(app,command=take_picture, text="Up", width = 5, grid=[7,3])

move_down = PushButton(app,command=take_picture, text="Down", width = 5, grid=[7,5])

move_left = PushButton(app,command=take_picture, text="Left", width = 5, grid=[6,4])

move_right = PushButton(app,command=take_picture, text="Right", width = 5, grid=[8,4])




app.display()

