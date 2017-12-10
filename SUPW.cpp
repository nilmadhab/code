#include <iostream>
using namespace std;
//https://www.codechef.com/submit/complete/15499449
#include<bits/stdc++.h>

void print(vector<int> v){
    for(auto i : v){
        cout << i << " ";
    }
    cout << "\n" ;
}

int min(int a, int b, int c){
    if(a < b && a < c) return a;
    if(b < a && b < c) return b;
    return c;
}
long min(long a, long b, long c){
    if(a < b && a < c) return a;
    if(b < a && b < c) return b;
    return c;
}
void compute(vector<int> ar){
    
    int N = ar.size();
    if(N < 3){
     cout << 0 << "\n";   
     return;
    }
    vector<long> dp(N);

    dp[0] = ar[0];
    dp[1] = ar[1];
    dp[2] = ar[2];

    for (int i = 3; i < N; ++i)
    {
        dp[i] = ar[i] + min(dp[i-1], dp[i-2], dp[i-3]);
    }
    //print(dp);
    cout << min(dp[N-1], dp[N-2], dp[N-3])  << "\n";

}
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
        ar.push_back(a);
    }
    //sort(ar.begin(), ar.end());
    //print(ar);
    compute(ar);
    return 0;
}