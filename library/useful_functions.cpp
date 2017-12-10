#include <iostream>
using namespace std;


//INT_MIN
#include<bits/stdc++.h>

#define ll long long

#define F first
#define S second

#define endl "\n"

ll max(ll a, ll b){
    if(a > b) return a;
    return b;
}

void print(vector<int> v, int N){
    for (int i = 0; i < N; ++i)
    {
        cout << v[i] << " ";
    }
    cout << "\n" ;
}

void print(vector<int> v){
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << " ";
    }
    cout << "\n" ;
}

void print(vector<vector<int> > & dp)
{
    for (int i = 0; i < dp.size(); ++i)
    {
        print(dp[i], dp[i].size());
    }
}

void initialize2DMatrix(vector<vector<int> > & dp, int N){

    for (int i = 0; i < N; ++i)
    {
        vector<int> temp(N);
        for(int j = 0 ; j < N; j++)
        {
            temp[i] = 0;
        }
        dp[i] = temp;
    }
}
