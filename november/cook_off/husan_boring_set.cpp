#include <iostream>
using namespace std;

#define endl "\n"

//INT_MIN
#include<bits/stdc++.h>

#define ll long long
vector<int> vec(50005);

ll max(ll a, ll b){
    if(a > b) return a;
    return b;
}

ll aux(int start, int end , int N){

    assert(start < N && end < N && start <= end );

    return (vec[end] - vec[start])*(end-start+1);
}



void compute(int N, int P)
{
    string ans(N, 'b');
    string part(P, 'b');
    if(P <= 2){
        cout << "impossible" << endl;
        return;
    }

    part[0] = 'a';
    part[P-1] = 'a';


    for (int i = 0; i < N/P; ++i)
    {
        int start = i*P;
        for(int j = 0; j < P; j++){
            ans[start+j] = part[j];
        }
    }


    cout << ans << endl;





}

int main() {
    //std::ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;

    for (int i = 0; i < T; ++i)
    {

        int  N,P;
        cin >> N >> P;
        
        compute(N, P);
    }

    return 0;
}