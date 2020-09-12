#ifndef _VEC3_H
#define _VEC3_H
#include "type.h"

class Vec3 {
 public:
  Real v[3];

  Vec3() { v[0] = v[1] = v[2] = 0; }
  Vec3(Real x) { v[0] = v[1] = v[2] = x; }
  Vec3(Real x, Real y, Real z) {
    v[0] = x;
    v[1] = y;
    v[2] = z;
  }
};

#endif