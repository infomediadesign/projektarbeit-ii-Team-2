#pragma once
#include "../INCLUDES.h"

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

    Vector2 text_position = {850,600};

    int textState;
    bool text = false;

    Dialog();
    void DialogStart();
    void DialogNext();
    void DialogEnd();
    ~Dialog();
  };
}