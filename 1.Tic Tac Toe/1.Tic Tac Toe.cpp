#include <iostream>
#include <string>
using namespace std;
class player{
public:
char  username[16]={" player "};
int score={0};
friend void playerinput();
char token;
void addscore(){
    score++;
}
void takename(){
    char p;
    do{
    cout<<"Please enter your username :)";
    cin>>username;
    cout<<"Select X/O :"<<endl;
    cin>>token;
    cout<<"Press Y/y to continue with :"<<username<<" and "<<token<<endl;
    cin>>p;
    }while(p != 'y'&& p!='Y');
}   
   
};
class board{
    public:
    char ttt[3][3]={{'-','-','-'},
                    {'-','-','-'},
                    {'-','-','-'}};
    int col,row;
    friend void playerinput();
    void tiecheck();
    void display(){
        for(int i =0;i<3;i++){
            for (int j=0;j<3;j++)
            {
                cout<<(ttt[i][j])<<" ";
            }
             cout<<endl;
        }
    }
    
};
void playerinput(player &a2,board &bo){
    cout<<a2.username<<"  make your move  :"<<endl;
    while(true){
    cout<<"Enter column :"<<endl;
    cin>>bo.col;
    cout<<"Enter row :"<<endl;
    cin>>bo.row;    
    if (bo.row < 0 || bo.row > 2 || bo.col < 0 || bo.col > 2|| bo.ttt[bo.col][bo.row] != '-') {
        cout << " Invalid move. Try again.  " << endl;
        continue;
    }
    else{
        bo.ttt[bo.col][bo.row]=a2.token;
        bo.display();
        break;

    }
    }
}
bool wincheckp11(const char (&arr)[3][3],const player &p1){
    for(int i=0 ;i<3;i++){
        if((arr[i][0]== p1.token && arr[i][1]== p1.token && arr[i][2]== p1.token)||((arr[0][i]==p1.token && arr[1][i]==p1.token && arr[2][i]==p1.token))){
            cout<<"Player : "<<p1.username<<" won "<<endl;
            return true;
        }
    }
    return false;
}
bool wincheckp22(const char (&arr)[3][3],const player &p1){
    for(int i=0 ;i<3;i++){
    if((arr[i][0]== p1.token && arr[i][1]== p1.token && arr[i][2]== p1.token)||((arr[0][i]==p1.token && arr[1][i]==p1.token && arr[2][i]==p1.token))){
        cout<<"Player : "<<p1.username<<"  won "<<endl;
        return true;
    }
    }
    return false;
    }
bool tiecheck(const char arr[3][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(arr[i][j]=='-'){return false;}
        }
    }
    return true;
}
int main(){
cout<<"Tic Tac To"<<endl;
cout<<"Loading"<<endl;
cout<<"============"<<endl;
cout<<"00|01|02"<<endl;
cout<<"10|11|12"<<endl;
cout<<"20|21|22"<<endl;
cout<<"Press Enter to continue "<<endl;
player p1;
p1.takename();
player p2;
p2.takename();
board b;
b.display();
while(true){
    b.display();
    playerinput(p1,b);
    if(wincheckp11(b.ttt,p1)){break;}
    playerinput(p2,b);
    if (wincheckp22(b.ttt,p2)){break;}
    if(tiecheck(b.ttt)){cout<<" Its a Tie!! ";break;}
}

return 0;
}