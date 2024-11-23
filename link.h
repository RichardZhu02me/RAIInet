#ifndef LINK_H
#define LINK_H
#include <string>


class Link{
    int travelDistance;
    int row;
    int col;
    char id;
    int type;
    
    string linkType;
    bool hidden;
    Player* owner;
    public:
        Link(char id, int type, int strength);
        ~Link();
        //getters:
        int getRow() const;
        int getCol() const;
        char getId() const;
        int getType() const;
        
        void up();
        void down();
        void left();
        void right();

        void isHidden();
        void isDownloaded();
        //increase the travel distance by 1
        void boost();
        //set the link to the opposite linkType
        void polarize();
        void hide();
        void reveal();
        Player* getOwner() const;
};
#endif
