#include <iostream>
using namespace std;

#define endl "\n"

//INT_MIN
#include<bits/stdc++.h>

//#include "/Users/nilmadhab/Desktop/code/library/useful_functions.cpp"

#define ll long long
vector<int> vec(100005);


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
    if(N == 1)
    {
        cout << 0 << endl;
        cout << vec[0] << endl;
        return;
    }
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
        int N;
        cin >> N;
        for (int i = 0; i < N; ++i)
        {
            cin >> vec[i];
        }
        compute(N);
    }

    //
    //print(mat);

    ////////////// compute



    return 0;
}