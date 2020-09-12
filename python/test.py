import numpy as np

import MyLib

print(MyLib.func1(1, 2))
print(MyLib.func2())

x = 0
MyLib.func3(x)
print(x)

v = MyLib.Vec3(1, 2, 3)
print(v[1])

print(v + np.array([1, 2, 3]))
