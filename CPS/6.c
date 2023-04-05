import cv2
from pushbullet import Pushbullet
from time import sleep 
from tkinker import messagebox
from tkinker import *

cam = cv2.VideoCapture(0)
image = 0

def CaptureImage():
	print("Capturing Image :")
	ret, image = cam.read()
	k = cv2.waitKey(10000)
	print("Image Capture successfully")
	cv2.imwrite('/home/pi/pictures/testimage.jpg',image)
	cam.release()
	cv2.destroyAllWindows()
	print("Sending the Notification")

def SendNotification():
	root = Tk()
	root.geometry("50x70")
	pb = Pushbullet("______apikey_from_web_____")
	dev = pb.get_device("XYZ")
	with open('/home/pi/pictures/testimage.jpg','rb') as pic:
		file_data = pb.upload_file(pic,"Picture.jpg")
		push = pb.push_file(**file_data)
		Value = push["active"]
		if Value == True:
			messagebox.showinfo("showinfo",Messagesent successfully...")
		else:
			messagebox.showwarning("showwarning",Sending Message Failed..")

CaptureImage()
SendNotification()