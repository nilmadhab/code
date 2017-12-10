#include <iostream>
using namespace std;

//INT_MIN
#include<bits/stdc++.h>

#define ll long long

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

long long Ssum(vector<int> a, vector<int> b, int i, int j)
{
    int N = a.size();
    assert(i >= 0 && i < N && j >=0 && j < N && a.size() == b.size() );

    if( i == j) return a[i];

    long long sum = 0;

    sum += a[i];
    sum += a[j];



    if( i < j)
    {
        for(int k = i+1 ; k < j ; k++){
            sum += b[k];
        }
        return sum;
    }else{
        for(int k = 0 ; k < j ; k++){
            sum += b[k];
        };

        for(int k = i+1 ; k < N ; k++){
            sum += b[k];
        }

        return sum;


    }
}





void compute(vector<int> a, vector<int> b){
    
    int N = a.size();
    assert( a.size() == b.size() );
    
    ll maximum = INT_MIN;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j  < N; ++j)
        {
            ll ans = Ssum(a,b, i, j);
            //cout << i << " " << j << " " << ans << "\n";
            maximum = max(maximum, ans);
        }
    }

    cout << maximum << "\n";
    

}
int main() {
    //std::ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    //T = 1;
    vector<int> a(N);
    vector<int> b(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> a[i];
    }   

    for (int i = 0; i < N; ++i)
    {
        cin >> b[i];
    }  

    compute(a,b);

    return 0;
}