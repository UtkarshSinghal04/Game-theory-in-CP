#include<iostream>
using namespace std;

void display(int n){
    cout<<"Sticks: ";
    for(int i = 1; i<=n; i++){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main(){
    int sticks;
    cout<<"Number of sticks in this game: ";
    cin>>sticks;

    display(sticks);
    if(sticks%4==0){
        cout<<"Can't Win(if you are smart)"<<endl;
        return 0;
    } 
    while(sticks!=0){
        cout<<"My turn: "<<(sticks%4)<<endl;
      sticks -= (sticks%4);
      display(sticks);
      if(sticks == 0){
        break;
      }
      int opp;
      cout<<"Your turn: ";
      cin>>opp;
      while((opp<1) || (opp>3)){
        cout<<"Can't remove these many sticks."<<endl;;
        cout<<"Your turn: ";
      cin>>opp;
      }  
      sticks -= opp;
      display(sticks);
    }
    cout<<"You lose!!";
    
}