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

ll aux(int start, int end , int N){

    assert(start < N && end < N && start <= end );

    return (vec[end] - vec[start])*(end-start+1);
}

void compute(vector< vector<int> > & graph, vector<int>  branches, int city )
{

}

int main() {
    //std::ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    //T = 1;

    for (int t = 0; t < T; ++t)
    {

        int  N,M;
        cin >> N >> M;
        vector< vector < int > > graph(N);
        unordered_set<int> branches;
        for (int i = 0; i < N; ++i)
        {
            vector<int > vec;
            graph[i]  = vec;
        }
        for (int i = 0; i < N-1; ++i)
        {
            int u, v;
            cin >> u >> v;

            graph[u-1].push_back(v-1);
            graph[v-1].push_back(u-1);
        }

        for (int i = 0; i < M; ++i)
        {
            int type, C;
            cin >> type >> C;
            if(type == 1){
                branches.insert(C-1);
            }else{
                compute(graph, branches, C-1);
            }

        }

        print_graph(graph);

    }

    return 0;
}