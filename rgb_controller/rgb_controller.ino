// gamma correction arrays
const uint8_t gamma8[] = {
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  2,  2,  2,  2,  2,  2,  2,
    2,  3,  3,  3,  3,  3,  3,  3,  4,  4,  4,  4,  4,  5,  5,  5,
    5,  6,  6,  6,  6,  7,  7,  7,  7,  8,  8,  8,  9,  9,  9, 10,
   10, 10, 11, 11, 11, 12, 12, 13, 13, 13, 14, 14, 15, 15, 16, 16,
   17, 17, 18, 18, 19, 19, 20, 20, 21, 21, 22, 22, 23, 24, 24, 25,
   25, 26, 27, 27, 28, 29, 29, 30, 31, 32, 32, 33, 34, 35, 35, 36,
   37, 38, 39, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 50,
   51, 52, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 66, 67, 68,
   69, 70, 72, 73, 74, 75, 77, 78, 79, 81, 82, 83, 85, 86, 87, 89,
   90, 92, 93, 95, 96, 98, 99,101,102,104,105,107,109,110,112,114,
  115,117,119,120,122,124,126,127,129,131,133,135,137,138,140,142,
  144,146,148,150,152,154,156,158,160,162,164,167,169,171,173,175,
  177,180,182,184,186,189,191,193,196,198,200,203,205,208,210,213,
  215,218,220,223,225,228,231,233,236,239,241,244,247,249,252,255 };

// give it a name:
int red = 6; 
int red_val = 0;
int grn = 5;
int grn_val = 0;
int blu = 3;
int blu_val = 0;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(red, OUTPUT);     
  pinMode(grn, OUTPUT);
  pinMode(blu, OUTPUT);
  
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  red_val = analogRead(A0);    // pot
  blu_val = analogRead(A2);    // joystick rX
  grn_val = analogRead(A1);    // joystick rY
  
  Serial.print(red_val);
  Serial.print(", ");
  Serial.print(grn_val);
  Serial.print(", ");
  Serial.println(blu_val);
  
  analogWrite(red, gamma8[red_val/4]);   // 
  analogWrite(blu, gamma8[blu_val/4]);   // 
  analogWrite(grn, gamma8[grn_val/4]);   // 

}
