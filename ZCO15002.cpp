#include <iostream>
using namespace std;
//https://www.codechef.com/ZCOPRAC/problems/ZCO12001
#include<bits/stdc++.h>

void print(vector<int> v){
    for(auto i : v){
        cout << i << " ";
    }
    cout << "\n" ;
}
void compute(vector<int> ar, int k){
    
    int ans = 0;
    int N = ar.size();

    int start = 0;
    int end = 1;

    while(end < N){
        while(end <N && ar[end] - ar[start] < k){
            end +=1;
        }
        ans += (N-end);
        start +=1;
    }

    printf("%d\n",ans );

}
int main() {
    //std::ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,K;
    cin >> N >> K;
    vector<int> ar;
    for (int i = 0; i < N; ++i)
    {
        int a;
        cin >> a;
        ar.push_back(a);
    }
    sort(ar.begin(), ar.end());
    compute(ar, K);
    return 0;
}