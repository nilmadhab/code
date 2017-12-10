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

ll aux(int start, int end , int N){

    assert(start < N && end < N && start <= end );

    return (vec[end] - vec[start])*(end-start+1);
}

void compute(int l , int r, int L, int R)
{
    int count = 0;
    for (int i = l; i <= r; ++i)
    {
        int maximum = vec[i];
        if(maximum > R){
            continue;
        }
        for (int j = i; j <= r; ++j)
        {
            if(maximum < vec[j]){
                maximum =  vec[j];
            }
            if(maximum > R){
                break;
            }

            if(maximum >= L && maximum <= R){
                count +=1;
            }
        }
    }

    cout << count << endl;

}

int main() {
    //std::ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    //cin >> T;
    T = 1;

    for (int t = 0; t < T; ++t)
    {

        int  N,Q, L, R;
        cin >> N >> Q >> L >> R;
        for (int i = 0; i < N; ++i)
        {
            vec[i] = 0;
        }
        for (int i = 0; i < Q; ++i)
        {
            int a , b , c;
            cin >> a >> b >> c;
            if(a == 1){
                // replace bth element by c
                vec[b-1] = c; 
                //print(vec, N);

            }else{
                /*
                Return the number of subarrays [a , b] that lies in subarray [l , r] 
                such that the value of the maximum array element in that subarray 
                is atleast L and atmost R. 
                */
                compute( b-1, c-1, L, R);
            }
        }

    }

    return 0;
}