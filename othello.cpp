#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
int legal(int p, int board[8][8], int i, int j){
    int sum=0;
    int x=i, y=j;
    if (i!=0 && j!=0 && board[i-1][j-1]==-p){

        while(i!=0 && j!=0){
            i--;
            j--;
            if(board[i][j]==p) {
                sum+=1;
                break;
                }
            if(board[i][j]==0) break;
            
        }
    }//attack from up left
    i=x,j=y;
    if (i!=7 && j!=7 && board[i+1][j+1]==-p){
        while(i!=7 && j!=7){
            i++;
            j++;
            if(board[i][j]==p) {
                sum+=2;
                break;
                }
            if(board[i][j]==0) break;
        }
    }// attack from down right
        i=x,j=y;
    if (i!=7 && j!=0 && board[i+1][j-1]==-p){
        while(i!=7 && j!=0){
            i++;
            j--;
            if(board[i][j]==p) {
                sum+=4;
                break;
                }
            if(board[i][j]==0) break;
        }
    }//attach from down left
        i=x,j=y;
    if (i!=0 && j!=7 && board[i-1][j+1]==-p){
        while(i!=0 && j!=7){
            i--;
            j++;
            if(board[i][j]==p) {

                sum+=8;
                break;
                }
            if(board[i][j]==0) break;
            
        }
    }// attack from up right
        i=x,j=y;
    if (i!=0 && board[i-1][j]==-p){
        while(i!=0){
            i--;
            if(board[i][j]==p) {
                sum+=16;
                break;
                }
            if(board[i][j]==0) break;
            
        }
    } //attack from up
        i=x,j=y;
    if (j!=0 && board[i][j-1]==-p){
        while(j!=0){
            j--;
            if(board[i][j]==p) {
                sum+=32;
                break;
                }
            if(board[i][j]==0) break;
        }
    }//attack from left
        i=x,j=y;
    if (i!=7 && board[i+1][j]==-p){
        while(i!=7){
            i++;
            if(board[i][j]==p) {
                sum+=64;
               
                // cout<<i<<" "<<j<<endl;
                 break;
                }
            if(board[i][j]==0) break;
            
        }
    }// from down
        i=x,j=y;
    if (j!=7 && board[i][j+1]==-p){
        while(j!=7){
            j++;
            if(board[i][j]==p) {
                sum+=128;
                break;
                }
            if(board[i][j]==0) break;
            
        }
    }
        i=x,j=y;
    return sum;
}
int moves(int p, int a[8][8], int board[8][8]){
    int sum=0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(board[i][j]!=0){
                a[i][j]=0;
            }
            else {
                a[i][j]=(legal(p,board,i,j)>0);
                sum+=a[i][j];
            }
        }
    }
    if(sum==0){
         for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(board[i][j]!=0){
                a[i][j]=0;
            }
            else {
                a[i][j]=legal(-p,board,i,j);
                sum+=a[i][j];
            }
        }
    }
    if(sum==0) return 0;
    else return -p;
    }
    else return p;
}

void update(int board[8][8],int i, int j, int p){
    board[i][j]=p;
int x=i, y=j;
int sum=legal(p,board,i,j);
// cout<<sum<<endl;
    if (sum & 1){
        while(i!=0 && j!=0){
            i--;
            j--;
            if(board[i][j]==p) {
                break;
                }
            if(board[i][j]==0) break;
            board[i][j]=p;
        }
    }//attack from up left
        i=x,j=y;
    if (sum & 2){
        while(i!=7 && j!=7){
            i++;
            j++;
            if(board[i][j]==p) {

                break;
                }
            if(board[i][j]==0) break;
            board[i][j]=p;
        }
    }// attack from down right
        i=x,j=y;
    if (sum & 4){
        while(i!=7 && j!=0){
            i++;
            j--;
            if(board[i][j]==p) {

                break;
                }
            if(board[i][j]==0) break;
            board[i][j]=p;
        }
    }//attach from down left
        i=x,j=y;
    if (sum & 8){
        while(i!=0 && j!=7){
            i--;
            j++;
            if(board[i][j]==p) {

                break;
                }
            if(board[i][j]==0) break;
            board[i][j]=p;
            
        }
    }// attack from up right
        i=x,j=y;
    if (sum & 16){
        while(i!=0){
            i--;
            if(board[i][j]==p) {
                break;
                }
            if(board[i][j]==0) break;
            board[i][j]=p;
        }
    } //attack from up
        i=x,j=y;
    if (sum & 32){
        while(j!=0){
            j--;
            if(board[i][j]==p) {

                break;
                }
            if(board[i][j]==0) break;
            board[i][j]=p;
        }
    }//attack from left
        i=x,j=y;
    if (sum & 64){
        while(i!=7){
            i++;
            if(board[i][j]==p) {
                break;
                }
            if(board[i][j]==0) break;
            board[i][j]=p;
            // cout<<i<<" "<<j<<endl;
        }
    }
        i=x,j=y;
    if (sum & 128){
        while(j!=7){
            j++;
            if(board[i][j]==p) {
                break;
                }
            if(board[i][j]==0) break;
            board[i][j]=p;
        }
    }
        i=x,j=y;
}

void pr(int a[8][8], int b[8][8]){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(a[i][j]==1) cout<<"1"<<" ";
            else if(a[i][j]==-1) cout<<"2"<<" ";
            else if(b[i][j]) cout<<"_"<<" ";
            else cout<<"0"<<" ";
            // cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

int val(int board[8][8]){
    int sum=0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(board[i][j]==1) sum+=1;
            else if(board[i][j]==-1) sum-=1;
        }
    }
    for(int i=2;i<6;i++){
        sum+=5*board[i][0];
        sum+=5*board[i][7];
    }
    for(int j=2;j<6;j++){
        sum+=5*board[0][j];
        sum+=5*board[7][j];
    }
    sum+=35*(board[0][0]+board[0][7]+board[7][0]+board[7][7]);
    return sum;
}


int win(int b[8][8]){
    int sum=0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            sum+=b[i][j];
        }
    }
    return sum;
}

int rec(int board[8][8],int p, int nest){
    int v;
    int a[8][8];
    int b=moves(p,a,board);
    if(nest==0 || b==0){
        v=val(board);
    }
    else if(b!=p){
        rec(board,-p,nest);
    }
    else{
        
        if(p==1){
            v=-1234;
            for(int i=0;i<8;i++){
                for(int j=0;j<8;j++){
                    if(a[i][j]==1){
                        int cp[8][8];
                        for(int x=0;x<8;x++){
                            for(int y=0;y<8;y++){
                                cp[x][y]=board[x][y];
                            }
                        }
                        cp[i][j]=p;
                        update(cp,i,j,p);
                        v=max(v,rec(cp,-p,nest-1));
                    }
                }
            }
        }
        else{
            v=1234;
            for(int i=0;i<8;i++){
                for(int j=0;j<8;j++){
                    if(a[i][j]==1){
                        int cp[8][8];
                        for(int x=0;x<8;x++){
                            for(int y=0;y<8;y++){
                                cp[x][y]=board[x][y];
                            }
                        }
                        cp[i][j]=p;
                        update(cp,i,j,p);
                        v=min(v,rec(cp,-p,nest-1));
                    }
                }
            }
        }
    }
    return v;
}

int ai(int board[8][8], int p){
    int x=64;
    int i=7;
    int a[8][8];
    int res=63;
    moves(p,a,board);
    while(x--){
        int xi=x;
        int v=1234;
        int x=xi/8;
        int y=xi%8;
        if(a[x][y]==1){
            int cp[8][8];
            for(int x=0;x<8;x++){
                for(int y=0;y<8;y++){
                    cp[x][y]=board[x][y];
                }
            }
            cp[x][y]=p;
            update(cp,x,y,p);
            if(v>rec(cp,-p,i-1)){
                v=rec(cp,-p,i-1);
                res=xi;
            };
        }
    }
    return res;
}




int main(){
    int board[8][8];//state of the board
    for (int a=0;a<8;a++) for ( int b=0;b<8;b++)board[a][b]=0;//intializing
    board[3][3]=board[4][4]=-1;// -1 is white
    board[3][4]=board[4][3]=1;// 1 is black
    int a[8][8];//used to store the possible moves
    int i=1;//player playing
    cout<<"no of players:";
    int num=0;
    cin>>num;
    i=moves(i,a,board);
    pr(board,a);
    cout<<endl;
    // cout<<endl<<i;
    while(i!=0){
        if(i==1){
            cout<<"Black enter your move(row, column)";
            int x,y;
            cin>>x>>y;
            while (x>7 || y>7 ||y<0|| x<0 || !a[x][y]){
                cout<<"\nplease enter valid input";
                cin>>x>>y;
            }
            update(board,x,y,i);
            i=moves(-i,a,board);
        }
        else if(i==-1){
            int x,y;
            if(num!=1)
            {cout<<"White enter your move(row, column)";
            cin>>x>>y;
            while (x>7 || y>7 ||y<0|| x<0 || !a[x][y]){
                cout<<"\nplease enter valid input";
                cin>>x>>y;
            }
            
        }
        else{
        int xi;
        xi=ai(board, i );
        x=xi/8;
        y=xi%8;}
        update(board,x,y,i);
        i=moves(-i,a,board);
        cout<<"last move was"<<x<<" "<<y<<endl;
        }
       
        pr(board,a);
        cout<<endl;
    }
    cout<<win(board);
}
