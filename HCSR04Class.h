#ifndef HCSR04_CLASS
#define HCSR04_CLASS

#include "BaseClass.h"
#include "MethodDescriptor.h"

namespace nanpy {
    class HCSR04Class : public BaseClass {
        public:
            int tp, ep;
            void elaborate( nanpy::MethodDescriptor* m );
            const char* get_firmware_id();
    };
}

#endif
