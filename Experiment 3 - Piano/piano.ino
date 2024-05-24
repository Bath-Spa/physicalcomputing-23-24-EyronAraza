// Button Pins
int button_pins[7] = {13, 12, 11, 10, 9, 8, 7};
int button_pins_length = sizeof(button_pins)/sizeof(button_pins[0]);

// Buzzer pin
int buzzer_pin = 6;

// Button value
int btn_value = 0;

// Note sound frequencies
int note_freqs[7] = {523, 587, 659, 698, 783, 880, 987};

void setup() {
  // Set button pins
  for (int i = 0; i < button_pins_length; i++){
    pinMode(button_pins[i], INPUT_PULLUP);
  }

  // Set buzzer pin
  pinMode(buzzer_pin, OUTPUT);
}

void loop() {
  // Initialize note
  int note = 0;

  // Check each button and set their respective frequency sounds
  for (int i = 0; i < button_pins_length; i++) {
    btn_value = digitalRead(button_pins[i]);
    if (btn_value == LOW) { // Button pressed
      note = note_freqs[i]; // Set note var to corresponding note frequency
    } 
  }

  // Play note
  if (note != 0){
    tone(buzzer_pin, note); // play a tone from buzzer
  } else {
    noTone(buzzer_pin); // tone off
  }
}
