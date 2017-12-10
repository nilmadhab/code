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

void penalty(int N){
    long ans = 0;
    for (int i = 1; i < N; ++i)
    {
        ans += abs(vec[i]-vec[i-1]);
    }

    cout << ans << endl;
    //return penalty;
}

void compute(int N)
{
    /*
        Define the Chef's number for the set 
        as a minimal sum of penalties of the 
        connections between numbers from this set(each number must be connected with 
        at least one other number), 
        if size of the set more or equal than 2,
         and 0 otherwise.
        The connection between numbers x and y has a penalty equal the 
        absolute value |x-y|.
    */

    sort(vec.begin(), vec.begin() + N);
    print(vec, N);
    penalty(N);

}

int main() {
    //std::ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t)
    {
        int N, Q;
        cin >> N >> Q; 
        int size = N;    
        for (int i = 0; i < N; ++i)
        {
            cin >> vec[i];
        }

        for (int i = 0; i < Q; ++i)
        {
            int type, x;

            cin >> type >> x;

            // type 1 add
            // type 2 erase 
            if(type == 1){
                vec[size++] = x;
            }else{
                // remove 
                vec.erase(remove(vec.begin(), vec.end(), x), vec.end());
                size--;
            }

            compute(size);
        }

    }

    //
    //print(mat);

    ////////////// compute



    return 0;
}