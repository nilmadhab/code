#include <iostream>
using namespace std;
//http://www.spoj.com/problems/AGGRCOW/
#include<bits/stdc++.h>

void print(string s, vector<int> v){
    cout << s << " " ;
    for(auto i : v){
        cout << i << " ";
    }
    cout << "\n" ;
}

void print(string s, vector<bool> v){
    cout << s << " " ;
    for(auto i : v){
        cout << i << " ";
    }
    cout << "\n" ;
}


void compute(vector<int> ar){
    
    int N = ar.size();
    if(N < 2) {
        cout << N << "\n";
        return;
    }
    
    vector<int> dp(N);
    for (int i = 0; i < N; ++i)
    {
        dp[i] = 1;
    }

    //dp[0] = 1;

    int MAXI = 1;

    for (int i = 1; i < N; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if(abs(ar[i]) > abs(ar[j]) && ar[i]*ar[j] < 0){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        MAXI = max(MAXI, dp[i]);
    }

    //print("res", dp);
     cout << MAXI << "\n";

}
// TIME complexity = NlogN + C*(N + N  ) = 2*C*N
// N = 100,000 , 10^5, C <= N need to do it in NlogN time 
int main() {
    //std::ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<int> ar;
    for (int i = 0; i < N; ++i)
    {
        int a ;
        
        cin >> a;
        ar.push_back(a) ;
        //print("ar", ar);
        
        
        
        
    }
    
    compute(ar);
    
    return 0;
}