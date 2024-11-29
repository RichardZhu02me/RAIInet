#ifndef CELL_H
#define CELL_H

#include <memory>
#include "build.h"
#include "link.h"

using namespace std;

struct Cell {
    Link* link;
    bool firewall;
    bool server;
    unique_ptr<Build> build;
    
    Cell(): link(nullptr), firewall(false), server(false), build(nullptr) {}
    Cell(Link* link, bool firewall, bool server, unique_ptr<Build> build): 
        link(link), firewall(firewall), server(server), build(std::move(build)) {}
    
    // Explicitly delete copy operations
    Cell(const Cell&) = delete;
    Cell& operator=(const Cell&) = delete;
    
    // Add move operations
    Cell(Cell&& other) noexcept : 
        link(other.link),
        firewall(other.firewall),
        server(other.server),
        build(std::move(other.build)) {
        other.link = nullptr;
    }
    
    Cell& operator=(Cell&& other) noexcept {
        if (this != &other) {
            link = other.link;
            firewall = other.firewall;
            server = other.server;
            build = std::move(other.build);
            other.link = nullptr;
        }
        return *this;
    }

    void buildServer(int playerId) {
        build = Build::buildServer(playerId);
        server = true;
    }
};

#endif
