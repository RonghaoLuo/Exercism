#include "doctor_data.h"
heaven::Vessel::Vessel(std::string name, int integer) {
    this->name = name;
    this->integer = integer;
}
heaven::Vessel::Vessel(std::string name, int integer, star_map::System system) {
    this->name = name;
    this->integer = integer;
    this->system = system;
}