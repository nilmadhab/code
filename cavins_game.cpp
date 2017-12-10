#include <iostream>
using namespace std;

//INT_MIN
#include<bits/stdc++.h>



void print(vector<int> v){
    for(auto i : v){
        cout << i << " ";
    }
    cout << "\n" ;
}


void print_vec_vec(vector< vector<int> > & vec)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        print(vec[i]);
    }

    cout << " \n " ;
}

void initialize(vector<int> &vec, int val)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        vec[i] = val;
    }
}



void compute(vector<int>  & vec, int k){
    
    int answer = 0;

    int N = vec.size();

    if(N == 1) {
        cout << 0 << '\n';
        return;
    }

    vector<int> dp1(N);
    vector<int> dp2(N);

    initialize(dp1, 0);
    initialize(dp2, 0);

    for (int i = k+1; i < N; ++i)
    {
        int last_ind = max(k, i-2);
        int maxi = INT_MIN;
        for (int j = last_ind; j < i; ++j)
        {
            maxi = max(maxi, dp1[j]);
        }

        dp1[i] = maxi + vec[i];
    }

    //print(dp1);

    // back

    dp2[N-1] = dp1[N-1];
    dp2[N-2] = max(dp1[N-2], dp2[N-1] + vec[N-2]);

    for (int i = N-3; i >= 0; --i)
    {
        maxi = max(dp2[i+1], dp2[i+2]);

        dp2[i] = max(dp1[i], maxi + vec[i] );
    }

    //print(dp2);

    cout << dp2[0] << '\n';

}
int main() {
    //std::ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    //cin >> T;
    T = 1;
    //vector<int> ar;
    for (int i = 0; i < T; ++i)
    {
        
        int N, k ;
        cin >> N >> k;
        vector<int>  info(N);
        for(int j= 0 ; j < N ; j ++){
            cin >> info[j];
        }

        compute(info, k-1);
    }

    return 0;
}