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

void print(vector<int> v){
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << " ";
    }
    cout << "\n" ;
}

void print_graph(vector< vector<int> > & vec)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        print(vec[i]);
    }

    cout << " \n " ;
}

bool maximum_index(vector<vector< int > > & mat, int & row, int & col)
{
    int num_rows = mat.size();
    int num_cols = mat[0].size();
    int x = 0;
    int y = 0;
    int maxi = -1;
    for (int i = 0; i < num_rows; ++i)
    {
        for(int j = 0 ; j < num_cols; j++)
        {
            if(maxi < mat[i][j]){
                maxi = mat[i][j];
                x = i;
                y = j;
            }
        }
    }

    if(maxi > 0){
        row = x;
        col = y;
        return true;
    }
    return false;
}

void BFS(vector<vector< int > > & mat, int row, int col)
{
    int num_rows = mat.size();
    int num_cols = mat[0].size();

    queue<pair<int, int> > que;
    que.push(make_pair(row, col));

    while(que.size() > 0)
    {
        pair<int, int> pop = que.front();
        que.pop();
        int x = pop.first;
        int y = pop.second;

        if(x+1 < num_rows &&
                 mat[x+1][y] <=  mat[x][y] &&
                  mat[x+1][y] != -1){
            que.push(make_pair(x+1, y));
        }
        if(x-1 >= 0 &&
                 mat[x-1][y] <=  mat[x][y] &&
                  mat[x-1][y] != -1){
            que.push(make_pair(x-1, y));
        }
        if(y+1 < num_cols &&
                 mat[x][y+1] <=  mat[x][y] &&
                  mat[x][y+1] != -1){
            que.push(make_pair(x, y+1));
        }
        if(y-1 >= 0 &&
                 mat[x][y-1] <=  mat[x][y] &&
                  mat[x][y-1] != -1){
            que.push(make_pair(x , y-1));
        }

        mat[x][y] = -1; 
    }

    //print_graph(mat);

}

void compute(vector<vector< int > > & mat)
{
    int num_rows = mat.size();
    int num_cols = mat[0].size();

    int row = 0;
    int col = 0;
    int count = 0;
    while(maximum_index(mat, row, col) == true){
        BFS(mat, row, col);
        count+=1;
    }



    cout << count << endl;

}

int main() {
    //std::ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;

    for (int i = 0; i < T; ++i)
    {

        int  n,m;
        cin >> n >> m;

        vector<vector< int > > mat(n);

        for (int i = 0; i < n; ++i)
        {
            vector<int> temp(m);
            for (int j = 0; j < m; ++j)
            {
                cin >> temp[j];
            }
            mat[i] = temp;
        }
        compute(mat);
    }
    
    return 0;
}