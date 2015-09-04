#include "level.h"

using namespace std;

Level:: Level(ifstream &file, Player* pl)
{
    p = pl;
    // default size specs
    width = 79;
    height = 25;
    display = new char *[height];

    for(int i =0; i<height; i++)
    {
        display[i] = new char[width];
        if(!file.eof()) // Reads in from a file and stores the strings into the 2-D array
        {
            string s;
            getline(file, s);
            for(int j =0; j<width; j++)
            {
                display[i][j] = s[j];
            }
        }
    }

    c1 = new Chamber(26,4);
    c2 = new Chamber(37,10);

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 37; j++) {
            if(i == 0 && j >= 23) {
                delete c2->layout[i][j];
                c2->layout[i][j] = NULL;
                c2->display[i][j] = ' ';
            }
            else if(i == 1 && j >= 23) {
                delete c2->layout[i][j];
                c2->layout[i][j] = NULL;
                c2->display[i][j] = ' ';
            }
            else if(i == 2 && j >= 31) {
                delete c2->layout[i][j];
                c2->layout[i][j] = NULL;
                c2->display[i][j] = ' ';
            }
            else if(i == 3 && j >= 34) {
                delete c2->layout[i][j];
                c2->layout[i][j] = NULL;
                c2->display[i][j] = ' ';
            }
            else if(i > 3 &&j <= 21) {
                delete c2->layout[i][j];
                c2->layout[i][j] = NULL;
                c2->display[i][j] = ' ';
            }
        }
    }

    c3 = new Chamber(12, 3);
    c4 = new Chamber(21, 7);
    c5 = new Chamber(39, 6);

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 28; j++)
        {
            delete c5->layout[i][j];
            c5->layout[i][j] = NULL;
            c5->display[i][j] = ' ';
        }
    }

}

// contructor for text files not default
Level:: Level(Player* pl, char ** ch)
{
    p = pl;
    // default size specs
    width = 79;
    height = 25;

    display = new char *[height];

    for(int i = 0; i<height; i++)
    {
        display[i] = new char[width];

        for(int j =0; j<width; j++)
        {
            display[i][j] = ch[i][j];
        }
    }

    c1 = new Chamber(display, p, 3, 3, 26,4);
    c2 = new Chamber(display, p, 39, 3, 37,10);

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 37; j++) {
            if(i == 0 && j >= 23) {
                delete c2->layout[i][j];
                c2->layout[i][j] = NULL;
                c2->display[i][j] = ' ';
            }
            else if(i == 1 && j >= 23) {
                delete c2->layout[i][j];
                c2->layout[i][j] = NULL;
                c2->display[i][j] = ' ';
            }
            else if(i == 2 && j >= 31) {
                delete c2->layout[i][j];
                c2->layout[i][j] = NULL;
                c2->display[i][j] = ' ';
            }
            else if(i == 3 && j >= 34) {
                delete c2->layout[i][j];
                c2->layout[i][j] = NULL;
                c2->display[i][j] = ' ';
            }
            else if(i > 3 &&j <= 21) {
                delete c2->layout[i][j];
                c2->layout[i][j] = NULL;
                c2->display[i][j] = ' ';
            }
        }
    }

    c3 = new Chamber(display, p, 38 ,10, 12, 3);
    c4 = new Chamber(display, p, 4, 15, 21, 7);
    c5 = new Chamber(display, p, 37, 16, 39, 6);

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 28; j++)
        {
            delete c5->layout[i][j];
            c5->layout[i][j] = NULL;
            c5->display[i][j] = ' ';
        }
    }
}

Level:: ~Level()
{
    for(int i = 0; i < height; i++)
    {
        delete [] display[i];
    }
    delete [] display;
    delete c1;
    delete c2;
    delete c3;
    delete c4;
    delete c5;
};

Player * Level:: getPlayer()
{
    return p;
}

void Level:: print() // Prints out the 2-D array
{
    //Dave added this, remove if incorrect
    //Chamber 1
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 26; j++) {
            display[i+3][j+3] = c1->display[i][j];
        }
    }
    //Fucking Chamber 2
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 37; j++) {
            if(i == 0 && j < 23) {
                display[i+3][j+39] = c2->display[i][j];
            }
            if(i == 1 && j < 23) {
                display[i+3][j+39] = c2->display[i][j];
            }
            if(i == 2 && j < 31) {
                display[i+3][j+39] = c2->display[i][j];
            }
            if(i == 3 && j < 34) {
                display[i+3][j+39] = c2->display[i][j];
            }
            if(i > 3 && j > 21) {
                display[i+3][j+39] = c2->display[i][j];
            }
        }
    }
    //Chamber 3
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 12; j++) {
            display[i+10][j+38] = c3->display[i][j];
        }
    }
    //Chamber 4
    for(int i = 0; i < 7; i++) {
        for(int j = 0; j < 21; j++) {
            display[i+15][j+4] = c4->display[i][j];
        }
    }
    //Fucking Chamber 5
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 39; j++) {
            if(i < 3 && j > 27) {
                display[i+16][j+37] = c5->display[i][j];
            }
            if(i >=3) {
                display[i+16][j+37] = c5->display[i][j];
            }
        }
    }
    for(int i =0; i<height; i++)
    {
        for(int j =0; j<width; j++)
        {
            cout << display[i][j];
        }
        cout << endl;
    }

}

void Level::updatePlayer() {
    int pgold = 0;
    int patk = 0;
    int pdef = 0;
    int php = 0;
    string paction = p->getAction();
    if(p->getChamberNum() == 1) {
        pgold = c1->layout[p->getY()][p->getX()]->getGold() - p->getGold();
        patk = c1->layout[p->getY()][p->getX()]->getATK() - p->getATK();
        pdef = c1->layout[p->getY()][p->getX()]->getDEF() - p->getDEF();
        php = c1->layout[p->getY()][p->getX()]->getHP() - p->getHP();
        paction = c1->layout[p->getY()][p->getX()]->getAction();
        c1->layout[p->getY()][p->getX()]->setAction("");
    }
    if(p->getChamberNum() == 2) {
        pgold = c2->layout[p->getY()][p->getX()]->getGold() - p->getGold();
        patk = c2->layout[p->getY()][p->getX()]->getATK() - p->getATK();
        pdef = c2->layout[p->getY()][p->getX()]->getDEF() - p->getDEF();
        php = c2->layout[p->getY()][p->getX()]->getHP() - p->getHP();
        paction = c2->layout[p->getY()][p->getX()]->getAction();
        c2->layout[p->getY()][p->getX()]->setAction("");
    }
    if(p->getChamberNum() == 3) {
        pgold = c3->layout[p->getY()][p->getX()]->getGold() - p->getGold();
        patk = c3->layout[p->getY()][p->getX()]->getATK() - p->getATK();
        pdef = c3->layout[p->getY()][p->getX()]->getDEF() - p->getDEF();
        php = c3->layout[p->getY()][p->getX()]->getHP() - p->getHP();
        paction = c3->layout[p->getY()][p->getX()]->getAction();
        c3->layout[p->getY()][p->getX()]->setAction("");
    }
    if(p->getChamberNum() == 4) {
        pgold = c4->layout[p->getY()][p->getX()]->getGold() - p->getGold();
        patk = c4->layout[p->getY()][p->getX()]->getATK() - p->getATK();
        pdef = c4->layout[p->getY()][p->getX()]->getDEF() - p->getDEF();
        php = c4->layout[p->getY()][p->getX()]->getHP() - p->getHP();
        paction = c4->layout[p->getY()][p->getX()]->getAction();
        c4->layout[p->getY()][p->getX()]->setAction("");
    }
    if(p->getChamberNum() == 5) {
        pgold = c5->layout[p->getY()][p->getX()]->getGold() - p->getGold();
        patk = c5->layout[p->getY()][p->getX()]->getATK() - p->getATK();
        pdef = c5->layout[p->getY()][p->getX()]->getDEF() - p->getDEF();
        php = c5->layout[p->getY()][p->getX()]->getHP() - p->getHP();
        paction = c5->layout[p->getY()][p->getX()]->getAction();
        c5->layout[p->getY()][p->getX()]->setAction("");
    }
    p->addGold(pgold);
    p->changeATK(patk);
    p->changeDEF(pdef);
    p->changeHP(php);
    p->setAction(paction);
}

void Level::tick()
{
    c1->tick();
//cout << "C1 WORKS" << endl;
    c2->tick();
//cout << "C2 WORKS" << endl;
    c3->tick();
//cout << "C3 WORKS" << endl;
    c4->tick();
//cout << "C4 WORKS" << endl;
    c5->tick();
//cout << "C5 WORKS" << endl;
    updatePlayer();
}

// spawning for when default file is read
void Level::spawn()
{

// ********************************** PLAYER **********************************
    int which, nx, ny;
    which = rand() % 5 + 1;

    if(which == 1)
    {
        ny = rand() % 4;
        nx = rand() % 26;
        while(c1->display[ny][nx] != '.') {
            ny = rand()%4;
            nx = rand()%26;
        }
        p->setLX(nx+3);
        p->setLY(ny+3);
        c1->display[ny][nx] = '@';
        if(p->getType() == "human") {
            delete c1->layout[ny][nx];
            c1->layout[ny][nx] = new Human(nx,ny);
        }
        else if(p->getType() == "elf") {
            delete c1->layout[ny][nx];
            c1->layout[ny][nx] = new Elf(nx,ny);
        }
        else if(p->getType() == "dwarf") {
            delete c1->layout[ny][nx];
            c1->layout[ny][nx] = new Dwarf(nx,ny);
        }
        else {
            delete c1->layout[ny][nx];
            c1->layout[ny][nx] = new Orc(nx,ny);
        }
        c1->layout[ny][nx]->changeHP((int)(p->getHP() - c1->layout[ny][nx]->getHP()));
        c1->layout[ny][nx]->addGold(p->getGold());
    }
    else if(which == 2)
    {
        ny = rand() % 10;
        nx = rand() % 37;

        while(c2->display[ny][nx] != '.')
        {
            ny = rand() % 10;
            nx = rand() % 37;
        }
        p->setLY(ny+3);
        p->setLX(nx+39);
        c2->display[ny][nx] = '@';
        if(p->getType() == "human") {
            delete c2->layout[ny][nx];
            c2->layout[ny][nx] = new Human(nx,ny);
        }
        else if(p->getType() == "elf") {
            delete c2->layout[ny][nx];
            c2->layout[ny][nx] = new Elf(nx,ny);
        }
        else if(p->getType() == "dwarf") {
            delete c2->layout[ny][nx];
            c2->layout[ny][nx] = new Dwarf(nx,ny);
        }
        else {
            delete c2->layout[ny][nx];
            c2->layout[ny][nx] = new Orc(nx,ny);
        }
        c2->layout[ny][nx]->changeHP((int)(p->getHP() - c2->layout[ny][nx]->getHP()));
        c2->layout[ny][nx]->addGold(p->getGold());
    }
    else if(which == 3)
    {
        ny = rand() % 3;
        nx = rand() % 12;
        while(c3->display[ny][nx] != '.') {
            ny = rand() % 3;
            nx = rand() % 12;
        }
        p->setLY(ny+10);
        p->setLX(nx+38);
        c3->display[ny][nx] = '@';
        if(p->getType() == "human") {
            delete c3->layout[ny][nx];
            c3->layout[ny][nx] = new Human(nx,ny);
        }
        else if(p->getType() == "elf") {
            delete c3->layout[ny][nx];
            c3->layout[ny][nx] = new Elf(nx,ny);
        }
        else if(p->getType() == "dwarf") {
            delete c3->layout[ny][nx];
            c3->layout[ny][nx] = new Dwarf(nx,ny);
        }
        else {
            delete c3->layout[ny][nx];
            c3->layout[ny][nx] = new Orc(nx,ny);
        }
        c3->layout[ny][nx]->changeHP((int)(p->getHP() - c3->layout[ny][nx]->getHP()));
        c3->layout[ny][nx]->addGold(p->getGold());
    }
    else if(which == 4)
    {
        ny = rand() % 7;
        nx = rand() % 21;
        while(c4->display[ny][nx] != '.') {
            ny = rand() % 7;
            nx = rand() % 21;
        }
        p->setLY(ny+15);
        p->setLX(nx+4);
        c4->display[ny][nx] = '@';
        if(p->getType() == "human") {
            delete c4->layout[ny][nx];
            c4->layout[ny][nx] = new Human(nx,ny);
        }
        else if(p->getType() == "elf") {
            delete c4->layout[ny][nx];
            c4->layout[ny][nx] = new Elf(nx,ny);
        }
        else if(p->getType() == "dwarf") {
            delete c4->layout[ny][nx];
            c4->layout[ny][nx] = new Dwarf(nx,ny);
        }
        else {
            delete c4->layout[ny][nx];
            c4->layout[ny][nx] = new Orc(nx,ny);
        }
        c4->layout[ny][nx]->changeHP((int)(p->getHP() - c4->layout[ny][nx]->getHP()));
        c4->layout[ny][nx]->addGold(p->getGold());
    }
    else
    {
        ny = rand() % 6;
        nx = rand() % 39;
        while(c5->display[ny][nx] != '.')
        {
            ny = rand() % 6;
            nx = rand() % 39;
        }
        p->setLY(ny+16);
        p->setLX(nx+37);
        c5->display[ny][nx] = '@';
        if(p->getType() == "human") {
            delete c5->layout[ny][nx];
            c5->layout[ny][nx] = new Human(nx,ny);
        }
        else if(p->getType() == "elf") {
            delete c5->layout[ny][nx];
            c5->layout[ny][nx] = new Elf(nx,ny);
        }
        else if(p->getType() == "dwarf") {
            delete c5->layout[ny][nx];
            c5->layout[ny][nx] = new Dwarf(nx,ny);
        }
        else {
            delete c5->layout[ny][nx];
            c5->layout[ny][nx] = new Orc(nx,ny);
        }
        c5->layout[ny][nx]->changeHP((int)(p->getHP() - c5->layout[ny][nx]->getHP()));
        c5->layout[ny][nx]->addGold(p->getGold());
    }

    // Set default attributes of the player
    p->setChamberNum(which);
    p->setX(nx);
    p->setY(ny);
    p->setAction("The player character has spawned");
    p->setPosType("floortile");
    p->setInChamber(true);

// ******************************* STAIRS ********************************
    int stairswhich = rand() % 5 + 1;
    while(stairswhich == which) { //stairs cannot be in same chamber at player's starting chamber
        stairswhich = rand()%5 + 1;
    }
    if(stairswhich == 1)
    {
        ny = rand() % 4;
        nx = rand() % 26;
        while(c1->display[ny][nx] != '.') {
            ny = rand() %4;
            nx = rand() %26;
        }
        c1->display[ny][nx] = '\\';
        delete c1->layout[ny][nx];
        c1->layout[ny][nx] = new Stairs(nx,ny);
    }
    else if(stairswhich == 2) //fucking chamber 2 always has special cases
    {
        ny = rand() % 10;
        nx = rand() % 37;

        while(c2->display[ny][nx] == '|' || c2->display[ny][nx] != '.')
        {
            ny = rand() % 10;
            nx = rand() % 37;
        }
        c2->display[ny][nx] = '\\';
        delete c2->layout[ny][nx];
        c2->layout[ny][nx] = new Stairs(nx,ny);
    }
    else if(stairswhich == 3)
    {
        ny = rand() % 3;
        nx = rand() % 12;

        while(c3->display[ny][nx] != '.')
        {
            ny = rand() % 3;
            nx = rand() % 12;
        }

        c3->display[ny][nx] = '\\';
        delete c3->layout[ny][nx];
        c3->layout[ny][nx] = new Stairs(nx,ny);
    }
    else if(stairswhich == 4)
    {
        ny = rand() % 7;
        nx = rand() % 21;

        while(c4->display[ny][nx] != '.')
        {
            ny = rand() % 7;
            nx = rand() % 21;
        }

        c4->display[ny][nx] = '\\';
        delete c4->layout[ny][nx];
        c4->layout[ny][nx] = new Stairs(nx,ny);
    }
    else
    {
        ny = rand() % 6;
        nx = rand() % 39;

        while(c5->display[ny][nx] != '.')
        {
            ny = rand() % 6;
            nx = rand() % 39;
        }

        c5->display[ny][nx] = '\\';
        delete c5->layout[ny][nx];
        c5->layout[ny][nx] = new Stairs(nx,ny);
    }
// ***************************** POTIONS *********************************
    for(int count = 0; count < 10; count++) {
        int potionwhich = rand() % 6;
        which = rand() % 5 + 1;
        if(which == 1) {
            ny = rand() % 4;
            nx = rand() % 26;
            while(c1->display[ny][nx] != '.') {
                ny = rand() %4;
                nx = rand() %26;
            }
            if(potionwhich == 0) {
                delete c1->layout[ny][nx];
                c1->layout[ny][nx] = new Potion(nx,ny,"RH");
            }
            if(potionwhich == 1) {
                delete c1->layout[ny][nx];
                c1->layout[ny][nx] = new Potion(nx,ny,"BA");
            }
            if(potionwhich == 2) {
                delete c1->layout[ny][nx];
                c1->layout[ny][nx] = new Potion(nx,ny,"BD");
            }
            if(potionwhich == 3) {
                delete c1->layout[ny][nx];
                c1->layout[ny][nx] = new Potion(nx,ny,"PH");
            }
            if(potionwhich == 4) {
                delete c1->layout[ny][nx];
                c1->layout[ny][nx] = new Potion(nx,ny,"WA");
            }
            if(potionwhich == 5) {
                delete c1->layout[ny][nx];
                c1->layout[ny][nx] = new Potion(nx,ny,"WA");
            }
            c1->display[ny][nx] = 'P';
        }
        else if(which == 2) {
            ny = rand() % 10;
            nx = rand() % 37;
            while(c2->display[ny][nx] != '.') {
                ny = rand() %10;
                nx = rand() %37;
            }
            if(potionwhich == 0) {
                delete c2->layout[ny][nx];
                c2->layout[ny][nx] = new Potion(nx,ny,"RH");
            }
            if(potionwhich == 1) {
                delete c2->layout[ny][nx];
                c2->layout[ny][nx] = new Potion(nx,ny,"BA");
            }
            if(potionwhich == 2) {
                delete c2->layout[ny][nx];
                c2->layout[ny][nx] = new Potion(nx,ny,"BD");
            }
            if(potionwhich == 3) {
                delete c2->layout[ny][nx];
                c2->layout[ny][nx] = new Potion(nx,ny,"PH");
            }
            if(potionwhich == 4) {
                delete c2->layout[ny][nx];
                c2->layout[ny][nx] = new Potion(nx,ny,"WA");
            }
            if(potionwhich == 5) {
                delete c2->layout[ny][nx];
                c2->layout[ny][nx] = new Potion(nx,ny,"WA");
            }
            c2->display[ny][nx] = 'P';
        }
        else if(which == 3) {
            ny = rand() % 3;
            nx = rand() % 12;
            while(c3->display[ny][nx] != '.') {
                ny = rand() %3;
                nx = rand() %12;
            }
            if(potionwhich == 0) {
                delete c3->layout[ny][nx];
                c3->layout[ny][nx] = new Potion(nx,ny,"RH");
            }
            if(potionwhich == 1) {
                delete c3->layout[ny][nx];
                c3->layout[ny][nx] = new Potion(nx,ny,"BA");
            }
            if(potionwhich == 2) {
                delete c3->layout[ny][nx];
                c3->layout[ny][nx] = new Potion(nx,ny,"BD");
            }
            if(potionwhich == 3) {
                delete c3->layout[ny][nx];
                c3->layout[ny][nx] = new Potion(nx,ny,"PH");
            }
            if(potionwhich == 4) {
                delete c3->layout[ny][nx];
                c3->layout[ny][nx] = new Potion(nx,ny,"WA");
            }
            if(potionwhich == 5) {
                delete c3->layout[ny][nx];
                c3->layout[ny][nx] = new Potion(nx,ny,"WA");
            }
            c3->display[ny][nx] = 'P';
        }
        else if(which == 4) {
            ny = rand() % 7;
            nx = rand() % 21;
            while(c4->display[ny][nx] != '.') {
                ny = rand() %7;
                nx = rand() %21;
            }
            if(potionwhich == 0) {
                delete c4->layout[ny][nx];
                c4->layout[ny][nx] = new Potion(nx,ny,"RH");
            }
            if(potionwhich == 1) {
                delete c4->layout[ny][nx];
                c4->layout[ny][nx] = new Potion(nx,ny,"BA");
            }
            if(potionwhich == 2) {
                delete c4->layout[ny][nx];
                c4->layout[ny][nx] = new Potion(nx,ny,"BD");
            }
            if(potionwhich == 3) {
                delete c4->layout[ny][nx];
                c4->layout[ny][nx] = new Potion(nx,ny,"PH");
            }
            if(potionwhich == 4) {
                delete c4->layout[ny][nx];
                c4->layout[ny][nx] = new Potion(nx,ny,"WA");
            }
            if(potionwhich == 5) {
                delete c4->layout[ny][nx];
                c4->layout[ny][nx] = new Potion(nx,ny,"WA");
            }
            c4->display[ny][nx] = 'P';
        }
        else {
            ny = rand() % 6;
            nx = rand() % 39;
            while(c5->display[ny][nx] != '.') {
                ny = rand() %6;
                nx = rand() %39;
            }
            if(potionwhich == 0) {
                delete c5->layout[ny][nx];
                c5->layout[ny][nx] = new Potion(nx,ny,"RH");
            }
            if(potionwhich == 1) {
                delete c5->layout[ny][nx];
                c5->layout[ny][nx] = new Potion(nx,ny,"BA");
            }
            if(potionwhich == 2) {
                delete c5->layout[ny][nx];
                c5->layout[ny][nx] = new Potion(nx,ny,"BD");
            }
            if(potionwhich == 3) {
                delete c5->layout[ny][nx];
                c5->layout[ny][nx] = new Potion(nx,ny,"PH");
            }
            if(potionwhich == 4) {
                delete c5->layout[ny][nx];
                c5->layout[ny][nx] = new Potion(nx,ny,"WA");
            }
            if(potionwhich == 5) {
                delete c5->layout[ny][nx];
                c5->layout[ny][nx] = new Potion(nx,ny,"WA");
            }
            c5->display[ny][nx] = 'P';
        }
    }

// ********************* Gold **********************
    for(int count = 0; count < 10; count++) {
        which = rand() % 5 +1;
        int goldwhich = rand() % 8;
        if(which == 1) {
            ny = rand()%4;
            nx = rand()%26;
            while(c1->display[ny][nx] != '.') {
                ny = rand()%4;
                nx = rand()%26;
            }
            if(goldwhich < 5) {
                delete c1->layout[ny][nx];
                c1->layout[ny][nx] = new Gold(nx,ny,1);
                c1->display[ny][nx] = 'G';
            }
            else if(goldwhich < 7) {
                delete c1->layout[ny][nx];
                c1->layout[ny][nx] = new Gold(nx,ny,2);
                c1->display[ny][nx] = 'G';
            }
//      else if(goldwhich < 8) {
//        delete c1->layout[ny][nx];
//        c1->layout[ny][nx] = new DragonGold(nx,ny);
//        c1->display[ny][nx] = 'G';
//      }
        }
        if(which == 2) {
            ny = rand()%10;
            nx = rand()%37;
            while(c2->display[ny][nx] != '.') {
                ny = rand()%10;
                nx = rand()%37;
            }
            c2->display[ny][nx] = 'G';
            if(goldwhich < 5) {
                delete c2->layout[ny][nx];
                c2->layout[ny][nx] = new Gold(nx,ny,1);
            }
            else if(goldwhich < 7) {
                delete c2->layout[ny][nx];
                c2->layout[ny][nx] = new Gold(nx,ny,2);
            }
//      else if(goldwhich < 8) {
//        delete c2->layout[ny][nx];
//        c2->layout[ny][nx] = new DragonGold(nx,ny);
//      }
        }
        if(which == 3) {
            ny = rand()%3;
            nx = rand()%12;
            while(c3->display[ny][nx] != '.') {
                ny = rand()%3;
                nx = rand()%12;
            }
            c3->display[ny][nx] = 'G';
            if(goldwhich < 5) {
                delete c3->layout[ny][nx];
                c3->layout[ny][nx] = new Gold(nx,ny,1);
            }
            else if(goldwhich < 7) {
                delete c3->layout[ny][nx];
                c3->layout[ny][nx] = new Gold(nx,ny,2);
            }
//      else if(goldwhich < 8) {
//        delete c3->layout[ny][nx];
//        c3->layout[ny][nx] = new DragonGold(nx,ny);
//      }
        }
        if(which == 4) {
            ny = rand()%7;
            nx = rand()%21;
            while(c4->display[ny][nx] != '.') {
                ny = rand()%7;
                nx = rand()%21;
            }
            c4->display[ny][nx] = 'G';
            if(goldwhich < 5) {
                delete c4->layout[ny][nx];
                c4->layout[ny][nx] = new Gold(nx,ny,1);
            }
            else if(goldwhich < 7) {
                delete c4->layout[ny][nx];
                c4->layout[ny][nx] = new Gold(nx,ny,2);
            }
//      else if(goldwhich < 8) {
//        delete c4->layout[ny][nx];
//        c4->layout[ny][nx] = new DragonGold(nx,ny);
//    }
        }
        if(which == 5) {
            ny = rand()%6;
            nx = rand()%39;
            while(c5->display[ny][nx] != '.') {
                ny = rand()%6;
                nx = rand()%39;
            }
            c5->display[ny][nx] = 'G';
            if(goldwhich < 5) {
                delete c5->layout[ny][nx];
                c5->layout[ny][nx] = new Gold(nx,ny,1);
            }
            else if(goldwhich < 7) {
                delete c5->layout[ny][nx];
                c5->layout[ny][nx] = new Gold(nx,ny,2);
            }
//      else if(goldwhich < 8) {
//        delete c1->layout[ny][nx];
//        c1->layout[ny][nx] = new DragonGold(nx,ny);
//      }
        }
    }
// *********************** ENEMIES *************************
    for(int count = 0; count < 20; count++) {
        which = rand() % 5 + 1;
        int enemywhich  = rand() % 18;
        if(which == 1) {
            ny = rand() % 4;
            nx = rand() % 26;
            while(c1->display[ny][nx] != '.') {
                ny = rand() % 4;
                nx = rand() % 26;
            }
            if(enemywhich < 5) {
                delete c1->layout[ny][nx];
                c1->layout[ny][nx] = new Goblin(nx,ny);
                c1->display[ny][nx] = 'N';
            }
            else if(enemywhich < 9) {
                delete c1->layout[ny][nx];
                c1->layout[ny][nx] = new Werewolf(nx,ny);
                c1->display[ny][nx] = 'W';
            }
            else if(enemywhich < 12) {
                delete c1->layout[ny][nx];
                c1->layout[ny][nx] = new Vampire(nx,ny);
                c1->display[ny][nx] = 'V';
            }
            else if(enemywhich < 14) {
                delete c1->layout[ny][nx];
                c1->layout[ny][nx] = new Troll(nx,ny);
                c1->display[ny][nx] = 'T';
            }
            else if(enemywhich < 16) {
                delete c1->layout[ny][nx];
                c1->layout[ny][nx] = new Phoenix(nx,ny);
                c1->display[ny][nx] = 'X';
            }
            else if(enemywhich < 18) {
                delete c1->layout[ny][nx];
                c1->layout[ny][nx] = new Merchant(nx,ny);
                c1->display[ny][nx] = 'M';
            }
        }
        if(which == 2) {
            ny = rand() % 10;
            nx = rand() % 37;
            while(c2->display[ny][nx] != '.') {
                ny = rand() % 10;
                nx = rand() % 37;
            }
            if(enemywhich < 5) {
                delete c2->layout[ny][nx];
                c2->layout[ny][nx] = new Goblin(nx,ny);
                c2->display[ny][nx] = 'N';
            }
            else if(enemywhich < 9) {
                delete c2->layout[ny][nx];
                c2->layout[ny][nx] = new Werewolf(nx,ny);
                c2->display[ny][nx] = 'W';
            }
            else if(enemywhich < 12) {
                delete c2->layout[ny][nx];
                c2->layout[ny][nx] = new Vampire(nx,ny);
                c2->display[ny][nx] = 'V';
            }
            else if(enemywhich < 14) {
                delete c2->layout[ny][nx];
                c2->layout[ny][nx] = new Troll(nx,ny);
                c2->display[ny][nx] = 'T';
            }
            else if(enemywhich < 16) {
                delete c2->layout[ny][nx];
                c2->layout[ny][nx] = new Phoenix(nx,ny);
                c2->display[ny][nx] = 'X';
            }
            else if(enemywhich < 18) {
                delete c2->layout[ny][nx];
                c2->layout[ny][nx] = new Merchant(nx,ny);
                c2->display[ny][nx] = 'M';
            }
        }
        if(which == 3) {
            ny = rand() % 3;
            nx = rand() % 12;
            while(c3->display[ny][nx] != '.') {
                ny = rand() % 3;
                nx = rand() % 12;
            }
            if(enemywhich < 5) {
                delete c3->layout[ny][nx];
                c3->layout[ny][nx] = new Goblin(nx,ny);
                c3->display[ny][nx] = 'N';
            }
            else if(enemywhich < 9) {
                delete c3->layout[ny][nx];
                c3->layout[ny][nx] = new Werewolf(nx,ny);
                c3->display[ny][nx] = 'W';
            }
            else if(enemywhich < 12) {
                delete c3->layout[ny][nx];
                c3->layout[ny][nx] = new Vampire(nx,ny);
                c3->display[ny][nx] = 'V';
            }
            else if(enemywhich < 14) {
                delete c3->layout[ny][nx];
                c3->layout[ny][nx] = new Troll(nx,ny);
                c3->display[ny][nx] = 'T';
            }
            else if(enemywhich < 16) {
                delete c3->layout[ny][nx];
                c3->layout[ny][nx] = new Phoenix(nx,ny);
                c3->display[ny][nx] = 'X';
            }
            else if(enemywhich < 18) {
                delete c3->layout[ny][nx];
                c3->layout[ny][nx] = new Merchant(nx,ny);
                c3->display[ny][nx] = 'M';
            }
        }
        if(which == 4) {
            ny = rand() % 7;
            nx = rand() % 21;
            while(c4->display[ny][nx] != '.') {
                ny = rand() % 7;
                nx = rand() % 21;
            }
            if(enemywhich < 5) {
                delete c4->layout[ny][nx];
                c4->layout[ny][nx] = new Goblin(nx,ny);
                c4->display[ny][nx] = 'N';
            }
            else if(enemywhich < 9) {
                delete c4->layout[ny][nx];
                c4->layout[ny][nx] = new Werewolf(nx,ny);
                c4->display[ny][nx] = 'W';
            }
            else if(enemywhich < 12) {
                delete c4->layout[ny][nx];
                c4->layout[ny][nx] = new Vampire(nx,ny);
                c4->display[ny][nx] = 'V';
            }
            else if(enemywhich < 14) {
                delete c4->layout[ny][nx];
                c4->layout[ny][nx] = new Troll(nx,ny);
                c4->display[ny][nx] = 'T';
            }
            else if(enemywhich < 16) {
                delete c4->layout[ny][nx];
                c4->layout[ny][nx] = new Phoenix(nx,ny);
                c4->display[ny][nx] = 'X';
            }
            else if(enemywhich < 18) {
                delete c4->layout[ny][nx];
                c4->layout[ny][nx] = new Merchant(nx,ny);
                c4->display[ny][nx] = 'M';
            }
        }
        if(which == 5) {
            ny = rand() % 6;
            nx = rand() % 39;
            while(c5->display[ny][nx] != '.') {
                ny = rand() % 6;
                nx = rand() % 39;
            }
            if(enemywhich < 5) {
                delete c5->layout[ny][nx];
                c5->layout[ny][nx] = new Goblin(nx,ny);
                c5->display[ny][nx] = 'N';
            }
            else if(enemywhich < 9) {
                delete c5->layout[ny][nx];
                c5->layout[ny][nx] = new Werewolf(nx,ny);
                c5->display[ny][nx] = 'W';
            }
            else if(enemywhich < 12) {
                delete c5->layout[ny][nx];
                c5->layout[ny][nx] = new Vampire(nx,ny);
                c5->display[ny][nx] = 'V';
            }
            else if(enemywhich < 14) {
                delete c5->layout[ny][nx];
                c5->layout[ny][nx] = new Troll(nx,ny);
                c5->display[ny][nx] = 'T';
            }
            else if(enemywhich < 16) {
                delete c5->layout[ny][nx];
                c5->layout[ny][nx] = new Phoenix(nx,ny);
                c5->display[ny][nx] = 'X';
            }
            else if(enemywhich < 18) {
                delete c5->layout[ny][nx];
                c5->layout[ny][nx] = new Merchant(nx,ny);
                c5->display[ny][nx] = 'M';
            }
        }
    }
}

// Call in main function.
// Checks to see if the player is able to move in a given direction
bool Level::canPlayerMove(int dx, int dy)
{
    if((display[p->getLY() + dy][p->getLX() + dx] == '.') ||
            (display[p->getLY() + dy][p->getLX() + dx] == '+') ||
            (display[p->getLY() + dy][p->getLX() + dx] == '#') ||
            (display[p->getLY() + dy][p->getLX() + dx] == '\\'))
    {
        return true;
    }
    else if(display[p->getLY() + dy][p->getLX() + dx] == 'G')
    {
        if(p->getChamberNum() == 1)
        {
            return ((c1->layout[p->getY() + dy][p->getX() + dx]->getType() != "dragongold") ||
                    (c1->layout[p->getY() + dy][p->getX() + dx]->isDragonDead()));
        }
        else if(p->getChamberNum() == 2)
        {
            return ((c2->layout[p->getY() + dy][p->getX() + dx]->getType() != "dragongold") ||
                    (c2->layout[p->getY() + dy][p->getX() + dx]->isDragonDead()));
        }
        if(p->getChamberNum() == 3)
        {
            return ((c3->layout[p->getY() + dy][p->getX() + dx]->getType() != "dragongold") ||
                    (c3->layout[p->getY() + dy][p->getX() + dx]->isDragonDead()));
        }
        if(p->getChamberNum() == 4)
        {
            return ((c4->layout[p->getY() + dy][p->getX() + dx]->getType() != "dragongold") ||
                    (c4->layout[p->getY() + dy][p->getX() + dx]->isDragonDead()));
        }
        else
        {
            return ((c5->layout[p->getY() + dy][p->getX() + dx]->getType() != "dragongold") ||
                    (c5->layout[p->getY() + dy][p->getX() + dx]->isDragonDead()));
        }
    }
    else
    {
        return false;
    }
}
// Call in main function.
// Checks to see if the player is able to attack in a given direction
// Returns pointer to the enemy if it can attack, otherwise returns NULL
Enemy* Level::canPlayerAttack(int dx, int dy)
{
    int dpY = p->getY()+dy;
    int dpX = p->getX()+dx;
    if(display[p->getLY() + dy][p->getLX() + dx] == 'V' || display[p->getLY() + dy][p->getLX() + dx] == 'W' || display[p->getLY() + dy][p->getLX() + dx] == 'N' ||
            display[p->getLY() + dy][p->getLX() + dx] == 'M' || display[p->getLY() + dy][p->getLX() + dx] == 'D' || display[p->getLY() + dy][p->getLX() + dx] == 'X' ||
            display[p->getLY() + dy][p->getLX() + dx] == 'T') {
        if(p->getChamberNum() == 1) {
            if(dpY >= 0 && dpX >= 0 && dpY < c1->height && dpX < c1->width)
                return static_cast<Enemy*> (c1->layout[p->getY() + dy][p->getX() + dx]);
        }
        if(p->getChamberNum() == 2) {
            if(dpY >= 0 && dpX >= 0 && dpY < c2->height && dpX < c2->width)
                return static_cast<Enemy*> (c2->layout[p->getY() + dy][p->getX() + dx]);
        }
        if(p->getChamberNum() == 3) {
            if(dpY >= 0 && dpX >= 0 && dpY < c3->height && dpX < c3->width)
                return static_cast<Enemy*> (c3->layout[p->getY() + dy][p->getX() + dx]);
        }
        if(p->getChamberNum() == 4) {
            if(dpY >= 0 && dpX >= 0 && dpY < c4->height && dpX < c4->width)
                return static_cast<Enemy*> (c4->layout[p->getY() + dy][p->getX() + dx]);
        }
        if(p->getChamberNum() == 5) {
            if(dpY >= 0 && dpX >= 0 && dpY < c5->height && dpX < c5->width)
                return static_cast<Enemy*> (c5->layout[p->getY() + dy][p->getX() + dx]);
        }
    }
    return NULL;
}

// Call in main function.
// Checks to see if the player is able to use a potion in a given direction
// Returns pointer to the potion if it can attack, otherwise returns NULL
Potion* Level::canPlayerUse(int dx, int dy)
{
    int dpY = p->getY() + dy;
    int dpX = p->getX() + dx;
    if(dpY>= 0 && dpX >= 0) {
        if(display[p->getLY() + dy][p->getLX() + dx] == 'P') {
            if(p->getChamberNum() == 1) {
                if(dpY < c1->height && dpX < c1->width)
                    return static_cast<Potion*> (c1->layout[p->getY() + dy][p->getX() + dx]);
            }
            if(p->getChamberNum() == 2) {
                if(dpY < c2->height && dpX < c2->width)
                    return static_cast<Potion*> (c2->layout[p->getY() + dy][p->getX() + dx]);
            }
            if(p->getChamberNum() == 3) {
                if(dpY < c3->height && dpX < c3->width)
                    return static_cast<Potion*> (c3->layout[p->getY() + dy][p->getX() + dx]);
            }
            if(p->getChamberNum() == 4) {
                if(dpY < c4->height && dpX < c4->width)
                    return static_cast<Potion*> (c4->layout[p->getY() + dy][p->getX() + dx]);
            }
            if(p->getChamberNum() == 5) {
                if(dpY < c5->height && dpX < c5->width)
                    return static_cast<Potion*> (c5->layout[p->getY() + dy][p->getX() + dx]);
            }
        }
    }
    return NULL;
}


void Level::removePotion(Potion* pot) {
    int newX = pot->getX();
    int newY = pot->getY();
    int c = p->getChamberNum();
    if(c == 1) {
        c1->layout[newY][newX] = new Cell(newX,newY);
        c1->display[newY][newX] = '.';
    }
    if(c == 2) {
        c2->layout[newY][newX] = new Cell(newX,newY);
        c2->display[newY][newX] = '.';
    }
    if(c == 3) {
        c3->layout[newY][newX] = new Cell(newX,newY);
        c3->display[newY][newX] = '.';
    }
    if(c == 4) {
        c4->layout[newY][newX] = new Cell(newX,newY);
        c4->display[newY][newX] = '.';
    }
    if(c == 5) {
        c5->layout[newY][newX] = new Cell(newX,newY);
        c5->display[newY][newX] = '.';
    }
    updatePlayer();
}

// CALL IN MAIN FUNCTION. BE SURE TO CALL CANPLAYERMOVE BEFORE CALLING THIS
// Moves the player in the given direction
void Level:: movePlayer(int dx, int dy)
{
    int newX = p->getX() + dx;
    int newY = p->getY() + dy;
    int newLX = p->getLX() + dx;
    int newLY = p->getLY() + dy;
    int chamberNum = p->getChamberNum();
    Chamber * ch = new Chamber[5];

    ch[0] = *c1;
    ch[1] = *c2;
    ch[2] = *c3;
    ch[3] = *c4;
    ch[4] = *c5;

    Cell * c; // Temporary destination pointer

    if(display[newLY][newLX] == '\\')
    {
        cout << "STAIRS"<< endl;
        p->setPosType("stairs");
        return;
    }
    // If where the player is standing on and where the player wants to go is a floortile, switch the pointers
    if(p->getPosType() == "floortile" &&  display[newLY][newLX] == '.')
    {
        c = ch[chamberNum-1].layout[newY][newX];
        p->setInChamber(true);
        p->setPosType("floortile");
        ch[chamberNum-1].layout[newY][newX] = ch[chamberNum-1].layout[p->getY()][p->getX()]; // Assign the destination to point at the player
        ch[chamberNum-1].layout[p->getY()][p->getX()] = c; // Assign the old location to point at whatever was at the new destination
        ch[chamberNum-1].layout[newY][newX]->setX(newX);
        ch[chamberNum-1].layout[newY][newX]->setY(newY);
    }
    else if(p->getPosType() == "floortile" &&  display[newLY][newLX] == 'G')
    {
        c = ch[chamberNum-1].layout[newY][newX];
        p->setInChamber(true);
        p->setPosType("floortile");
        ch[chamberNum-1].layout[newY][newX] = ch[chamberNum-1].layout[p->getY()][p->getX()]; // Assign the destination to point at the player
        ch[chamberNum-1].layout[p->getY()][p->getX()] = c; // Assign the old location to point at whatever was at the new destination
        ch[chamberNum-1].layout[newY][newX]->setX(newX);
        ch[chamberNum-1].layout[newY][newX]->setY(newY);

        int newGold = ch[chamberNum-1].layout[p->getY()][p->getX()]->getAmount();
        // destroy the gold object and make a floortile to replace it
        delete ch[chamberNum-1].layout[p->getY()][p->getX()];
        ch[chamberNum-1].layout[p->getY()][p->getX()] = new Cell(p->getX(), p->getY());

        ch[p->getChamberNum() - 1].layout[newY][newX]->addGold(newGold);

        cout << "floortile to gold" << endl;
    }
    else if(p->getPosType() == "door" && display[newLY][newLX] == '#') // if current is door and destination is a passage
    {
        p->setPosType("passage");
        p->setInChamber(false);
        display[p->getLY()][p->getLX()] = '+';
        display[newLY][newLX] = '@';
    }
    else if(p->getPosType() == "door" && display[newLY][newLX] != '#') // if current is a door and destination is not a passage
    {
        // Determine which chamber the player is entering
        if(newLY <= 8 && newLX <= 29)
        {
            p->setChamberNum(1);
            //Determine the x and y coordinates relative to the chamber the player is entering
            // The coordinates are set so that p will have X and Y before the move is made,
            // and the move functions in main will update the X and Y -> more consistent
            if(newLX >= 26)
            {
                p->setX(26);
                p->setY(1);
            }
            else
            {
                p->setX(10);
                p->setY(4);
            }
        }
        else if(newLY >= 13 && newLX <= 27)
        {
            p->setChamberNum(4);
            if(newLX <= 15)
            {
                p->setX(9);
                p->setY(-1);
            }
            else
            {
                p->setX(21);
                p->setY(5);
            }
        }
        else if(newLY >= 14 && newLX >= 36)
        {
            p->setChamberNum(5);
            if(newLY <= 16)
            {
                p->setX(32);
                p->setY(-1);
            }
            else if(newLY <= 19)
            {
                p->setX(6);
                p->setY(2);
            }
            else
            {
                p->setX(-1);
                p->setY(4);
            }
        }
        else if(newLY >= 9 && newLY <= 13 && newLX >= 37 && newLX <= 50)
        {
            p->setChamberNum(3);
            if(newLY <= 11)
            {
                p->setX(5);
                p->setY(-1);
            }
            else
            {
                p->setX(5);
                p->setY(3);
            }
        }
        else
        {
            p->setChamberNum(2);
            if(newLY <= 8 && newLY >= 6)
            {
                p->setX(4);
                p->setY(4);
            }
            else if(newLY <= 8)
            {
                p->setX(-1);
                p->setY(1);
            }
            else if(newLX >= 65)
            {
                p->setX(30);
                p->setY(10);
            }
            else
            {
                p->setX(21);
                p->setY(8);
            }
        }
        newX = p->getX() + dx;
        newY = p->getY() + dy;

        int newGold = -1;
        if(display[newLY][newLX] == 'G') // if the destination is gold, is not a dragongold because canMove takes care of that
        {
            newGold = ch[p->getChamberNum() -1].layout[newY][newY]->getAmount();
            ch[p->getChamberNum() - 1].layout[newY][newX]->addGold(newGold); //update the gold amount of layout but not game
            delete ch[p->getChamberNum()-1].layout[newY][newX]; // delete the gold object
        }
        // create a new player in the destinationMBER" << p->getChamberNum() << endl;
//  cout << "CHAMBER: " << p->getChamberNum() << endl;
//   cout << "newY" << newY << endl;
//  cout << "newX" << newX << endl;
        if(p->getType() == "human")
        {
            ch[p->getChamberNum() - 1].layout[newY][newX] = new Human(newX, newY);
        }
        else if(p->getType() == "elf")
        {
            ch[p->getChamberNum() - 1].layout[newY][newX] = new Elf(newX, newY);
        }
        else if(p->getType() == "dwarf")
        {
            ch[p->getChamberNum() - 1].layout[newY][newX] = new Dwarf(newX, newY);
        }
        else
        {
            ch[p->getChamberNum() - 1].layout[newY][newX] = new Orc(newX, newY);
        }

        // copy the game player pointer's properties to the player on the layout
        // everything will be updated. Game pointer's gold is not updated if walking on gold, updatePlayer will handle this
        // since the pointer in layout is updated


        ch[p->getChamberNum() - 1].layout[newY][newX]->setX(newX);
        ch[p->getChamberNum() - 1].layout[newY][newX]->setY(newY);

        ch[p->getChamberNum() - 1].layout[newY][newX]->setType(p->getType());

        // ch[p->getChamberNum() - 1].layout[newY][newX]->setChamberNum(p->getChamberNum);
        ch[p->getChamberNum() - 1].layout[newY][newX]->changeHP(p->getHP() - ch[p->getChamberNum()-1].layout[newY][newX]->getHP());
        ch[p->getChamberNum() - 1].layout[newY][newX]->changeDEF(p->getDEF() - ch[p->getChamberNum()-1].layout[newY][newX]->getDEF());
        ch[p->getChamberNum() - 1].layout[newY][newX]->changeATK(p->getATK() - ch[p->getChamberNum()-1].layout[newY][newX]->getATK());

        //  ch[p->getChamberNum() - 1].layout[newY][newX] = p;
        if(newGold > -1)
            ch[p->getChamberNum() - 1].layout[newY][newX]->addGold(p->getGold() + newGold); // add the player's previous gold from game pointer and the new gold added from the object

        // update the game player pointer and display
        p->setPosType("floortile");
        p->setInChamber(true);
        display[p->getLY()][p->getLX()] = '+';
        display[newLY][newLX] = '@';

    }
    else if(p->getPosType() == "passage" && display[newLY][newLX] == '+') // if current is a passage and destination is a door
    {
        p->setPosType("door");
        p->setInChamber(false);
        display[p->getLY()][p->getLX()] = '#';
        display[newLY][newLX] = '@';
    }
    else if(p->getPosType() == "passage" && display[newLY][newLX] == '#') // if current is a passage and destination is a passage
    {
        p->setPosType("passage");
        p->setInChamber(false);
        display[p->getLY()][p->getLX()] = '#';
        display[newLY][newLX] = '@';
    }
    else if(p->getPosType() == "floortile" && display[newLY][newLX] == '+') // if current is a floortile and destination is a door
    {
        cout << "floortile to door" << endl;
        p->setPosType("door");
        p->setInChamber(false);
        // we are leaving a chamber, destruct the player object
        delete ch[chamberNum-1].layout[p->getY()][p->getX()];
        ch[chamberNum-1].layout[p->getY()][p->getX()] = new Cell(p->getY(), p->getX()); // replace it with a floortile
        p->setChamberNum(-1);
        display[p->getLY()][p->getLX()] = '.';
        display[newLY][newLX] = '@';
    }
    else
    {
        cout << "error" << endl;
    }
    /*
      // If not, construct a new type
      else
      {
        string newType = c->getType();
        delete ch[chamberNum-1].layout[newY][newX];
        ch[chamberNum-1].layout[newY][newX] = ch[chamberNum-1].layout[p->getY()][p->getX()];

        if(p->getPosType() == "floortile")
        {
          ch[chamberNum-1].layout[p->getY()][p->getX()] = new Cell(p->getY(), p->getX());
        }
        else
        {
          ch[chamberNum-1].layout[p->getY()][p->getX()] = new Passage(p->getY(), p->getX());
          if(p->getPosType() == "door")
          {
            ch[chamberNum-1].layout[p->getY()][p->getX()]->setDoor();
          }
        }
        p->setPosType(newType);
      }
    */

    /*
      p->setX(newX);
      p->setY(newY);
      p->setCX(p->getCX() + dx);
      p->setCY(p->getCY() + dy);
    */
}


