#include "Morse.h"

Morse::Morse(int pin, int dotDur)
: pin_(pin),
  dotDur_(dotDur),
  dashDur_(dotDur_ * 3),
  ieGapDur_(dotDur_),
  shortGapDur_(dotDur_ * 3),
  mediumGapDur_(dotDur_ * 7) {
  pinMode(pin_, OUTPUT);
}

Morse::~Morse() {}

void Morse::write(String msg) {
  for (int i = 0; i < msg.length(); ++i) {
    write(msg[i]);
  }
}

void Morse::write(char c) {

  String s = toMorse(c);
  int len = s.length();

  for (int i = 0; i < len; ++i) {
    if (s[i] == '.') {
      write(dotDur_);
    } else if (s[i] == '-') {
      write(dashDur_);
    } else if (s[i] == ' ') {
      delay(mediumGapDur_ - 2 * shortGapDur_);
    }
    if (i < len - 1) {
      delay(ieGapDur_);
    } else if (i == len - 1) {
      delay(shortGapDur_);
    }
  }
}

void Morse::write(int dur) {
  digitalWrite(pin_, HIGH);
  delay(dur);
  digitalWrite(pin_, LOW);
}

String Morse::toMorse(char c) {

  String result;

  switch(toupper(c)) {
  case 'A': 
    result = ".-"; 
    break;
  case 'B': 
    result = "-..."; 
    break;
  case 'C': 
    result = "-.-."; 
    break;
  case 'D': 
    result = "-.."; 
    break;
  case 'E': 
    result = "."; 
    break;
  case 'F': 
    result = "..-."; 
    break;
  case 'G': 
    result = "--."; 
    break;
  case 'H': 
    result = "...."; 
    break;
  case 'I': 
    result = ".."; 
    break;
  case 'J': 
    result = ".---"; 
    break;
  case 'K': 
    result = "-.-"; 
    break;
  case 'L': 
    result = ".-.."; 
    break;
  case 'M': 
    result = "--"; 
    break;
  case 'N': 
    result = "-."; 
    break;
  case 'O': 
    result = "---"; 
    break;
  case 'P': 
    result = ".--."; 
    break;
  case 'Q': 
    result = "--.-"; 
    break;
  case 'R': 
    result = ".-."; 
    break;
  case 'S': 
    result = "..."; 
    break;
  case 'T': 
    result = "-"; 
    break;
  case 'U': 
    result = "..-"; 
    break;
  case 'V': 
    result = "...-"; 
    break;
  case 'W': 
    result = ".--"; 
    break;
  case 'X': 
    result = "-..-"; 
    break;
  case 'Y': 
    result = "-.--"; 
    break;
  case 'Z': 
    result = "--.."; 
    break;
  case '0': 
    result = "-----"; 
    break;
  case '1': 
    result = ".----"; 
    break;
  case '2': 
    result = "..---"; 
    break;
  case '3': 
    result = "...--"; 
    break;
  case '4': 
    result = "....-"; 
    break;
  case '5': 
    result = "....."; 
    break;
  case '6': 
    result = "-...."; 
    break;
  case '7': 
    result = "--..."; 
    break;
  case '8': 
    result = "---.."; 
    break;
  case '9': 
    result = "----."; 
    break;
  case '.': 
    result = ".-.-.-"; 
    break;
  case ',': 
    result = "--..--"; 
    break;
  case '?': 
    result = "..--.."; 
    break;
  default:
    result = " ";
    break;
  }

  return result;
}
