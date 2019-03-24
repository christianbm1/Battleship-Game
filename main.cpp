#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cctype>
#include <string>
#include <unistd.h>
#include <cstdlib> 
#include "battleshipgame.h"

using namespace std;

void whileCheck(char&);

int main()
{
  // need in order to randomized the numbers
  srand(time(NULL));
  int diffic, ans;
  char cont;
  // declare an object of typebattleship game.
  battleshipGame abjects;
  // call member function intro for the intro
  abjects.introduction();
  sleep(1);
  do {
    //show difficulty levels
    abjects.difficulty();
    cin >> diffic;
    cin.clear();
    cin.ignore();

    if (diffic <= 3 || diffic > 0) {    
      //set difficulty level           
      abjects.initialize(diffic);
    }
    else {
      cout << "Invalid Selection." << endl;
    }
    //check ammo and hits, if so end game.
    while(abjects.ammo > 0 && abjects.hits < 12) {
      cout << endl << "Insert your hit. Letter first (column), and then the number (row) WITHOUT A SPACE for double digits " << endl;
      //cin>> abjects;
      cin.clear();
      //cin.ignore();
      getline(cin, abjects);

      cout << abjects.hity << endl;
      if(abjects.hity > 0 ) {
        cout <<" Previous shots: " <<endl;
        //linkedlist
        abjects.thelist();
        //show the ammo left and hits gotten
        abjects.theConsole();
        cout << abjects << endl;
      } else {
        cout << "Try again, please" << endl;
      }
    }
    cout <<endl;
    cout << setfill(' ') << setw(25) << "Game is Finished" << endl;
   
    if(abjects.hits==12) {
      cout<< "Congratulations, you win!" << endl;
    }
    else {
      cout<< "Sorry you lost. Aim better next time!" << endl;
    }
    cout << endl;
    whileCheck(cont);
  } while(cont == 'y');//end starting while
    system ("pause");
}

void whileCheck(char& a) {
  cout << endl;
  cin.clear();
  cin.ignore(100,'\n');
  cout << "Do you wish to do it again? Y/N" << endl;
  cin >> a;

	while(a != 'y' && a != 'Y' && a != 'n'&& a != 'N') {
    cout << "Did you enter the correct response? If not, please enter your response again." << endl;
	  cin.clear();
    cin.ignore(100,'\n');
	  cin >> a;
  }
}
  