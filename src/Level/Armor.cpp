/*#include"Armor.h"

dArr<std::string> Armor::names;

void Armor::initNames()
{
  Armor::names.push("Sungods-Chestplate");
  Armor::names.push("Sungods-Helmet");
  Armor::names.push("Posidons-Chestplate");
  Armor::names.push("Posidons-Helmet");
}

Armor::Armor()
    :Item()
{
  this->type = -1;
  this->hp = 0;
  this->defence = 0;
  this->strength = 0;
}

Armor::Armor(int type, int hp, int defence, int strength, std::string name)
    : Item(itemTypes::ARMOR, name)
{
  this->defence = +5;
  this->type = rand() % 2;

  switch (this->type)
  {
  case armorType::HEAD:
    this->typeStr = "Head";
    break;
  case armorType::CHEST:
    this->typeStr = "Chest";
    break;
  default:
    this->typeStr = "ERROR INVALID!";
    break;
  }

  this->setName(Armor::names[rand() % Armor::names.size()]);
  {
    this->type = type;
    this->hp = hp;
    this->strength = strength;
    this->defence = defence;
  }
}

Armor::~Armor()
{

}

Armor* Armor::clone()const
{
  return new Armor(*this);
}

std::string Armor::toString()const
{
  std::string str =
    this->getName()
    + " | Type: "
    + this->typeStr
    + " | Def: "
    + std::to_string(this->defence);

  return str;
}

std::string Armor::toStringSave()const
{
  std::string str =
    std::to_string(this->getItemType())
    + " "
    + this->getName()
    + " "
    + std::to_string(this->defence)
    + " "
    + std::to_string(this->type)
    + " ";

  return str;
}

*/