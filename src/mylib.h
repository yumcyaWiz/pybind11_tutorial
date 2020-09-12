#ifndef _MYLIB_H
#define _MYLIB_H

int func1(int i, int j);
int func2(int i = 1, int j = 2);

void func3(int& x);

class Vec3 {
 public:
  float v[3];

  Vec3();
  Vec3(float x);
  Vec3(float x, float y, float z);
};

#endif