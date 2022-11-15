#pragma once;

class Character {
    public:

        int getHitPoints();
        int getArmorClass();
        int getHitBonus();
        int getInitBonus();


    private:

        int hitPoints;
        int armorClass;
        int hitBonus;
        int initBonus;

};