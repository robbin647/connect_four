# This is documentation for class ```Bitboard```

+ I have created a C++ class called "Bitboard". Below is the documentation for using it.

## class ```Bitboard``` documentation

The ```Bitboard``` class simply represents 6X7 game board in a bit basis.

+ methods/functions in ```Bitboard```

    1. ```makeMove()```  
    Takes in an integer (the column #) and add a piece to that column. **Remember I set column number from 0 to 6!** To see what the column number is for each column, visit the [*A handy bitboard figure*] (##A handy bitboard figure) section below.

    2. ```undoMove()```  
    This is a void-type function which lets you immediately undo the last move. For example, I am now at the 10th move. If I call ```Bitboard.undoMove()``` I will return to the 9th move and play again.

    3. ```isWin()```  
    This function helps you determine whether X wins or O wins. To determine if X wins, call it by ```Bitboard.isWin('X')```, and ```Bitboard.isWin('O')``` for O.

    4. ```isDraw()```  
    Checks if all 42 moves have been played and no one wins. This function returns true if it is the case.

    5. ```listMoves()```  
    Returns an array. This gives you an array of all possible columns where your piece can go. Remember I use column # to denote a column. See [*A handy bitboard figure*] (##A handy bitboard figure) section below.

+ properties/ variables in ```Bitboard```

    1. ```long Boards[2]```  
    This is an array storing two 64-bit long integers, XBoard and OBoard (please see *```XBoard``` and ```OBoard```*). By default I set ```Boards[0]=XBoard``` and ```Boards[1]=OBoard```. It is notable to explain how we select ```XBoard``` or ```OBoard```. Because we let X plays first, so X plays when ```counter```=0, 2, 4, ... Namely, we want to select X when counter is even.

        ```c++
        if (counter % 2 == 0){
            //select XBoard, or Boards[0]
        }
        else{
            //select OBoard, or Boards[1]
        }
        ```
        However, the operation ```counter % 2``` has the same effect as ```counter & 1```, where ```&``` is bitwise AND (you may verify it yourself, when doing bit operation, C++ treats an integer as a bitstring). And this is exactly what I have written in the methods ```makeMove()``` and ```undoMove()```.

    2. ```XBoard``` and ```OBoard```  
    These are two 64-bit long integers. ```XBoard``` stores where X has put his pieces on the 6X7 game board, and the same for ```OBoard```.  

    3. ```height[7]```  
    This is an array of which each element where the next piece will go that column. For example, ```height[2]``` is an integer that is equal to the index of next-to-go piece in column #2. (Please refer to the [*A handy bitboard figure*] (##A handy bitboard figure) section below to see what are the indices)

    4. ```counter```  
    An integer which tells you how many moves we have done. Remember it starts with 0!

    5. ```int moves[42]```  
    This is an array that stores all the moves that have been done. For example, moves[10] gives you the number of the column (N.B. range from 0 to 6 !)  that we add a piece to when ```counter```=10.


## A handy bitboard figure.

+ Note all integers are the index of its corresponding bit in a **long** integer.  Please look at the left-bottom quarter of this figure (i.e. left-bottom rectangle which is marked by horizontal and vertical bars), they represent the *6X7* game board!

```
6   13  20  27  34  41  48   |   55  62         <-- row 7 (additional)
--------------------------------------          
5   12  19  26  33  40  47   |   54  61         <-- row 6
4   11  18  25  32  39  46   |   53  60         <-- row 5
3   10  17  24  31  38  45   |   52  59         <-- row 4
2   9   16  23  30  37  44   |   51  58         <-- row 3
1   8   15  22  29  36  43   |   50  57         <-- row 2
0   7   14  21  28  35  42   |   49  56  63     <-- row 1
^   ^   ^   ^   ^   ^   ^        ^   ^   ^
c0  c1  c2  c3  c4  c5  c6       c7  c8  c9

Remark: c0 means column #0 and etc. Note that we add additional row (row 7) and columns (c7, c8, c9).
```

## Why bitboard?

There are reasons why we use bitboard. For more information please see [Bitboard] (https://github.com/denkspuren/BitboardC4/blob/master/BitboardDesign.md)

+ Tailored for Connect-four, the Bitboard encode the whole 6X7 game board in **64 bits** (just fitting into a **long** type in C++!)

+ The bitboard as a sophiscated data structure is really helpful in speeding up the game.
    - Adding a piece to board means to perform XOR to a bitboard
    - Check if four pieces are aligned (i.e. check winning) is made easy by only doing bitwise shift and bitwise AND
