// Includes the library code
#include <LiquidCrystal.h>

// Defines the LCD's parameters: (rs, enable, d4, d5, d6, d7)
LiquidCrystal lcd(9, 8, 5, 4, 3, 2);
int valeur = 0; // Variable où on stock la valeur du potentiomètre
float tension = 0;

void setup() {
  
  // Set up the LCD's number of columns and rows
  lcd.begin(16, 2);
  Serial.begin(9600);  // Initialisons la communication serial
  
}

void loop() {

  valeur = analogRead(A0); // on lit les données du pin A0 
  tension = (valeur*5.00/1023.00);
  // Prints the introductory message
  Serial.print("Tension : ");
  Serial.print(tension);
  Serial.println(" Volts");
  // Prints the first part of the message to the LCD
  lcd.print(tension);
  lcd.print(" V");
  delay(1000);
  lcd.clear();
  
}
