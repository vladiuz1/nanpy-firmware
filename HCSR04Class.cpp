#include "cfg_all.h"

#if USE_HCSR04

#include <Arduino.h>
#include "HCSR04Class.h"
#include <stdlib.h>

const char* nanpy::HCSR04Class::get_firmware_id()
{
    return "HCSR04";
}

void nanpy::HCSR04Class::elaborate( nanpy::MethodDescriptor* m ) {
        if (strcmp(m->getName(), "begin") == 0) {
            // sets the pins to correct mode
            tp = m->getInt(0);
            ep = m->getInt(1);
            pinMode(tp, OUTPUT);
            pinMode(ep, INPUT);
            m->returns(0);
        }
        if (strcmp(m->getName(), "read") == 0) {
            // reads the delay between write and pulse, converts to distance in mm and returns value (int)
            int duration, mm;
            digitalWrite(tp, LOW);
            delayMicroseconds(2);
            digitalWrite(tp, HIGH);
            delayMicroseconds(10);
            digitalWrite(tp, LOW);
            duration = pulseIn(ep, HIGH);
            mm = int(duration / 5.8);
            m->returns(mm);
        }
};
#endif
