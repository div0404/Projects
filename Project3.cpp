//Tic Tac Toe Game

#include<iostream>
using namespace std;

char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};

string n1 = " ";
string n2 = " ";
char token = 'x';
bool tie = false;
int row,col;

//constructing the board and adding the element
void functionOne(){

    
    cout<<"    |     |     "<<endl;
    cout<<" " <<board[0][0]<<"  | "<< board[0][1]<<"   |  "<<board[0][2]<<"   "<<endl;
    cout<<"____|_____|____ "<<endl;
    cout<<"    |     |     "<<endl;
    cout<<" " <<board[1][0]<<"  | "<< board[1][1]<<"   |  "<<board[1][2]<<"   "<<endl;
    cout<<"____|_____|____ "<<endl;
    cout<<"    |     |     "<<endl;
    cout<<" " <<board[2][0]<<"  | "<< board[2][1]<<"   |  "<<board[2][2]<<"   "<<endl;
    cout<<"    |     |     "<<endl;
    
    cout<<endl;
}

//taking the input digit and placing the token
void functionTwo(){
    int digit;
    
    if(token == 'x'){
        cout<<n1<<" please enter the digit"<<endl;
        cin>>digit;
    }
    if(token == '0'){
        cout<<n2<<" please enter the digit"<<endl;
        cin>>digit;
    }

    if(digit == 1){
        row = 0;
        col = 0;
    }
    if(digit == 2){
        row = 0;
        col = 1;
    }
    if(digit == 3){
        row = 0;
        col = 2;
    }
    if(digit == 4){
        row = 1;
        col = 0;
    }
    if(digit == 5){
        row = 1;
        col = 1;
    }
    if(digit == 6){
        row = 1;
        col = 2;
    }
    if(digit == 7){
        row = 2;
        col = 0;
    }
    if(digit == 8){
        row = 2;
        col = 1;
    }
    if(digit == 9){
        row = 2;
        col = 2;
    }
    else if(digit<1 or digit>9){
        cout<<"Invalid!!!"<<endl;
    }

    if(token == 'x' and board[row][col]!='x' and board[row][col]!='0'){
        board[row][col] = 'x';
        token = '0';
    }
    else if(token == '0' and board[row][col]!='x' and board[row][col]!='0'){
        board[row][col] = '0';
        token = 'x';
    }
    else{
        cout<<"There is no space available"<<endl;
        functionTwo();
    }
    functionOne();
}

//condition to win the game & whether game is still on | it is a tie
bool functionthree(){
    //condion to win
    for(int i=0;i<3;i++){
        if((board[i][0] == board[i][1] and board[i][0] == board[i][2]) || (board[0][i] == board[1][i] and board[0][i]==board[2][i])){
            return true;
        }
    }
    if(board[0][0]==board[1][1] and board[0][0]==board[2][2] || board[0][2]==board[1][1] and board[0][2]==board[2][0]){
        return true;
    }

    //whether game is still on
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]!='x' and board[i][j]!='0'){
                return false;
            }
        }
    }
    return tie = true;
}

int main(){

    cout<<"Enter the name of the player1"<<endl;
    getline(cin,n1);
    cout<<"Enter the name of the player2"<<endl;
    getline(cin,n2);

    cout<<n1 <<" is player1 so he will play first "<<endl;
    cout<<n2<<" is player2 so he will play second "<<endl;
    
    functionOne();

    while(!functionthree()){
        functionTwo();
        functionthree();
    }

    if(token == 'x' and tie == false){
        cout<<n2<<" won!!"<<endl;
    }
    else if(token == '0' and tie == false){
        cout<<n1<<" won!!"<<endl;
    }
    else{
        cout<<"its a draw!!"<<endl;
    }
}