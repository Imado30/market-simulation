// uvicorn Server:rest_api --port 8000 --reload
// cmake -S . -B build && cmake --build build && cmake --install build
// python3 -m uvicorn Server:rest_api --port 8000 --reload
//cmake -S . -B build &&
//cmake --build build &&
//cmake --install build

#include <pybind11/pybind11.h>
#include <Nutzer.hpp>
#include <Angebot.hpp>
#include <Markt.hpp>
#include <string>
#include <pybind11/stl.h>

namespace py = pybind11;
using namespace Handelsplatz;

PYBIND11_MODULE(handelsplatz, m) {
    m.doc() = "Handelsplatz";

    py::class_<Nutzer>(m, "Nutzer")
        .def(py::init<std::string,std::string>())        
        .def("get_berry", &Nutzer::get_berry)
        .def("set_berry", &Nutzer::set_berry)
        .def("find_ware", &Nutzer::find_ware)
        .def("get_menge", &Nutzer::get_menge)
        .def("add", &Nutzer::add)
        .def("add_for_delete", &Nutzer::add_for_delete)
        .def("offer_einfügen", &Nutzer::offer_einfügen)
        .def("find_my_offer", &Nutzer::find_my_offer)
        .def("remove_my_offer", &Nutzer::remove_my_offer)
        .def("get_my_offer", &Nutzer::get_my_offer)
        .def("get_inventar", &Nutzer::get_inventar)
        .def("get_pw", &Nutzer::get_pw)
        .def("get_my_offer_size", &Nutzer::get_my_offer_size)
        .def("remove", &Nutzer::remove);

    py::class_<Angebot>(m, "Angebot")
        .def(py::init<std::string, int, double>())
        .def("get_warentyp", &Angebot::get_warentyp)
        .def("get_anzahl", &Angebot::get_anzahl)
        .def("get_preis", &Angebot::get_preis); 

    py::class_<Markt>(m, "Markt")
        .def(py::init<>())
        .def("create_offer", &Markt::create_offer)
        .def("get_offer", &Markt::get_offer)
        .def("delete_offer", &Markt::delete_offer)
        //.def("accept_offer", &Markt::accept_offer)
        //.def("sell", &Markt::sell)
        //.def("buy", &Markt::buy);
        .def("create_user", &Markt::create_user)
        .def("get_user", &Markt::get_user)
        .def("edit_user", &Markt::edit_user)
        .def("get_size_user", &Markt::get_size_user)
        .def("auth", &Markt::auth)
        .def("edit_my_offer", &Markt::edit_my_offer)
        .def("get_size_offers", &Markt::get_size_offers)
        .def("add_offer_ids", &Markt::add_offer_ids);
}