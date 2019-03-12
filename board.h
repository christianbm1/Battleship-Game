#include <string>

using namespace std;

class board
{
friend ostream& operator<<(ostream&, const board&);
friend istream& operator>>(istream&, board&);

public:
board();
~board();
void initializeBoard();//initiliaze board... make a two dymanic array board based on level of difficulty entered from battleshipgame class
void printBoard();// prints the board so user can see
void showActualBoard();// shows the actual board with the actual staionary boats.
void setBoard(int);//depending on level... sets board size.
void intro()const;// gives introduction and rules of the game
void populate(); // populates the board with * in all places.
bool placeship(int, int, int, int,int,char); // places ships on the board. prevents ships from overlapping
void checkhit(char,int);//checks whether the user entered coordinates are a hit or a miss.
void theConsole();// the ammo and hits
void dolinkedlist();// after every use input, it adds the coordinates to linked list, plus either hit or miss
void printlinkedlist();// prints linkedlist
void setfirst();//set the first pointer for linked list
void setlast();// set the last pointer for linked list
void setmunitions();// sets ammo/hs to their respective numbers. s when user wants to play again, these variables go back to beginning
int returnhits();//return hit. to battleshipgame hitunction
int returnammo();//return ammot.. to battleshipgame ammo function
int returnmiss();//either miss or hit... 1  or 2, for linkiedlist purposes

struct nodeType// linked list struct
{
char x;
int y;
int hom;       
nodeType* link;
};

protected:    
int diffXSetter;//the y ultimate value of boad size
int diffYSetter;// the x ultimate value of board size

private:
char **hhh;//the array that the user will see.
char **temp;// the array with the ships on the baord game... user will not see.
int ammo;
int hit;
int miss;
char hitx;//user input x coordinate
int hity;// user input y coordinate
nodeType *first;//pointeror linked list
nodeType *last;// pointer for linked list
nodeType *newnode;//pointer for linked list
};

