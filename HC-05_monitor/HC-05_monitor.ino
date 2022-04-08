int state = 0; // To read state of serial data from HC05 module
void setup() {
  Serial.begin(9600); // Default communication rate of the Bluetooth module
}
void loop() {
  Serial.println(""); // Print some information on the serial monitor whenever it is bluetooth or not
}
