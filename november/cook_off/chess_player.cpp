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

void print(map<int, int> myMap){
    for(map<int, int >::const_iterator it = myMap.begin();
    it != myMap.end(); ++it)
    {
        std::cout << it->first << " " << it->second  << "\n";
    }

    cout << endl;
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

void set_2_max(vector< int > & mat, int & large, int & largest){
    largest = mat[0];
    large = mat[1];
    if(large > largest){
        int temp = largest;
        largest = large;
        large = temp;
    }
    for (int i = 2; i < mat.size(); ++i)
    {
        if(mat[i] > largest){
            large = largest;
            largest = mat[i];
        }else if(mat[i] > large){
            large = mat[i];
        }
    }
}

void compute(vector< vector<int > >  & mat)
{
    int N = mat.size();
    vector<int> available(N);
    for (int i = 0; i < N; ++i)
    {
        available[i] = 1;
    }
    cout << "wait" << endl;
    for (int i = 1; i < mat.size(); ++i)
    {
        int min = mat[i][1];
        int max = mat[i][2];
        bool flag = false;
        for(int j = 0 ; j < i && flag == false ; j++){
            if(
                available[j] == 1 && 
                mat[j][0] >= min && mat[j][0] <= max  // rating
                && mat[i][0] >= mat[j][1] && mat[i][0] <= mat[j][2]
                && mat[j][4] == mat[i][4] // time 
                && mat[j][3] == mat[i][3] // isRated
                &&( (mat[i][5] == 2 && mat[j][5] == 2 ) || 
                    (mat[i][5] == 1 && mat[j][5] == 0) ||  
                    (mat[i][5] == 0 && mat[j][5] == 1) )
                )
            {
                available[i] = 0;
                available[j] = 0;
                cout << j+1 << endl;
                flag = true;
            }
        }
        if(flag == false){
            cout << "wait" << endl;
        }
    }

}

int main() {
    //std::ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;

    for (int i = 0; i < T; ++i)
    {

        int  N;
        cin >> N;

        vector< vector<int> >  mat(N);

        for (int i = 0; i < N; ++i)
        {
           int R, min, max, time;
           string isRated, color;
           cin >> R >> min >> max >> time >> isRated >> color;
           vector<int> temp(6);
           temp[0] = R;
           temp[1] = min;
           temp[2] = max;
           temp[3] = time;

           if(isRated == "rated"){
             temp[4] = 1;
           }else{
            temp[4] = 0;
           }

           if(color == "white"){
                temp[5] = 0;
           }else if(color == "black"){
                temp[5] = 1;
           }else{
                temp[5] = 2;
           }

           mat[i] = temp;

        }
        compute(mat);
    }
    
    return 0;
}