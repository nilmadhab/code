#include <iostream>
using namespace std;

#define endl "\n"

//INT_MIN
#include<bits/stdc++.h>

//#include "/Users/nilmadhab/Desktop/code/library/useful_functions.cpp"

#define ll long long
vector<int> vecAX(1005);
vector<int> vecAY(1005);
vector<int> vecBX(1005);
vector<int> vecBY(1005);



ll max(ll a, ll b){
    if(a > b) return a;
    return b;
}

ll min(ll a, ll b){
    if(a > b) return b;
    return a;
}

void compute(int N)
{
    cout << N << endl;
    for (int i = 1; i < N; ++i)
    {
        cout << vec[i] << " ";
    }
    cout << vec[0] << endl;
}

int main() {
    //std::ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin >>T;
    for (int t = 0; t < T; ++t)
    {
        int N,M;
        cin >> N >> M;
        for (int i = 0; i < N; ++i)
        {
            cin >> vecAX[i] >> vecAY[i];
        }

        for (int i = 0; i < M; ++i)
        {
            cin >> vecBX[i] >> vecBY[i];
        }

        compute(N, M);
    }

    //
    //print(mat);

    ////////////// compute



    return 0;
}