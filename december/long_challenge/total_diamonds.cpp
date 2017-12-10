#include <iostream>
using namespace std;

#define endl "\n"

#include<bits/stdc++.h>
#define ll long long
const int M = 1000001;
vector<ll> vec(M);


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
    vec[0] = 0;
    vec[1] = 2;
    vec[2] = 12;
    int last = 7;
    for (int i = 3; i <= M; ++i)
    {
        vec[i] = vec[i-1]+diamond(i*2);
        last = last- diamond(i) + diamond(2*i-1);
        vec[i] += last*2;
        last += diamond(i*2);
    }

}

int main() {
        //std::ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    compute();
    cin >>T;
    for (int t = 0; t < T; ++t)
    {
        int N;
        cin >> N;
        assert(N <= M);
        cout<< vec[N] << endl;
            //print(vec, N);
    }

        //
        //print(mat);

        ////////////// compute



    return 0;
}