#include<simplecpp>
#include<cstdlib>
#include<ctime>
#include<cmath>
void loc(int pos,int&a,int&b){
    a=((pos/65536)-100)/100;
    b=((pos%65536)-100)/100;
}
int check(int c[][3],int n){
    
    for(int i=0;i<3;i++){if(c[i][1]==c[i][0] && c[i][1]==c[i][2]){
        if (c[i][0]==1) return -1;
        else if(c[i][0]==0) return 1;}
        if(c[1][i]==c[0][i] && c[1][i]==c[2][i]){
            if (c[0][i]==1) return -1;
            else if(c[0][i]==0) return 1;}
        
    }
    if(c[1][1]==c[0][0] && c[1][1]==c[2][2]){
        if (c[1][1]==1) return -1;
        else if(c[1][1]==0) return 1;}
    
    if(c[1][1]==c[2][0] && c[1][1]==c[0][2]){
        if (c[1][1]==1) return -1;
        else if(c[1][1]==0) return 1;}
    return 0;
}
void draw(int a,int b,int pos){
    if (pos){
        Line l5 (110+100*a,110+100*b,190+100*a,190+100*b);//make cross
        l5.imprint();
        Line l6 (110+100*a,190+100*b,190+100*a,110+100*b);//make circle
        l6.imprint();
    }
    else {
        Circle pt(0,0,0);
        pt.reset(150+a*100,150+b*100,40);
        pt.imprint();}
}

void move(int i,int c[][3],int &a,int &b){

    int d[3][3];
    for (int n=0;n<3;n++) {for (int x=0;x<3;x++)d[n][x]=-2;}
    //trivial case
    for(a=0;a<3;a++){
        for (b=0;b<3;b++){
            if (c[a][b]==2){
                int win=0;
                c[a][b]=(i)%2;
                win=check(c,i);
                
                if (win!=0){return;}
                else {c[a][b]=2;}
                             
                d[a][b]=-1;
            }
        }
    }
    for (int n=0;n<3;n++) {for (int x=0;x<3;x++)d[n][x]=-2;}
    //trivial case
    for(a=0;a<3;a++){
        for (b=0;b<3;b++){
            if (c[a][b]==2){
                int win=0;
                c[a][b]=(i+1)%2;
                win=check(c,i+1);
                
                if (win!=0){c[a][b]=i%2;
                    return;}
                else {c[a][b]=2;}
                             
                d[a][b]=-1;
            }
        }
    }
    
    //test
    //cout<<i;
    //prob
    for(a=0;a<3;a++)
        for (b=0;b<3;b++){if(c[a][b]==2){
            int c1[3][3];
            for (int n=0;n<3;n++) for (int x=0;x<3;x++)c1[n][x]=c[n][x];
            int t=i;
            c1[a][b]=t++%2;
            while(check(c1,t)==0&&t<=9){
                int x,y;
                move(t++,c1,x,y);}
            int k=1;
            if (i%2==1) k=-1;
            d[a][b]=check(c1,t)*k;
    
        }
        else d[a][b]=-2;
        }
    
    //return
    //for (int n=0;n<3;n++) {for (int x=0;x<3;x++){cout<<d[n][x]<<" ";}cout<<"\n";}
   //cout<<"\n\n\n";
   
    for(a=0;a<3;a++)
        for (b=0;b<3;b++){
            if (d[a][b]==1){
                c[a][b]=i%2;
                return;}
        }
    for(a=0;a<3;a++)
        for (b=0;b<3;b++){
            if (d[a][b]==0){
                c[a][b]=i%2;
                return;}
        }
    for(a=0;a<3;a++)
        for (b=0;b<3;b++){
            if (d[a][b]==-1){c[a][b]=i%2;
                return;}
        }
}
main_program{
    //for rand 1 player;
    time_t tim;
    time (&tim);
    srand(tim);
    int n;
    cout<<"no of players: ";
    cin>>n;
    int t=2;
    if(n==1){
        
        t=(rand()+rand()+rand()+rand()+rand()+rand()+rand()+rand()+rand())%2;
        srand(time(0));
        t=abs(t+rand()+rand()+rand()+rand()+rand()+rand()+rand()+rand()+rand())%2;
        if (t==0)cout<<"\nyou are first player\n";
        else if (t==1)cout<<"\nyou are second player\n";
    }
    //wait(5);//for test rand
    initCanvas("Tic Tac Toe",500,500);
    //make cross
    Line l1 (100,200,400,200);
    l1.imprint();
    Line l2 (100,300,400,300);
    l2.imprint();
    Line l3 (200,100,200,400);
    l3.imprint();
    Line l4 (300,100,300,400);
    l4.imprint();
    int c[3][3];
    int win=0;
    for (int i=0;i<3;i++) {for (int x=0;x<3;x++)c[i][x]=2;}
    for (int i=0;i<9;i++){
        if(n==2|| i%2==t){
            int po=getClick();
            int a,b;
            loc(po,a,b);
            if(a==3)a=2;
            if(b==3)b=2;
            if (c[b][a]==2){
                c[b][a]=i%2;
                draw(a,b,c[b][a]);}
            else {i--;
                continue;
            }}
        else{int a,b;
            move(i,c,b,a);
           // for (int n=0;n<3;n++) {for (int x=0;x<3;x++){cout<<c[n][x]<<" ";}cout<<"\n";}
            //cout<<"\n\n\n";
            draw(a,b,c[b][a]);
        }
        win=check(c,i);
        if (win!=0) break;
    }
    if (win==1)cout<<"first player wins";
    else if (win==-1)cout<<"second player wins";
    else if  (win==0)cout<<"draw";
    wait(3);
   
}
