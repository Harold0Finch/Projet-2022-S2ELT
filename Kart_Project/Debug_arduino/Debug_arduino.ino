// Includes the library code
#include <LiquidCrystal.h>

// Defines the LCD's parameters: (rs, enable, d4, d5, d6, d7)
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
int mesure_V = 0; // Variable où on stock la valeur de la mesure de tension
int mesure_A = 0; // Variable où on stock la valeur de la mesure d'intensité
float tension = 0; // Variable où on stock la valeur de la tension
float intensite = 0; // Variable où on stock la valeur de l'intensité
const int code = 98; // code pour entrer en mode debug ( b )
const int fast_debug = 102; // code pour entrer en mode debug rapide (uniquement en cmd) (f)
int incode = 0;
int refresh = 300; // Intervalle de rafraichissement des valeurs

const float facteur_V = 10.9704; // Facteur de réduction du pont diviseur de tension
const float facteur_A = 0.625; // Facteur de réduction de la sonde de courant

void setup() {

  lcd.begin(16, 2); // Initialisation du LCD
  Serial.begin(9600);  // Initialison de la communication serie

}

void loop() {

  if ( Serial.available() ) {
	  incode = Serial.read();
	  if (incode == code) { // Si le code entré sur la com serie correspond au code debug, le mode debug se lance
		  Serial.println("--- DEBUG MODE ---");
		  lcd.print("---- DEBUG ----");
		  delay(1000);
		  lcd.clear();

		  mesure_V = analogRead(A0); // On lit les données du pin A0
		  lcd.print("mesure V on A0");
		  Serial.println("mesure V on A0");
		  lcd.setCursor(0, 1);
		  lcd.print(mesure_V);
		  Serial.println(mesure_V);
		  delay(5000);
		  lcd.clear();

		  lcd.print("facteur_V");
		  lcd.setCursor(0, 1);
		  lcd.print(facteur_V);
		  Serial.println("facteur_V");
		  Serial.println(facteur_V);
		  delay(5000);
		  lcd.clear();

		  tension = (facteur_V*mesure_V*5.00/1023.00); // Calul de la tension avec les paramètres: (5V = 1023) donc : (valeur * 5) / 1023
		  lcd.print("tension");
		  lcd.setCursor(0, 1);
		  lcd.print(tension);
		  Serial.println("tension");
		  Serial.println(tension);
		  delay(5000);
		  lcd.clear();

		  mesure_A = analogRead(A1); // On lit les données du pin A0
		  lcd.print("mesure A on A1");
		  Serial.println("mesure A on A1");
		  lcd.setCursor(0, 1);
		  lcd.print(mesure_A);
		  Serial.println(mesure_A);
		  delay(5000);
		  lcd.clear();

  		  lcd.print("facteur_A");
		  lcd.setCursor(0, 1);
		  lcd.print(facteur_A);
		  Serial.println("facteur_A");
		  Serial.println(facteur_A);
		  delay(5000);
		  lcd.clear();

		  intensite = (facteur_A*mesure_A*5.00/1023.00); // Calul de la tension avec les paramètres: (5V = 1023) donc : (valeur * 5) / 1023
		  lcd.print("intensite");
		  lcd.setCursor(0, 1);
		  lcd.print(intensite);
		  Serial.println("intensite");
		  Serial.println(intensite);
		  delay(5000);
		  lcd.clear();

		  Serial.println("--- DEBUG END ---");
		  lcd.print("-- DEBUG END --");
		  delay(5000);
          lcd.clear();
	  }
	  else if (incode == fast_debug) { // Si le code entré sur la com serie correspond au code fast debug, le mode fast debug se lance
		  Serial.println("--- FAST DEBUG MODE ---");

		  mesure_V = analogRead(A0); // On lit les données du pin A0
		  Serial.println("mesure V on A0");
		  Serial.println(mesure_V);

		  Serial.println("facteur_V");
		  Serial.println(facteur_V);

		  tension = (facteur_V*mesure_V*5.00/1023.00); // Calul de la tension avec les paramètres: (5V = 1023) donc : (valeur * 5) / 1023
		  Serial.println("tension");
		  Serial.println(tension);

		  mesure_A = analogRead(A1); // On lit les données du pin A0
		  Serial.println("mesure A on A1");
		  Serial.println(mesure_A);

		  Serial.println("facteur_A");
		  Serial.println(facteur_A);

		  intensite = (facteur_A*mesure_A*5.00/1023.00); // Calul de la tension avec les paramètres: (5V = 1023) donc : (valeur * 5) / 1023
		  Serial.println("intensite");
		  Serial.println(intensite);

		  Serial.println("--- FAST DEBUG END ---");
	  }
	  else { // Sinon le code s'execute normalement
		  normal();
	  }
  }
  else {
	  normal();
  }
}

void volts_LCD() {
  mesure_V = analogRead(A0); // On lit les données du pin A0
  tension = (facteur_V*mesure_V*5.00/1023.00); // Calul de la tension avec les paramètres: (5V = 1023) donc : (valeur * 5) / 1023
  Serial.print("Tension : "); // Impression du message sur le moniteur série
  Serial.print(tension);
  Serial.println(" Volts");
  lcd.print("Tension :");
  lcd.print(tension); // Impression du message sur le LCD
  lcd.print(" V");
}

void amps_LCD() {
  mesure_A = analogRead(A1); // On lit les données du pin A1
  mesure_0A = analogRead(A2); // On lit les données du pin A2 pour obtenir la valeur pour laquelle I = 0
  intensite = ((facteur_A*mesure_A/100)-mesure_0A); // Calul de la tension avec les paramètres: (5V = 1023) donc : (valeur * 5) / 1023
  Serial.print("Courant : "); // Impression du message sur le moniteur série
  Serial.print(intensite);
  Serial.println(" Ampere");
  lcd.print("Courant :");
  lcd.print(intensite); // Impression du message sur le LCD
  lcd.print(" A");
}

void amps() {
  mesure_A = analogRead(A1); // On lit les données du pin A1
  mesure_0A = analogRead(A2); // On lit les données du pin A2 pour obtenir la valeur pour laquelle I = 0
  intensite = ((facteur_A*mesure_A/100)-mesure_0A); // Calul de la tension avec les paramètres: (5V = 1023) donc : (valeur * 5) / 1023
  lcd.print("Courant :");
  lcd.print(intensite); // Impression du message sur le LCD
  lcd.print(" A");
}

void volts() {
  mesure_V = analogRead(A0); // On lit les données du pin A0
  tension = (facteur_V*mesure_V*5.00/1023.00); // Calul de la tension avec les paramètres: (5V = 1023) donc : (valeur * 5) / 1023
  lcd.print("Tension :");
  lcd.print(tension); // Impression du message sur le LCD
  lcd.print(" V");
}

void normal() {
	volts_LCD();
	lcd.setCursor(0, 1);
	amps_LCD();
	delay(refresh);
    lcd.clear();
}
