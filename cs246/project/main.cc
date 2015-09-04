#include "game.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;

Player* getLayoutPlayer(Game * g) {
    int n = g->p->getChamberNum();
    if(n == 1) return static_cast<Player*> (g->level->c1->layout[g->p->getY()][g->p->getX()]);
    if(n == 2) return static_cast<Player*> (g->level->c2->layout[g->p->getY()][g->p->getX()]);
    if(n == 3) return static_cast<Player*> (g->level->c3->layout[g->p->getY()][g->p->getX()]);
    if(n == 4) return static_cast<Player*> (g->level->c4->layout[g->p->getY()][g->p->getX()]);
    if(n == 5) return static_cast<Player*> (g->level->c5->layout[g->p->getY()][g->p->getX()]);
    return g->p;
}

void getLayoutLook(Game * g) {
    /*  int n = g->p->getChamberNum();

      if(n == 1) g->p->look(*(g->level->c1->layout),4,26);
      if(n == 2) g->p->look(*(g->level->c2->layout),10,37);
      if(n == 3) g->p->look(*(g->level->c3->layout),3,12);
      if(n == 4) g->p->look(*(g->level->c4->layout),7,21);
      if(n == 5) g->p->look(*(g->level->c5->layout),6 39);

      if(n == 1) static_cast<Player*> (g->level->c1->layout[g->p->getY()][g->p->getX()])->look(g->level->c1->layout,4,26);
      if(n == 2) static_cast<Player*> (g->level->c2->layout[g->p->getY()][g->p->getX()])->look(g->level->c2->layout,10,37);
      if(n == 3) static_cast<Player*> (g->level->c3->layout[g->p->getY()][g->p->getX()])->look(g->level->c3->layout,3,12);
      if(n == 4) static_cast<Player*> (g->level->c4->layout[g->p->getY()][g->p->getX()])->look(g->level->c4->layout,7,21);
      if(n == 5) static_cast<Player*> (g->level->c5->layout[g->p->getY()][g->p->getX()])->look(g->level->c5->layout,6,39);
    */
}

void printScreen(Game * g)
{
    cout << string(100, '\n' );
    g->print();
}

Game * newGame(char * fileName, bool isDefaultFile)
{
    char c;
    Game *g;

    cout << "Welcome adventurer to Chamber Crawler 3000!" << endl;
    cout << "Please choose a designating class" << endl;
    cout << "(h)uman      (e)lf     (d)warf       (o)rc" << endl;
    while(cin >> c)
    {
        if(c == 'h')
        {
            g = new Game(fileName, isDefaultFile, "Human");
            return g;
        }
        else if(c == 'e')
        {
            g = new Game(fileName, isDefaultFile, "Elf");
            return g;
        }
        else if(c == 'd')
        {
            g = new Game(fileName, isDefaultFile, "Dwarf");
            return g;
        }
        else if(c == 'o')
        {
            g = new Game(fileName, isDefaultFile, "Orc");
            return g;
        }
        else
        {
            cout << "Invalid command. Please choose from the commands listed." << endl;
            cout << "(h)uman      (e)lf     (d)warf       (o)rc" << endl;
        }
    }
    return NULL;
}

int main(int argc, char *argv[])
{
    srand(time(NULL)); //replace 1 with time(NULL) later
    string c;
    string file;
    bool defaultFile;
    if(argc == 2)
    {
        file = argv[1];
    }
    else
    {
        file = "levelTemplate.txt";
    }
    defaultFile = (file == "levelTemplate.txt");

    char * fileName = new char[file.length()];
    for(unsigned int i = 0; i< file.length(); i++)
    {
        fileName[i] = file[i];
    }
    Game *g = newGame(fileName, defaultFile);
    printScreen(g);
    while(cin >> c)
    {
        if(c == "q")
        {
            cout << "Are you sure? (y/n)" << endl;
            cin >> c;
            if(c == "y") {
                cout << "You have quit. Final score: " << g->p->getGold() << endl;
                break;
            }
            if(c == "n") {
                printScreen(g);
            }
        }
        else if(c == "r") {


            main(argc, argv);
            break;
        }
// *********************** MOVEMENT ***********************************
        if(c == "no" || c == "so" || c == "ea" || c == "we" ||
                c == "ne" || c == "nw" || c == "se" || c == "sw")
        {
            if(c == "no")
            {
                if(g->level->canPlayerMove(0, -1))
                {
                    getLayoutPlayer(g)->setAction("The player moved north");
                    g->level->movePlayer(0, -1);
                    g->p->moveUp();
                    getLayoutLook(g);
                }
            }
            else if(c == "so")
            {
                if(g->level->canPlayerMove(0, 1))
                {
                    getLayoutPlayer(g)->setAction("The player moved south");
                    g->level->movePlayer(0, 1);
                    g->p->moveDown();
                    getLayoutLook(g);

                }
            }
            else if(c == "ea")
            {
                if(g->level->canPlayerMove(1, 0))
                {
                    getLayoutPlayer(g)->setAction("The player moved east");
                    g->level->movePlayer(1,0);
                    g->p->moveRight();
                    getLayoutLook(g);
                }
            }
            else if(c == "we")
            {
                if(g->level->canPlayerMove(-1, 0))
                {
                    getLayoutPlayer(g)->setAction("The player moved west");
                    g->level->movePlayer(-1,0);
                    g->p->moveLeft();
                    getLayoutLook(g);
                }
            }
            else if(c == "ne")
            {
                if(g->level->canPlayerMove(1, -1))
                {
                    getLayoutPlayer(g)->setAction("The player moved northeast");
                    g->level->movePlayer(1, -1);
                    g->p->moveUp();
                    g->p->moveRight();
                    getLayoutLook(g);
                }
            }
            else if(c == "nw")
            {
                if(g->level->canPlayerMove(-1, -1))
                {
                    getLayoutPlayer(g)->setAction("The player moved northwest");
                    g->level->movePlayer(-1, -1);
                    g->p->moveUp();
                    g->p->moveLeft();
                    getLayoutLook(g);
                }
            }
            else if(c == "se")
            {
                if(g->level->canPlayerMove(1, 1))
                {
                    getLayoutPlayer(g)->setAction("The player moved southeast");
                    g->level->movePlayer(1, 1);
                    g->p->moveDown();
                    g->p->moveRight();
                    getLayoutLook(g);
                }
            }
            else
            {
                if(g->level->canPlayerMove(-1, 1))
                {
                    getLayoutPlayer(g)->setAction("The player moved southwest");
                    g->level->movePlayer(-1, 1);
                    g->p->moveDown();
                    g->p->moveLeft();
                    getLayoutLook(g);
                }
            }

            if(g->p->getPosType() != "stairs")
            {
                g->tick();
            }
            else
            {
                g->newLevel(fileName);
            }
            printScreen(g);
        }
// *********************** USE A POTION ***********************************
        else if(c == "u") {
            cout << "Use (no)rth, (so)uth, (ea)st, or (we)st?" << endl;
            cin >> c;
            if(c == "no") {
                if(g->level->canPlayerUse(0,-1) != NULL) {
                    g->p->setAction("The player used a potion to the north");
                    getLayoutPlayer(g)->usePotion(g->level->canPlayerUse(0,-1));
                    g->level->removePotion(g->level->canPlayerUse(0,-1));
                }
            }
            else if(c == "so") {
                if(g->level->canPlayerUse(0,1) != NULL) {
                    g->p->setAction("The player used a potion to the south");
                    getLayoutPlayer(g)->usePotion(g->level->canPlayerUse(0,1));
                    g->level->removePotion(g->level->canPlayerUse(0,1));
                }
            }
            else if(c == "ea") {
                if(g->level->canPlayerUse(1,0) != NULL) {
                    g->p->setAction("The player used a potion to the east");
                    getLayoutPlayer(g)->usePotion(g->level->canPlayerUse(1,0));
                    g->level->removePotion(g->level->canPlayerUse(1,0));
                }
            }
            else if(c == "we") {
                if(g->level->canPlayerUse(-1,0) != NULL) {
                    g->p->setAction("The player used a potion to the west");
                    getLayoutPlayer(g)->usePotion(g->level->canPlayerUse(-1,0));
                    g->level->removePotion(g->level->canPlayerUse(-1,0));
                }
            }
            else if(c == "ne") {
                if(g->level->canPlayerUse(1,-1) != NULL) {
                    g->p->setAction("The player used a potion to the northeast");
                    getLayoutPlayer(g)->usePotion(g->level->canPlayerUse(1,-1));
                    g->level->removePotion(g->level->canPlayerUse(1,-1));
                }
            }
            else if(c == "nw") {
                if(g->level->canPlayerUse(-1,-1) != NULL) {
                    g->p->setAction("The player used a potion to the northwest");
                    getLayoutPlayer(g)->usePotion(g->level->canPlayerUse(-1,-1));
                    g->level->removePotion(g->level->canPlayerUse(-1,-1));
                }
            }
            else if(c == "se") {
                if(g->level->canPlayerUse(1,1) != NULL) {
                    g->p->setAction("The player used a potion to the southeast");
                    getLayoutPlayer(g)->usePotion(g->level->canPlayerUse(1,1));
                    g->level->removePotion(g->level->canPlayerUse(1,1));
                }
            }
            else if(c == "sw") {
                if(g->level->canPlayerUse(-1,1) != NULL) {
                    g->p->setAction("The player used a potion to the southwest");
                    getLayoutPlayer(g)->usePotion(g->level->canPlayerUse(-1,1));
                    g->level->removePotion(g->level->canPlayerUse(-1,1));
                }
            }
            g->tick();
            printScreen(g);
        }
// *********************** ATTACK AN ENEMY ************************
        else if(c == "a") {
            cout << "Attack (no)rth, (so)uth, (ea)st, or (we)st?" << endl;
            cin >> c;
            if(c == "no") {
                if(g->level->canPlayerAttack(0,-1) != NULL) {
                    getLayoutPlayer(g)->setAction("The player attacked the enemy to the north");
                    getLayoutPlayer(g)->attackEnemy(g->level->canPlayerAttack(0,-1));
                }
            }
            if(c == "so") {
                if(g->level->canPlayerAttack(0,1) != NULL) {
                    getLayoutPlayer(g)->setAction("The player attacked the enemy to the south");
                    getLayoutPlayer(g)->attackEnemy(g->level->canPlayerAttack(0,1));
                }
            }
            if(c == "ea") {
                if(g->level->canPlayerAttack(1,0) != NULL) {
                    getLayoutPlayer(g)->setAction("The player attacked the enemy to the east");
                    getLayoutPlayer(g)->attackEnemy(g->level->canPlayerAttack(1,0));
                }
            }
            if(c == "we") {
                if(g->level->canPlayerAttack(-1,0) != NULL) {
                    getLayoutPlayer(g)->setAction("The player attacked the enemy to the west");
                    getLayoutPlayer(g)->attackEnemy(g->level->canPlayerAttack(-1,0));
                }
            }
            if(c == "ne") {
                if(g->level->canPlayerAttack(1,-1) != NULL) {
                    getLayoutPlayer(g)->setAction("The player attacked the enemy to the northeast");
                    getLayoutPlayer(g)->attackEnemy(g->level->canPlayerAttack(1,-1));
                }
            }
            if(c == "nw") {
                if(g->level->canPlayerAttack(-1,-1) != NULL) {
                    getLayoutPlayer(g)->setAction("The player attacked the enemy to the northwest");
                    getLayoutPlayer(g)->attackEnemy(g->level->canPlayerAttack(-1,-1));
                }
            }
            if(c == "se") {
                if(g->level->canPlayerAttack(1,1) != NULL) {
                    getLayoutPlayer(g)->setAction("The player attacked the enemy to the southeast");
                    getLayoutPlayer(g)->attackEnemy(g->level->canPlayerAttack(1,1));
                }
            }
            if(c == "sw") {
                if(g->level->canPlayerAttack(-1,1) != NULL) {
                    getLayoutPlayer(g)->setAction("The player attacked the enemy to the southwest");
                    getLayoutPlayer(g)->attackEnemy(g->level->canPlayerAttack(-1,1));
                }
            }
            g->tick();
            printScreen(g);
        }
        else if(c == "1") {
            g->p->setAction("Cheater! +1K HP");
            getLayoutPlayer(g)->changeHP(1000);
            printScreen(g);
        }
        else if(c == "2") {
            g->p->setAction("Cheater! +5 ATK");
            Potion *pot = new Potion(0,0,"WA");
            getLayoutPlayer(g)->usePotion(pot);
            //delete pot;
            printScreen(g);
        }
        else if(c == "3") {
            g->p->setAction("Nice Try! -5 DEF");
            Potion *pot = new Potion(0,0,"WD");
            getLayoutPlayer(g)->usePotion(pot);
            //delete pot;
            printScreen(g);
        }
        else {
            printScreen(g);
            cout << "Invalid Command. Please enter a valid command." << endl;
        }
        if(g->p->getHP() <= 0) {
            cout << "You have died. Final score: " << g->p->getGold() << endl;
            break;
        }
        cout << "(no)rth (so)uth (ea)st (we)st (a)ttack (u)se (q)uit (r)estart" << endl;
    }
    delete g;
    delete fileName;
}
