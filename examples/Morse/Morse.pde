#include <Morse.h>

int pin = 13;
int dotDuration = 80;

Morse morse(pin, dotDuration);

void setup() {
}

void loop() {
  morse.write("Hello World");
  delay(2000);
}
