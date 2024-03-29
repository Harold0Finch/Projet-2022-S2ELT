// Includes the library code
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

// Defines the LCD's parameters: (rs, enable, d4, d5, d6, d7)
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
float mesure_V = 0; // Variable où on stock la valeur de la mesure de tension
float mesure_A = 0; // Variable où on stock la valeur de la mesure d'intensité
float mesure_0A = 0; // Variable où on stock la valeur de la mesure pour laquelle I = 0 A
float tension = 0; // Variable où on stock la valeur de la tension
float intensite = 0; // Variable où on stock la valeur de l'intensité
float intensite_1 = 0;
const int code = 98; // code pour entrer en mode debug (uniquement en cmd) (b)
const int fast_debug = 102; // code pour entrer en mode debug rapide (uniquement en cmd) (f)
int incode = 0;
const int refresh = 350; // Intervalle de rafraichissement des valeurs

const float facteur_V = 10.333333; // Facteur de réduction du pont diviseur de tension
const float facteur_A = 127.875; // Facteur de réduction de la sonde de courant

SoftwareSerial mySerial(11,12);

void setup() {

  lcd.begin(16, 2); // Initialisation du LCD
  Serial.begin(9600);  // Initialison de la communication serie
  mySerial.begin(9600);

}

void loop() {

  if ( Serial.available() ) {
	  incode = Serial.read();
	  if (incode == code) { // Si le code entré sur la com serie correspond au code debug, le mode debug se lance
		  Serial.println("--- DEBUG MODE ---");
      mySerial.println("--- DEBUG MODE ---");
		  lcd.print("---- DEBUG ----");
		  delay(1000);
		  lcd.clear();

		  mesure_V = analogRead(A0); // On lit les données du pin A0
		  lcd.print("mesure V on A0");
		  Serial.println("mesure V on A0");
      mySerial.println("mesure V on A0");
		  lcd.setCursor(0, 1);
		  lcd.print(mesure_V);
		  Serial.println(mesure_V);
      mySerial.println(mesure_V);
		  delay(5000);
		  lcd.clear();

		  lcd.print("facteur_V");
		  lcd.setCursor(0, 1);
		  lcd.print(facteur_V);
		  Serial.println("facteur_V");
		  Serial.println(facteur_V);
      mySerial.println("facteur_V");
      mySerial.println(facteur_V);
		  delay(5000);
		  lcd.clear();

		  tension = (facteur_V*mesure_V*5.00/1023.00); // Calul de la tension avec les paramètres: (5V = 1023) donc : (valeur * 5) / 1023
		  lcd.print("tension");
		  lcd.setCursor(0, 1);
		  lcd.print(tension);
		  Serial.println("tension");
		  Serial.println(tension);
      mySerial.println("tension");
		  mySerial.println(tension);
      delay(5000);
		  lcd.clear();

		  mesure_A = analogRead(A1); // On lit les données du pin A0
		  lcd.print("mesure on A1");
		  lcd.setCursor(0, 1);
		  lcd.print(mesure_A);
      Serial.println("mesure on A1");
		  Serial.println(mesure_A);
      mySerial.println("mesure on A1");
		  mySerial.println(mesure_A);
		  delay(5000);
		  lcd.clear();

      mesure_0A = analogRead(A2); // On lit les données du pin A0
      lcd.print("mesure on A2");
      lcd.setCursor(0, 1);
		  lcd.print(mesure_0A);
      Serial.println("mesure on A2");
		  Serial.println(mesure_0A);
      mySerial.println("mesure on A2");
		  mySerial.println(mesure_0A);
		  delay(5000);
		  lcd.clear();

  		lcd.print("facteur_A");
		  lcd.setCursor(0, 1);
		  lcd.print(facteur_A);
		  Serial.println("facteur_A");
		  Serial.println(facteur_A);
      mySerial.println("facteur_A");
		  mySerial.println(facteur_A);
		  delay(5000);
		  lcd.clear();

      intensite_1 = (mesure_A-mesure_0A);
      lcd.print("Difference A2/A1");
		  lcd.setCursor(0, 1);
		  lcd.print(intensite_1);
		  Serial.println("Difference A2 / A1");
		  Serial.println(intensite_1);
      mySerial.println("Difference A2 / A1");
		  mySerial.println(intensite_1);
		  delay(5000);
		  lcd.clear();

		  intensite = (intensite_1*100/facteur_A); // Calul de la tension avec les paramètres: (5V = 1023) donc : (valeur * 5) / 1023
		  lcd.print("intensite");
		  lcd.setCursor(0, 1);
		  lcd.print(intensite);
		  Serial.println("intensite");
		  Serial.println(intensite);
      mySerial.println("intensite");
		  mySerial.println(intensite);
		  delay(5000);
		  lcd.clear();

		  Serial.println("--- DEBUG END ---");
      mySerial.println("--- DEBUG END ---");
		  lcd.print("-- DEBUG END --");
		  delay(5000);
          lcd.clear();
	  }
	  else if (incode == fast_debug) { // Si le code entré sur la com serie correspond au code fast debug, le mode fast debug se lance
		  Serial.println("--- FAST DEBUG MODE ---");
      mySerial.println("--- FAST DEBUG MODE ---");

		  mesure_V = analogRead(A0); // On lit les données du pin A0
		  Serial.println("mesure V on A0");
		  Serial.println(mesure_V);
      mySerial.println("mesure V on A0");
		  mySerial.println(mesure_V);

		  Serial.println("facteur_V");
		  Serial.println(facteur_V);
      mySerial.println("facteur_V");
		  mySerial.println(facteur_V);

		  tension = (facteur_V*mesure_V*5.00/1023.00); // Calul de la tension avec les paramètres: (5V = 1023) donc : (valeur * 5) / 1023
		  Serial.println("tension");
		  Serial.println(tension);
      mySerial.println("tension");
		  mySerial.println(tension);

		  mesure_A = analogRead(A1); // On lit les données du pin A0
		  Serial.println("mesure on A1");
		  Serial.println(mesure_A);
      mySerial.println("mesure on A1");
		  mySerial.println(mesure_A);

      mesure_0A = analogRead(A2); // On lit les données du pin A0
		  Serial.println("mesure on A2");
		  Serial.println(mesure_0A);
      mySerial.println("mesure on A2");
		  mySerial.println(mesure_0A);

      intensite_1 = (mesure_A-mesure_0A);
      Serial.println("mesure_A-mesure_0A");
      Serial.println(intensite_1);
      mySerial.println("mesure_A-mesure_0A");
      mySerial.println(intensite_1);

		  Serial.println("facteur_A");
		  Serial.println(facteur_A);
      mySerial.println("facteur_A");
		  mySerial.println(facteur_A);

		  intensite = (intensite_1*100/facteur_A); // Calul de la tension avec les paramètres: (5V = 1023) donc : (valeur * 5) / 1023
		  Serial.println("intensite");
		  Serial.println(intensite);
      mySerial.println("intensite");
		  mySerial.println(intensite);

		  Serial.println("--- FAST DEBUG END ---");
      mySerial.println("--- FAST DEBUG END ---");
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
  mySerial.print("Tension : "); // Envoi du message par bluetooth
  mySerial.print(tension);
  mySerial.println(" Volts");
  lcd.print("Tension :");
  lcd.print(tension); // Impression du message sur le LCD
  lcd.print(" V");
}

void amps_LCD() {
  mesure_A = analogRead(A1); // On lit les données du pin A1
  mesure_0A = analogRead(A2); // On lit les données du pin A2 pour obtenir la valeur pour laquelle I = 0
  intensite_1 = (mesure_0A-mesure_A);
  intensite = (intensite_1*100/facteur_A); // Calul du courant avec les paramètres: (0A = mesure-0A) donc : (valeur * 5) / 1023
  Serial.print("Courant : "); // Impression du message sur le moniteur série
  Serial.print(intensite);
  Serial.println(" Ampere");
  mySerial.print("Courant : "); // Envoi du message par bluetooth
  mySerial.print(intensite);
  mySerial.println(" Ampere");
  lcd.print("Courant :");
  lcd.print(intensite); // Impression du message sur le LCD
  lcd.print(" A");
}

void amps() {
  mesure_A = analogRead(A1); // On lit les données du pin A1
  mesure_0A = analogRead(A2); // On lit les données du pin A2 pour obtenir la valeur pour laquelle I = 0
  intensite_1 = (mesure_A-mesure_0A);
  intensite = (intensite_1*100/facteur_A); // Calul de la tension avec les paramètres: (5V = 1023) donc : (valeur * 5) / 1023
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
