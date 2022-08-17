#include "Inventory.h"


std::vector<size_t> Inventory::find_indexes_of(const Item& item) const
{
  std::vector<size_t> indexes{};

  for (size_t idx = 0; idx < MAX_INV_SIZE; ++idx)
  {
    if (items[idx].id == item.id)
    {
      indexes.push_back(idx);
    }
  }

  return indexes;
}

size_t Inventory::find_next_empty_slot() const
{
  for (size_t idx = 0; idx < MAX_INV_SIZE; ++idx)
  {
    if (is_slot_empty(idx))
    {
      return idx;
    }
  }

  return MAX_INV_SIZE; // invalid value!
}

void Inventory::print() const
{
  for (size_t i = 0; i < MAX_INV_SIZE; ++i)
  {
    if (this->items[i].id != INVENTORY_EMPTY_SLOT_ID)
    {
      std::cout << "Inventory slot: " << i << "\n"
                << "Item ID: " << items[i].id << "\n"
                << "Item Num: " << items[i].curr_num_of_blocks_in_stack << "\n"
                << "Item Max Num: " << items[i].max_num_blocks_in_stack << std::endl;
      //<< "Item Texture: " << textures[items[i].id] << std::endl;
    }
  }
}

bool Inventory::add_item_to_existing_stack_if_possible(const Item& item)
{
  auto indexes_with_same_item = find_indexes_of(item);

  for (auto idx : indexes_with_same_item)
  {
    if (item.id == items[idx].id)
    {
      if (items[idx].curr_num_of_blocks_in_stack + item.curr_num_of_blocks_in_stack <=
          items[idx].max_num_blocks_in_stack)
      {
        items[idx].curr_num_of_blocks_in_stack += item.curr_num_of_blocks_in_stack;
        return true;
      }
    }
  }

  return false;
}

bool Inventory::add_item_to_new_stack_if_possible(Item&& item)
{
  size_t next_empty_slot = find_next_empty_slot();

  if (next_empty_slot >= 0)
  {
    this->items[next_empty_slot] = std::move(item);

    return true;
  }

  return false;
}

bool Inventory::add_item(Item&& item)
{
  bool was_possible_to_add_to_existing_stack = add_item_to_existing_stack_if_possible(item);

  if (!was_possible_to_add_to_existing_stack)
  {
    return add_item_to_new_stack_if_possible(std::move(item));
  }

  return false;
}