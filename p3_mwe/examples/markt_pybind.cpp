// uvicorn server:rest_api --port 8000 --reload
// cmake -S . -B build && cmake --build build && cmake --install build
// python3 -m uvicorn Server:rest_api --port 8000 --reload
//cmake -S . -B build &&
//cmake --build build &&
//cmake --install build

#include <pybind11/pybind11.h>
#include <Nutzer.hpp>
#include <Angebot.hpp>
#include <string>
#include <Markt.hpp>
#include <pybind11/stl.h>

namespace py = pybind11;
using namespace Handelsplatz;

PYBIND11_MODULE(handelsplatz, m) {
    m.doc() = "Handelsplatz";

    py::class_<Nutzer>(m, "Nutzer")
        .def(py::init<std::string, std::string>())
        .def("get_berry", &Nutzer::get_berry)
        .def("set_berry", &Nutzer::set_berry)
        .def("add", &Nutzer::add)
        .def("get_pw", &Nutzer::get_pw)
        .def("remove", &Nutzer::remove);

    py::class_<Angebot>(m, "Angebot")
        .def(py::init<std::string, int, double>())
        .def("get_warentyp", &Angebot::get_warentyp)
        .def("get_anzahl", &Angebot::get_anzahl)
        .def("get_preis", &Angebot::get_preis);

    py::class_<Markt>(m, "Markt")
        .def(py::init<>())
        .def("create_user", &Markt::create_user)
        .def("edit_user", &Markt::edit_user)
        .def("get_offer", &Markt::get_offer)
        .def("auth", &Markt::auth)
        .def("get_size_user", &Markt::get_size_user);

    
        


    

    
}