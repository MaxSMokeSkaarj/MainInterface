#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <queue>

using namespace std;

//preinit
queue<char> to_revpol(const string& in);
double calc(queue<char> in);
//template<class T> ostream& operator<<(ostream& out, queue < T > cs);
int end();

int calc() {
  
  while (true) {
    cout << "MainInterface v1.6 by MaxSMoke\n";
    cout << "Input a mathematical example...\nType 'e' to exit\n";
    string choice, exitChoice;
    queue<char> gen;
    getline(cin, choice);
    if (choice == "E" || choice == "e") {
      cout << "Exit? y/N\n";
      getline(cin, exitChoice);
      if (exitChoice == "y" || exitChoice == "Y") {
        return 0;
      } else if (exitChoice == "N" || exitChoice == "n") {
        cout << "Aborting...\n";
      } else {
        cout << "Error 201\n";
      }
    } else {
      gen = to_revpol(choice);
      cout << calc(gen) << endl;
      //return end();
    }
  }
  return 0;
}