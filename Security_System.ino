#define BLYNK_PRINT Serial  
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "TOKEN-ID";
char ssid[] = "VISHVAS";
char pass[] = "12345678";

WidgetLCD lcd(V1);
int a,b;
void setup()
{
Blynk.begin(auth, ssid, pass);
pinMode(D2,INPUT); //ldr
pinMode(D3,OUTPUT); //buzzer
pinMode(D4,INPUT); //phone switch

}

void loop()
{
Blynk.run();
  b=digitalRead(D4);
  if(b==0)
    {
      a=digitalRead(D2);
      if(a==0)
      {
digitalWrite(D3,1); 
lcd.clear();
lcd.print(0,0,"Emergency!!");
delay(1000);
      }
      else
      {
digitalWrite(D3,0);
lcd.clear();
lcd.print(0,0,"Security System");
delay(1000);
      } 
    }
   else
   {
digitalWrite(D3,0);
lcd.clear();
lcd.print(0,0,"Security System");
delay(1000);
   }
}
