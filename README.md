# Midterm IoT Project
#### Name: Ruby Hung
#### Date: 10.10.2017

## Brand Name: WeatherWear - Section of Soil Moisture

![alt](https://github.com/ruyuhung/WeatherWear_Soil/blob/master/WW.jpeg)
![alt](https://github.com/ruyuhung/WeatherWear_Soil/blob/master/WW_Model.png)
### Conceptual Description
For my IoT project, I hope to find the inspiration from day-to-day issues which could be responded or solved through the IoT device that I am going to produce. For the topics, I am interested in the interaction with the plants (or other environmental data) and its transformation to other form of senses, such as, image or audio. Since I have plenty of plants pots in my house, the soil moisture sensor becomes my primary tool. I am curious about how it works and would like to set a soil moisture threshold to turn on the servo motor to make an automatic watering machine for my own plants. However, after some research, the automatic watering system has been done on the [Sparkfun](https://www.sparkfun.com/products/13322) and [Youtube](https://www.youtube.com/watch?v=xMlL7NColtM) website. 
While searching for new ideas and brainstorming with my partner, Stephanie Fiddy; We found that instead of detecting the plant needs to be watered. In fact, the soil moisture sensor could be a great indication of what kinds of shoe that the users are going to wear before going out. If combine the soil moisture data with the temperature sensor, it might be possible to construct a set of wearing customized suggestion for the user.


### Form
Since the device needs to be connected with the soil, a plant pot will be a great location to situate both of our sensors. Each of the photon has an enclosure with a hook to allow it hang on the edge of the plant pot which will allow the users some flexibility of putting their sensors. In addition, the soil moisture sensor has to go out from the photon. The enclosure is designed according to the need. 

#### Design of Enclosure:
I used Autodesk Fusion 360 for the enclosure since it is a great tool for solid 3D modelling and printing. By designing two aspects of the sketches and some extrusion and cutting, the prototype of enclosure is as the following. After exporting the top and the bottom part of enclosure. I sent them to the 3D printers in Co-Lab. The machine is Ultimaker 2 and processed through the cloud service for 3D slicing and repairing.
![alt](https://github.com/ruyuhung/WeatherWear_Soil/blob/master/WWS_Enclosure.png)

#### Electronics Exposed: 
![alt](https://github.com/ruyuhung/WeatherWear_Soil/blob/master/WWS_Exposure.JPG)

#### Finished Enclosure:
*After Printing
![alt](https://github.com/ruyuhung/WeatherWear_Soil/blob/master/FinishedEnclosure.JPG)
*With the plant
![alt](https://github.com/ruyuhung/WeatherWear_Soil/blob/master/WWS_Final_0.jpg)

#### Mobile Interface:
![alt](https://github.com/ruyuhung/WeatherWear_Soil/blob/master/WWS_Interfcae_0.PNG)

The first value display is the soil moisture value. The second one is the LCD display.

### Technical Details
#### Physical Part:

In my Shoe Type Part, I will have to make the soil moisture work first and then try different levels of moisture. After that, I categorize them into three different types. From some moisture, you might want to wear sandals. And for some moisture, it might be better to just wear rainboots.

##### List of Hardware:
* Photon redboard
* Soil Moisture Sensor
* Soldering Jump Wires*3
* Battery
* Blynk app

##### Wiring Diagram

![alt](https://github.com/ruyuhung/WeatherWear_Soil/blob/master/WWS_CircuitDesign.png)

#### Coding Part and Link to the Code:
Specific function that I use in this project including reading the soil moisture data, if statement to help sort various data threshold output to the Blynk app. For this project, I have 'sandals,' 'sneakers,' and 'rainboots.' The LCD function will be the first one as the x position on the screen, the second value is the y position which is only 0 and 1, and the final part is the display value. Here I use array to define the different shoeType
```
char* shoeType[] = {"Sandals", "Sneakers", "Rainboots"};
```
``` 
if (val > 2500 )
{ 
  lcdSoil.print(0, 0, shoeType[2]);
  delay(2000);
  Particle.publish("Rainboots");
}

else if (val < 1000)
{   
    lcdSoil.print(0,0, shoeType[0]);
    delay(2000);
    Particle.publish("Sandals");
}
else {
    lcdSoil.print(0,0, shoeType[1]);
    delay (2000);
    Particle.publish("Sneakers");
}
```

Here is the [Link](https://github.com/ruyuhung/physical-computing-midterm/blob/master/WWS.ino) to my entire code.

#### Communication Part:
##### Blynk Bridge
In this project, we first try to use Blynk Bridge as a communicating tool. However, after following for the official document on the [Blynk Website](http://docs.blynk.cc/#widgets-other-bridge) for a few hours. It didn’t work out. Our concept is to send the each sensor’s data to the other one.

##### Particle.Publish & Particle.Subscribe
We use the [particle.publish and subscribe](https://docs.particle.io/reference/firmware/photon/#particle-subscribe-) function to send the string message and trigger the LCD on Blynk to print. Here is the code of subscribe:
```
Particle.subscribe("sweater", sweaterHandler, "300041001151353338363333");
Particle.subscribe("nosweater", noSweaterHandler, "300041001151353338363333");
```

And new function for sweaterHandler and NoSweaterHandler

```
void sweaterHandler(const char *event, const char *data)
  {
          lcdCloth.clear();  
          lcdCloth.print (0,0, "Sweater");
          Serial.print("received sweater event");
     }
    
     void noSweaterHandler(const char *event, const char *data)
  {
          lcdCloth.clear();
          lcdCloth.print (0,0, "NoSweater");
          Serial.print("received no sweater event");
     } 

```
#### One way or Two way communication
![alt](https://github.com/ruyuhung/WeatherWear_Soil/blob/master/TwoWayCommuni.JPG)
Though we succeed in communicating mutual ways, it seems like for the mutual communication, that the photon reacts so slow and we might have to reset the Blynk app again for reading the data. Therefore, for in class demonstration, we will try do it only one way. For other communication issues, could go check on [Stephanie's documentation](https://github.com/sfiddy/physical-computing-midterm/).

## Future Improvement
Since the soil moisture is quite sensitive and depends highly on different kinds of soil. Therefore, it might be more precuse to have more technical details between the sensor and the response of the moisture level. 

3D Printer Process

![alt](https://github.com/ruyuhung/WeatherWear_Soil/blob/master/WWS_Printing.gif)
