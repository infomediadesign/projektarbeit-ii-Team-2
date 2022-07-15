#include "../INCLUDES.h"

#include "Item.h"

class Inventory
{
private:
  int cap;
  int nrOfItems;
  Item **itemArr;
  void expand();
  void initialize(const int from = 0);

public:
  Inventory();
  ~Inventory();
  Inventory(const Inventory &obj);
  inline int size()const { return this->nrOfItems; };
  Item& operator[](const int index);
  void operator=(const Inventory &obj);
  void addItem(const Item &item);
  void removeItem(int index);
  inline void debugPrint() const
  {
    for (size_t i = 0; i < this->nrOfItems; i++)
    {
      std::cout << this->itemArr[i]->debugPrint() << std::endl;
    }
  }
};


//we need a connection between the combat system, cuz of the stat change
  /*
   * namespace Game
{
class Inventory {

char itemname;
int HP, Def, Str;

char * MyGetValue(int v, char *tmp);

#define ENUM_MAP(type, strings) char * getStringValue(const type &T) \
 { \
 return MyGetValue((int)T, strings); \
 }

; enum itemtype {Armor, Potions, Weapons};

ENUM_MAP(itemtype,"Armor|Potions|Weapons")



public:
void itemclass();
void armor();
void potions();
void showdata();
void menu();
};

}
   *
  int HP, Def, Str;
  enum Items {helmet, chestplate, health_potion, attack_potion, ability_potion, defense_potion};

  //differentiate between armor and potions
  void armor(); //differentiate between armor and potions
  void potions();

  String Items(e)
  {
    switch(e)
      {
      case helmet: HP + 5;
      case chestplate: HP + 10;

      case health_potion: HP + 10;
      case attack_potion: Str + 10;
      case ability_potion:; // fills the ability bar up
      case defense_potion: Def +10;
      }
  }

  };
}


using namespace std;
class Inventory {

int item_HP;
int item_Def;
int item_Str;
int itemstats;
char itemname[50];
float HP, Def, Str, discount;


public:
void getdata();
void showdata();
void write_to_file();   //function to write in file
void disp_all();        //function to read all records from the file
void display_sp(int n); //function to read specific record from file
void modify();
void deleterecord();    //function to delete record of file
void menu();            //function to display all products price lists
void place_order();     //function to place order and generate the bill
void admin_menu();

int renameItemNumber()
{
  return itemnumber;
}
int renameItemDiscount()
{
  return discount;
}
float renameItemPrice()
{
  return HP;
}
char* renameItemName()
{
  return itemname;
}
};

*/


