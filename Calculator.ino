#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include  <Keypad.h>

//OLED Info
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


const  byte ROWS = 1; // one rows
const byte COLS = 1; // one columns
byte rowPins[ROWS] = {11};
byte colPins[COLS] = {3};

// Define  the Keymap
char keys[ROWS][COLS] = {

  {'0'}

};

Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS  ); //  Create the Keypad

void setup(){
  pinMode(11, INPUT);
  pinMode(3, INPUT);


  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);

  //set the column to always be high
  digitalWrite(3,HIGH);


  // Wait for display
  delay(500);

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();
  delay(2000); // Pause for 2 seconds

  Serial.print("fhuihgei");

  // Clear the buffer
  display.clearDisplay();

  display.setTextSize(1);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(0,0); 


  display.println(F("hello"));
  display.display();
}

char key;

int buttonState;

void loop(){
  key = kpd.getKey();  //storing pressed key value in a char

  buttonState = digitalRead(11);
  if(buttonState == HIGH){
    Serial.print("yippee");
  }
  else{
    Serial.print("oh no");
  }

  if(key!=NO_KEY){
    display_result();
  }
}

void display_result(){
  // Draw a single pixel in white
  //display.drawPixel(10, 10, SSD1306_WHITE);
  display.setTextSize(1);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(0,0); 


  display.println(F("yippee! (:"));
  display.display();
}
