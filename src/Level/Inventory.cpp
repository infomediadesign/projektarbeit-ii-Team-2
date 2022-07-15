#include "Inventory.h"

Inventory::Inventory()
{
  this->cap = 5;
  this->nrOfItems = 0;
  this->itemArr = new Item*[cap];
  this->initialize();
}

Inventory::~Inventory()
{
  for (size_t i = 0; i < this->nrOfItems; i++)
  {
    delete this->itemArr[i];
  }
  delete[] this->itemArr;
}

Inventory::Inventory(const Inventory &obj)
{
  this->cap = obj.cap;
  this->nrOfItems = obj.nrOfItems;
  this->itemArr = new Item*[this->cap];

  for (size_t i = 0; i < this->nrOfItems; i++)
  {
    this->itemArr[i] = obj.itemArr[i]->clone();
  }

  initialize(this->nrOfItems);
}

Item& Inventory::operator[](const int index)
{
  if (index < 0 || index >= this->nrOfItems)
    throw("BAD INDEX!");

  return *this->itemArr[index];
}

void Inventory::operator=(const Inventory &obj)
{
  for (size_t i = 0; i < this->nrOfItems; i++)
  {
    delete this->itemArr[i];
  }
  delete[] this->itemArr;

  this->cap = obj.cap;
  this->nrOfItems = obj.nrOfItems;
  this->itemArr = new Item*[this->cap];

  for (size_t i = 0; i < this->nrOfItems; i++)
  {
    this->itemArr[i] = obj.itemArr[i]->clone();
  }

  initialize(this->nrOfItems);
}

void Inventory::expand()
{
  this->cap *= 2;

  Item **tempArr = new Item*[this->cap];

  for (size_t i = 0; i < this->nrOfItems; i++)
  {
    tempArr[i] = this->itemArr[i];
  }

  delete[] this->itemArr;

  this->itemArr = tempArr;

  this->initialize(this->nrOfItems);
}

void Inventory::initialize(const int from)
{
  for (size_t i = from; i < cap; i++)
  {
    this->itemArr[i] = nullptr;
  }
}

void Inventory::addItem(const Item &item)
{
  if (this->nrOfItems >= this->cap)
  {
    expand();
  }

  this->itemArr[this->nrOfItems++] = item.clone();
}

void Inventory::removeItem(int index) {
  if (index < 0 || index >= this->nrOfItems)
    throw("OUT OF BOUNDS REMOVE ITEM INVENTORY");

  delete this->itemArr[index];
  this->itemArr[index]             = this->itemArr[this->nrOfItems - 1];
  this->itemArr[--this->nrOfItems] = nullptr;
}



/*
void Inventory::armor()
{
  // helmet         HP + 5;
  // chestplate     HP + 10
}

void Inventory::potions()
{
  // healthpotion   HP + 5
  // attackpotion   Str + 5
  // abilitypotion  fill up "Ability bar"
  // defensepotion  Def + 5
}
String getStringFromEnum(e)
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


void Game::Inventory::itemclass() {

itemtype i;

std::cout<< getStringValue(i);

int type;
do
{
  std::cout<<"\n\n\n\tINVENTORY MENU";
  std::cout<<"\n\n\t 1.ARMOR";
  std::cout<<"\n\n\t 2.ARMOR";
  std::cout<<"\n\n\t 3.POTIIONS";
  std::cout<<"\n\n\t 4.POTIIONS";
  std::cout<<"\n\n\t 5.POTIIONS";
  std::cout<<"\n\n\t 6.POTIIONS";
  std::cout<<"\n\n\t 7.RETURN TO PAUSE MENU";
  std::cout<<"\n\n\t Please select your option (1-7) \t";
  std::cin>>type;
  switch (type)
  {
  case '1': ;
    break;
  case '2': ;
    break;
  case '3':
    break;
  case '4':
    break;
  case '5':
    break;
  case '6':
    break;
  case '7':
    break;
  default :std::cout<<"\a";
  }
} while (type!='7');
}

void Game::Inventory::armor() {}
void Game::Inventory::potions() {}
void Game::Inventory::showdata() {}
void Game::Inventory::menu() {}

fstream f; //global declaration for stream object, object
Inventory i;

void Inventory::getdata()
{

  cout<<"Please enter the item-number here--> \n";
  cin >> itemstats;
  cout<<"Please enter the items name here --> \n";
  cin >> itemname;
  cout<<"Please enter the items price here--> \n";
  cin >> price;
  cout<<"Please enter the discount here --> \n";
  cin >> discount;
}
void Inventory::showdata()
{

  cout <<"\nThe item-number is : "<<itemstats;
  cout <<"\nThe item-name is : "<<itemname;
  cout <<"\nThe items-price is : "<<price;
  cout <<"\nDiscount : "<<discount;
}
void Inventory::write_to_file()
{
  f.open("store.dat", ios::out|ios::app);
  i.getdata();
  f.write((char*)&i, sizeof (i));
  f.close();
  cout<<"\n\nAn item has been added ";
}
void Inventory::disp_all()
{

  cout<<"\n\n\n\t\tDISPLAY ALL RECORDS !!! \n\n";
  f.open("store.dat",ios::in);
  while(f.read((char*)&i, sizeof (i)))
  {
    i.showdata();
    cout<<"\n\n====================================\n";
  }
  f.close();
}
void Inventory::display_sp(int n)
{
  int flag = 0;
  f.open("store.dat",ios::in);
  while(f.read((char*)&i, sizeof (i)))
  {
    if(i.renameItemNumber()==n)
    {

      i.showdata();
      flag = 1;
    }
  }
  f.close();
  if(flag == 0)
    cout<<"\n\nRecord does not exist";
}
void Inventory::modify()
{
  int no, found = 0;

  cout<<"\n\n\t To Modify ";
  cout<<"\n\n\t Please enter the item-number here";
  cin>>no;
  f.open("store.dat", ios::in|ios::out);
  while (f.read((char*)&i,sizeof (i)))
  {
    if(i.renameItemNumber())
    {
      i.showdata();


      cout<<"\nPlease enter the new details of the item"<<endl;
      i.getdata();
      int pos = -1*((int)sizeof (i));
      f.seekp(pos,ios::cur);
      f.write((char*)&i,sizeof(i));
      cout<<"\n\n\t Record Updated";
      found = 1;
    }
  }
  f.close();
  if(found == 0)
    cout<<"\n\n Record not found ";
}
void Inventory::deleterecord()
{
  int no;

  cout<<"\n\n\tDelete Record";
  cout<<"\n\n\tPlease enter the item number of which you want to delete";
  cin>>no;
  f.open("store.dat", ios::out);
  fstream f2;
  f2.open("temp.dat", ios::out);
  f.seekg(0,ios::beg);
  while(f.read((char*)&i, sizeof (i)))
  {
    if(i.renameItemNumber()!=no)
    {
      f2.write((char*)&i,sizeof (i));
    }
  }
  f2.close();
  f.close();
  remove("store.dat");
  rename("temp.dat", "store.dat");
  cout<<"\n\n\tRecord Deleted ..";
}
void Inventory::menu()
{

  f.open("store.dat", ios::in);
  if(!f)
  {
    cout<<"ERROR!!! FILE COULD NOT BE OPEDED\n\n\n go to admin menu to create File";
    cout<<"\n\n\n Program is closing ....";
    exit(0);
  }
  cout<<"\n\n\t\t ITEM MENU \n\n";
  cout<<"====================================\n";
  cout<<"ITEM.NO. \t\tNAME \t\tPRICE\n";
  cout<<"====================================\n";
  while(f.read((char*)&i,sizeof(i)))
  {
    cout<<i.renameItemNumber()<<"\t\t"<<i.renameItemName()<<"\t\t"<<i.renameItemPrice()<<endl;
  }
  f.close();
}
void Inventory::place_order()
{
  int order_arr[50], quan[50], c = 0;
  float amt, damt, total = 0;
  char ch = 'Y';
  menu();
  cout<<"\n=============================";
  cout<<"\n      PLACE YOUR ORDER       ";
  cout<<"===============================\n";
  do
  {
    cout<<"\n\nEnter the item-number : \n";
    cin>>order_arr[c];
    cout<<"\n\nQuantity of items : \n";
    cin>>quan[c];
    cout<<"\n\nDo you wish to order another item? (y/n) : \t";
    cin>>ch;
  } while (ch == 'y' || ch =='Y');
  cout<<"\n\nThank you for your purchase";

  cout<<"\n\n**********INVOICE************\n";
  cout<<"\nItem-number \tName \tQuantity \tPrice \tAmount after discount\n";
  for(int x = 0; x <= c; x++)
  {
    f.open("store.dat", ios::in);
    f.read((char*)&i,sizeof (i));
    while(!f.eof())
    {
      if(i.renameItemNumber()==order_arr[x])
      {
        amt=i.renameItemPrice()*quan[x];
        damt=amt-(-amt*i.renameItemDiscount()/100);
        cout<<"\n"<<order_arr[x]<<"\t"<<i.renameItemName()<<"\t"<<quan[x]<<"\t\t"<<i.renameItemPrice()<<"\t"<<amt<<"\t\t"<<damt;
        total+=damt;
      }
      f.read((char*)&i,sizeof (i));
    }
    f.close();
  }
  cout<<"\n\n\t\t\t\t\tTOTAL = "<<total;
}
void Inventory::admin_menu()
{

  char ch2;
  cout<<"\n\n\tADMIN MENU";
  cout<<"\n\t1.CREATE ITEM";
  cout<<"\n\t2.DISPLAY ALL ITEMS";
  cout<<"\n\t3.QUERY";
  cout<<"\n\t4.MODIFY ITEM";
  cout<<"\n\t5.DELETE";
  cout<<"\n\t6.BACK TO MAIN MENU";
  cout<<"\n\n\tPlease enter your choice (1-6) \t";
  cin>>ch2;
  switch(ch2)
  {
  case'1':

    write_to_file();
    break;
  case'2':
    disp_all();
    break;
  case'3':
    int num;

    cout<<"\n\n\tPlease enter the item-number";
    cin>>num;
    display_sp(num);
    break;
  case '4': modify();
    break;
  case '5': deleterecord();
    break;
  case '6': menu();
    break;
  default:cout<<"\a";admin_menu();
  }
}


 */

