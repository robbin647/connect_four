# Connect four


## For HW3 markers

  + This game (Connect Four) is implemented in C++  
  + Below is a description of our source code:  
    - main.cpp is where the program starts, with the function of printing game boards and asking for user inputs
    - gameTree.cpp is a library source file in which we implement our own ```Tree``` class  

## Back end  
  Back end functionalities:  
  1. Create a decision tree for the game (either created at the beginning of the game or created during the game, i.e. dynamically)
  2. Generate computer move

## Front end  
  Front end functionalities:
  1. implement a 6 by 7 game board
  2. ask the user who does the first move
  3. if it is the user's turn, ask which column the user would like to place his piece
  4. after a move is chosen, refresh the game board  
 <br>
 Recommeded "classes":  
 
 Note: for the data type of "Board", we can refer to a good idea called [Bitboard] (https://github.com/denkspuren/BitboardC4/blob/master/BitboardDesign.md)
  
  ```c++
  class gameBoard{
    public:
      <datatype> getCurrentBoard() {       //the Getter(), returns the infomation about all pieces that are NOW on board
      }
      <datatype> setBoard() {              //the Setter(). The parameter(s) specifies where the next piece will go. 
                                           //Remember to refresh the board after a piece is added to the board
      }
      bool isWin() {                        //before the 42nd piece is placed, check if either of the players wins
      }
      bool isGameOver() {                  //Check if the game ends with all 42 cells filled 
                                           //Need to call isWin() again after 42 cells are filled, because a plyer may win at the 42nd ply
      }
    private:
      <datatype> Board ;                   //Information about all pieces on the game board
                                           //There may be more than one variables or objects to achieve this
  };
  ```
 
