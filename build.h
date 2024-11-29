#ifndef BUILD_H
#define BUILD_H

#include <string>   
#include <memory>

using namespace std;

class Build {
private:    
    //the player that built the structure
    int playerId;
    //the name of the structure
    string structureName;

public:
    //constructor for the build
    Build(int playerId, const string& name);
    //destructor for the build
    ~Build();
    
    //get the player that built the structure
    int getPlayerId() const;
    //get the name of the structure
    string getStructureName() const;
    
    //creates a firewall for the given player
    static unique_ptr<Build> buildFirewall(int playerId);
    //creates a server for the given player
    static unique_ptr<Build> buildServer(int playerId);
};

#endif
