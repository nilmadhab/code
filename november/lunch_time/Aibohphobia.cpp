#include <iostream>
using namespace std;

#define endl "\n"

//INT_MIN
#include<bits/stdc++.h>

#define ll long long
vector<int> vec(100005);

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

void print(vector<vector<int> > & dp)
{
    for (int i = 0; i < dp.size(); ++i)
    {
        print(dp[i], dp[i].size());
    }
}

int MAX = 1000000001;

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

void compute(string s)
{
    int N = s.size();
    vector<vector<int> > dp (N);
    initialize2DMatrix(dp, N);
    for (int i = N-1; i >= 0 ; --i)
    {
        for(int j = i+1 ; j < N; j++ )
        {
            if(s[i] == s[j])
            {
                if(j==i+1){
                    dp[i][j] = 0;
                }else{
                   dp[i][j] = dp[i+1][j-1]; 
                }
                
            }else{
                if(j == i+1){
                    dp[i][j] = 1;
                }else{
                    dp[i][j] = 1 + min( dp[i+1][j] , dp[i][j-1] );
                }
            }
        }
    }

    //print(dp);

    cout << dp[0][N-1] << endl;


}

int main() {
    //std::ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >>T;
    for (int t = 0; t < T; ++t)
    {
        string s;
        cin >> s;
        compute(s);

    }

    //
    //print(mat);

    ////////////// compute



    return 0;
}