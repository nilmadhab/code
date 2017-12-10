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

    assert(M == N);

    vector< pair< int, int >  > maxis_up_down(M);
    vector< pair< int, int >  > maxis_left_right(M);
    
    ll total_cost_up_down = 0;
    ll total_cost_left_right = 0;

    for (int i = 0; i < M; ++i)
    {
        // i is the second 
        // first line first second, second line second sec
        int maxi = 0;
        for(int j = 0 ; j < N; j ++){
            if(maxi <= vec[i][i][j]){
                maxi = vec[i][i][j];
                maxis_up_down[i] = make_pair(i+1, j+1 );
            }

            
        }

        total_cost_up_down += maxi;
    }


    for (int i = 0; i < M; ++i)
    {
        // i is the second 
        // first line first second, second line second sec
        int col = i;
        int maxi = 0;
        for(int row = 0 ; row < N; row ++){
            if(maxi <= vec[col][row][col]){
                maxi = vec[col][row][col];
                maxis_left_right[i] = make_pair(row+1, col+1 );
            }           
        }

        total_cost_left_right += maxi;
    }

    if(total_cost_up_down > total_cost_left_right){
        for (int i = 0; i < M; ++i)
        {
            cout << maxis_up_down[i].first << " " << maxis_up_down[i].second << endl;
        }

    }else{
        for (int i = 0; i < M; ++i)
        {
            cout << maxis_left_right[i].first << " " << maxis_left_right[i].second << endl;
        }

    }

    


}

void mix(vector< vector< vector<int> > >  vec){
    int M = vec.size();
    int N = vec[0].size();

    int full = M/N + 1;

    int remaining = N - full;


    //cout << full << " " << remaining << " full and remaining " << endl;

    vector< pair< int, int >  > maxis_up_down(remaining);

    for (int i = 0; i < remaining; ++i)
    {
        // i is the second 
        // first line first second, second line second sec
        int maxi = 0;
        for(int j = 0 ; j < N; j ++){
            if(maxi <= vec[i][i][j]){
                maxi = vec[i][i][j];
                maxis_up_down[i] = make_pair(i+1, j+1 );
            }   
        }
    }


    for (int i = 0; i < remaining; ++i)
    {
        cout << maxis_up_down[i].first << " " << maxis_up_down[i].second << endl;
        
    }


    int i = remaining ;

    int row = remaining+1;
    int col = 1;
    cout << row << " " << col << endl;
    while(i < M){

        if(col == N){
            row +=1;
            col = 1;
        }else{
            col +=1;
        }

        cout << row << " " << col << endl;
        i+=1;
    }





}

void compute(vector< vector< vector<int> > >  vec)
{
    int M = vec.size();
    int N = vec[0].size();

    if(M == N){
        getMaximumForEachLine(vec);
        return;
    }


    mix(vec);
    return;

    

    /*
    int i = 1 ;

    int row = 1;
    int col = 1;
    cout << row << " " << col << endl;
    while(i < M){

        if(col == N){
            row +=1;
            col = 1;
        }else{
            col +=1;
        }

        cout << row << " " << col << endl;
        i+=1;
    }
    */
    

    

}

int main() {
    //std::ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M;
    cin >> N >> M;
    vector<vector< vector< int > > >  mat(M);
    vector< pair< int, int >  > maxis(M);
    for (int t = 0; t < M; ++t)
    {
        vector<vector<int > > temp(N);
        int maxi = 0;
        //pair < int, int > 
        for (int i = 0; i < N; ++i)
        {
            vector<int > temp2(N);
            for(int j = 0 ; j < N ; j++)
            {
                cin >> temp2[j];
            }
            temp[i] = temp2;
        }

        mat[t] = temp;
    }

    //
    //print(mat);

    ////////////// compute
    compute(mat);


    return 0;
}