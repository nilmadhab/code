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

void compute(vector< int > & mat)
{
    int N = mat.size();

    map<int, int> freq;

    for (int i = 0; i < N; ++i)
    {
        if(freq.find(mat[i]) != freq.end()){
            map<int, int>:: iterator it = freq.find(mat[i]);
            it->second +=1;
        }else{
            freq.insert(make_pair(mat[i], 1));
        }
    }

    int large = 0;
    int largest = 0;
    set_2_max(mat, large, largest);

    float large_count = (float)freq.find(large)->second;
    float largest_count = (float)freq.find(largest)->second;

    //cout << largest << " " << large << " " << prob_large << " " << prob_largest << endl;

    //cout << prob_largest * prob_large << endl;


    ////////////////////////////////////

    if(large == largest){

        cout << (large_count/N) * (largest_count-1)/(N-1)  << endl; 

    }else{

        cout << (large_count/N) * (largest_count)/(N-1) + 
            (largest_count/N) * (large_count)/(N-1) << endl;


    }

   //print(freq);



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

        vector< int >  mat(N);

        for (int i = 0; i < N; ++i)
        {
           cin >>  mat[i];
        }
        compute(mat);
    }
    
    return 0;
}