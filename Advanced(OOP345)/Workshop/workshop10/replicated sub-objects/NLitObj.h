// Replicated Base Classes
#include "Name.h"
typedef unsigned long int ulong;

class NLitObj : public Name {
    ulong color;
public:
    NLitObj(const char* n, ulong c);
    ulong emission() const;
};