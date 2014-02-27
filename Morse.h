#pragma include once

#include <Arduino.h>

class Morse {
public:
  Morse(int, int);
  ~Morse();
  void write(String);
private:
  int pin_;
  int dotDur_;
  int dashDur_;
  int ieGapDur_;
  int shortGapDur_;
  int mediumGapDur_;
  String toMorse(char);
  void write(char);
  void write(int);
  void debug(String);
  void debug(char);
};
