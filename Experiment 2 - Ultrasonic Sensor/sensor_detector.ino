// LED Pins
const int red_led_pin = 13;
const int green_led_pin = 12;

// Sensor Pins
const int echo_pin = 2;
const int trig_pin = 3;

// Buzzer Pins
const int buzzer_pin = 8;

// Distance Initialization
float distance, duration;
const int DISTANCE_THRESHOLD = 10;

void setup() {
  // For console printing and debugging purposes
  Serial.begin(9600);

  // Set pin modes
  pinMode(red_led_pin, OUTPUT);
  pinMode(green_led_pin, OUTPUT);
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
}

void loop() {
  // Read trigger 
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig_pin, LOW);
  
  // Measure duration using echo pin
  duration = pulseIn(echo_pin, HIGH);
  // Calculate the distance in centimeters
  distance = duration * 0.034/2;
  
  // Detect something
  if (distance < DISTANCE_THRESHOLD){
    digitalWrite(red_led_pin, HIGH); // enable red light
  	digitalWrite(green_led_pin, LOW); // disable green light
    tone(buzzer_pin, 261, 100); // play sound
  } else { // Else out of detection
    digitalWrite(red_led_pin, LOW); // disable red light
  	digitalWrite(green_led_pin, HIGH); // enable green light
    noTone(buzzer_pin); // stop sound
  }

  // For checking the distance through serial monitor
  Serial.print("distance cm: ");
  Serial.println(distance);
}

void megalovania(){
  tone(3,294,125);//D4
delay(125);
tone(3,294,125);//D4
delay(125);
tone(3,587,250);//D5
delay(250);
tone(3,440,250);//A4
delay(375);
tone(3,415,125);//Ab4
delay(250);
tone(3,392,250);//G4
delay(250);
tone(3,349,250);//F4
delay(250);
tone(3,294,125);//D4
delay(125);
tone(3,349,125);//F4
delay(125);
tone(3,392,125);//G4
delay(125);
tone(3,261,125);//C4(middle)     
delay(62);
tone(3,261,125);//C4(middle)     
delay(62);
tone(3,261,125);//C4(middle)     
delay(62);
tone(3,261,125);//C4(middle)     
delay(62);
tone(3,587,250);//D5
delay(250);
tone(3,440,375);//A4
delay(375);
tone(3,415,125);//Ab4
delay(250);
tone(3,392,250);//G4
delay(250);
tone(3,349,250);//F4
delay(250);
tone(3,294,125);//D4
delay(125);
tone(3,349,125);//F4
delay(125);
tone(3,392,125);//G4
delay(125);
tone(3,247,125);//B3
delay(125);
tone(3,247,125);//B3
delay(125);
tone(3,587,250);//D5
delay(250);
tone(3,440,375);//A4
delay(375);
tone(3,415,125);//Ab4
delay(250);
tone(3,392,250);//G4
delay(250);
tone(3,349,250);//F4
delay(250);
tone(3,294,125);//D4
delay(125);
tone(3,349,125);//F4
delay(125);
tone(3,392,125);//G4
delay(125);
tone(3,233,62);//Bb3
delay(62);
tone(3,233,62);//Bb3
delay(62);
tone(3,233,62);//Bb3
delay(62);
tone(3,233,62);//Bb3
delay(62);
tone(3,587,250);//D5
delay(250);
tone(3,440,375);//A4
delay(375);
tone(3,415,125);//Ab4
delay(250);
tone(3,392,250);//G4
delay(250);
tone(3,349,250);//F4
delay(250);
tone(3,294,125);//D4
delay(125);
tone(3,349,125);//F4
delay(125);
tone(3,392,125);//G4
delay(125);
tone(3,294,125);//D4
delay(125);
tone(3,294,125);//D4
delay(125);
tone(3,587,250);//D5
delay(250);
tone(3,440,375);//A4
delay(375);
tone(3,415,125);//Ab4
delay(250);
tone(3,392,250);//G4
delay(250);
tone(3,349,250);//F4
delay(250);
tone(3,294,125);//D4
delay(125);
tone(3,349,125);//F4
delay(125);
tone(3,392,125);//G4
delay(125);
tone(3,261,125);//C4(middle)     
delay(62);
tone(3,261,125);//C4(middle)     
delay(62);
tone(3,261,125);//C4(middle)     
delay(62);
tone(3,261,125);//C4(middle)     
delay(62);
tone(3,587,250);//D5
delay(250);
tone(3,440,375);//A4
delay(375);
tone(3,415,125);//Ab4
delay(250);
tone(3,392,250);//G4
delay(250);
tone(3,349,250);//F4
delay(250);
tone(3,294,125);//D4
delay(125);
tone(3,349,125);//F4
delay(125);
tone(3,392,125);//G4
delay(125);
tone(3,247,125);//B3
delay(125);
tone(3,247,125);//B3
delay(125);
tone(3,587,250);//D5
delay(250);
tone(3,440,375);//A4
delay(375);
tone(3,415,125);//Ab4
delay(250);
tone(3,392,250);//G4
delay(250);
tone(3,349,250);//F4
delay(250);
tone(3,294,125);//D4
delay(125);
tone(3,349,125);//F4
delay(125);
tone(3,392,125);//G4
delay(125);
tone(3,233,62);//Bb3
delay(62);
tone(3,233,62);//Bb3
delay(62);
tone(3,233,62);//Bb3
delay(62);
tone(3,233,62);//Bb3
delay(62);
tone(3,588,250);//D5
delay(250);
tone(3,440,375);//A4
delay(375);
tone(3,415,125);//Ab4
delay(250);
tone(3,392,250);//G4
delay(250);
tone(3,349,250);//F4
delay(250);
tone(3,294,125);//D4
delay(125);
tone(3,349,125);//F4
delay(125);
tone(3,392,125);//G4
delay(125);
}
