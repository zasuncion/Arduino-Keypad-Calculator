#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//OLED Info
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Button Pins
const int zero = 10;
const int one = 9;
const int add = 7;
const int sub = 6;
const int mult = 5;
const int dvd = 4;
const int eql = 2;
const int clr = 3;

// Internal Variables for calculations
long Num1 = 0;
long Num2 = 0;
long Value = 0; //Used to store inputted values and the output

char action;
bool result = false;

void appendDigit(int digit) {
  Value = Value * 10 + digit;
}

void calculateResult() {
  switch(action) {
    case '+': 
      Value = Num1 + Num2;
      break;
    case '-': 
      Value = Num1 - Num2; 
      break;
    case '*': 
      Value = Num1 * Num2; 
      break;
    case '/': 
      if (Num2 != 0){
        Value = Num1 / Num2;
      }
      else{
        Value = 0;
      }
      break;
  }
}

void displayResult(){
  display.clearDisplay();
  display.setCursor(0,0);
  display.setTextSize(2);

  display.print(Num1); //could probably use concatenation but it seemed like typecasting isn't a good idea here
  display.print(action);
  display.print(Num2);

  if(result){
    display.print("=");
    display.print(Value);
  }

  display.display();
}

void setup(){

  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);

  pinMode(zero, INPUT_PULLUP);
  pinMode(one, INPUT_PULLUP);
  pinMode(add, INPUT_PULLUP);
  pinMode(sub, INPUT_PULLUP);
  pinMode(mult, INPUT_PULLUP);
  pinMode(dvd, INPUT_PULLUP);
  pinMode(eql, INPUT_PULLUP);
  pinMode(clr, INPUT_PULLUP);

  display.setTextSize(1);
  display.setCursor(0,0);

  display.println(F("hello"));
  display.display();

  delay(1500);
}

void loop(){

   // delete
  if(digitalRead(clr) == LOW){
    Num1 = Num2 = Value = 0;
    result = false;
    action = 0;
    delay(200);
  }

  // update digits
  if(digitalRead(zero) == LOW){ appendDigit(0); delay(200); }
  if(digitalRead(one) == LOW){ appendDigit(1); delay(200); }

  // detect operation
  if(digitalRead(add) == LOW){
    Num1 = Value;
    Value = 0;
    action = '+';
    delay(200);
  }

  if(digitalRead(sub) == LOW){
    Num1 = Value;
    Value = 0;
    action = '-';
    delay(200);
  }

  if(digitalRead(mult) == LOW){
    Num1 = Value;
    Value = 0;
    action = '*';
    delay(200);
  }

  if(digitalRead(dvd) == LOW){
    Num1 = Value;
    Value = 0;
    action = '/';
    delay(200);
  }

  // For Result
  if(digitalRead(eql) == LOW){
    Num2 = Value;
    result = true;
    calculateResult();
    delay(200);
  }

  displayResult();
}

  display.println(F("yippee! (:"));
  display.display();
}
