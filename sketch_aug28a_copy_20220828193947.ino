#include <LiquidCrystal.h> // includes the LiquidCrystal Library
LiquidCrystal lcd(1, 2, 4, 5, 6, 7); // Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7)
const int trigPin = 9;
const int echoPin = 10;
long duration;
int distanceCm, distanceInch;
   long tempDuration;
   int tempDist;

bool arrived=false;
bool left=false;
int count=0;
void setup() {
  lcd.begin(16, 2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distanceCm = duration * 0.034 / 2;
  distanceInch = duration * 0.0133 / 2;
  lcd.setCursor(0, 0);
  lcd.print("Distance: ");
  lcd.print(distanceInch);
  lcd.print("inch");
  delay(10);
  //lcd.setRgb(0,0,0);
 if(distanceInch<12){
   delay(4000);
        lcd.clear();


   while(true){     
     //lcd.clear();
         lcd.setCursor(0, 0);
  lcd.print("Distance: ");
  lcd.print(distanceInch);
  lcd.print(" inch");
               lcd.setCursor(0, 1);
        lcd.print("Rakat:");
        lcd.print(count/2);
        lcd.println("");
  delay(10);
       digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
      duration = pulseIn(echoPin, HIGH);
      distanceInch = duration * 0.0133 / 2;
      if(distanceInch>=12){
      	//left=true;
        //arrived=false;
        count++;
        //lcd.clear();
          lcd.setCursor(0, 1);
        lcd.print("Rakat:");
        lcd.print(count/2);
        lcd.println("");
        break;
      }
     continue;     
   }
 /* lcd.clear();
  lcd.setCursor(0, 0); // Sets the location at which subsequent text written to the LCD will be displayed
  lcd.print("Rakat: "); // Prints string "Distance" on the LCD
  lcd.print(count); // Prints the distance value from the sensor
  //lcd.print(" cm");
  delay(10);
  lcd.setCursor(0, 1);
  lcd.print("Distance: ");
  lcd.print(distanceInch);
  lcd.print(" inch");
  delay(10);*/
  }
  else{
  	lcd.setCursor(0, 1);
    //lcd.clear();
    lcd.print("Rakat: ");
    lcd.print(count/2);
    lcd.println("");
    
  }

}