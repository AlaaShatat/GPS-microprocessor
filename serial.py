import serial
lat = []
lng = []
port = "COM9"
baud = 9600
ser = serial.Serial(port, baud, timeout = 1)
 
while True:
    onel = ser.readline().strip()
    if onel =='s':
        break
    lat.append(float(onel))
 
while True:
    onel = ser.readline().strip()
    if onel =='d':
        break
    lng.append( float(onel))
    