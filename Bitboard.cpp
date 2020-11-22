/*
*   This is the definition of class "Bitboard"
*   For more information, please see my documentation Bitboard_doc.md
*
*/
#include <iostream>
class Bitboard {
    public:
    //below are all function declarations, for definitions scroll down to the bottom
    void makeMove(int column);
    void undoMove();
    bool isWin(long bitboard);
    bool isDraw();
    int * listMoves();

    private:

    long Boards[2];     //An array which contains only XBoard and OBoard
    long XBoard;        //board info from X's view
    long OBoard;        //board info from O's view
    int height[7];      //height[i] is the index of the next-to-go piece in column[i]
    int counter;        //how many plies have been done
    int moves[42];      //moves[i] records the affected column # in the i-th ply

    Bitboard(){         //constructor
        XBoard=0;
        OBoard=0;
        Boards[0] = XBoard; Boards[1] = OBoard;
        for (int i=0; i<7; i++){    //initialize height[], every next-to-go piece is on row 1
            height[i]=i*7;
        }
        counter=0;      //we haven't begun yet, so this is ply 0
        ;               //initialize moves[] as well? Maybe
    }
};

//The following are explicit definition of all methods/functions

void Bitboard::makeMove(int column){      //call this when you want to add a piece to the board
    long move = 1L << height[column];
    height[column] += 1;
    Boards[counter & 1] = Boards[counter & 1] ^ move;       //if counter is even, it's X's turn
                                                            //if counter is odd, it's O's turn
    moves[counter] = column;              //add this move to history
    counter++;
}

void Bitboard::undoMove(){                //immediately undo the last move
    int column = moves[--counter];
    long move = 1L << (--height[column]);
    Boards[counter & 1] = Boards[counter & 1] ^ move;
}

bool Bitboard::isWin(){                     //check if ONE player wins by connect-four
                                            //'bitboard' can only be either XBoard or OBoard
    long bitboard;
    try                                     //error handling
    {
        if (who == 'X')
            bitboard=XBoard;
        else if (who == 'O')
            bitboard=OBoard;
        else
            throw who;             
    }
    catch(const char e)
    {
        std::cerr << "Error in Bitboard::isWin(): 'who' cannot be "<<e << '\n';
    }
    
    if (bitboard & (bitboard >> 6) & (bitboard >> 12) & (bitboard >> 18) != 0)
        return true;
    else if (bitboard & (bitboard >> 8) & (bitboard >> 16) & (bitboard >> 24) != 0)
        return true;
    else if (bitboard & (bitboard >> 7) & (bitboard >> 14) & (bitboard >> 21) != 0)
        return true;
    else if (bitboard & (bitboard >> 1) & (bitboard >> 2) & (bitboard >> 3) != 0)
        return true;
    else
        return false;
}

bool Bitboard::isDraw(){                //@return true if it is a draw
                                        //The game is draw if no one wins until the 42nd move

    const long FILLED= 0x0fdfbf7efdfbf;
    /* const long FILLED = 0111111011111101111110111111011111101111110111111; */
    if (XBoard ^ OBoard ^ FILLED == 0) return true;
    else return false;
}

int * Bitboard::listMoves(){             //@return an integer array
    int possible_moves[7];               //I don't know how many moves are there, so assume, at most 7
    const long TOP = 0x1020408102040;
    /* const long TOP = 0b1000000100000010000001000000100000010000001000000; */
    int top_of_stack= 0;
    for (int column =0 ; column<=6; column ++){
        if ( (TOP & (1L << height[column]) ) == 0 )
            possible_moves[top_of_stack] = column;
            top_of_stack++;
    }
    int * moves = new int [top_of_stack];   
    for (int i=0; i<top_of_stack; i++){     //copy from possible_moves[] to moves[]
        moves[i]=possible_moves[i];
    }
    return moves;
}
