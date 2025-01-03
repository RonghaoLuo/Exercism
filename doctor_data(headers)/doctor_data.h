#pragma once
#include <string>
namespace star_map {
    enum class System {
        BetaHydri,
        EpsilonEridani
    };
}

namespace heaven {
    class Vessel {
        public:
            Vessel(std::string name, int integer);
            Vessel(std::string name, int integer, star_map::System system);
        private:
            std::string name;
            int integer;
            star_map::System system;
    };
}