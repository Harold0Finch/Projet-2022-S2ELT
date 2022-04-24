// Includes the library code
#include <LiquidCrystal.h>

// Defines the LCD's parameters: (rs, enable, d4, d5, d6, d7)
LiquidCrystal lcd(9, 8, 5, 4, 3, 2);

// Defines the first user defined character - :)
byte smile1[8] = {
  0b00000,
  0b11010,
  0b11001,
  0b00001,
  0b00001,
  0b11001,
  0b11010,
  0b00000
};

// Defines the second user defined character - ;)
byte smile2[8] = {
  0b00000,
  0b11010,
  0b11001,
  0b00001,
  0b01001,
  0b01001,
  0b10010,
  0b00000
};

void setup() {
  
  // Set up the LCD's number of columns and rows
  lcd.begin(16, 2);
  
}

void loop() {

  // Creates the user defined characters - :) and ;)
  lcd.createChar(1, smile1);
  lcd.createChar(2, smile2);

  // Prints the introductory message
  
  // Prints the first part of the message to the LCD
  lcd.print("Hello everyone!");
  // Sets the cursor to column 0, row 2
  // (note: the counting of rows and columns begins with 0)
  lcd.setCursor(0, 1);
  // Prints the second part of the message to the LCD
  lcd.print("We are ...");
  delay(2000);
  // Clears the LCD screen
  lcd.clear();
  
  // Prints the website's name and the user defined 
  // characters to the LCD

  // Sets the cursor to column 3, row 1 (so that it appears
  // in the middle of the LCD)
  lcd.setCursor(2, 0);
  // Prints the website's name and characters separately
  lcd.print("GEE");
  delay(500);
  lcd.print("KE");
  delay(500);
  lcd.print("RING");
  delay(500);
  lcd.setCursor(12, 0);
  // Prints the first character 
  lcd.write(byte(1));
  delay(500);
  // Prints the second character (only for a short period
  // of time to make a blinking efect)
  lcd.setCursor(12, 0);
  lcd.write(byte(2));
  delay(300);
  lcd.setCursor(12, 0);
  // Prints the first character again
  lcd.write(byte(1));
  delay(2000);
  lcd.clear();

  // Prints the ending message

  lcd.setCursor(15, 0);
  lcd.print("  visit us on");
  lcd.setCursor(15, 1);
  lcd.print("www.geekering.com");
  // Loop for scrolling the message since it begins (from
  // the right side of the LCD) until it desapears
  for (int i = 0; i < 32; i++) {
    lcd.scrollDisplayLeft();
    delay(400);
  }
}
