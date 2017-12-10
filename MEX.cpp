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
    
    int N = ar.size();

    for (int i = 0; i < N; ++i)
    {
        /* code */
    }

    printf("%d\n",ans-1 );

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
        int a ;
        scanf("%d" &a);
        ar.push_back(a);
    }
    sort(ar.begin(), ar.end());
    //print(ar);
    compute(ar,K);
    return 0;
}