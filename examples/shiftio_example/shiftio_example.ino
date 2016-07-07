#include <ShiftIO.h>
//include the ShiftIO library

ShiftIO reg;
//define ShiftIO to reg

void setup() {
reg.begin(3,4,5,1);
//begin(latch pin,clock pin,data pin,registe pinr amount);
}

void loop() {
reg.set(0,1);
delay(200);
reg.set(0,0);
delay(200);
}