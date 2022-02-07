//
// Created by tucha on 2/8/2022.
//

#include "RungeeKutta4.h"

State RungeeKutta4::solve(Body &object, State& state, float h) {

    State dx, k1, k2, k3, k4;

    k1 = object.f(state);
    k2 = object.f(*state.add(*k1.mul(0.5f * h)));
    k3 = object.f(*state.add(*k2.mul(0.5f * h)));
    k4 = object.f(*state.add(*k3.mul(h)));
    dx.add(*k1.mul(h / 6));
    dx.add(*k2.mul(h / 3));
    dx.add(*k3.mul(h / 3));
    dx.add(*k4.mul(h / 6));

    return dx;

}
