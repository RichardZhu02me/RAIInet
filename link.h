#ifndef LINK_H
#define LINK_H
#include <string>


class Link{
    int travelDistance;
    string linkType;
    bool hidden;
    Player* owner;
    public:
        //increase the travel distance by 1
        void boost();
        //set the link to the opposite linkType
        void polarize();
        void hide();
        void reveal();
        Player* getOwner() const;
};
#endif
