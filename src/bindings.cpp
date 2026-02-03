#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "monster.h"
#include "customMonsters.h"
#include "battleEngine.h"

namespace py = pybind11;

PYBIND11_MODULE(pokebindings, m)
{
    m.doc() = "Python bindings for the Pokémon battle engine.";

    // Expose the Monster base class
    py::class_<Monster>(m, "Monster")
        .def(py::init<int, int, int, int, int, int, const std::string &>(),
             py::arg("health"), py::arg("attack"), py::arg("defense"),
             py::arg("special_attack"), py::arg("special_defense"),
             py::arg("speed"), py::arg("name"))
        .def("is_fainted", &Monster::isFainted)
        .def("print_stats", &Monster::printStats)
        .def("print_moves", &Monster::getMovesString);

    // Expose actual Pokemon
    py::class_<Bulbasaur, Monster>(m, "Bulbasaur")
        .def(py::init<>());
    py::class_<Charmander, Monster>(m, "Charmander")
        .def(py::init<>());

    // Expose battle engine
    py::class_<BattleEngine::StateMachine>(m, "BattleEngine")
        .def(py::init<>())
        .def("commence_battle", &BattleEngine::StateMachine::commenceBattle);
}