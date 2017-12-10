#include <iostream>
using namespace std;
//https://www.codechef.com/submit/complete/15499449
#include<bits/stdc++.h>

void print(vector<int> v){
    for(auto i : v){
        cout << i << " ";
    }
    cout << "\n" ;
}

void print(vector<vector<pair<int, int>>> graph){
    for (int i = 0; i < graph.size(); ++i)
    {
        cout << i << " : " ;
        for(int j = 0; j < graph[i].size(); j++){

            cout << graph[i][j].first << "," << graph[i][j].second << " | ";
        }
        
        cout << endl;
    }
    
    
}

int get_rev_col(int c){
    if(c == 1) return 2;
    return 1;
}

int get_next_unvisited(vector<bool>& visited)
{
    for (int i = 0; i < visited.size(); ++i)
    {
        if(!visited[i]) return i;
    }

    return -1;
}

bool graph_coloring(vector<vector<pair<int, int>>>& graph)
{

    int N = graph.size();
    vector<bool> visited(N);
    vector<int> que;
    //que.push_back(0);
    // paint adjacent by color 2
    // 0 is color 1 
    int color = 1;
    while(1){
        int next = get_next_unvisited(visited);
        cout << "next " << next << endl;
        if(next == -1) break;
        que.push_back(next);
        while(que.size() > 0){
            print(que);
            int pop = que[0];
            que.erase(que.begin());
            
            print(graph);
            visited[pop] = true;
            vector<pair<int, int>> adjs = graph[pop];
            for(int j = 0 ; j < graph[pop].size(); j++){
                if(graph[pop][j].second == 0){
                // not visited
                   if(!visited[graph[pop][j].first]){
                        que.push_back(graph[pop][j].first);
                    visited[graph[pop][j].first] = true;
                   }
                    
                    graph[pop][j].second = get_rev_col(color);


                }else{
                    if(graph[pop][j].second == get_rev_col(color)){
                    // ok
                    }else{
                        return false;
                    }
                }
            }
            color = get_rev_col(color);

        } 
    }
    return true;
}


int main() {
    //std::ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    
    for (int t = 0; t < T; ++t)
    {
        int N,M ;
        cin >> N >> M;
        vector<vector<pair<int, int> > > graph(N);
        int u,v;
        for (int i = 0; i < M; ++i)
        {
            cin >> u >> v ;
            graph[u-1].push_back(make_pair(v-1, 0));
            graph[v-1].push_back(make_pair(u-1, 0));
        }
        cout << "Scenario #"<< t+1 <<":" << "\n";
        if(!graph_coloring(graph)){
            cout << "Suspicious bugs found! \n";
        }else{
            cout << "No Suspicious bugs found! \n";
        }
        print(graph);
    }
    //sort(ar.begin(), ar.end());
    //print(ar);
    
    return 0;
}