#pragma once

#include"../INCLUDES.h"
#include"Item.h"

enum armorType { HEAD = 0, CHEST};

class Armor :
    public Item
{
private:
  int type;
  std::string typeStr;
  int hp;
  int defence;
  int strength;

public:
  Armor();
  Armor(
    int type,
    int hp,
    int defence,
    int strength,
    std::string name);

  virtual ~Armor();

  //Pure virtual
  virtual Armor* clone()const;

  //Functions
  std::string toString()const;
  std::string toStringSave()const;

  //Accessors
  inline int getDefence()const { return this->defence; }
  inline int getType()const { return this->type; }

  //Static
  static dArr<std::string> names;
  static void initNames();
};
