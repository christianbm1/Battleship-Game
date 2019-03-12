#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>
#include "battleshipgame.h"


using namespace std;

board::board()
{
diffXSetter = 0;
diffYSetter = 0;
}

board::~board()
{
delete [] *hhh;
delete [] *temp;
delete first;
delete last;
delete newnode;
}

void board::initializeBoard()
{
     hhh = new char* [diffYSetter+1];
     for(int row =0; row <= diffYSetter+1; row++)
     hhh[row] = new char[diffXSetter+1];
     
     temp = new char* [diffYSetter+1];
     for(int row =0; row <= diffYSetter+1; row++)
     temp[row] = new char[diffXSetter+1];
}

void board::populate()
{     
     for(int row = 0; row <= diffYSetter; row++)
      for(int col = 0; col <= diffXSetter; col++)
       hhh[row][col] = '*';
       
       for(int row = 0; row <= diffYSetter; row++)
      for(int col = 0; col <= diffXSetter; col++)
       temp[row][col] = ' ';
}

void board::printBoard()
{
     for(int row=0; row <=diffYSetter; row++)
     { 
             if(row == 0)
            { cout << ' ' << ' ' << "|";}
             else if (row > 0 && row < 10)
             {cout << " " << row << "|";}
             else 
             {cout << row << "|";}
      for(int col=1; col <= diffXSetter; col++)
      {
              if(row==0)
             { cout << " " << char(64+col) << ' ' << "|";}
              else
             { cout << ' ' << hhh[row][col] << ' ' << "|";}
      }
              cout << endl;        
     }
}

void board::showActualBoard()
{
     for(int row=0; row <=diffYSetter; row++)
     { 
             if(row == 0)
            { cout << ' ' << ' ' << "|";}
             else if (row > 0 && row < 10)
             {cout << " " << row << "|";}
             else 
             {cout << row << "|";}
      for(int col=1; col <= diffXSetter; col++)
      {
              if(row==0)
             { cout << " " << char(64+col) << ' ' << "|";}
              if(row>0)
             { cout << ' ' << temp[row][col] << ' ' << "|";}
      }
              cout << endl; 
}
}

void board::setBoard(int level)
{
    if(level == 1)
    {
    diffXSetter = 8;
    diffYSetter = 8;
}
    if (level == 2)
      {
    diffXSetter = 10;
    diffYSetter = 10;
}
    if (level == 3)
      {
    diffXSetter = 12;
    diffYSetter = 12;
}
}

void board::intro() const
{
cout << setw(3) << '*' << ' ' << setw(69) << setfill(' ') << ' ' << setfill('*') << ' ' << setw(3) << '*' << endl;

cout << setw(3) << '*' << ' ' << setw(24) << ' ';
cout << "BATTLESHIP GAME RULES";
cout << ' ' << setw(24) << ' ' << setw(3) << '*' << endl;

cout << setw(3) << '*' << ' ' << setw(69) << setfill(' ') << ' ' << setfill('*') << ' ' << setw(3) << '*' << endl;
cout << setw(3) << '*' << ' '<< setfill(' ') << setw(16) << ' ';
cout << "Each game will have at least 3 ships. ";
cout << setfill(' ') << setw(16) << ' ' << setfill('*') << setw(4) << ' ' << endl;
cout << setw(3) << '*' << ' '<< setfill(' ') << setw(11) << ' ';
cout << "There are 3 distinct ships out at sea. They are: ";
cout << setfill(' ') << setw(10) << ' ' << setfill('*') << setw(4) << ' ' << endl;
cout << setw(3) << '*' << ' ' << setw(69) << setfill(' ') << ' ' << setfill('*') << ' ' << setw(3) << '*' << endl;

cout << setw(3) << '*' << ' '<< setfill(' ') << setw(30) << ' ';
cout << "Submarine ";
cout << setfill(' ') << setw(30) << ' ' << setfill('*') << setw(4) << ' ' << endl;
cout << setw(3) << '*' << ' ' << setw(69) << setfill(' ') << ' ' << setfill('*') << ' ' << setw(3) << '*' << endl;
cout << setw(3) << '*' << ' '<< setfill(' ') << setw(18) << ' ';
cout << "The Submarine's size is 3 squares. ";
cout << setfill(' ') << setw(17) << ' ' << setfill('*') << setw(4) << ' ' << endl;
cout << setw(3) << '*' << ' '<< setfill(' ') << setw(7) << ' ';
cout << "Because of its size";
cout << " the submarine is stealthy and lethal.";
cout << setfill(' ') << setw(6) << ' ' << setfill('*') << setw(4) << ' ' << endl;
cout << setw(3) << '*' << ' ' << setw(69) << setfill(' ') << ' ' << setfill('*') << ' ' << setw(3) << '*' << endl;


cout << setw(3) << '*' << ' '<< setfill(' ') << setw(30) << ' ';
cout << "Destroyer ";
cout << setfill(' ') << setw(30) << ' ' << setfill('*') << setw(4) << ' ' << endl;
cout << setw(3) << '*' << ' ' << setw(69) << setfill(' ') << ' ' << setfill('*') << ' ' << setw(3) << '*' << endl;
cout << setw(3) << '*' << ' '<< setfill(' ') << setw(17) << ' ';
cout << "The Destroyer's size is 4 squares. ";
cout << setfill(' ') << setw(18) << ' ' << setfill('*') << setw(4) << ' ' << endl;
cout << setw(3) << '*' << ' '<< setfill(' ') << setw(12) << ' ';
cout << "Beware of the destoyer's mighty firepower. ";
cout << setfill(' ') << setw(15) << ' ' << setfill('*') << setw(4) << ' ' << endl;
cout << setw(3) << '*' << ' ' << setw(69) << setfill(' ') << ' ' << setfill('*') << ' ' << setw(3) << '*' << endl;

cout << setw(3) << '*' << ' '<< setfill(' ') << setw(31) << ' ';
cout << "Carrier ";
cout << setfill(' ') << setw(31) << ' ' << setfill('*') << setw(4) << ' ' << endl;
cout << setw(3) << '*' << ' ' << setw(69) << setfill(' ') << ' ' << setfill('*') << ' ' << setw(3) << '*' << endl;
cout << setw(3) << '*' << ' '<< setfill(' ') << setw(19) << ' ';
cout << "The Carrier takes on 5 squares. ";
cout << setfill(' ') << setw(19) << ' ' << setfill('*') << setw(4) << ' ' << endl;
cout << setw(3) << '*' << ' '<< setfill(' ') << setw(18) << ' ';
cout << "It is the biggest ship out at sea. ";
cout << setfill(' ') << setw(17) << ' ' << setfill('*') << setw(4) << ' ' << endl;
cout << setw(3) << '*' << ' '<< setfill(' ') << setw(15) << ' ';
cout << "Therefore, if shouldn't be hard to spot!";
cout << setfill(' ') << setw(15) << ' ' << setfill('*') << setw(4) << ' ' << endl;
cout << setw(3) << '*' << ' ' << setw(69) << setfill(' ') << ' ' << setfill('*') << ' ' << setw(3) << '*' << endl;

cout << setw(77) <<  '*' << endl;
cout << setw(3) << '*' << ' ' << setw(69) << setfill(' ') << ' ' << setfill('*') << ' ' << setw(3) << '*' << endl;
cout << setw(3) << '*' << ' '<< setfill(' ') << setw(2) << ' ';
cout << "Remember, the ships positions are either horizontal or vertical. ";
cout << setfill(' ') << setw(3) << ' ' << setfill('*') << setw(4) << ' ' << endl;
cout << setw(3) << '*' << ' '<< setfill(' ') << setw(19) << ' ';
cout << "Their menuaveurs are stationary.";
cout << setfill(' ') << setw(19) << ' ' << setfill('*') << setw(4) << ' ' << endl;
cout << setw(3) << '*' << ' '<< setfill(' ') << setw(22) << ' ';
cout << "% MEANS YOU HAVE HIT SEA.";
cout << setfill(' ') << setw(23) << ' ' << setfill('*') << setw(4) << ' ' << endl;
cout << setw(3) << '*' << ' '<< setfill(' ') << setw(15) << ' ';
cout << "You have 20 attempts to hit all targets!";
cout << setfill(' ') << setw(15) << ' ' << setfill('*') << setw(4) << ' ' << endl;
cout << setw(3) << '*' << ' ' << setw(69) << setfill(' ') << ' ' << setfill('*') << ' ' << setw(3) << '*' << endl;
cout << setw(3) << '*' << ' '<< setfill('*') << setw(25) << ' ';
cout << "Good Luck, Captain! "; 
cout << setfill('*') << setw(25) << ' ' << setfill('*') << setw(4) << ' ' << endl << endl;
}

bool board::placeship(int x, int y, int dir, int size,int lvl,char t)
{
     int i, p,row,col,bsize;
     row=x;
     col=y;
     if(lvl == 1)
     {
            bsize = 8;
     }
        else if(lvl == 2)
        {

            bsize = 10;
        }
            else
            {
                bsize = 12;
            }
            
            if(row<0 || row> bsize || col >= bsize)
            {
                return false;
            }
            if(dir == 1)
            {
                if(row + size>= bsize)
                {
                    return false;
                }
                for(int i = row; i <row+size;i++)
                {
                    if(temp[i][col] != ' ')
                    {
                        return false;
                    }
                }
                for(int i = row; i<row+size;i++)
                {
                    temp[i][col]=t;
                }
            }
            else if(dir == 2)
            {
                if(col+size>=bsize)
                {
                    return false;
                }
                for(int j = col; j<col+size;j++)
                {
                    if(temp[row][j] != ' ')
                    {
                        return false;
                    }
                }
                for(int j = col; j<col+size;j++)
                {
                    temp[row][j]=t;
                }
            }
            return true;
        }

void board::checkhit(char x, int y)
{
     x = toupper(x);
     if(temp[y][static_cast<int>(x-64)] == 'S'||temp[y][static_cast<int>(x-64)] == 'D'||temp[y][static_cast<int>(x-64)] == 'C')
     {
      hhh[y][static_cast<int>(x-64)] = temp[y][static_cast<int>(x-64)];
      hit++;
      ammo--;
      miss = 1;
     }
     else
     {
     hhh[y][static_cast<int>(x-64)] = '%';
     ammo--;
     miss = 2;
     }
     dolinkedlist();
}

int board::returnammo()
{ 
return ammo;     
}

int board::returnhits()
{
return hit;
}

int board::returnmiss()
{
return miss;
}

istream& operator>>(istream& obj, board& xxx)
{
       obj >> xxx.hitx >> xxx.hity;
       
       xxx.checkhit(xxx.hitx,xxx.hity);
       
       return obj;
}

ostream& operator<<(ostream& obj, const board& xxx)
{

       for(int row=0; row <=xxx.diffYSetter; row++)
     { 
             if(row == 0)
            { obj << ' ' << ' ' << "|";}
             else if (row > 0 && row < 10)
             {obj << " " << row << "|";}
             else 
             {obj << row << "|";}
      for(int col=1; col <= xxx.diffXSetter; col++)
      {
              if(row==0)
             { obj << " " << char(64+col) << ' ' << "|";}
              else
             { obj << ' ' << xxx.hhh[row][col] << ' ' << "|";}
      }
              obj << endl;        
     }
     obj << "You have hit coordinates: " << "(" << static_cast<char>(toupper(xxx.hitx));
     obj << "," << xxx.hity << ")" << endl;
     
     return obj;
}

void board::theConsole()
{
cout << endl << endl;
cout << "Ammo: " << ammo;
cout << setfill(' ') << setw(diffXSetter*2+5) << ' ' << "Hits: " << hit <<endl;     
}

void board::dolinkedlist() 
{
     newnode = new nodeType;

     newnode->x = toupper(hitx);
     newnode->y = hity;
     newnode->hom = miss;
     newnode->link = NULL;
     
     if (first == NULL)
     {
         first = newnode;
         last = newnode;
     }
     else
     {
         last->link = newnode;
         last = newnode;
     }  
}

void board::printlinkedlist()
{
 nodeType *current;
 
 current = first;
 
 while (current != NULL)
{   
 switch(current->hom)
 {
  case 1:
     cout << "Coordinates: " << "(" << current->x << ", " << current->y << ") " << "HIT" << endl;       
     break;
 case 2:
      cout << "Coordinates: " << "(" << current->x << ", " << current->y << ") " << "MISS" << endl; 
      break;  
 }
    current = current->link;
}
}

void board::setfirst()
{
     first = NULL;
}

void board::setlast()
{
     last = NULL;
}

void board::setmunitions()
{
ammo = 20;
hit = 0;
miss=0; 
}
