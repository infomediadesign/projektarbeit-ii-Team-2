#pragma once
#include "../INCLUDES.h"

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

