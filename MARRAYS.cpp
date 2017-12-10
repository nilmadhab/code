#include <iostream>
using namespace std;
#include <vector>
#include <math.h>
#include <assert.h>
#include<bits/stdc++.h>

int max_cost = 0;

void print(vector<int> v){
    for(auto i : v){
        cout << i << " ";
    }
    cout << " | " ;
}


void print_vec_vec(vector< vector<int> > & vec)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        print(vec[i]);
    }

    cout << " \n " ;
}

int cost(vector<vector<int> > & vec)
{
    int ans = 0;
    for (int i = 0; i < vec.size()-1; ++i)
    {
        ans += abs(vec[i][vec[i].size()-1] - vec[i+1][0])*(i+1);
    }

    return ans;


}

void rotate(vector<vector<int> > & vec, int ind)
{
    assert(ind >=0 && ind < vec.size());

    int first = vec[ind][0];

    vec[ind].erase(vec[ind].begin());
    vec[ind].push_back(first);

}

void backTrack(vector<vector<int> > & vec, int rotation_index)
{
    //cout << "inside back tyrack "<< " cost " << max_cost<< " " << rotation_index << " rotation_index" << endl;
    if(rotation_index == vec.size()) return;
    //print_vec_vec(vec);
    for (int i = 0; i < vec[rotation_index].size(); ++i)
    {

        max_cost = max(max_cost, cost(vec));
        backTrack(vec, rotation_index+1);
        rotate(vec, rotation_index);
        //print_vec_vec(vec);

    }

}

void compute(vector<vector<int> > & vec){

    if(vec.size() == 2){

        vector<int> first = vec[0];
        vector<int> second = vec[1];

        sort(first.begin(), first.end());
        sort(second.begin(), second.end());

        cout << max( abs(first[0]-second[second.size()-1] ) , 
            abs(second[0]-first[first.size()-1] ) ) << '\n';

    }else{
        backTrack(vec, 0);
        //print_vec_vec(vec);

        cout << max_cost << '\n';
    }
    
    

}
int main() {
    //std::ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    //vector<int> ar;
    for (int i = 0; i < T; ++i)
    {
        max_cost = 0;
        int N ;
        cin >> N;
        vector<vector<int> > info(N);
        for(int j= 0 ; j < N ; j ++){
            int M;
            cin >> M;
            vector<int> temp(M);
            for (int m = 0; m < M; ++m)
            {
                cin >> temp[m] ;
            }

            info[j] = temp;
        }

        compute(info);
    }
    
    

    
    
    return 0;
}