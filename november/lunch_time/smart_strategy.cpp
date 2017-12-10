#include <iostream>
using namespace std;

#define endl "\n"

//INT_MIN
#include<bits/stdc++.h>

#define ll long long
vector<int> vec(500005);

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

void compute(vector<int> D, vector<int> quaries)
{
    int N = D.size();
    int Q = quaries.size();

    long mul = 1;

    for (int i = 0; i < N && mul < MAX; ++i)
    {
        mul *=  D[i];
    }

    if(mul >= MAX){
        for (int i = 0; i < Q; ++i)
        {
            cout << "0" << " ";
        }
        cout << endl;
    }else{
        for (int i = 0; i < Q; ++i)
        {
            cout << quaries[i]/mul << " ";
        }
        cout << endl;
    }



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
        vector<int >  D(N);
        
        for (int i = 0; i < N; ++i)
        {
            cin >> D[i];
        }

        vector<int> quaries(Q);

        for (int i = 0; i < Q; ++i)
        {
            cin >> quaries[i];
        }

        compute(D,quaries);

    }

    //
    //print(mat);

    ////////////// compute



    return 0;
}