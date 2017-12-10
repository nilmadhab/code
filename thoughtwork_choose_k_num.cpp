#include <iostream>
using namespace std;

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

void compute(int N , vector<int> vec , ll S){

    int start = 0;
    int end = N-1;
    int MAX_K = 0;
    ll max_diff = 0;
    while( end >= 0 && aux(start, end , N) > S ){
        end -=1;
    }
    MAX_K = end-start+1;
    max_diff = aux(start, end , N);
    
    //cout  << MAX_K << " max k , max diff  " << max_diff << " start, end " << start << " " << end << endl; 
    start +=1;
    while(start < N){
        end = max(end, start);
        int temp = end;
        while(end + 1 < N && aux(start, end+1 ,N) <= S){
            end +=1;
        }
        if(end - start + 1  > MAX_K){
            MAX_K = end-start+1;
            max_diff = aux(start, end ,N);
        }else if( end - start + 1  == MAX_K && aux(start, end ,N) > max_diff ){
            MAX_K = end-start+1;
            max_diff = aux(start, end ,N);
        }
        
        //cout << MAX_K << " max k , max diff  " << max_diff << " start, end " << start << " " << end << endl; 
        start +=1;
    }

    cout << MAX_K << " " << max_diff << endl;


}

int main() {
    //std::ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;

    for (int i = 0; i < T; ++i)
    {

        int N;
        ll S;
        cin >> N >> S ;
        assert(N <= 50000);
        vec.clear();
        for (int i = 0; i < N; ++i)
        {
            cin >> vec[i];
        }
        
        sort(vec.begin(), vec.begin() + N);
        compute(N, vec, S);
    }

    return 0;
}