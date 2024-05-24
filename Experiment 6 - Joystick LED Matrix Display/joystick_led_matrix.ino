#include <LedControl.h>

// Joystick pins
#define VRX_PIN A0 // Arduino pin connected to VRX pin VERTICAL
#define VRY_PIN A1 // Arduino pin connected to VRY pin HORIZONTAL

// Initialize joystick X and Y values
int x_value = 0; // To store value of the X axis
int y_value = 0; // To store value of the Y axis

// Define maximum and minimum values for X and Y values from joystick
int x_y_max = 1000;
int x_y_min = 100;

// LED Matrix's initial values
int led_matrix_address = 0; // Choosing available LED matrix(s) connected to arduino
int led_matrix_brightness = 5; // Set brightness of LED matrix (0-15)

// LED Matrix pins
int DIN = 10; // data in   
int CS =  9; // chip system
int CLK = 8; // clock

// Create object for LED Matrix
LedControl lc = LedControl(DIN, CLK, CS, led_matrix_address);

void setup() {
  Serial.begin(9600);

  // LED Matrix setup
  lc.shutdown(led_matrix_address, false); // to ensure LED matrix is enable 
  lc.setIntensity(led_matrix_address, led_matrix_brightness); // Set brightness of LED matrix (0-15)
  lc.clearDisplay(led_matrix_address); // Clear LED matrix display
}

void loop() {
  // read Joystick's X and Y values
  x_value = analogRead(VRX_PIN);
  y_value = analogRead(VRY_PIN);

  // Print joystick's X and Y values
  Serial.print("x = ");
  Serial.print(x_value);
  Serial.print(", y = ");
  Serial.println(y_value);

  // Check Joystick control values to create respective LED arrows art
  if (x_value > x_y_max){ // Check if joystick is UP
    // Display UP arrow to LED Matrix
    byte up[8] = {0b00011000, 0b00001100, 0b00000110, 0b11111111, 0b11111111, 0b00000110, 0b00001100, 0b00011000};
    printByte(up);
  } else if (x_value < x_y_min){ // Check if joystick is DOWN
    // Display DOWN arrow to LED Matrix
    byte down[8] = {0b00011000, 0b00110000, 0b01100000, 0b11111111, 0b11111111, 0b01100000, 0b00110000, 0b00011000};
    printByte(down);
  } else if (y_value > x_y_max) { // Check if joystick is LEFT
    // Display LEFT arrow to LED Matrix
    byte left[8] = {0b00011000, 0b00011000, 0b00011000, 0b10011001, 0b11011011, 0b01111110, 0b00111100, 0b00011000};
    printByte(left);
  } else if (y_value < x_y_min) { // Check if joystick is RIGHT
    // Display RIGHT arrow to LED Matrix
    byte right[8] = {0b00011000, 0b00111100, 0b01111110, 0b11011011, 0b10011001, 0b00011000, 0b00011000, 0b00011000};
    printByte(right);
  } else {
    lc.clearDisplay(led_matrix_address); // clear the LED matrix display
  }
  delay(200);
}

// Print lights to LED matrix based on 8 elements of bytes
void printByte(byte character[]) {
  for(int i=0;i<8;i++)
  {
    lc.setRow(led_matrix_address, i, character[i]);
  }
}