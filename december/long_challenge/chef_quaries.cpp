#include <iostream>
using namespace std;

#define endl "\n"

//INT_MIN
#include<bits/stdc++.h>

//#include "/Users/nilmadhab/Desktop/code/library/useful_functions.cpp"

#define ll long long
const int M = 1000005;
vector<int> vec(M);
int MOD = 1e9+7;

ll max(ll a, ll b){
    if(a > b) return a;
    return b;
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

void compute()
{

    ll sum = 0;

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <=N; ++j)
        {
            int roomNumber = i+j;

            sum += diamond(roomNumber);

            cout << roomNumber << " " <<  diamond(roomNumber) << " " << sum << endl;
        }
    }

    vec[0] = 2;

    for (int i = 1; i < M; ++i)
    {
        for(int row = 0; row<= i ; row++){
            
        }
    }

    cout << sum << endl;

    
}

int main() {
    //std::ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin >>T;
    for (int t = 0; t < T; ++t)
    {
        int N;
        cin >> N;
        compute(N);
        //print(vec, N);
    }

    //
    //print(mat);

    ////////////// compute



    return 0;
}