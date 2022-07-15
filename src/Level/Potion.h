#pragma once

#include"../INCLUDES.h"
#include"Item.h"

enum potionType { ATTACK = 0, HEAL, DEFENCE, ABILLITY};

class Potions :
    public Item
{
private:
  int type;
  std::string typePot;
  int damageMin;
  int damageMax;
  int healMin;
  int healMax;
  int hp;
  int defence;
  int strength;


public:
  Potions();
  Potions(
    int damageMin,
    int damageMax,
    int healMin,
    int healMax,
    std::string name);

  virtual ~Potions();

  //Pure virtual
  virtual Potions * clone()const;

  //Functions
  std::string toString()const;
  std::string toStringSave()const;

  //Accessors
  inline int getDamageMin()const { return this->damageMin; }
  inline int getDamageMax()const { return this->damageMax; }
  inline int getHealMin()const { return this->healMin; }
  inline int getHealMax()const { return this->healMax; }
  inline int getHP()const { return this->hp; }
  inline int getDefence()const { return this->defence; }
  inline int getStrengthDamageMin()const { return this->strength; }

  //Modifiers

  //Static
  static dArr<std::string> names;
  static void initNames();
};
