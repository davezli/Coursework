#include "chamber.h"

using namespace std;

Chamber:: Chamber() {} //defualt ctor

// Constructor for default level layout
Chamber:: Chamber(int w, int h)
{
    // Dimensions of the chamber
    width = w;
    height = h;
    display = new char * [height];
    layout = new Cell **[height];

    // Contruct the default text and cell array
    for(int i = 0; i < height; i++)
    {
        display[i] = new char[width];
        layout[i] = new Cell *[width];

        for(int j = 0; j < width; j++)
        {
            display[i][j] = '.'; // Default floortile text
            // Assign defualt values for cell
            layout[i][j] = new Cell(j,i);
        }
    }
}

// NOT FINISHED FOR OTHER CELLS
// Constructor for text files
Chamber:: Chamber(char ** c, Player * p, int shiftw, int shifth, int w, int h)
{
    // Dimensions of the chamber
    width = w;
    height = h;

    int countw = 0;
    int counth = 0;

    display = new char * [height];
    layout = new Cell ** [height];

    // Contruct the text array and cell array
    for(int i = shifth; i < height + shifth; i++)
    {
        display[counth] = new char[width];
        layout[counth] = new Cell*[width];

        for(int j = shiftw; j < width + shiftw; j++)
        {

            if(c[i][j] == '.') // if floortile
            {
                display[counth][countw] = c[i][j];
                layout[counth][countw] =  new Cell(j,i);
            }
            else if(c[i][j] == '\\') // if stairs
            {
                display[counth][countw] = c[i][j];
                delete layout[counth][countw];
                layout[counth][countw] =  new Stairs(j,i);
            }
            else if(c[i][j] == '@') // if player
            {
                display[counth][countw] =  c[i][j];
                delete layout[counth][countw];
                if(p->getRace() == "human")
                {
                    layout[counth][countw] = new Human(j,i);
                }
                else if(p->getRace() == "elf")
                {
                    layout[counth][countw] = new Elf(j,i);
                }
                else if(p->getRace() == "dwarf")
                {
                    layout[counth][countw] = new Dwarf(j,i);
                }
                else
                {
                    layout[counth][countw] = new Orc(j,i);
                }
            }

            else if(c[i][j] == 'V') // Vampire
            {
                display[counth][countw] = c[i][j];
                delete layout[counth][countw];
                layout[counth][countw] =  new Vampire(j,i);
            }
            else if(c[i][j] == 'W') // Werewolf
            {
                display[counth][countw] = c[i][j];
                delete layout[counth][countw];
                layout[counth][countw] =  new Werewolf(j,i);
            }
            else if(c[i][j] == 'N') // Goblin
            {
                display[counth][countw] = c[i][j];
                delete layout[counth][countw];
                layout[counth][countw] =  new Goblin(j,i);
            }
            else if(c[i][j] == 'M') // Merchant
            {
                display[counth][countw] = c[i][j];
                delete layout[counth][countw];
                layout[counth][countw] =  new Merchant(j,i);
            }
            else if(c[i][j] == 'D') // Dragon
            {
                display[counth][countw] = c[i][j];
                delete layout[counth][countw];
                layout[counth][countw] =  new Dragon(j,i);
            }
            else if(c[i][j] == 'X') // Phoenix
            {
                display[counth][countw] = c[i][j];
                delete layout[counth][countw];
                layout[counth][countw] =  new Phoenix(j,i);
            }
            else if(c[i][j] == 'T') // Troll
            {
                display[counth][countw] = c[i][j];
                delete layout[counth][countw];
                layout[counth][countw] =  new Troll(j,i);
            }
            else if(c[i][j] == 'G') // Gold
            {
                display[counth][countw] = c[i][j];
                delete layout[counth][countw];
                layout[counth][countw] =  new Gold(j,i,1);
            }
            else if(c[i][j] == 'P') // Potion
            {
                display[counth][countw] = c[i][j];
                delete layout[counth][countw];
                layout[counth][countw] =  new Potion(j,i, "BH");
            }

            countw++;
        }
        countw = 0;
        counth++;
    }
}

Chamber:: ~Chamber()
{
    for(int i = 0; i < height; i++)
    {
        for(int j =0; j < width; j++)
        {
            delete  layout[i][j];
        }
        delete [] layout[i];
        delete [] display[i];
    }

    delete [] layout;
    delete [] display;
}

Chamber & Chamber:: operator=(const Chamber &other)
{
    layout = other.layout;
    return *this;
}


// Prints out the character array for the chamber
void Chamber:: print()
{

    for(int i = 0; i< height; i++)
    {
        for(int j = 0; j<width; j++)
        {
            cout<<display[i][j];
        }
        cout<<endl;
    }

}

void Chamber::updateDisplay() {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            if(layout[i][j] != NULL) {
                if(layout[i][j]->getType() == "werewolf") display[i][j] = 'W';
                if(layout[i][j]->getType() == "vampire") display[i][j] = 'V';
                if(layout[i][j]->getType() == "troll") display[i][j] = 'T';
                if(layout[i][j]->getType() == "goblin") display[i][j] = 'N';
                if(layout[i][j]->getType() == "merchant") display[i][j] = 'M';
                if(layout[i][j]->getType() == "dragon") display[i][j] = 'D';
                if(layout[i][j]->getType() == "phoenix") display[i][j] = 'X';
                if(layout[i][j]->getType() == "human") display[i][j] = '@';
                if(layout[i][j]->getType() == "elf") display[i][j] = '@';
                if(layout[i][j]->getType() == "dwarf") display[i][j] = '@';
                if(layout[i][j]->getType() == "orc") display[i][j] = '@';
                if(layout[i][j]->getType() == "floortile") display[i][j] = '.';
                if(layout[i][j]->getType() == "stairs") display[i][j] = '\\';
                if(layout[i][j]->getType() == "passage") display[i][j] = '#';
                if(layout[i][j]->getType() == "door") display[i][j] = '+';
                if(layout[i][j]->getType() == "gold") display[i][j] = 'G';
                if(layout[i][j]->getType() == "dragongold") display[i][j] = 'G';
                if(layout[i][j]->getType() == "RH") display[i][j] = 'P';
                if(layout[i][j]->getType() == "BA") display[i][j] = 'P';
                if(layout[i][j]->getType() == "BD") display[i][j] = 'P';
                if(layout[i][j]->getType() == "PH") display[i][j] = 'P';
                if(layout[i][j]->getType() == "WA") display[i][j] = 'P';
                if(layout[i][j]->getType() == "WD") display[i][j] = 'P';
            }
        }
    }
}

void Chamber:: tick() {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            if(layout[i][j] != NULL)
            {
                if(layout[i][j]->getType() == "werewolf" || layout[i][j]->getType() == "vampire" || layout[i][j]->getType() == "goblin" ||
                        layout[i][j]->getType() == "troll" || layout[i][j]->getType() == "phoenix") {
                    if(layout[i][j]->look(layout, width, height) != NULL) { //If there's a player in attack range
                        if(layout[i][j]->getHP() <= 0) { //check if it's dead
                            int newX = j;
                            int newY = i;
                            layout[i][j]->look(layout, width, height)->addGold(1);
                            layout[i][j]->look(layout, width, height)->setAction(layout[i][j]->look(layout, width, height)->getAction() + " and killed it");
                            delete layout[i][j];
                            layout[i][j] = new Cell(newX, newY);
                        }
                    }
                }
                if(layout[i][j]->getType() == "merchant") {
                    if(layout[i][j]->look(layout, width, height) != NULL && (static_cast<Enemy*> (layout[i][j]))->checkMHostile()) { //If there's a player in attack range and merchants are hostile
                        if(layout[i][j]->getHP() <= 0) {
                            int newX = j;
                            int newY = i;
                            layout[i][j]->look(layout, width, height)->addGold(1);
                            layout[i][j]->look(layout, width, height)->setAction(layout[i][j]->look(layout, width, height)->getAction() + " and killed it");
                            delete layout[i][j];
                            layout[i][j] = new Gold(newX, newY, 4);
                        }
                    }
                }
            }
        }
    }

    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            if(layout[i][j] != NULL)
            {
                if(layout[i][j]->getType() == "werewolf" || layout[i][j]->getType() == "vampire" || layout[i][j]->getType() == "goblin" ||
                        layout[i][j]->getType() == "troll" || layout[i][j]->getType() == "phoenix") {
                    if(layout[i][j]->look(layout, width, height) != NULL) { //If there's a player in attack range
                        if(layout[i][j]->getHP() <= 0) { //check if it's dead
                            int newX = j;
                            int newY = i;
                            layout[i][j]->look(layout, width, height)->addGold(1); //give gold to the player
                            layout[i][j]->look(layout, width, height)->setAction(layout[i][j]->look(layout, width, height)->getAction() + " and killed it");
                            delete layout[i][j];
                            layout[i][j] = new Cell(newX, newY);
                        }
                        else {
                            layout[i][j]->attackPlayer(static_cast<Player*> (layout[i][j]->look(layout, width, height))); // attack it
                        }
                    }
                    else if(!(layout[i][j]->hasMoved())) {// otherwise, move if it hasn't this turn
                        layout[i][j]->moveRandom(layout, width, height);
                    }
                }
                if(layout[i][j]->getType() == "merchant") {
                    if(layout[i][j]->look(layout, width, height) != NULL && (static_cast<Enemy*> (layout[i][j]))->checkMHostile()) { //If there's a player in attack range and merchants are hostile
                        if(layout[i][j]->getHP() <= 0) {
                            int newX = j;
                            int newY = i;
                            layout[i][j]->look(layout, width, height)->addGold(1);
                            layout[i][j]->look(layout, width, height)->setAction(layout[i][j]->look(layout, width, height)->getAction() + " and killed it");
                            delete layout[i][j];
                            layout[i][j] = new Gold(newX, newY, 4);
                        }
                        else {
                            layout[i][j]->attackPlayer(static_cast<Player*> (layout[i][j]->look(layout, width, height))); // attack it
                        }
                    }
                    else if(!(layout[i][j]->hasMoved())) {// otherwise, move if it hasn't this turn
                        layout[i][j]->moveRandom(layout, width, height);
                    }
                }
            }
        }
    }
    updateDisplay();
    for(int i = 0; i < height; i++) { // Resets Moved boolean for next turn
        for(int j = 0; j < width; j++) {
            if(layout[i][j] != NULL)
            {
                if(layout[i][j]->getType() == "werewolf" || layout[i][j]->getType() == "vampire" || layout[i][j]->getType() == "goblin" ||
                        layout[i][j]->getType() == "troll" || layout[i][j]->getType() == "phoenix" || layout[i][j]->getType() == "merchant")
                    layout[i][j]->resetMoved();
            }
        }
    }
}

void Chamber:: spawn() {

}
