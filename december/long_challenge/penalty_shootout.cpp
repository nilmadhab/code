#include <iostream>
using namespace std;

#define endl "\n"

//INT_MIN
#include<bits/stdc++.h>

//#include "/Users/nilmadhab/Desktop/code/library/useful_functions.cpp"

#define ll long long
vector<int> vec(200005);


ll max(ll a, ll b){
    if(a > b) return a;
    return b;
}

ll min(ll a, ll b){
    if(a > b) return b;
    return a;
}


int diamond(int roomNumber)
{
    int odd = 0;
    int even = 0;
    int count = 0;
    while(roomNumber > 0){
        if(roomNumber % 2 ==0){
            even += roomNumber%10;
        }else{
            odd += roomNumber%10;
        }
        roomNumber = roomNumber/10;
    }

    return abs(odd-even);
}

void findWhenDecided(string s)
{

}


/*
    10 10 01 10 01 
*/
void compute(string s)
{
    int count = 0;
    bool isWinnerFound = false;
    int teamA = 0;
    int teamB = 0;
    int matchLeftA = 5;
    int matchLeftB = 5;
    for (int i = 0; i < 10 && !isWinnerFound; ++i)
    {
        if(i%2 == 0){
            if(s[i] == '1'){
                teamA +=1;
            }
            matchLeftA -=1;
        }else{
            if(s[i] == '1'){
                teamB +=1;
            }
            matchLeftB -= 1;
        }
        if(teamA > teamB + matchLeftB ){
            cout << "TEAM-A " << i+1 << endl;
            return;
        }else if(teamB > teamA + matchLeftA){
            cout  << "TEAM-B " << i+1 << endl;
            return;
        }
    }

    for (int i = 10; i <= 18;)
    {
        if(s[i] != s[i+1]){
            if(s[i] == '1'){
                cout << "TEAM-A " << i+2 << endl;
                return;
            }else{
                cout << "TEAM-B " << i+2 << endl;
                return;
            }
        }
        i+=2;   
    }

    cout << "TIE " <<endl;
}

int main() {
    //std::ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //int T = 1;
    //cin >>T;
    string s;
    while(cin >> s){
        compute(s);
    }

    //
    //print(mat);

    ////////////// compute



    return 0;
}