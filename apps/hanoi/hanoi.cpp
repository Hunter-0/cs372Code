#include <iostream>
#include <chrono>
using namespace std;

void moveDisks(int, int, int, int);
void printIt(int , int , int );

int main() {
    const int FROMPEG = 1;
    const int TOPEG = 3;
    const int TEMPPEG = 2;
    const int NUMDISKS = 3;
    for (auto numdisks: {100}) {
      cout << "Numdisks: " << numdisks << endl;
      auto start = std::chrono::steady_clock::now();
      moveDisks(numdisks, FROMPEG, TOPEG, TEMPPEG);
      auto end = std::chrono::steady_clock::now();
      std::chrono::duration<double> elapsed_seconds = end-start;
      cout << "Moved " << numdisks << " pegs"
           << " from peg " << FROMPEG
           << " to peg " << TOPEG << endl;
      cout<< "Seconds elapsed: "<<elapsed_seconds.count()<<endl;
    }
}

void moveDisks(int num, int fromPeg, int toPeg, int tempPeg) {
     if (num > 0) {
        moveDisks(num -1, fromPeg, tempPeg, toPeg);
        printIt(num, fromPeg, toPeg);
        moveDisks(num-1, tempPeg, toPeg, fromPeg);
     }
}

void printIt(int disk, int fromPeg, int toPeg) {
  // Do nothing for timing test, but otherwise
  //cout<< "Move disk " << disk<< " from pef " << fromPeg<< " to peg " << toPeg << endl;
}
