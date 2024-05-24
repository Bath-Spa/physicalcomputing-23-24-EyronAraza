#include <Keypad.h>

// LED and buzzer Pins
int green_led_pin = 11;
int red_led_pin = 10;
int buzzer_pin = 12;

// Initialize Pass
String pass = "4321"; // The correct pass
String input_pass = ""; // Empty string to store keys that is inputted from keypad

// Intialize number of rows and columns for key pad
const int ROW_NUM = 4; 
const int COLUMN_NUM = 4; 

// Mapping keys from the keypad
char keys[ROW_NUM][COLUMN_NUM] = {
  {'1','2','3', 'A'},
  {'4','5','6', 'B'},
  {'7','8','9', 'C'},
  {'*','0','#', 'D'}
};

// Initialize pins for keypad 
byte pin_rows[ROW_NUM] = {9, 8, 7, 6}; // connect to the row pins of the keypad
byte pin_columns[COLUMN_NUM] = {5, 4, 3, 2}; // connect to the column pins of the keypad

// Create keypad
Keypad keypad = Keypad(makeKeymap(keys), pin_rows, pin_columns, ROW_NUM, COLUMN_NUM);

void setup(){
  Serial.begin(9600); // for printing in console and testing purposes
}

void loop(){
  // Get input keys from keypad
  char key = keypad.getKey();

  // Check if key is pressed
  if (key) {
    input_pass += key; // add key character to input pass string

    // Play sound when pressing keys
    tone(buzzer_pin, 1000);
    delay(20);
    noTone(buzzer_pin);

    // Print key pressed to serial
    Serial.print("KEY: ");
    Serial.println(key);

    // Check if input pass reaches the max length of 4
    if (input_pass.length() == 4) {
      // Print pass to serial
      Serial.print("PASS: ");
      Serial.println(input_pass);

      // Check if pass is correct or not
      if (input_pass == pass){
        Serial.println("CORRECT PASS!");
        play_correct_sound();
      } else { 
        Serial.println("WRONG PASS!");
        play_wrong_sound();
      }

      // Reset input pass
      input_pass = "";
    }
  }
}

// Function for playing correct sound
void play_correct_sound() {
  digitalWrite(green_led_pin, HIGH); // LED on
  tone(buzzer_pin, 523); // C5 note
  delay(250);
  tone(buzzer_pin, 659); // E5 note
  delay(250);
  tone(buzzer_pin, 783); // G5 note
  delay(250);
  tone(buzzer_pin, 1046); // C6 note
  delay(250);
  noTone(buzzer_pin);
  digitalWrite(green_led_pin, LOW); // LED off
}

// Function for playing wrong sound
void play_wrong_sound() {
  digitalWrite(red_led_pin, HIGH); // LED on
  tone(buzzer_pin, 200);
  delay(1000);
  noTone(buzzer_pin);
  digitalWrite(red_led_pin, LOW); // LED off
}