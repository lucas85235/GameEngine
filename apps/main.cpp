#include "Engine.h"

int main() {
    Engine& engine = Engine::Instance();
    engine.Run();
    return 0;
}
