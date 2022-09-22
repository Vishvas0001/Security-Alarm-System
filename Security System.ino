/*Modified by
 * VISHVAS 
   (St. Soldier Institute of Engg. & Technology, Jalandhar)
 */


const int ledPin = 4;     // This is GPIO4 pin which is labeled as D2 on NodeMCU

const int buzzerPin = 5;   // This is GPIO5 pin which is labeled as D1 on NodeMCU


const int ldrPin = A0;    // LDR data pin connected to Analog pin 0

void setup () {

Serial.begin(112500);     //Set the baud rate

pinMode(ledPin, OUTPUT);     

pinMode(buzzerPin, OUTPUT);

pinMode(ldrPin, INPUT);

}

void loop() {

int ldrStatus = analogRead(ldrPin);

if (ldrStatus >=20) {     //if the value of buzzer goes higher and equal to 20 then buzzer will beep else no
 
tone(buzzerPin, 1000); 

digitalWrite(ledPin, HIGH);

delay(100);

noTone(buzzerPin);

digitalWrite(ledPin, LOW);

delay(100);

Serial.println("----------- ALARM ACTIVATED -----------");

}

else {

noTone(buzzerPin);

digitalWrite(ledPin, LOW);

Serial.println("ALARM DEACTIVATED");

}

}
