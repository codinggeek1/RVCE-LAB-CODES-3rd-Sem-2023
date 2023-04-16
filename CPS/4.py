import time 
import requests 
import Adafruitat_DHT

apikey = "......."
pin = 4
sensor = Adafruit_DHT.DHT11
humid = [] 
temp = []

for i in range(5):
  h,t = Adafruit_DHT.read(sensor,pin)
  humid.append(h)
  temp.append(t)
  time.sleep(5)
  
for i in range(5):
  t = temp[i]
  h = humid[i]
  payload = { "API" : apikey, "field" : str(t), "field2" : str(h) }
  req = requests.post(".....", params = payload)
  time.sleep(5)
  
if(req ok):
  printf("Updated")

else:
  printf("Error")
