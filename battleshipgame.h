#include "board.h"
#include "ship.h"

using namespace std;

class battleshipGame 
{   
friend istream& operator>>(istream&, battleshipGame&);// overloaded operator
friend istream& getline(istream&, battleshipGame&);
friend ostream& operator<<(ostream&, const battleshipGame&);//overloaded operator


public:
battleshipGame();//contructor
~battleshipGame();//destructor
void introduction() const;//introduction. calls intro of board to give rules of the game
void initialize(int);// initialize... cals various functions from board to initialize ship size, ammo, hits, level, and board.
void difficulty();// sets the level of difficulty. set board structure depending on level of difficult. 8X8, or 10X10 .. etc
void theConsole();// shows the ammo available and hits accomplished
void thelist();//linkedlist... adds each coordinate entered and whether hit or miss..
int hits;// number of hits user has accomplished
int ammo;//number of ammo or retrys user has remaining.
int hity;

private:
board theBoard;//composition the board.
ship Submarine;//composition ship... declare a submarine of type ship
ship Destroyer;// same as above, of type ship
ship Carrier;// same as above, of type ship
};