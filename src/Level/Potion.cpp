/*#include "Potion.h"

dArr<std::string> Potions::names;

void Potions::initNames()
{
  Potions::names.push("Attack");
  Potions::names.push("Defence");
  Potions::names.push("Health");
  Potions::names.push("Abillity");
}

Potions::Potions()
    :Item()
{
  this->damageMax = 0;
  this->damageMin = 0;
  this->healMax = 0;
  this->healMin = 0;
  this->hp = 0;
  this->defence = 0;
  this->strength = 0;
}

Potions::Potions(int damageMin, int damageMax, int healMin, int healMax, std::string name)
    : Item(itemTypes::POTION, name)
{

    this->damageMin = damageMin;
    this->damageMax = damageMax;
    this->healMin = healMin;
    this->healMax = healMax;

    switch (this->type)
    {
    case potionType::ATTACK:
      this->typePot = "Attack";
      break;
    case potionType::DEFENCE:
      this->typePot = "Defense";
      break;
    case potionType::ABILLITY:
      this->typePot = "Abillity";
      break;
    case potionType::HEAL:
      this->typePot = "Heal";
      break;
    default:
      this->typePot = "ERROR INVALID!";
      break;
    }
    {
      this->setName(Potions::names[rand() % Potions::names.size()]);
    }
}

Potions::~Potions()
{

}

Potions *Potions::clone()const
{
  return new Potions(*this);
}

std::string Potions::toString()const
{
  std::string str =
    this->getName()
    + " | Damage: "
    + std::to_string(this->damageMin)
    + " - "
    + std::to_string(this->damageMax);
    + " | Heal: "
    + std::to_string(this->healMin)
    + " - "
    + std::to_string(this->healMax);
    + " | hp: "
    + std::to_string(this->hp);
    + " | defence: "
    + std::to_string(this->defence);
    + " | strength: "
    + std::to_string(this->strength);
  return str;
}

std::string Potions::toStringSave()const
{
  std::string str =
    std::to_string(this->getItemType())
    + " "
    + this->getName()
    + " "
    + std::to_string(this->damageMin)
    + " "
    + std::to_string(this->damageMax)
    + " "
    + std::to_string(this->healMin)
    + " "
    + std::to_string(this->healMax)
    + " "
    + std::to_string(this->hp)
    + " "
    + std::to_string(this->defence)
    + " "
    + std::to_string(this->strength)
    + " ";
    return str;
}
*/