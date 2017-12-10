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

int find_median(vector<int> ar, int K)
{
    
    int N = ar.size();
    assert(K < N);

    sort(ar.begin(), ar.end());

    //print(ar);

    return ar[(N+K)/2];

}



int compute(string s){

    int N = s.size();

    vector<vector<bool> > dp(N);
    for (int i = 0; i < N; ++i)
    {
        vector<bool> temp(N);
        dp[i] = temp;
    }

    int count = 0;
    for (int i = N-2; i > -1 ; i--){
        for(int j = i+1; j < N ; j++){
            //check if S[i:j] is valid
            if(s[i] == s[j]){
                if(j == i+1 || j == i+2){
                    dp[i][j] = true; 
                    count +=1;
                }
                else{
                    if(dp[i+1][j-1] == true && s[i+1] == s[i+2]){
                        dp[i][j] = true;
                        count +=1;
                    }
                }

            }
        }
    }
    return count;

}
int main() {
//std::ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;

    
    for (int i = 0; i < T; ++i)
    {

        int N,K;
        cin >> N >> K;
        vector<int> ar(N);
        for(int j = 0 ; j < N ; j ++)
        {
            cin >> ar[j];
        }

        cout << find_median(ar, K) << "\n";
    }

    return 0;
}