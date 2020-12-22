// Virtual Inheritance
#include <iostream>
#include "NLitCube.h"

NLitCube::NLitCube(const char* n, double l, ulong c) : Name(n), NCube(n, l), NLitObj(n, c) {}