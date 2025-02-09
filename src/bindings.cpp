#include <pybind11/pybind11.h>
#include "core/Engine.h"

namespace py = pybind11;

PYBIND11_MODULE(game_engine, m) {
    py::class_<Engine>(m, "Engine")
        .def(py::init<>())
        .def("run", &Engine::Run)
        .def("stop", &Engine::Stop);
}
