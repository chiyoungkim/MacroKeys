#include <HID.h>
#include <Keyboard.h>

const int numPins = 2;
const int inPin[numPins] = {A0, A1};

double buttonState[numPins] = {0, 0};         // current state of the button
int lastButtonState = 0;     // previous state of the button

char ctrlKey = KEY_LEFT_GUI;
char altKey = KEY_LEFT_ALT;

void setup()                    // run once, when the sketch starts
{
  // initialize the button pin as a input:
  for (int i = 0; i < numPins; ++i) {
    pinMode(inPin[i], INPUT); 
  }
  
  Keyboard.begin();
  Serial.begin(9600);           // set up Serial library at 9600 bps

  Serial.println("Hello world!");  // prints hello with ending line break
}

void loop()                       // run over and over again
{
  // read the pushbutton input pin:
  for (int i = 0; i < numPins; ++i) {
    buttonState[i] = analogRead(inPin[i]);
  }
  
  // compare the buttonState to its previous state
  if (buttonState[0] != lastButtonState) {
    if (buttonState[0] > 512) {
      if (buttonState[1] > 512) {
        command1();
      }
      else if (buttonState[1] <= 512) {
        command2();
      }
    }
    else if (buttonState[0] <= 512) {
      if (buttonState[1] > 512) {
        command3();
      }
      else if (buttonState[1] <= 512) {
        command4();
      }
    }
        Serial.println(buttonState[0]);
        Serial.println(buttonState[1]);
    lastButtonState = buttonState[0];
        Serial.println(buttonState[0]);
        Serial.println(buttonState[1]);
    // Delay a little bit to avoid bouncing
    delay(100);
  }

}

void command1() {
  Keyboard.press(altKey);
  Keyboard.press(KEY_TAB);
  Keyboard.releaseAll();
}

void command2() {
  Keyboard.press(altKey);
  Keyboard.press(ctrlKey);
  Keyboard.press(KEY_DELETE);
  Keyboard.releaseAll();
}

void command3() {
  Keyboard.press(KEY_CAPS_LOCK);
  Keyboard.releaseAll();
}

void command4() {
  Keyboard.press(KEY_UP_ARROW);
  Keyboard.releaseAll();
}
