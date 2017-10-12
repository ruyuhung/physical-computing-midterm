#include <blynk.h>


int val = 0; 
int soilPin = A0;
int soilPower = 7;
char* shoeType[] = {"Sandals", "Sneakers", "Rainboots"};

int pinData = 0;


char auth[] = "43c1e63dd17641969eadc944aa1be864";
WidgetLCD lcdSoil(V10);
WidgetLCD lcdCloth(V12);




void setup() 
{
  Serial.begin(9600);  
  pinMode(soilPower, OUTPUT);
  digitalWrite(soilPower, LOW);
  Blynk.begin(auth); 
  
//   Particle.subscribe("sweater", sweaterHandler, "300041001151353338363333");
//   Particle.subscribe("nosweater", noSweaterHandler, "300041001151353338363333");
  
}

 void loop() 
{
    
Blynk.run();
Serial.print("Soil Moisture = ");    //get soil moisture value from the function below and print it
Serial.println(readSoil());

Blynk.virtualWrite(V11, val);
delay(1000);

lcdSoil.clear();


if (val > 2500 )
{
 
  lcdSoil.print(0, 0, shoeType[2]);
  delay(2000);
//  Serial.print(shoeType[2]);
  Particle.publish("Rainboots");
}


else if (val < 1000)
{   
    lcdSoil.print(0,0, shoeType[0]);
    delay(2000);
  //  Serial.print (shoeType[0]);
    Particle.publish("Sandals");
}
else {
    lcdSoil.print(0,0, shoeType[1]);
//    Serial.print (shoeType[1]);
    delay (2000);
    Particle.publish("Sneakers");
}



}

//   void sweaterHandler(const char *event, const char *data)
//   {
//           lcdCloth.clear();  
//           lcdCloth.print (0,0, "Sweater");
//           Serial.print("received sweater event");
//      }
    
//      void noSweaterHandler(const char *event, const char *data)
//   {
//           lcdCloth.clear();
//           lcdCloth.print (0,0, "NoSweater");
//           Serial.print("received no sweater event");
//      } 


int readSoil()
{

    digitalWrite(soilPower, HIGH);
    delay(10);
    val = analogRead(soilPin); 
    digitalWrite(soilPower, LOW);
    return val;
}


