#include <avr/io.h>
#include "Arduino.h"
#include "ShiftIO.h"

void ShiftIO::begin(int latch, int clock, int data, int regamount){ //define shift register pins
_latchpin = latch;
_clockpin = clock;
_datapin = data;
_registercount = regamount * 8;
pinMode(_latchpin, OUTPUT);
pinMode(_clockpin, OUTPUT);
pinMode(_datapin, OUTPUT);
}

void ShiftIO::set(int _pin, int _state){ //Set pin state and update(shift) it to the register
if((_pin<_registercount) && (_pin>=0)) {
    if((_state>=0) && (_state<=1)) {
      _getshiftvalue[_pin] = _state;
    }
  }
digitalWrite(_latchpin, 0);
for(int shift_x=0;shift_x<_registercount;shift_x++){
digitalWrite(_datapin, _getshiftvalue[shift_x]);
digitalWrite(_clockpin,1);
digitalWrite(_clockpin,0);
}

digitalWrite(_latchpin, 1);
}