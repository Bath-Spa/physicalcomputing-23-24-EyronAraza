// LED PINS
int led_pins[5] = {13,12,11,10,9};
int led_pins_length = sizeof(led_pins)/sizeof(led_pins[0]);
int led_anim_delay = 100; // set animation cycle speed
int led_index = 0;

// Button setup
int btn_pin = 7;
int btn_value = 0;
int btn_switch = true;

// Slowdown Animation
int anim_init_slowdown = 300; // how many seconds slow?
long anim_total_slowdowns_max =  5; // how many times should it slowdown until it stops?
int anim_total_slowdowns_count = 999; // to count slowdown (it's set to high value so it doesn't activate slowdown at beginning)

// Animation cycle switch
bool anim_switch = false;

void setup() {
  // Set led pin modes
  for (int i = 0; i < led_pins_length; i++){
    pinMode(led_pins[i], OUTPUT);
  }

  // set button
  pinMode(btn_pin, INPUT);
}

void loop() {
  btn_value = digitalRead(btn_pin);

  // Push button 
  if (btn_value == HIGH){
    btn_switch = false;
    anim_total_slowdowns_count = 0;
  } 

  // LED Cycle Animation
  if (btn_switch){
      digitalWrite(led_pins[led_index], HIGH);
      delay(led_anim_delay);
      digitalWrite(led_pins[led_index], LOW);

      // Play LED animation cycle
      led_animation_cycle();
  } else {
    // Make LED animation slowdown before stopping
    if (anim_total_slowdowns_count <= anim_total_slowdowns_max) { 
      digitalWrite(led_pins[led_index], HIGH);
      delay(anim_init_slowdown);
      digitalWrite(led_pins[led_index], LOW);

      // Reuse led animation cycle for this slow down
      led_animation_cycle();

      // Adding extra seconds to make it slow down
      anim_init_slowdown = anim_init_slowdown + 50; 

      // Increment total slow downs
      anim_total_slowdowns_count++;
    }
    else {
      // Stop and light up specific LED
      digitalWrite(led_pins[led_index], HIGH);
    }
  }
}

// Function for making LED animation switch between left and right
void led_animation_cycle(){
  if (anim_switch){
    // Make LED animation go left
    if (led_index <= 0){
      anim_switch = !anim_switch; // switch anim if reach index 0
    } else {
      led_index--; // decrement LEDs index
    } 
  } else {
    // Make LED animation go right
    if (led_index >= led_pins_length - 1){
      anim_switch = !anim_switch; // switch anim if reach max length of LEDs
    } else {
      led_index++; // increment LEDs index
    } 
  }
}

