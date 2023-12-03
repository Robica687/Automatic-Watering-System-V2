const int dry = 550;
const int wet = 200;
int motorPin = 3; // pin pentru pompa
int blinkPin = 13; 
int watertime = 3; // in secunde
int waittime = 1; // in minute

void setup()
{
  pinMode(motorPin, OUTPUT); 
  pinMode(blinkPin, OUTPUT); 
  Serial.begin(9600);
}

void loop()
{
  int moisturePin = analogRead(A0); // citeste valoarea senzorului de umezeala 
  int percentage = map(moisturePin, wet, dry, 100, 0);
  Serial.print(percentage);
  Serial.println("%");
  if (percentage < 35) { // daca scade sub 35%, atunci incepe sa actioneze pompa 
    digitalWrite(motorPin, HIGH); 
    digitalWrite(blinkPin, HIGH); 
    delay(watertime * 1000);      
  }
  else {
    digitalWrite(motorPin, LOW);  
    digitalWrite(blinkPin, LOW);  
    delay(waittime * 1000);      
  }

}