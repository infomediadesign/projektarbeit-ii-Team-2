#pragma once
#include "../INCLUDES.h"
#include "../Player/Nemo.h"

/*
using namespace std;

class DialogueNode;

class DialogueOption {
public:
  DialogueOption(string Text, int ReturnCode, DialogueNode *NextNode);
  string text;
  int returnCode;
  DialogueNode *nextNode;
};

class DialogueNode {
public:
  DialogueNode(string Text);
  //DialogueNode(const char);
  string text;
  vector <DialogueOption> dialogueOptions;

};

class Dialogue {
public:
  Dialogue();

  void init();
  void start();
  void destroyDialogue();

  int performDialogue();

private:
  vector<DialogueNode *> dialogueNodes;
};

*/
namespace Game {
  class Dialog {
  public:
    Game::Nemo * nemo;

    Texture2D Dialogbox = LoadTexture("assets/graphics/Character/Dialogbox.png");

    //Vector2 text_position = {850,600};

    int textState = 1;
    bool text = false;

    void DialogStart();
  };
}