#include "mylib.h"

int func1(int i, int j) { return i + j; }
int func2(int i, int j) { return i + j; }

void func3(int& x) { x = 1; }

Vec3::Vec3() { v[0] = v[1] = v[2] = 0; }
Vec3::Vec3(float x) { v[0] = v[1] = v[2] = x; }
Vec3::Vec3(float x, float y, float z) {
  v[0] = x;
  v[1] = y;
  v[2] = z;
}