#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/**********************************************
 * Proposed solution to:
 * https://www.youtube.com/watch?v=xHh0ui5mi_E
 **********************************************/

static const
int NUM_DICE_TO_ROLL = 90 * 1000;

static
int buckets[30];

static
int getDiceRoll(void) {
    return rand() % 6 + 1;
}

static
void printBuckets(void) {
    int total = 0;
    for (int i = 0; i <= 25; i++) {
        total += buckets[i];
    }
    for (int i = 0; i <= 25; i++) {
        printf ("%d: %d  %f %%\n", i, buckets[i], buckets[i] / (float) total * 100);
    }
}

int main () {
    srand (time(NULL));
    
    for (int i = 0; i < NUM_DICE_TO_ROLL; i++) {

        // Regular dice roll
        //buckets[getDiceRoll()] ++ ;

        // Three dice roll into one
        //int diceSum = 0;
        //diceSum += getDiceRoll();
        //diceSum += getDiceRoll();
        //diceSum += getDiceRoll();
        //diceSum = diceSum % 6;
        //if (diceSum >= 0 && diceSum <= 6) {
            //buckets[diceSum] ++ ;
        //}

        // Regular two dice
        //buckets[ getDiceRoll() + getDiceRoll() ] ++ ;

        // Three dice roll into two
        int dice[3] = { getDiceRoll(), getDiceRoll(), getDiceRoll() };
        int diceOne = (dice[0] + dice[1]) % 6 + 1;
        int diceTwo = (dice[1] + dice[2]) % 6 + 1;
        buckets[ diceOne + diceTwo ] ++ ;

    }

    printBuckets();
}
