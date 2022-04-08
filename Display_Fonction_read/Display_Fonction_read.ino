// Includes the library code
#include <LiquidCrystal.h>

// Defines the LCD's parameters: (rs, enable, d4, d5, d6, d7)
LiquidCrystal lcd(9, 8, 5, 4, 3, 2);
int valeur = 0;     // Variable où on stock la valeur du potentiomètre
float tension = 0;  // Variable où on stock la valeur de la tension

void setup() {
  
  lcd.begin(16, 2); // Initialisation du LCD
  Serial.begin(9600);  // Initialison de la communication serie
  
}

void loop() {

  valeur = analogRead(A0); // on lit les données du pin A0 
  tension = (valeur*5.00/1023.00);
  Serial.print("Tension : "); // Impression du message sur le moniteur série
  Serial.print(tension);
  Serial.println(" Volts");
  lcd.print(tension); // Impression du message sur le LCD
  lcd.print(" V");
  delay(1000); // Attente de 1 sec entre chaque rafraichissement
  lcd.clear(); // On efface le message sur le LCD
  
}
