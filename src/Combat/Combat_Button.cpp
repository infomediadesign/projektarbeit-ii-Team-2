#include "Combat_Button.h"


Texture2D Game::Combat_Button::getTexture() {
  if(active)
    return this->texture_active;

  return this->texture_inactive;
}

Game::Combat_Button::Combat_Button(Texture2D texture_active, Texture2D texture_inactive, int pos_x, int pos_y, bool active)
    : texture_active(texture_active), texture_inactive(texture_inactive), pos_x(pos_x), pos_y(pos_y), active(active) {

}

Game::Combat_Button::~Combat_Button() {
  UnloadTexture(this->texture_active);
  UnloadTexture(this->texture_inactive);
}
void Game::Combat_Button::update()
{
  std::vector<Game::Combat_Button*> buttons;
  int active_button = 0;

  auto*  button1 = new Game::Combat_Button(LoadTexture("assets/graphics/BattleScreen/Agypten/Aktion_Attack_Ausgewahlt.png"),
                                   LoadTexture("\"assets/graphics/BattleScreen/Agypten/Aktion_Attack_.png\""),
                                   565,
                                   470,
                                   true);

  auto* button2 = new Game::Combat_Button(LoadTexture("\"assets/graphics/BattleScreen/Agypten/Aktion_Time_Ausgewahlt_.png\""),
                                   LoadTexture("\"assets/graphics/BattleScreen/Agypten/Aktion_Time.png\""),
                                   button1->pos_x,
                                   button1->pos_y + 35,
                                   false);


  buttons.push_back(button1);
  buttons.push_back(button2);

  if(IsKeyPressed(KEY_DOWN)) {
    buttons[active_button]->active = false;
    if(active_button < buttons.size()-1)
      active_button++;
    else active_button = 0;

    buttons[active_button]->active = true;
  }

  if(IsKeyPressed(KEY_UP)) {
    buttons[active_button]->active = false;
    if(active_button == 0)
      active_button = (int) buttons.size()-1;
    else active_button--;

    buttons[active_button]->active = true;
  }

  if(IsKeyPressed(KEY_SPACE)) {
    std::cout << "Button Nr. " << active_button << " gedrückt..." << std::endl;
  }
  for(auto& button : buttons) {
    DrawTexture(button->getTexture(), button->pos_x, button->pos_y, WHITE);
  }
  }
