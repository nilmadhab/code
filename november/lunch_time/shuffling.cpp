#include <iostream>
using namespace std;

#define endl "\n"

//INT_MIN
#include<bits/stdc++.h>

#define ll long long
vector<int> vec(100005);

#define endl "\n"

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
void print(vector<int> v){
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << " ";
    }
    cout << "\n" ;
}

int MAX = 1000000001;

int process(int S, int x, int y)
{
    vector<int> even(S/2);
    vector<int> odd(S/2);

    for (int i = 0; i < S; ++i)
    {
        if(i%2 == 0){
            odd[i/2] = vec[i]; 
        }else{
            even[i/2] = vec[i];
        }
    }

    int index = (S/2)*x/y;
    int j=0;
    for (int i = 0; i < S/2 ; ++i)
    {
        if(i != index){
            vec[j++] = odd[i];
        }
        
    }

    for (int i = 0; i < S/2 ; ++i)
    {
        if(i != index){
            vec[j++] = even[i];
        }
    }
    //print(even);
    //print(odd);
    //print(vec, S - 2);
    return S - 2;
}

void compute(int M, int X, int Y)
{
    for (int i = 0; i < M; ++i)
    {
        vec[i] = i+1;
    }
    int S = M;
    do{
         S = process(S, X, Y);
    }while(S > 2);
    int ans = vec[0] ^ vec[1];
    cout << ans << endl;

}

int main() {
    //std::ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >>T;
    for (int t = 0; t < T; ++t)
    {
        int M, X, Y;
        cin >> M >> X >> Y;     
        compute(M, X, Y);

    }

    //
    //print(mat);

    ////////////// compute



    return 0;
}