#include <string>

#include "mylib.h"
#include "pybind11/pybind11.h"

namespace py = pybind11;

PYBIND11_MODULE(MyLib, m) {
  m.def("func1", &func1);
  m.def("func2", &func2, py::arg("i") = 1, py::arg("j") = 2);
  m.def("func3", &func3);

  py::class_<Vec3>(m, "Vec3", py::buffer_protocol())
      .def(py::init<>())
      .def(py::init<float>())
      .def(py::init<float, float, float>())

      .def_buffer([](Vec3& v) {
        return py::buffer_info(v.v, sizeof(float),
                               py::format_descriptor<float>::format(), 1, {3},
                               {sizeof(float)});
      })

      .def_readonly("v", &Vec3::v)

      .def("__repr__",
           [](const Vec3& v) {
             return "(" + std::to_string(v.v[0]) + ", " +
                    std::to_string(v.v[1]) + ", " + std::to_string(v.v[2]) +
                    ")";
           })
      .def("__getitem__", [](const Vec3& v, int i) { return v.v[i]; });
}
