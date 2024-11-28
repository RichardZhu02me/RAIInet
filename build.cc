#include "build.h"
#include "player.h"

using namespace std;

Build::Build(int playerId, const string& name) 
    : playerId{playerId}, structureName{name} {}

Build::~Build() {}

int Build::getPlayerId() const {
    return playerId;
}

string Build::getStructureName() const {
    return structureName;
}

unique_ptr<Build> Build::buildFirewall(int playerId) {
    return make_unique<Build>(playerId, "firewall");
}

unique_ptr<Build> Build::buildServer(int playerId) {
    return make_unique<Build>(playerId, "server");
}
