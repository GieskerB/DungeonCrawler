
#include "includes.inc"

#include "includes/WorldBlueprint.hpp"
#include "src/WorldBlueprint.cpp"

int main() {

    auto bp = WorldBlueprint(2);
    bp.buildWorld(nullptr);

    return 0;
}


