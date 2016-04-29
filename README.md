### Three Dice Problem

This is a proposed solution to the problem on
https://www.youtube.com/watch?v=xHh0ui5mi_E

Specifically, if you have three indistinguishable dice, how can you mathematically generate a
single dice roll? And then for part 2, how do you generate two dice rolls.

For part 1 the answer was revealed to be 
```
sum (3d6) % 6
```
In fact, this produces an answer between 0 and 5 (as one would expect for modulo). The correct 
solution is instead
```
sum (3d6) % 6 + 1
```

Next for part 2, our answer in part one can be partially reused:
```
diceOne = sum (2d6) % 6 + 1
diceTwo = sum (2d6) % 6 + 1
```
In other words, pick any two of the three dice and add them together and % 6 + 1. Next take the 
remaining die and one of the two dice used before and perform the operation again (sum, % 6 + 1). 

This gives two random dice from three. However since two initial dice must be chosen and then one 
die must be chosen to be reused, there would be more than one possible answer.
