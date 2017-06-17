/*
  SeeedTouchScreen.cpp - Library for 4-line resistance touch screen.
  Modified by loovee Aug 12, 2012.
  (c) ladyada / adafruit
  Code under MIT License.
*/

#ifndef __Andino_M1__
	#include "pins_arduino.h"
	#include "wiring_private.h"
#endif

#include <avr/pgmspace.h>
#include "Arduino.h"
#include "SeeedTouchScreen.h"
// increase or decrease the touchscreen oversampling. This is a little different than you make think:
// 1 is no oversampling, whatever data we get is immediately returned
// 2 is double-sampling and we only return valid data if both points are the same
// 3+ uses insert sort to get the median value.
// We found 2 is precise yet not too slow so we suggest sticking with it!

#define NUMSAMPLES 2		// sample number
#define COMP       2
#define AVERAGE    1
#define RXPLATE    300
#define TSDEBUG    0		// if print the debug information
Point::Point(void) {
    x = y = 0;
}

Point::Point(int x0, int y0, int z0)
{
    x = x0;
    y = y0;
    z = z0;
}

bool Point::operator==(Point p1)
{
    return  ((p1.x == x) && (p1.y == y) && (p1.z == z));
}

bool Point::operator!=(Point p1)
{
    return  ((p1.x != x) || (p1.y != y) || (p1.z != z));
}

/*
The shield provides a pin/terminal for each of the modeled resistors:
    Arduino A0 to Y-
    Arduino A1 to X-
    Arduino A2 to Y+
    Arduino A3 to X+
*/

TouchScreen::TouchScreen(uint8_t xp, uint8_t yp, uint8_t xm, uint8_t ym) {
	_yp = A2;
    _xm = A1;
    _ym = A0;
    _xp = A3;
}

#if AVERAGE
#define AVERAGETIME 4
int avr_analog(int adpin)
{
    int sum = 0;
    int max = 0;
    int min = 1024;
    for(int i = 0; i<AVERAGETIME; i++)
    {
        int tmp = analogRead(adpin);
        if(tmp > max)max = tmp;
        if(tmp < min)min = tmp;
        sum += tmp;
        //   sum+=analogRead(adpin);
    }
    return (sum-min-max)/(AVERAGETIME-2);

}
#endif


Point TouchScreen::getPoint(void) {
    int x, y, z = 1;
    int samples[NUMSAMPLES];
#if TSDEBUG
    int xx[2] = {0, 0};
    int yy[2] = {0, 0};
#endif
    uint8_t i, valid;

#if defined (__Andino_M1__)
    unsigned char xp_pin = A3;
    unsigned char xm_pin = A1;
    unsigned char yp_pin = A2;
    unsigned char ym_pin = A0;
#else
    uint8_t xp_port = digitalPinToPort(_xp);
    unsigned char yp_port = digitalPinToPort(_yp);
    unsigned char xm_port = digitalPinToPort(_xm);
    unsigned char ym_port = digitalPinToPort(_ym);

    unsigned char xp_pin = digitalPinToBitMask(_xp);
    unsigned char yp_pin = digitalPinToBitMask(_yp);
    unsigned char xm_pin = digitalPinToBitMask(_xm);
    unsigned char ym_pin = digitalPinToBitMask(_ym);
#endif
    valid = 1;


#if defined (__Andino_M1__)
    pinMode(yp_pin, INPUT_PULLUP); // Hi-Z Y+
    pinMode(ym_pin, INPUT_PULLUP); // Hi-Z Y-
#else
    pinMode(_yp, INPUT);
    pinMode(_ym, INPUT);
    *portOutputRegister(yp_port) &= ~yp_pin; // Hi-Z Y+
    *portOutputRegister(ym_port) &= ~ym_pin; // Hi-Z Y-
#endif

#if defined (__Andino_M1__)
    pinMode(xp_pin, OUTPUT);
    pinMode(xm_pin, OUTPUT);
	digitalWrite(xp_pin, HIGH); //Set X+ to VCC
	digitalWrite(xm_pin, LOW); //Set X- to GND
#else
    pinMode(_xp, OUTPUT);
    pinMode(_xm, OUTPUT);
    *portOutputRegister(xp_port) |= xp_pin; //Set X+ to VCC
    *portOutputRegister(xm_port) &= ~xm_pin; //Set X- to GND
#endif

    for (i=0; i<NUMSAMPLES; i++)
    {
#if AVERAGE
        samples[i] = avr_analog(_yp);
#else
        samples[i] = analogRead(_yp);
#endif

#if TSDEBUG
        xx[i] = samples[i];
#endif
    }

#if !COMP
    if (samples[0] != samples[1]) { valid = 0; }
#else
    int icomp = samples[0]>samples[1]?samples[0]-samples[1]:samples[1] - samples[0];
    if(icomp > COMP)valid = 0;
#endif

    x = (samples[0] + samples[1]);

#if defined (__Andino_M1__)
    pinMode(xp_pin, INPUT_PULLUP); // Hi-Z X+
    pinMode(xm_pin, INPUT_PULLUP); // Hi-Z X-

    pinMode(yp_pin, OUTPUT);
    pinMode(ym_pin, OUTPUT);
    digitalWrite(yp_pin,HIGH); //Set Y+ to VCC
    digitalWrite(ym_pin,LOW); //Set Y- to GND
#else
    pinMode(_xp, INPUT);
    pinMode(_xm, INPUT);
    *portOutputRegister(xp_port) &= ~xp_pin; // Hi-Z X+

    pinMode(_yp, OUTPUT);
    pinMode(_ym, OUTPUT);
	*portOutputRegister(yp_port) |= yp_pin; //Set Y+ to VCC
#endif

    for (i=0; i<NUMSAMPLES; i++) {
#if AVERAGE
        samples[i] = avr_analog(_xm);
#else
        samples[i] = analogRead(_xm);
#endif
#if TSDEBUG
        yy[i] = samples[i];
#endif
    }

#if !COMP
    if (samples[0] != samples[1]) { valid = 0; }
#else
    icomp = samples[0]>samples[1]?samples[0]-samples[1]:samples[1] - samples[0];
    if(icomp>COMP)valid = 0;
#endif
    y = (samples[0]+samples[0]);

#if defined (__Andino_M1__)
    pinMode(xp_pin, OUTPUT);
    pinMode(ym_pin, OUTPUT);
    pinMode(xm_pin, INPUT_PULLUP); // Hi-Z X-
    pinMode(yp_pin, INPUT_PULLUP); // Hi-Z Y+
    digitalWrite(xp_pin,LOW); //Set X+ to ground
    digitalWrite(ym_pin,HIGH); // Set Y- to VCC
#else
    pinMode(_xp, OUTPUT);
    *portOutputRegister(xp_port) &= ~xp_pin;            // Set X+ to ground
    *portOutputRegister(ym_port) |=  ym_pin;            // Set Y- to VCC
    *portOutputRegister(yp_port) &= ~yp_pin;            // Hi-Z X- and Y+
    pinMode(_yp, INPUT);
#endif

    int z1          = analogRead(_xm);
    int z2          = analogRead(_yp);
    float rtouch    = 0;

    rtouch  = z2;
    rtouch /= z1;
    rtouch -= 1;
    rtouch *= (2046-x)/2;
    rtouch *= RXPLATE;
    rtouch /= 1024;
    z = rtouch;
    if (! valid) {
        z = 0;
    }

#if TSDEBUG
    if(z > __PRESURE){
        Serial.print("x1 = "); Serial.print(xx[0]);
        Serial.print("\tx2 = ");Serial.print(xx[1]);
        Serial.print("\ty2 = ");Serial.print(yy[0]);
        Serial.print("\ty2 = ");Serial.println(yy[1]);
    }
#endif

    return Point(x, y, z);
}

bool TouchScreen::isTouching(void)
{
    Point p = getPoint();
    if(p.z > __PRESURE)return 1;
    else return 0;
}
