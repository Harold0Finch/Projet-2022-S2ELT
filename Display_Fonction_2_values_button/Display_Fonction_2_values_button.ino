// Includes the library code
#include <LiquidCrystal.h>

// Defines the LCD's parameters: (rs, enable, d4, d5, d6, d7)
LiquidCrystal lcd(9, 8, 5, 4, 3, 2);
int valeur = 0;     // Variable où on stock la valeur du potentiomètre
float tension = 0;  // Variable où on stock la valeur de la tension
const int bouton = 22; //Broche de connection du bouton (22)
int BP = 0; // Variable de l'état du bouton
int BP_1 = 0; // Variable que l'on utilisera par la suite pour la fonction du bouton
int memoire = 0; // Variable pour l'affichage
int etat_BP = 0;

void setup() {
  
  lcd.begin(16, 2); // Initialisation du LCD
  Serial.begin(9600);  // Initialison de la communication serie
  pinMode(bouton,INPUT);
  
}

// void loop() {
	BP = digitalRead(bouton);
	if (BP! = etat_BP) {
		
		if (!BP){
			
			memoire = !memoire;
		}
		
		memoire = !memoire;
		
	}
	
	etat_BP = BP
	
	while (etat_BP == 0) {
		volts();
	}
	while (etat_BP == 1) {
		amps();
	}
	
}
	
	
void volts() {
  valeur = analogRead(A0); // On lit les données du pin A0 
  tension = (valeur*5.00/1023.00); // Calul de la tension avec les paramètres: (5V = 1023) donc : (valeur * 5) / 1023
  Serial.print("Tension : "); // Impression du message sur le moniteur série
  Serial.print(tension);
  Serial.println(" Volts");
  lcd.print("Tension :");
  lcd.print(tension); // Impression du message sur le LCD
  lcd.print(" V");
}

void amps() {
    valeur = analogRead(A1); // On lit les données du pin A0 
  tension = (valeur*5.00/1023.00); // Calul de la tension avec les paramètres: (5V = 1023) donc : (valeur * 5) / 1023
  Serial.print("Courant : "); // Impression du message sur le moniteur série
  Serial.print("?");
  Serial.println(" A");
  lcd.print("Courant :");
  lcd.print("?"); // Impression du message sur le LCD
  lcd.print(" A");
}
