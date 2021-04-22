//
// Created by kenny on 4/21/2021.
//

#ifndef SURVIVALGAME_LAND_H
#define SURVIVALGAME_LAND_H

#include <string>
#include <stdlib.h>
#include "player.h"

using namespace std;
enum LandTypes {LAKE, FOREST, DESERT, HOUSE, CAVE, FIELD, FARM, STRANGER, MAX_NUM_LANDS};

class Land {
public:
    virtual string getShortDescription() = 0;
    virtual string getLongDescription() = 0;
    virtual string visit(Player &p) = 0;

private:
};

class Lake : public Land {
public:
    string getShortDescription();
    string getLongDescription();
    string visit(Player &p);
private:
};

class Forest : public Land {
public:
    string getShortDescription();
    string getLongDescription();
    string visit(Player &p);
private:
};

class Desert : public Land {
public:
    string getShortDescription();
    string getLongDescription();
    string visit(Player &p);
private:
};

class House : public Land {
public:
    string getShortDescription();
    string getLongDescription();
    string visit(Player &p);
private:
};

class Cave : public Land {
public:
    string getShortDescription();
    string getLongDescription();
    string visit(Player &p);

private:
};

class Field : public Land {
public:
    string getShortDescription();
    string getLongDescription();
    string visit(Player &p);

private:
};

class Farm : public Land {
public:
    string getShortDescription();
    string getLongDescription();
    string visit(Player &p);

private:
};

class Stranger : public Land {
public:
    string getShortDescription();
    string getLongDescription();
    string visit(Player &p);

private:
};

Land* getRandomLand(void);


#endif //SURVIVALGAME_LAND_H
