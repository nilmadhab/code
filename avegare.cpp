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

void print_map(map<int, int> mp){
    map<int, int>::iterator it ;

    for ( it = mp.begin(); it != mp.end(); ++it)
    {
        cout << it->first << " " << it->second << "\n";
    }
}


void print_vec_vec(vector< vector<int> > & vec)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        print(vec[i]);
    }

    cout << "\n" ;
}

void initialize(vector<int> &vec, int val)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        vec[i] = val;
    }
}





void compute(vector<int> ar){
    
    map< int, int > mp;

    int N = ar.size();

    for (int i = 0; i < ar.size(); ++i)
    {
        if( mp.find(ar[i]) == mp.end() ){
            mp[ar[i]] = 1;
        }else{
            mp[ar[i]] = mp.find(ar[i])->second+1;
        }
    }
    int ans  = 0;
    for (int i = 0; i < N; ++i)
    {
        for(int j = i+1; j < N ; j++)
        {
            int avg = (ar[i]+ar[j])/2;
            if((ar[i]+ar[j]) % 2 == 0 && mp.find( avg ) != mp.end()){
                ans += mp.find(avg)->second;
          }
        }
    }

    //print_map(mp);

    cout << ans << "\n";
    

}
int main() {
    //std::ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    //T = 1;
    vector<int> ar(N);
    for (int i = 0; i < N; ++i)
    {
        
        
        cin >> ar[i];
        

        
    }   

    compute(ar);

    return 0;
}