#include "game.h"

using namespace std;

Game:: Game(char * fileName, bool isDefaultFile, string race)
{
    // set defaults when game starts
    currentLevel = 1;
    ifstream file(fileName, ifstream::in);
    playertype = race;
    if(playertype == "Human")
        p = new Human(0,0);
    else if(playertype == "Elf")
        p = new Elf(0,0);
    else if(playertype == "Dwarf")
        p = new Dwarf(0,0);
    else
        p = new Orc(0,0);

    isDefault = isDefaultFile;

    // generate different levels whether default file is read
    if(isDefault)
        level = new Level(file, p);
    else
    {
        levelArr = new Level*[8];
        fileCharArr = new char * [25];
        string s;
        for(int k = 0; k < 8; k ++)
        {
            for(int i = 0; i < 25; i++)
            {

                getline(file, s);

                fileCharArr[i] = new char[79];
                for(int j =0; j<79; j++)
                {
                    fileCharArr[i][j] = s[j]; // read in each line to the character arrays
                }
            }
            levelArr[k] = new Level(p, fileCharArr); // make levels based off of a 2-D char array
        }
    }

    this->generate();
}


void Game:: newLevel(char * fileName)
{
    currentLevel++;
    if(isDefault)
    {
        ifstream file(fileName, ifstream::in);
        level = new Level(file, p);
    }
    this->generate();
}

void Game:: print()
{
    if(isDefault)
    {
        level->print();
    }
    else
    {
        levelArr[currentLevel-1]->print();
    }
    cout << "Race: " << playertype << " Gold: " << p->getGold() << "		                                     Floor " << currentLevel << endl;
    cout << "HP: " << max(0,p->getHP()) << endl;
    cout << "Atk: " << p->getATK()  << endl;
    cout << "Def: " << p->getDEF() << endl;
    cout << "Action: " << p->getAction() << endl;
//  cout << "(X,Y): " << "(" << p->getX() << "," << p->getY() << ")" << endl;
//  cout << "(LX,LY): " << "(" << p->getLX() << "," << p->getLY() << ")" << endl;
//  cout << "Chamber: " << p->getChamberNum() << endl;
}

void Game:: generate()
{
    if(isDefault)
    {
        level->spawn();
    }
}

void Game:: tick()
{
    if(isDefault)
    {
        level->tick();
    }
    else
    {
        levelArr[currentLevel - 1]->tick();
    }
}

Game:: ~Game()
{
    delete p;
    delete level;

    delete [] levelArr;

}
