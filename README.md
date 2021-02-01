# Get help solving a Minesweeper puzzle

## How to
Start a Minesweeper game as normal. Once you have pressed a tile, create a file called _readFile.txt_ under MineSweeperConsole.

On the first line put the number of mines left.
On the rest of the lines put the grid you see in the game. The grid has to be a square matrix.

* For a number, just put the number
* For a blank space, put _B_
* For an unknown tile, put _U_
* For a tile where a flag has been added, put _M_
* No other characters are allowed and no newline at the end

To generate new guesses, press (capital) _C_ in the console.
A file called _writeFile.txt_ will be generated. This file will have the same format as the input file, with a few differences.
The single number at the top for number of mines will not be present.
Also
* Where it guesses a mine is, it will show a _G_
* Where it guesses there is not a mine, it will show _N_

## Algorithm
The algorithm is quite simple. 
First it looks through the grid to find the list of _frontier_ values. A frontier value is an unknown tile that is neighbor with a number.
After having found all the frontier values it starts looping over them in a depth-first fashion. It starts by guessing that the first frontier value is a mine. 
It then looks at the frontier value's neighbors to see if this was OK given the numbers on them.
If this was OK it makes a guess for the next value and repeats the process for that value.
If guessing mine was not OK it tries to guess it as not a mine. If this was also not OK it sets it as an unknown value again and goes back to the previous frontier value.
If it reaches the start and has gone through the possible guesses for the start value, the loop breaks.
If the end of the frontier is reached this vector of possible values is added to a vector of vectors of possible values. This vector is then merged so that only guesses with absolute certainty are allowed.

The algorithm can be seen as quite naive, since it possibly could look at all permutations in some extreme case. But in reality it will only look at a small subset of all permutations. 
This can be clearly seen at the beginning of the frontier. If, after going through a couple of the first values, it is discovered that the first value cannot be a mine the number of permutations has been cut in half.
So eliminating possible values at the start will greatly influence the number of times it loops.