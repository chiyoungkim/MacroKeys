// SingleKey
// Chiyoung Kim

#include <HID.h>
#include <Keyboard.h>

const int buttonPin = 2;

int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button

char ctrlKey = KEY_LEFT_CTRL;
char altKey = KEY_LEFT_ALT;

void setup()                    // run once, when the sketch starts
{
  // initialize the button pin as a input:
  pinMode(buttonPin, INPUT);

  Keyboard.begin();
  Serial.begin(9600);           // set up Serial library at 9600 bps

  Serial.println("Hello world!");  // prints hello with ending line break
}

void loop()                       // run over and over again
{
  // read the pushbutton input pin:
  buttonState = digitalRead(buttonPin);

  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      // send signal from keypress
      Serial.println("A");
      Keyboard.press(altKey);
      Keyboard.press(KEY_TAB);
      Keyboard.releaseAll();
    } else {
      // nothing
    }
    lastButtonState = buttonState;
    // Delay a little bit to avoid bouncing
    delay(100);
  }

}
