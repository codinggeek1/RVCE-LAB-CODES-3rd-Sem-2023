import Adafruit_DHT
import matplotlib.pyplot as plt
import time

# Initialize the DHT11 sensor
sensor = Adafruit_DHT.DHT11
pin = 4
a = 10

# Initialize lists to store the collected data
temperature_data = []
humidity_data = []

# Collect data from the sensor at regular intervals
while a>0:
    humidity, temperature = Adafruit_DHT.read(sensor, pin)
    temperature_data.append(temperature)
    humidity_data.append(humidity)
    time.sleep(5)
    a -= 1

# Use matplotlib to visualize the collected data
plt.plot(temperature_data, 'r')
plt.xlabel('No of Iterations')
plt.ylabel('Temperature')
plt.title('Temperature Graph')
plt.show()

plt.bar(range(len(humidity_data)), humidity_data)
plt.xlabel('No of Iterations')
plt.ylabel('Humidity')
plt.title('Humidity Graph')
plt.show()
