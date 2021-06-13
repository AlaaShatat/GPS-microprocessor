
from gmplot import gmplot 
lat_and_long_file=open("putty.txt","r")
print(lat_and_long_file.readable())
z=0
x=0
y=1
lat=[]
long=[]
#p="31.278345\x00\n".split('\\n')
#print(p[0])
def get_nuum_from_string(a_string):
    i=0
    number= ""
    while i < len(a_string):
        if a_string[i].isdigit():
           number = number + a_string[i]
        elif a_string[i]==".":
            number = number + a_string[i]
        else:
            break
        i=i+1
    return number 
#str1="45678.98770\gytty"
#num1=get_nuum_from_string(str1)
#print(num1)   
for lat_log in lat_and_long_file.readlines():
    if(x==1 and z>=3):
        #lat_log=lat_and_long_file.readline().strip()
        #var=lat_log.split('\\n')
        var=get_nuum_from_string(lat_log)

        if lat_log == ' ':
            break
        lat.append(float(var))
        
    

    if(y==1 and z>=3):
        #lat_log=lat_and_long_file.readline().strip()
        #var=lat_log.split('\\n')
        var=get_nuum_from_string(lat_log)

        if lat_log == ' ':
            break
        long.append(float(var))
    z=z+1
    temp=y
    y=x
    x=temp    
lat_and_long_file.close()
#print(p)
#print(long[1])
gmapOne=gmplot.GoogleMapPlotter(30.064554,31.276622,15)
gmapOne.scatter(lat,long,size=0,marker=False)
gmapOne.plot(lat,long,'blue',edge_width=2.5)
gmapOne.draw("g_map.html")
