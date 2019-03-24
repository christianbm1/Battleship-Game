#include <iostream>
#include <cstdlib>
#include <cstdlib> 
#include "ship.h" 

using namespace std;

ship::ship()
{
shipx = ((rand()%(9-1))+1);
shipy = ((rand()%(9-1))+1);
shipHV = ((rand()%(3-1))+1);
size = 3;
}

ship::ship(int num)
{           
size = num;        
}

ship::~ship()
{

}

int ship::setx() 
{
    shipx = ((rand()%(9-1))+1);  
    return shipx;
}
int ship::sety() 
{
    shipy = ((rand()%(9-1))+1);
    return shipy;
}

int ship::getsize() 
{
    return size;
}

int ship::setHV() 
{
    shipHV = ((rand()%(3-1))+1);
    return shipHV;
}
