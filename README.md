# Midterm IoT Project

Name:  Ruby Hung

Date: 10.11.2017

## Project: "Weather Wear" - Soil Moisture 

### Conceptual Description

For my IoT project, I hope to find the inspiration from day-to-day issues which could be responded or solved through the IoT device that I am going to produce. For the topics, I am interested in the interaction with the plants (or other environmental data) and its transformation to other form of senses, such as, image or audio. Since I have plenty of plants pots in my house, the soil moisture sensor becomes my primary tool. I am curious about how it works and would like to set a soil moisture threshold to turn on the servo motor to make an automatic watering machine for my own plants. However, after some research, the automatic watering system has been done on the Sparkfun and Youtube website. 
While searching for new ideas and brainstorming with my partner, Stephanie Fiddy; We found that instead of detecting the plant needs to be watered. In fact, the soil moisture sensor could be a great indication of what kinds of shoe that the users are going to wear before going out. If combine the soil moisture data with the temperature sensor, it might be possible to construct a set of wearing customized suggestion for the user.

### Form
Since the device needs to be connected with the soil, a plant pot will be a great location to situate both of our sensors. Each of the photon has an enclosure with a hook to allow it hang on the edge of the plant pot which will allow the users some flexibility of putting their sensors. In addition, the soil moisture sensor has to go out from the photon. The enclosure is designed according to the need. 


**Finished Enclosure:**
I used Autodesk Fusion 360 for the enclosure since it is a great tool for solid 3D modelling and printing. By designing two aspects of the sketches and some extrusion and cutting, the prototype of enclosure is as the following. After exporting the top and the bottom part of enclosure. I sent them to the 3D printers in Co-Lab. The machine is Ultimaker 2 and processed through the cloud service for 3D slicing and repairing.
![alt](https://github.com/ruyuhung/WeatherWear_Soil/blob/master/WWS_Enclosure.png)

![Finished Enclosure](finished_enclosure.jpg)

**Electronics Exposed:**

![Enclosure with electronics exposed](exposed_enclosure.jpg)

### Technical Details
//   
Here you should give an overview of the technical operation of your device, including:
* A wiring diagram
* list of hardware used
* Explanation of your
* Link to code   

//

You can include code snippets here:

```
Particle.subscribe("Execute", messageParse, MY_DEVICES);
```

but also link to your project's full code in this repository:  [photon.ino](photon.ino)

**Wiring Diagram**

![Wiring Diagram](WiringDiagram.png)
