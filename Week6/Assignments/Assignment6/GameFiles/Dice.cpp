#include "Dice.h"
#include <cstdlib>
#include <ctime>
 
// TODO: Implement rollDice().
// - Should return a random integer between 1 and 6, inclusive.
// - Think carefully about where to seed the random number generator.
//   If you seed it INSIDE this function, what happens every time it's called?
 
int RollDice() {
    static bool seeded = false;
    if (!seeded){
        srand(time(0));
        seeded = true;   
    } 
      return rand() % 6 + 1;
}