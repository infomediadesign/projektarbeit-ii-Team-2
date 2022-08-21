#pragma once
#include "../INCLUDES.h"

using namespace std;

class DialogueNode;

class DialogueOption {
public:
  string text;
  int returnCode;
  DialogueNode *nextNode;
};

class DialogueNode {
public:
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

