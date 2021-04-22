//
// Created by kenny on 4/21/2021.
//

#include "Land.h"

using namespace std;

Land* getRandomLand() {
    LandTypes selection = (LandTypes) (rand() % MAX_NUM_LANDS);

    switch (selection) {
        case LAKE:
            return new Lake;
            break;
        case FOREST:
            return new Forest;
            break;
        case DESERT:
            return new Desert;
            break;
        case HOUSE:
            return new House;
            break;
        case CAVE:
            return new Cave;
            break;
        case FIELD:
            return new Field;
            break;
        case FARM:
            return new Farm;
            break;
        case STRANGER:
            return new Stranger;
            break;
        default:
            return new Lake;
            break;
    }
}

string Lake::getShortDescription(){
    return "lake";
}

string Lake::getLongDescription(){
    return "You arrive at a large lake filled with clear sparkling water.";
}

string Lake::visit(Player& p){
    string description = "You drink from the lake, replenishing your thirst";
    p.setThirst(Player::DEFAULT_THIRST);
    return description;
}

string Forest::getShortDescription(){
    return "forest";
}

string Forest::getLongDescription(){
    return "You arrive in dense forest filled with trees and foliage.";
}

string Forest::visit(Player& p) {
    string description = "You forage for berries but find nothing.";

    int chance = rand() % 100;

    // Chance to find berries

    if (chance > 50) {
        description = "You foraged for berries in the forest and found some!";
        p.setHunger(p.getHunger() + 1);
        return description;
    }

    // Chance to get mauled by bear
    if(chance < 10 && chance > 5){
        description = "You are attacked by a hungry bear in the woods!";
        p.setHealth(p.getHealth() - 1);
    }

    // Chance to get double mauled
    if(chance < 5){
        description = "You are attacked by two very large bears!";
        int newHealth = (int)p.getHealth() - 2;
        newHealth = newHealth < 0 ? 0 : newHealth;
        p.setHealth(newHealth);
    }

    return description;
}

string Desert::getShortDescription(){
    return "desert";
}

string Desert::getLongDescription(){
    return "You arrive in a extremely hot, dry desert";
}

string Desert::visit(Player& p){
    string description = "The heat of the desert makes you dehydrated.";

    p.setThirst(p.getThirst() - 1);

    return description;
}

string House::getShortDescription() {
    return "house";
}

string House::getLongDescription() {
    return "You arrive at a cozy log cabin!";
}

string House::visit(Player &p) {
    int chance = rand() % 100;
    string description = "You search the house for supplies and find nothing";


    if (chance > 70) {
        description = "You foraged for supplies and found a medkit!";
        p.setHealth(p.getHealth() + 1);
        return description;
    }

    return description;

}

string Cave::getShortDescription() {
    return "cave";
}

string Cave::getLongDescription() {
    return "You enter a dark cave.";
}

string Cave::visit(Player &p) {
    int chance = rand() % 100;
    string description = "You are engulfed by darkness.";


    if (chance > 20) {
        description = "You hear footsteps in the back of the cave!";
        if (chance > 40) {
            description = "An angry bigfoot rushes out of the darkness!";
            int newHealth = (int)p.getHealth() - 2;
            newHealth = newHealth < 0 ? 0 : newHealth;
            p.setHealth(newHealth);
        }
        else {
            description = "The footsteps move away!";
        }
        return description;
    }
    return description;
}

string Field::getShortDescription() {
    return "field";
}

string Field::getLongDescription() {
    return "You enter an open field and hear a plane above you.";
}

string Field::visit(Player &p) {
    int chance = rand() % 100;
    string description = "The plane passes overhead";
    if (chance > 90) {
        description = "The plane drops a package over you containing food and water!";
        p.setHunger(p.getHunger() + 1);
        p.setThirst(Player::DEFAULT_THIRST);
        return description;
    }
    return description;
}

string Farm::getShortDescription() {
    return "farm";
}

string Farm::getLongDescription() {
    return "You enter a large barn.";
}

string Farm::visit(Player &p) {
    int chance = rand() % 100;
    string description = "The barn is empty.";
    if (chance > 70) {
        description = "The barn contains an abundance of food!";
        p.setHunger(p.getHunger() + 2);
        return description;
    }
    if(chance < 70) {
        description = "You are attacked by an angry bull and running away has made you hungry and thirsty!";
        p.setThirst(p.getThirst() - 1);
        p.setHunger(p.getHunger() - 1);
    }
    return description;
}

string Stranger::getShortDescription() {
    return "stranger";
}

string Stranger::getLongDescription() {
    return "You see a strange man.";
}

string Stranger::visit(Player &p) {
    int chance = rand() % 100;
    string description = "The man is silent.";
    if (chance > 50) {
        description = "The man gives you some food!";
        p.setHunger(p.getHunger() + 1);
        return description;
    }
    if(chance < 50) {
        description = "The man stabs you!";
        int newHealth = (int)p.getHealth() - 4;
        newHealth = newHealth < 0 ? 0 : newHealth;
        p.setHealth(newHealth);
    }
    return description;
}



