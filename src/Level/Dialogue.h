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
  string text;
  vector <DialogueOption> dialogueOptions;

};

class Dialogue {
public:
  Dialogue();

  void init();
  void destroyDialogue();

  int performDialogue();

private:
  vector<DialogueNode *> dialogueNodes;
};

