// sorry for making the code this messy(T_T)

#include <bits/stdc++.h>
using namespace std;

vector<int> played_by;

//assuming computer plays optimally

void display(vector<int> x){
    cout<<"Sticks: ";
    for(int i = 0; i<x.size(); i++){
        cout<<x[i]<<" ";
    }
    cout<<endl;
}

void your_move(vector<int> &x){
    int n;
    cout<<"Pile you want to remove the sticks from: ";
    cin>>n;
    while((n>=x.size()) || (x[n] == 0)){
        cout<<"wtf bro?"<<endl;
        cout<<"Pile you want to remove the sticks from: ";
        cin>>n;
    }

    int a;
    cout<<"Sticks you want to remove from this pile: ";
    cin>>a;
    while(a>x[n]){
        cout<<"wtf bro?"<<endl;
        cout<<"Sticks you want to remove from this pile: ";
        cin>>a;
    }

    x[n] -= a;
    played_by.push_back(1);
}

bool all_zero(vector<int> x){
    bool a = true;
    for(int i = 0; i<x.size(); i++){
        if(x[i] != 0){
            a = false;
            exit;
        }
    }
    return a;
}
vector<int> non_zero(vector<int> x){
    vector<int> c;
    for(int i = 0; i<x.size(); i++){
        if(x[i] != 0){
            c.push_back(i);
        }
    }
    return c;
}

int hmm(vector<int> x){
    vector<int> d = non_zero(x);
    int a = 0;
    for(int i =  0; i<d.size(); i++){
        if(x[d[i]]==1){
            a++;
        }
    }
    if(a >= d.size() - 1){
        return a;
    }
    else return 0;
}

// void must(int a, vector<int> &x){
//     vector<int> d = non_zero(x);
//         for(int i = 0; i<d.size(); i++){
//                 if((x[d[i]]>1) && (d.size()%2==0)){
//                     x[d[i]] = 0;
//                     break;
//                 }
//                 else if((x[d[i]]>1) && (d.size()%2!=0)){
//                     x[d[i]] = 1;
//                     break;
//                 }
//                 played_by.push_back(0);
//             cout<<"Computer has played"<<endl;
//     }
// }

void computer_move1(vector<int> &x){
        int xor_sum = x[0];
        vector<int> d = non_zero(x);
        for(int i = 1; i<x.size(); i++){
            xor_sum = xor_sum^x[i];
        }
        if(xor_sum){
        for(int i = 0; i<d.size(); i++){
            if(((x[d[i]]^xor_sum)<x[d[i]])){
                x[d[i]] = x[d[i]]^xor_sum;
                break;
             }
            }
        }
        else{
            srand(time(0));
            int e = rand()%d.size();
            int g;
            do{
                if(x[d[e]] == 1){
                    x[d[e]]--;
                    break;
                }
            g = rand()%x[d[e]];    
            x[d[e]] -= g;
            }while(g==0);
        }
        played_by.push_back(0);
        cout<<"Computer has played"<<endl;
    }

    void computer_move2(vector<int> &x){
        vector<int> d = non_zero(x);
        srand(time(0));
            int e = rand()%d.size();
            x[d[e]]--;
             played_by.push_back(0);
        cout<<"Computer has played"<<endl;
    }

int main(){
    int p;
    cout<<"Number of piles: ";
    cin>>p;
    vector<int> n;
    for(int i = 0; i<p; i++){
        cout<<"Sticks in "<<(i)<<"th pile: ";
        int x;
        cin>>x;
        n.push_back(x);
    }

/*we have
display
your_move
non_zero
comtuter_move*/

    bool start;
    cout<<"If you want to play 1st, enter 1. Else enter 0."<<endl;
    cin>>start;

    display(n);

    if(start){
        while(!all_zero(n)){
        your_move(n);
        display(n);
        int t = hmm(n);
         vector<int> d = non_zero(n);
        if((t) || (d.size()==1)){
            if((-(t-d.size()))){
                for(int i = 0; i<d.size(); i++){
                if((n[d[i]]>1) && (d.size()%2==0)){
                    n[d[i]] = 0;
                    break;
                }
                else if((n[d[i]]>1) && (d.size()%2!=0)){
                    n[d[i]] = 1;
                    break;
                } }
                played_by.push_back(0);
            cout<<"Computer has played"<<endl;
            }
            else computer_move2(n);
            display(n);
            while(!all_zero(n)){
            your_move(n);
            display(n);
            if(all_zero(n)){
            break;
            }
            computer_move2(n);
            display(n);
            }
            break;
            }
        if(all_zero(n)){
            break;
        }
        computer_move1(n);
        display(n);}
    }
    else{
         while(!all_zero(n)){
            int t = hmm(n);
         vector<int> d = non_zero(n);
        if((t) || (d.size() == 1)){
            if((-(t-d.size()))){
                for(int i = 0; i<d.size(); i++){
                if((n[d[i]]>1) && (d.size()%2==0)){
                    n[d[i]] = 0;
                    break;
                }
                else if((n[d[i]]>1) && (d.size()%2!=0)){
                    n[d[i]] = 1;
                    break;
                } }
                played_by.push_back(0);
            cout<<"Computer has played"<<endl;
            }
            else computer_move2(n);
            display(n);
            while(!all_zero(n)){
            your_move(n);
            display(n);
            if(all_zero(n)){
            break;
            }
            computer_move2(n);
            display(n);
            }
            break;
            }
        else computer_move1(n);
        display(n);
        if(all_zero(n)){
            break;
        }
        your_move(n);
        display(n);
         t = hmm(n);
         d = non_zero(n);
        if((t) || (d.size() == 1)){
            if((-(t-d.size()))){
                for(int i = 0; i<d.size(); i++){
                if((n[d[i]]>1) && (d.size()%2==0)){
                    n[d[i]] = 0;
                    break;
                }
                else if((n[d[i]]>1) && (d.size()%2!=0)){
                    n[d[i]] = 1;
                    break;
                } }
                played_by.push_back(0);
            cout<<"Computer has played"<<endl;
            }
            else computer_move2(n);
            display(n);
            while(!all_zero(n)){
            your_move(n);
            display(n);
            if(all_zero(n)){
            break;
            }
            computer_move2(n);
            display(n);
            }
            break;
            }
        }
    }

    if(*(played_by.end()-1) == 1){
        cout<<"COMPUTER WON!"<<endl;
    }
    else{
        cout<<"YOU WON!"<<endl;
    }

}