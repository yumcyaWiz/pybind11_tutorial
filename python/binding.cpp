#include "mylib.h"
#include "pybind11/pybind11.h"

namespace py = pybind11;

PYBIND11_MODULE(MyLib, m) {
  m.def("func1", &func1);
  m.def("func2", &func2, py::arg("i") = 1, py::arg("j") = 2);
  m.def("func3", &func3);
}
