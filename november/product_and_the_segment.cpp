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

void print(vector< vector< vector<int> > >  vec ){
    for (int i = 0; i < vec.size(); ++i)
    {
        cout << i  << " th second  " << endl;

        for(int j = 0 ; j < vec[i].size() ; j++){
            for(int k = 0; k < vec[j].size() ; k++)
            {
                cout << vec[i][j][k] << " " ;
            }
            cout << endl;
        }
    }
    cout << endl;
}

ll aux(int start, int end , int N){

    assert(start < N && end < N && start <= end );

    return (vec[end] - vec[start])*(end-start+1);
}

void getMaximumForEachLine(vector< vector< vector<int> > >  vec){

    int M = vec.size();
    int N = vec[0].size();

    vector< pair< int, int >  > maxis(M);
    if(M > N){
        M = N;
    }
    

    for (int i = 0; i < M; ++i)
    {
        // i is the second 
        // first line first second, second line second sec
        int maxi = 0;
        for(int j = 0 ; j < N; j ++){
            if(maxi <= vec[i][i][j]){
                maxi = vec[i][i][j];
                maxis[i] = make_pair(i+1, j+1 );
            }
            
        }
    }

    for (int i = 0; i < M; ++i)
    {
        cout << maxis[i].first << " " << maxis[i].second << endl;
    }



}

void swap(int & a, int & b){

    int temp = a;
    a = b;
    b = temp;

}

int product(vector<int> A, int P, int L, int R){
    if(L > R){
        swap(L ,R);
    }

    int ans = A[L]%P;
    for (int i = L+1; i <= R; ++i)
    {
        ans = ((ans % P)*(A[i] % P)) % P ;
    }


    return ans;
}

void compute(vector<int> A, vector<int> B, int P, int Q)
{
    int N = A.size();
    int LEN_B = B.size();
    int L, R, last_answer = 0 ;
    for (int i = 0; i < Q; ++i)
    {
        if(i == 0){
            L = B[0]%N;
            R = B[1]%N;           
        }else{
            if(i%64 == 0){
                int ind = i/64;
                L = (B[ind] + last_answer) % N;
                R = (B[ind+1] + last_answer) % N;   
            }else{
                L = (L + last_answer) % N ; 
                R = (R + last_answer) % N ;
            }
        }

        last_answer = (product(A, P, L, R)+1)%P;

        //cout << L << " " << R << " " <<  last_answer << " L R last_answer " << endl;


    }

    cout << last_answer % P << endl;

}

int main() {
    //std::ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T ;//>> M;
    for (int t = 0; t < T; ++t)
    {
        int N, Q, P;
        cin >> N >> P >> Q;
        vector<int> A(N);

        for (int i = 0; i < N; ++i)
        {
            cin >> A[i];
        }

        int LEN_B = Q/64 + 2;

        vector<int> B(LEN_B);

        for (int i = 0; i < LEN_B; ++i)
        {
            cin >> B[i] ; 
        }


        compute(A, B, P, Q);
    }

    //
    //print(mat);

    ////////////// compute
    


    return 0;
}