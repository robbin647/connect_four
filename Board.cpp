

#include <stdio.h>
#include<iostream>
#include<iomanip>
#include <string>
using namespace std;
class Piece{
public:
    Piece(){
        this->player=NULL;
        this->position[0]=NULL;
        this->position[1]=NULL;
    }
    Piece(int player,int position[2]){
        this->player=player;
        this->position[0]=position[0];
        this->position[1]=position[1];
    }
    int getPlayer(){
        return player;
    }
    int* getPosition(){
        return position;
    }
    
private:
    int player;
    int position [2];
    
    
};
class Board {
public:
    Board(){
        for (int i=0;i<6;i++){
            for (int j=0;j<7;j++){
                    full[i][j]=0;
                
                
            }
        }
        
    }
    void ChangeBoard(Piece piece){
        full[piece.getPosition()[0]][piece.getPosition()[1]]=piece.getPlayer();
    }
    int getFull(int x, int y){
        return full[x][y];
    }
    bool ifTerminates(){
        for (int i=0;i<6;i++){
          for (int j=0;j<7;j++){
                  if (full[i][j]==0){
                      return false;
                  
              }
          }
        }
        
        return true;
    }
    int whoWins (){
        for (int i=0;i<6;i++){
            for (int j=0;j<4;j++){
                if ((getFull(i,j)==getFull(i,j+1))&&(getFull(i,j+1)==getFull(i,j+2))&&(getFull(i,j+2)==getFull(i,j+3))&&(getFull(i,j)!=0)){
                    return getFull(i,j);
                }
            }
        }
        for (int i=0;i<3;i++){
            for (int j=0;j<7;j++){
if (((getFull(i,j)==getFull(i+1,j))&&(getFull(i+1,j)==getFull(i+2,j))&&(getFull(i+2,j)==getFull(i+3,j)))&&(getFull(i,j)!=0)){
                         return getFull(i,j);
            }
        }
    }
    for (int i=0;i<3;i++){
       if ((getFull(i,i)==getFull(i+1,i+1))&&(getFull(i+1,i+1)==getFull(i+2,i+2))&&(getFull(i+2,i+2)==getFull(i+3,i+3))&&(getFull(i,i)!=0)){
           return getFull(i,i);
       }
        if ((getFull(i,i-1)==getFull(i+1,i))&&(getFull(i+1,i)==getFull(i+2,i+1))&&(getFull(i+2,i+1)==getFull(i+3,i+2))&&(getFull(i,i-1)!=0)){
           return getFull(i,i-1);
       }
        if ((getFull(i,i-2)==getFull(i+1,i-1))&&(getFull(i+1,i-1)==getFull(i+2,i))&&(getFull(i+2,i)==getFull(i+3,i+1))&&(getFull(i,i-2)!=0)){
           return getFull(i,i-2);
       }
          if ((getFull(i,i-3)==getFull(i+1,i-2))&&(getFull(i+1,i-2)==getFull(i+2,i-1))&&(getFull(i+2,i-1)==getFull(i+3,i))&&(getFull(i,i-3)!=0)){
           return getFull(i,i-3);
       }
         if ((getFull(i,i+1)==getFull(i+1,i+2))&&(getFull(i+1,i+2)==getFull(i+2,i+3))&&(getFull(i+2,i+3)==getFull(i+3,i+4))&&(getFull(i,i+1)!=0)){
           return getFull(i,i+1);
       }
        if ((getFull(i,i+2)==getFull(i+1,i+3))&&(getFull(i+1,i+3)==getFull(i+2,i+4))&&(getFull(i+2,i+4)==getFull(i+3,i+5))&&(getFull(i,i+2)!=0)){
           return getFull(i,i+2);
       }
          if ((getFull(i,i+3)==getFull(i+1,i+4))&&(getFull(i+1,i+4)==getFull(i+2,i+5))&&(getFull(i+2,i+5)==getFull(i+3,i+6))&&(getFull(i,i+3)!=0)){
           return getFull(i,i+3);
       }
    }
      for (int i=7;i>=0;i--){
          if ((getFull(6-i,i)==getFull(6-(i-1),i-1))&&(getFull(6-(i-1),i-1)==getFull(6-(i-2),i-2))&&(getFull(6-(i-2),i-2)==getFull(6-(i-3),i-3))&&(getFull(6-i,i)!=0)){
              return getFull(6-i,i);
          }
           if ((getFull(6-i,i-1)==getFull(6-(i+1),i))&&(getFull(6-(i+1),i)==getFull(6-(i+2),i+1))&&(getFull(6-(i+2),i+1)==getFull(6-(i+3),i+2))&&(getFull(6-i,i-1)!=0)){
              return getFull(6-i,i-1);
          }
           if ((getFull(6-i,i-2)==getFull(6-(i+1),i-1))&&(getFull(6-(i+1),i-1)==getFull(6-(i+2),i))&&(getFull(6-(i+2),i)==getFull(6-(i+3),i+1))&&(getFull(6-i,i-2)!=0)){
              return getFull(6-i,i-2);
          }
             if ((getFull(6-i,i-3)==getFull(6-(i+1),i-2))&&(getFull(6-(i+1),i-2)==getFull(6-(i+2),i-1))&&(getFull(6-(i+2),i-1)==getFull(6-(i+3),i))&&(getFull(6-i,i-3)!=0)){
              return getFull(6-i,i-3);
          }
            if ((getFull(6-i,i+1)==getFull(6-(i+1),i+2))&&(getFull(6-(i+1),i+2)==getFull(6-(i+2),i+3))&&(getFull(6-(i+2),i+3)==getFull(6-(i+3),i+4))&&(getFull(6-i,i+1)!=0)){
              return getFull(6-i,i+1);
          }
           if ((getFull(6-i,i+2)==getFull(6-(i+1),i+3))&&(getFull(6-(i+1),i+3)==getFull(6-(i+2),i+4))&&(getFull(6-(i+2),i+4)==getFull(6-(i+3),i+5))&&(getFull(6-i,i+2)!=0)){
              return getFull(6-i,i+2);
          }
             if ((getFull(i,i+3)==getFull(i+1,i+4))&&(getFull(i+1,i+4)==getFull(i+2,i+5))&&(getFull(i+2,i+5)==getFull(i+3,i+6))&&(getFull(i,i+3)!=0)){
              return getFull(6-i,i+3);
          }
    }
        return -1;
    }
    void Setter (Piece piece){
        ChangeBoard(piece);
    }
   
    Piece* Getter(){
        Piece pi[42];
        for (int o=0;o<42;o++){
            pi[o]=Piece();
        }
          for (int i=0;i<6;i++){
            for (int j=0;j<7;j++){
                    if (full[i][j]!=0){
                        int pos[2]={i,j};
                        pi[u]=Piece(full[i][j],pos);
                        u++;
                    
                }
                
            }
        }
        return pi;
    }
   
   int getLength(){
       return u;
   }
private:
    int full [6][7];
                int u=0;

};

int main()
{
    Board b=Board();
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
 

    cout<< "Please enter the player number"<<endl;
    cin>> player;
    cout<< "Please enter the column number:"<<endl;
    while (cin>>column ){
         
        int row=6;
        while(b.getFull(row-1,column-1)>0){
            row--;
        }
        int posi[2]={row-1,column-1};
              Piece in=Piece(player,posi);
              b.Setter(in);
              if (b.ifTerminates()){
                  return 0;
              }

    }
          
    
        for (int i=0;i<6;i++){
            cout<<endl;
            for (int j=0;j<7;j++){
                cout <<b.getFull(i,j)<<" ";
                    
            }
            
        }
       cout<<endl;
        
    

    Piece* pc=b.Getter();
    for (int i=0;i<b.getLength();i++){
    
   // cout <<pc->getPlayer()<<" "<<pc->getPosition()[0]<<" "<<pc->getPosition()[1]<<endl;
        pc++;
    }
    
    
   cout<< b.whoWins();
}
