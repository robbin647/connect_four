#include <stdio.h>
#include<iostream>
#include<iomanip>
#include <string>
using namespace std;
class Piece {
public:
    Piece() {
        this->player = NULL;
        this->position[0] = NULL;
        this->position[1] = NULL;
    }
    Piece(int player, int position[2]) {
        this->player = player;
        this->position[0] = position[0];
        this->position[1] = position[1];
    }
    int getPlayer() {
        return player;
    }
    int* getPosition() {
        return position;
    }

private:
    int player;
    int position[2];


};
class Board {
public:
    Board() {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 7; j++) {
                full[i][j] = 0;


            }
        }
    }
    Board(Board* b, int p, int c) {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 7; j++) {
                full[i][j] = b->full[i][j];
            }
        }
        int row = 5;
        while (b->getFull(row, c) > 0) {
            row--;
        }
        full[row][c] = p;
    }
    void ChangeBoard(Piece piece) {
        full[piece.getPosition()[0]][piece.getPosition()[1]] = piece.getPlayer();
    }
    int getFull(int x, int y) {
        return full[x][y];
    }
    bool ifTerminates() {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 7; j++) {
                if (full[i][j] == 0) {
                    return false;

                }
            }
        }

        return true;
    }
    int whoWins() {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 4; j++) {
                if ((getFull(i, j) == getFull(i, j + 1)) && (getFull(i, j + 1) == getFull(i, j + 2)) && (getFull(i, j + 2) == getFull(i, j + 3)) && (getFull(i, j) != 0)) {
                    return getFull(i, j);
                }
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 7; j++) {
                if (((getFull(i, j) == getFull(i + 1, j)) && (getFull(i + 1, j) == getFull(i + 2, j)) && (getFull(i + 2, j) == getFull(i + 3, j))) && (getFull(i, j) != 0)) {
                    return getFull(i, j);
                }
            }
        }
        for (int i = 0; i < 3; i++) {
            if ((getFull(i, i) == getFull(i + 1, i + 1)) && (getFull(i + 1, i + 1) == getFull(i + 2, i + 2)) && (getFull(i + 2, i + 2) == getFull(i + 3, i + 3)) && (getFull(i, i) != 0)) {
                return getFull(i, i);
            }
            if ((getFull(i, i - 1) == getFull(i + 1, i)) && (getFull(i + 1, i) == getFull(i + 2, i + 1)) && (getFull(i + 2, i + 1) == getFull(i + 3, i + 2)) && (getFull(i, i - 1) != 0)) {
                return getFull(i, i - 1);
            }
            if ((getFull(i, i - 2) == getFull(i + 1, i - 1)) && (getFull(i + 1, i - 1) == getFull(i + 2, i)) && (getFull(i + 2, i) == getFull(i + 3, i + 1)) && (getFull(i, i - 2) != 0)) {
                return getFull(i, i - 2);
            }
            if ((getFull(i, i - 3) == getFull(i + 1, i - 2)) && (getFull(i + 1, i - 2) == getFull(i + 2, i - 1)) && (getFull(i + 2, i - 1) == getFull(i + 3, i)) && (getFull(i, i - 3) != 0)) {
                return getFull(i, i - 3);
            }
            if ((getFull(i, i + 1) == getFull(i + 1, i + 2)) && (getFull(i + 1, i + 2) == getFull(i + 2, i + 3)) && (getFull(i + 2, i + 3) == getFull(i + 3, i + 4)) && (getFull(i, i + 1) != 0)) {
                return getFull(i, i + 1);
            }
            if ((getFull(i, i + 2) == getFull(i + 1, i + 3)) && (getFull(i + 1, i + 3) == getFull(i + 2, i + 4)) && (getFull(i + 2, i + 4) == getFull(i + 3, i + 5)) && (getFull(i, i + 2) != 0)) {
                return getFull(i, i + 2);
            }
            if ((getFull(i, i + 3) == getFull(i + 1, i + 4)) && (getFull(i + 1, i + 4) == getFull(i + 2, i + 5)) && (getFull(i + 2, i + 5) == getFull(i + 3, i + 6)) && (getFull(i, i + 3) != 0)) {
                return getFull(i, i + 3);
            }
        }
        for (int i = 7; i >= 0; i--) {
            if ((getFull(6 - i, i) == getFull(6 - (i - 1), i - 1)) && (getFull(6 - (i - 1), i - 1) == getFull(6 - (i - 2), i - 2)) && (getFull(6 - (i - 2), i - 2) == getFull(6 - (i - 3), i - 3)) && (getFull(6 - i, i) != 0)) {
                return getFull(6 - i, i);
            }
            if ((getFull(6 - i, i - 1) == getFull(6 - (i + 1), i)) && (getFull(6 - (i + 1), i) == getFull(6 - (i + 2), i + 1)) && (getFull(6 - (i + 2), i + 1) == getFull(6 - (i + 3), i + 2)) && (getFull(6 - i, i - 1) != 0)) {
                return getFull(6 - i, i - 1);
            }
            if ((getFull(6 - i, i - 2) == getFull(6 - (i + 1), i - 1)) && (getFull(6 - (i + 1), i - 1) == getFull(6 - (i + 2), i)) && (getFull(6 - (i + 2), i) == getFull(6 - (i + 3), i + 1)) && (getFull(6 - i, i - 2) != 0)) {
                return getFull(6 - i, i - 2);
            }
            if ((getFull(6 - i, i - 3) == getFull(6 - (i + 1), i - 2)) && (getFull(6 - (i + 1), i - 2) == getFull(6 - (i + 2), i - 1)) && (getFull(6 - (i + 2), i - 1) == getFull(6 - (i + 3), i)) && (getFull(6 - i, i - 3) != 0)) {
                return getFull(6 - i, i - 3);
            }
            if ((getFull(6 - i, i + 1) == getFull(6 - (i + 1), i + 2)) && (getFull(6 - (i + 1), i + 2) == getFull(6 - (i + 2), i + 3)) && (getFull(6 - (i + 2), i + 3) == getFull(6 - (i + 3), i + 4)) && (getFull(6 - i, i + 1) != 0)) {
                return getFull(6 - i, i + 1);
            }
            if ((getFull(6 - i, i + 2) == getFull(6 - (i + 1), i + 3)) && (getFull(6 - (i + 1), i + 3) == getFull(6 - (i + 2), i + 4)) && (getFull(6 - (i + 2), i + 4) == getFull(6 - (i + 3), i + 5)) && (getFull(6 - i, i + 2) != 0)) {
                return getFull(6 - i, i + 2);
            }
            if ((getFull(i, i + 3) == getFull(i + 1, i + 4)) && (getFull(i + 1, i + 4) == getFull(i + 2, i + 5)) && (getFull(i + 2, i + 5) == getFull(i + 3, i + 6)) && (getFull(i, i + 3) != 0)) {
                return getFull(6 - i, i + 3);
            }
        }
        return -1;
    }
    void Setter(Piece piece) {
        ChangeBoard(piece);
    }

    Piece* Getter() {
        Piece pi[42];
        for (int o = 0; o < 42; o++) {
            pi[o] = Piece();
        }
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 7; j++) {
                if (full[i][j] != 0) {
                    int pos[2] = { i,j };
                    pi[u] = Piece(full[i][j], pos);
                    u++;

                }

            }
        }
        return pi;
    }

    int getLength() {
        return u;
    }

    int getPossibleMoves() {
        int cnt = 0;
        for (int c = 0; c < 7; c++) {
            for (int r = 0; r < 6; r++) {
                if (full[r][c] == 0) {
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }

    bool equals(Board* b) {
        for (int c = 0; c < 7; c++) {
            for (int r = 0; r < 6; r++) {
                if (this->full[r][c] != b->full[r][c]) {
                    return false;
                }
            }
        }
        return true;
    }

    void print() {
        for (int i = 0; i < 6; i++) {
            cout << endl;
            for (int j = 0; j < 7; j++) {
                cout << this->getFull(i, j) << " ";

            }

        }
        cout << endl;
    }

private:
    int full[6][7];
    int u = 0;

};

//game tree

class node {
public:
    int value;
    int level;
    Board* b = NULL;
    node* nsibling = NULL;
    node* fchild = NULL;
    node(Board* b, int l) {
        this->b = b;
        level = l;
    }

    int nextplayer() {
        if (level % 2 == 0) {
            return 2;
        }
        else {
            return 1;
        }
    }
};

class tree {
public:
    node* root = new node(new Board(), 0);
    node* currentNode = root;
    void generateTree(node* n) {
        if (n->b->getPossibleMoves() == 0) {
            if (n->b->whoWins() == 1) {
                n->value = 1;
            }
            else if (n->b->whoWins() == 2) {
                n->value = -1;
            }
            else {
                n->value = 0;
            }
            return;
        }
        else {
            n->fchild = new node(new Board(n->b, n->nextplayer(), 0), n->level + 1);
            node* tmp = n->fchild;
            for (int i = 1; i < n->b->getPossibleMoves(); i++) {
                generateTree(tmp);
                if (i != n->b->getPossibleMoves() - 2) {
                    tmp->nsibling = new node(new Board(n->b, n->nextplayer(), i), n->level + 1);
                    tmp = tmp->nsibling;
                }
            }
            n->value = generateValue(n);
        }
    }
    int generateValue(node* n) {
        int min = 1;
        int max = -1;
        node* tmp = n->fchild;
        while (tmp != NULL) {
            if (tmp->value > max) {
                max = tmp->value;
            }
            else if (tmp->value < min) {
                min = tmp->value;
            }
            tmp = tmp->nsibling;
        }
        if (n->level % 2 == 0) {
            return max;
        }
        else {
            return min;
        }
    }

    //computer first move
    void setCurrentNode(Board* b) {
        node* tmp = root->fchild;
        while (tmp != NULL) {
            if (tmp->b->equals(b)) {
                currentNode = tmp;
                break;
            }
            tmp = tmp->nsibling;
        }
    }

    Board* nextMove(Board* b) {
        currentNode = currentNode->fchild;
        while (currentNode != NULL) {
            if (currentNode->b->equals(b)) {
                break;
            }
            currentNode = currentNode->nsibling;
        }
        if (currentNode == NULL) {
            return NULL;
        }
        node* tmp = currentNode->fchild;
        while (tmp != NULL) {
            if (tmp->value == currentNode->value) {
                currentNode = tmp;
                break;
            }
            tmp = tmp->nsibling;
        }
        return currentNode->b;
    }
};

//

int main()
{
    Board* b =new Board();
    tree gametree;
    gametree.generateTree(gametree.root);
    int column;
    int player;
    /*    int pos1[2]={4,4};
        int pos2[2]={5,3};
        int pos3[2]={3,5};
        int pos4[2]={2,6};*/


        /*   b.Setter(Piece(1,pos1));
           b.Setter(Piece(1,pos2));
           b.Setter(Piece(1,pos3));
           b.Setter(Piece(1,pos4));*/


    cout << "Please enter the player number" << endl;
    cin >> player;

    cout << "Please enter the column number:" << endl;
    while (cin >> column) {

        int row = 6;
        while (b->getFull(row - 1, column - 1) > 0) {
            row--;
        }
        int posi[2] = { row - 1,column - 1 };
        Piece in = Piece(player, posi);
        b->Setter(in);
        b->print();
        b=gametree.nextMove(b);
        if (b->whoWins() != -1) {
            cout << b->whoWins();
            return 0;
        }
        if (b->ifTerminates()) {
            return 0;
        }

    }



    /*Piece* pc = b->Getter();
    for (int i = 0; i < b->getLength(); i++) {

        // cout <<pc->getPlayer()<<" "<<pc->getPosition()[0]<<" "<<pc->getPosition()[1]<<endl;
        pc++;
    }*/

}