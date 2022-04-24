int valeur = 0; // Variable où on stock la valeur du potentiomètre

void setup() {
  Serial.begin(9600);  // Initialisons la communication serial
}

void loop() {
  valeur = analogRead(A0); // on lit les données du pin A0 

  // on imprime la valeur sur le moniteur serie (0 - 1023)
  Serial.print("Valeur analogique : ");
  Serial.println(valeur);
  delay(1000);
}
