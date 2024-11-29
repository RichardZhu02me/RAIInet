#ifndef BUILD_H
#define BUILD_H

#include <string>   
#include <memory>

using namespace std;

class Build {
private:
    int playerId;
    string structureName;

public:
    Build(int playerId, const string& name);
    ~Build();
    
    int getPlayerId() const;
    string getStructureName() const;
    
    static unique_ptr<Build> buildFirewall(int playerId);
    static unique_ptr<Build> buildServer(int playerId);
};

#endif
