#include "cfg_all.h"

#if USE_HCSR04

#include <Arduino.h>
#include "HCSR04Class.h"
#include <stdlib.h>

const char* nanpy::HCSR04Class::get_firmware_id()
{
    return "HCSR04";
}

void nanpy::HCSR04Class::elaborate( MethodDescriptor* m ) {
        ObjectsManager<HCSR04>::elaborate(m);
        if (strcmp(m->getName(),"new") == 0) {
            HCSR04* pins;
            pins = new HCSR04(m->getInt(0), m->getInt(1));
            pinMode(pins->tp, OUTPUT);
            pinMode(pins->ep, INPUT);
            v.insert(pins);
            m->returns(v.getLastIndex());
        }
        if (strcmp(m->getName(), "read") == 0) {
            // reads the delay between write and pulse, converts to distance in mm and returns value (int)
            int duration, mm;
            digitalWrite(v[m->getObjectId()]->tp, LOW);
            delayMicroseconds(2);
            digitalWrite(v[m->getObjectId()]->tp, HIGH);
            delayMicroseconds(10);
            digitalWrite(v[m->getObjectId()]->tp, LOW);
            duration = pulseIn(v[m->getObjectId()]->ep, HIGH);
            mm = int(duration / 5.8);
            m->returns(mm);
        }
};
#endif
