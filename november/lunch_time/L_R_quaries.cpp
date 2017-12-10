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

int MAX = 1000000001;

void compute(int L, int R)
{
    ll maxi = 0;
    for (int i = L; i <= R; ++i)
    {
        maxi = max(maxi, (vec[i]-vec[L])*(vec[R]-vec[i]) );
    }
    cout << maxi << endl;
}

int main() {
    //std::ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >>T;
    for (int t = 0; t < T; ++t)
    {
        int N,Q;
        cin >> N >> Q;
        
        for (int i = 0; i < N; ++i)
        {
            cin >> vec[i];
        }

        for (int i = 0; i < Q; ++i)
        {
            int type, a, b;
            cin >> type >> a >> b;
            if(type == 1){
                compute(a-1,b-1);
            }else{
                vec[a-1] = b;
            }
            //print(vec, N);
        }

    }

    //
    //print(mat);

    ////////////// compute



    return 0;
}