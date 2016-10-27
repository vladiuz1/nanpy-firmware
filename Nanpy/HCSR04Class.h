#ifndef HCSR04_CLASS
#define HCSR04_CLASS

#include "BaseClass.h"
#include "MethodDescriptor.h"

class HCSR04 {
    public:
        int tp, ep;
        HCSR04 (int trigPin, int echoPin): tp(trigPin), ep(echoPin) {};
};

namespace nanpy {
    class HCSR04Class: public ObjectsManager<HCSR04>{
        public:
            void elaborate( MethodDescriptor* m );
            const char* get_firmware_id();
    };
};

#endif
