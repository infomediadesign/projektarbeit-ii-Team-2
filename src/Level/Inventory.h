#include "../INCLUDES.h"

struct Item {
  int type;
  int id;
  bool is_stackable;
  int max_num_blocks_in_stack;
  int curr_num_of_blocks_in_stack;
};

class Inventory
{
public:
  bool add_item(Item&& item);

private:
  bool is_slot_empty(size_t idx) const { return items[idx].id == INVENTORY_EMPTY_SLOT_ID; }
  std::vector<size_t> find_indexes_of(const Item& item) const;
  size_t find_next_empty_slot() const;

  bool add_item_to_existing_stack_if_possible(const Item& item);
  bool add_item_to_new_stack_if_possible(Item&& item);

  void print() const;

  static constexpr size_t MAX_INV_SIZE = 40; // can transform into a class template!

  std::array<Item, MAX_INV_SIZE> items;

  static constexpr int INVENTORY_EMPTY_SLOT_ID = -1;
};

//we need a connection between the combat system, cuz of the stat change
