#include<iostream>
#include<cmath>
using namespace std;

void display(int n){
    cout<<"Sticks: ";
    for(int i = 1; i<=n; i++){
        cout<<i<<" ";
    }
    cout<<endl;
}

void printDivisors(int n)
{
    cout<<1<<" ";
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            if (n / i == i)
                cout << i << " ";
            else 
                cout << i << " " << n / i << " ";
        }
    }
    cout<<endl;
}
// for sticks >= 4, every even state is a winning state and ever odd one is losing state
//1st few states(1st one is state "0"): 1 2 3 4 5 6 7 8 9 10....
//                                      W L W W L W L W L W.....
//Since every nxt odd number(>=4) has only odd factors, u'll always land on an even number(which is a winning state) 
int main(){
    int sticks;
    cout<<"Number of sticks in this game: ";
    cin>>sticks;

    display(sticks);

    if(sticks&1){
        while(sticks != 0){
            cout<<"Alice's Options: ";
            printDivisors(sticks);
            int n;
            cin>>n;
            if(sticks%n != 0){
                cout<<"Wrong output. Enter again. ";
                cin>>n;
            }
            cout<<"Alice's turn: "<<n<<endl;
            sticks -= n;
            display(sticks);
            cout<<"Bob's Options: ";
            printDivisors(sticks);cout<<endl;
            if(sticks == 4){
                 cout<<"Bob's turn: "<<2<<endl;
            sticks -= 2;
            }
            else{
            cout<<"Bob's turn: "<<1<<endl;
            sticks--;}
            display(sticks);
        }
        cout<<"Bob Won!";
    }
    else{
        while(sticks != 0){
            cout<<"Alice's Options: ";
            printDivisors(sticks);
            if(sticks == 4){
                 cout<<"Alice's turn: "<<2<<endl;
            sticks -= 2;
            }
            else{
            cout<<"Alice's turn: "<<1<<endl;
            sticks--;}
            display(sticks);
            if(sticks==0){
                break;
            }
            cout<<"Bob's Options: ";
            printDivisors(sticks);
            int n;
            cin>>n;
            if(sticks%n != 0){
                cout<<"Wrong output. Enter again. ";
                cin>>n;
            }
            cout<<"Bob's turn: "<<n<<endl;
            sticks -= n;
            display(sticks);

    }
    cout<<"Alice Won!";
}
}