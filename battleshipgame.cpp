#include <iostream>
#include <iomanip>
#include "battleshipgame.h"

using namespace std;
bool empty = false;
int sent = 1;

battleshipGame::battleshipGame()
:Destroyer(4), Carrier(5) 
{                    
}

battleshipGame::~battleshipGame()
{
}

void battleshipGame::introduction() const
{
     //boardGame::introduction();
     cout << setw(77) <<  setfill('*') << endl;
     cout << setw(77) <<  '*' << endl;
     cout << setw(3) << '*' << ' ' << setw(69) << setfill(' ') << ' ' << setfill('*') << ' ' << setw(3) << '*' << endl;

     cout << setw(3) << '*' << ' ' << setw(30) << ' ';
     cout << "BATTLESHIP";
     cout << ' ' << setw(29) << ' ' << setw(3) << '*' << endl;

     cout << setw(3) << '*' << ' ' << setw(69) << setfill(' ') << ' ' << setfill('*') << ' ' << setw(3) << '*' << endl;
     cout << setw(77) <<  '*' << endl;
     cout << setw(3) << '*' << ' ' << setw(69) << setfill(' ') << ' ' << setfill('*') << ' ' << setw(3) << '*' << endl;
     theBoard.intro();
}

void battleshipGame::initialize(int lev)
{
     cout << "Intializing level: " << lev << ". It will commence shortly." << endl;
     
     theBoard.setBoard(lev);
     theBoard.initializeBoard();
     theBoard.populate();
     theBoard.setmunitions();//resets the trys and hits or, sets them to their regular numbers. hits=0, ammo=1
     
    while(sent != 0)
     {
     if(theBoard.placeship(Carrier.setx(),Carrier.sety(),Carrier.setHV(),Carrier.getsize(),lev,'C'))
     sent = 0;
     }
     cout << "Carrier initiated." << endl;
     sent = 1;

    while(sent !=0)
    {
     if(theBoard.placeship(Submarine.setx(),Submarine.sety(),Submarine.setHV(),Submarine.getsize(),lev,'S'))
     sent=0;
    }
     cout << "Submarine initiated." << endl;
     sent=1;
    
    while(sent !=0)
    {
     if(theBoard.placeship(Destroyer.setx(),Destroyer.sety(),Destroyer.setHV(),Destroyer.getsize(),lev,'D'))
     sent=0;
    }
     cout << "Destroyer initiated." << endl;
     sent=1;
     theConsole();
     theBoard.printBoard();
     theBoard.setfirst();
     theBoard.setlast();
     //theBoard.showActualBoard();
}

void battleshipGame::difficulty()
{
     cout << setw(3) << '*' << ' ' << setw(11) << ' ';
     cout << "Choose a number for the Level of Difficulty: ";
     cout << ' ' << setw(13) << ' ' << setw(3) << '*' << endl;
     
     cout << setw(3) << '*' << ' '<< setfill(' ') << setw(32) << ' ';
     cout << "1 Easy ";
     cout << setfill(' ') << setw(31) << ' ' << setfill('*') << setw(4) << ' ' << endl;
     
     cout << setw(3) << '*' << ' '<< setfill(' ') << setw(31) << ' ';
     cout << "2 Medium ";
     cout << setfill(' ') << setw(30) << ' ' << setfill('*') << setw(4) << ' ' << endl;
     
     cout << setw(3) << '*' << ' '<< setfill(' ') << setw(32) << ' ';
     cout << "3 Hard ";
     cout << setfill(' ') << setw(31) << ' ' << setfill('*') << setw(4) << ' ' << endl;
}

void battleshipGame::theConsole()
{
     hits = theBoard.returnhits();
     ammo = theBoard.returnammo();
     theBoard.theConsole();
}

istream& operator>>(istream& obj, battleshipGame& thisclass)
{

       obj >> thisclass.theBoard;
       return obj;
}

ostream& operator<<(ostream& objj, const battleshipGame& thisclass)
{
       objj << thisclass.theBoard;
      return objj;
}

void battleshipGame::thelist()
{
     theBoard.printlinkedlist();
}

