#include "Dialogue.h"

/*
DialogueNode::DialogueNode(string Text) {
  text = Text;
}

DialogueOption::DialogueOption(string Text, int ReturnCode, DialogueNode *NextNode) {
  text = Text;
  returnCode = ReturnCode;
  nextNode = NextNode;
}

//Constructor!
Dialogue::Dialogue()
{

}

//sets up the tree
void Dialogue::init()
{

  /*const char message[128] = "This sample illustrates a text writing\nanimation effect! Check it out! ;)";
  int framesCounter = 0;

  if (IsKeyDown(KEY_SPACE)) framesCounter += 8;
  else framesCounter++;

  if (IsKeyPressed(KEY_ENTER)) framesCounter = 0;

  DialogueNode *node0 = new DialogueNode("Welcome Nemo, I'm guessing this is your first time-travel?");
  //DialogueNode *node0 = new DialogueNode("Welcome Nemo, I'm guessing this is your first time-travel?");
  DialogueNode *node1 = new DialogueNode("Then dont get any help from me you twat!");
  DialogueNode *node2 = new DialogueNode("I'm Epanox a Time Guardian...");
  DialogueNode *node3 = new DialogueNode("No I can't send you back because you are the one who's travelled through time, in order for you to travel back home you need to find the time crystals hidden in the dungeon.");
  DialogueNode *node4 = new DialogueNode("You are currently in egypt, 2490 B.C");
  DialogueNode *node5 = new DialogueNode("In oder for you to return home you need to collect time crystals hidden in the dungeon, but be warned there are enemy's in that dungeon as well.");

  //Node 0
  node0->dialogueOptions.push_back(DialogueOption("Yes, who are you?", 0, node2));
  node0->dialogueOptions.push_back(DialogueOption("No, Fuck OFF!", 0, node1));
  dialogueNodes.push_back(node0);

  //Node 1
  node1->dialogueOptions.push_back(DialogueOption("Then dont get any help from me you twat! ", 0, nullptr));
  dialogueNodes.push_back(node1);

  //Node 2
  node2->dialogueOptions.push_back(DialogueOption("A Time Guardian? Does that mean you can send me back?", 0, node3));
  node2->dialogueOptions.push_back(DialogueOption("Where am I/ When am I?", 0, node4));
  node2->dialogueOptions.push_back(DialogueOption("How do I get home?", 0, node5));
  dialogueNodes.push_back(node2);

  //Node 3
  node3->dialogueOptions.push_back(DialogueOption("Where am I/ When am I?", 0, node4));
  node3->dialogueOptions.push_back(DialogueOption("Got it i'll go on, thanks for the help.", 0, nullptr));
  dialogueNodes.push_back(node3);

  //Node 4
  node4->dialogueOptions.push_back(DialogueOption("Egypt, damn I've always wanted to travel here, Ill be on my way, thanks...", 1, nullptr));
  node4->dialogueOptions.push_back(DialogueOption("No way, how do I get home?!.", 0, node5));
  dialogueNodes.push_back(node4);

  //Node 5
  node5->dialogueOptions.push_back(DialogueOption("Ok thanks for tip, I'll be off then!", 1, nullptr));
  dialogueNodes.push_back(node5);
  }

void Dialogue::destroyDialogue()
{
  for (int i = 0; i < dialogueNodes.size(); i++) {
    delete dialogueNodes[i];
  }
  dialogueNodes.clear();
}
//does the actual conversation and returns the outcome
int Dialogue::performDialogue()
{ if (dialogueNodes.size() == 0) {
    return - 1;
  }

  DialogueNode *currentNode = dialogueNodes[0];
  
  while (true){
    
    cout << currentNode->text << "\n\n";

    for (int i = 0; i < currentNode->dialogueOptions.size(); i++) {
      cout << i + 1 << ": "<< currentNode->dialogueOptions[i].text << endl;
    }
    cout << endl;
    int input;
    cin >> input;
    input--;

    if (input < 0 || input > currentNode->dialogueOptions.size()){
      cout << "Invalid input!\n";
    } else {
      // check for end of conversation
      if (currentNode->dialogueOptions[input].nextNode == nullptr) {
        return currentNode->dialogueOptions[input].returnCode;
      };

      currentNode = currentNode->dialogueOptions[input].nextNode;

    }
    cout << endl;
  }
  return 0;
}
void Dialogue::start() {
  DrawText("Welcome to Custodia", 958, 593 , 10, BLACK);
}
*/

void Game::Dialog::DialogStart() {
  DrawTexture(Dialogbox, nemo->NemoPosition.x - 180 , nemo->NemoPosition.y + 90 , WHITE);
  if (IsKeyPressed(KEY_SPACE)){
    textState + 1;
    PlaySound(GameAudio::dialoge);
    SetSoundVolume(GameAudio::dialoge, float(0.1));
  }

  if (IsKeyReleased(KEY_SPACE) && textState == 0) {
    textState = 1;
  } else if (IsKeyReleased(KEY_SPACE) && textState == 1) {
    textState = 2;
  } else if (IsKeyReleased(KEY_SPACE) && textState == 2) {
    textState = 3;
  } else if (IsKeyReleased(KEY_SPACE) && textState == 3) {
    textState = 4;
  } else if (IsKeyReleased(KEY_SPACE) && textState == 4) {
    textState = 5;
  } else if (IsKeyReleased(KEY_SPACE) && textState == 5) {
    textState = 6;
  } else if (IsKeyReleased(KEY_SPACE) && textState == 6) {
    textState = 7;
  } else if (IsKeyReleased(KEY_SPACE) && textState == 7) {
    textState = 8;
  } else if (IsKeyReleased(KEY_SPACE) && textState == 8) {
    textState = 9;
  } else if (IsKeyReleased(KEY_SPACE) && textState == 9) {
    textState = 10;
  } else if (IsKeyReleased(KEY_SPACE) && textState == 10) {
    textState = 11;
  } else if (IsKeyReleased(KEY_SPACE) && textState == 11) {
    textState = 12;
  }

  switch (textState) {
  default: break;
  case 1:
    DrawText("Instructions", nemo->NemoPosition.x - 180 , nemo->NemoPosition.y + 75, 15, BLACK);
    DrawText("To start the conversation press SPACE.", nemo->NemoPosition.x - 162 , nemo->NemoPosition.y + 110, 15, WHITE);
    DrawText("To skip to the next part of the", nemo->NemoPosition.x - 162 , nemo->NemoPosition.y + 135, 15, WHITE);
    DrawText("conversation press SPACE again.", nemo->NemoPosition.x - 162 , nemo->NemoPosition.y + 160, 15, WHITE);
    break;
  case 2:
    DrawText("Epanox ", nemo->NemoPosition.x - 180 , nemo->NemoPosition.y + 75, 15, BLACK);
    DrawText("Welcome traveller, are you alright? ", nemo->NemoPosition.x - 162 , nemo->NemoPosition.y + 110, 15, WHITE);
    DrawText("Quite the travel you've done.", nemo->NemoPosition.x - 162 , nemo->NemoPosition.y + 135, 15, WHITE);
    break;
  case 3:
    DrawText("Nemo ", nemo->NemoPosition.x - 180 , nemo->NemoPosition.y + 75, 15, BLACK);
    DrawText("Where am I... is that a pyramid? Am I in Egypt? ", nemo->NemoPosition.x - 162 , nemo->NemoPosition.y + 110, 15, WHITE);
    DrawText("Wait did you just say time travel?", nemo->NemoPosition.x - 162 , nemo->NemoPosition.y + 135, 15, WHITE);
    DrawText("By the way who are you?", nemo->NemoPosition.x - 162 , nemo->NemoPosition.y + 160, 15, WHITE);
    break;
  case 4:
    DrawText("Epanox", nemo->NemoPosition.x - 180 , nemo->NemoPosition.y + 75, 15, BLACK);
    DrawText("I'm Epanox a creature, that can travel through", nemo->NemoPosition.x - 162 , nemo->NemoPosition.y + 110, 15, WHITE);
    DrawText("time. Yes we are currently in ancient egypt, the", nemo->NemoPosition.x - 162 , nemo->NemoPosition.y + 135, 15, WHITE);
    DrawText("date is currently Monday 12.June 2470 BC.", nemo->NemoPosition.x - 162 , nemo->NemoPosition.y + 160, 15, WHITE);
    break;
  case 5:
    DrawText("Nemo", nemo->NemoPosition.x - 180 , nemo->NemoPosition.y + 75, 15, BLACK);
    DrawText("Let me get this straight. I've travelled to ancient ", nemo->NemoPosition.x - 162 , nemo->NemoPosition.y + 110, 15, WHITE);
    DrawText("Egypt and you are a time creature of some sorts? ", nemo->NemoPosition.x - 162 , nemo->NemoPosition.y + 135, 15, WHITE);
    DrawText("Does that mean you can send me back home?", nemo->NemoPosition.x - 162 , nemo->NemoPosition.y + 160, 15, WHITE);
    break;
  case 6:
    DrawText("Epanox", nemo->NemoPosition.x - 180 , nemo->NemoPosition.y + 75, 15, BLACK);
    DrawText("I'm a creature that travels through time... alone.", nemo->NemoPosition.x - 162 , nemo->NemoPosition.y + 110, 15, WHITE);
    DrawText("So no... I can't get you back. But I do ", nemo->NemoPosition.x - 162 , nemo->NemoPosition.y + 135, 15, WHITE);
    DrawText("know how you might get home... wanna know?", nemo->NemoPosition.x - 162 , nemo->NemoPosition.y + 160, 15, WHITE);
    break;
  case 7:
    DrawText("Nemo", nemo->NemoPosition.x - 180 , nemo->NemoPosition.y + 75, 15, BLACK);
    DrawText("Yes please, I can't wait to get back home.", nemo->NemoPosition.x - 162 , nemo->NemoPosition.y + 110, 15, WHITE);
    break;
  case 8:
    DrawText("Epanox", nemo->NemoPosition.x - 180 , nemo->NemoPosition.y + 75, 15, BLACK);
    DrawText("Alright, there's a Time Crystal in that Pyramid.", nemo->NemoPosition.x - 162 , nemo->NemoPosition.y + 110, 15, WHITE);
    DrawText("These Time Crystals allow one to travel through ", nemo->NemoPosition.x - 162 , nemo->NemoPosition.y + 135, 15, WHITE);
    DrawText("time. I'd say it's your best bet to getting home.", nemo->NemoPosition.x - 162 , nemo->NemoPosition.y + 160, 15, WHITE);
    break;
  case 9:
    DrawText("Nemo", nemo->NemoPosition.x - 180 , nemo->NemoPosition.y + 75, 15, BLACK);
    DrawText("Ok, I see... then I'll just get the Time Crystal and ", nemo->NemoPosition.x - 162 , nemo->NemoPosition.y + 110, 15, WHITE);
    DrawText("poof I'm back home. Cheers thanks for the help.", nemo->NemoPosition.x - 162 , nemo->NemoPosition.y + 135, 15, WHITE);
    break;
  case 10:
    DrawText("Epanox", nemo->NemoPosition.x - 180 , nemo->NemoPosition.y + 75, 15, BLACK);
    DrawText("Before you go let me warn you... ", nemo->NemoPosition.x - 162 , nemo->NemoPosition.y + 110, 15, WHITE);
    DrawText("there might be Monsters in there.", nemo->NemoPosition.x - 162 , nemo->NemoPosition.y + 135, 15, WHITE);
    DrawText("Be careful, and safe travels.", nemo->NemoPosition.x - 162 , nemo->NemoPosition.y + 160, 15, WHITE);
    break;
  case 11:
    DrawText("Nemo", nemo->NemoPosition.x - 180 , nemo->NemoPosition.y + 75, 15, BLACK);
    DrawText("No need to worry I'm built tough! ", nemo->NemoPosition.x - 162 , nemo->NemoPosition.y + 110, 15, WHITE);
    break;
  case 12: textState = 1;
    text = false;
    break;
  }
}