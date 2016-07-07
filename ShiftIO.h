#ifndef ShiftIO_h
#define ShiftIO_h
#include "Arduino.h"

class ShiftIO{
	public:
	int _registercount;
	int _getshiftvalue[];
	int getPSA();
	void begin(int latch, int clock, int data, int regamount);
	void set(int _pin, int _state);
	int shift[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	
		private:
		int _datapin;
		int _clockpin;
		int _latchpin;
};
#endif