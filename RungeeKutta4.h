#ifndef PHYSSIN_RUNGEEKUTTA4_H
#define PHYSSIN_RUNGEEKUTTA4_H

#include "State.h"
#include "Body.h"

class RungeeKutta4{
public:
    State solve(Body &object, State& state, float h);
};


#endif //PHYSSIN_RUNGEEKUTTA4_H
