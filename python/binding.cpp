#include <string>

#include "mylib.h"
#include "pybind11/pybind11.h"

namespace py = pybind11;

PYBIND11_MODULE(MyLib, m) {
  m.def("func1", &func1);
  m.def("func2", &func2, py::arg("i") = 1, py::arg("j") = 2);
  m.def("func3", &func3);

  py::class_<Vec3>(m, "Vec3")
      .def(py::init<>())
      .def(py::init<float>())
      .def(py::init<float, float, float>())

      .def("__repr__",
           [](const Vec3& v) {
             return "(" + std::to_string(v.v[0]) + ", " +
                    std::to_string(v.v[1]) + ", " + std::to_string(v.v[2]) +
                    ")";
           })

      .def_readonly("v", &Vec3::v);
}