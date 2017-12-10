#include <iostream>
using namespace std;

#define endl "\n"

//INT_MIN
#include<bits/stdc++.h>

//#include "/Users/nilmadhab/Desktop/code/library/useful_functions.cpp"

#define ll long long
vector<int> vec(200005);

#define endl "\n"

ll max(ll a, ll b){
    if(a > b) return a;
    return b;
}

ll maximum_sum(int N, int index){

    //print(vec, N);
    ll maximum_sum = 0;

    /*
    1 2 3 4 5
    2 3 4 5 1
    3 4 5 1 2
    4 5 1 2 3
    5 1 2 3 4 
    */

    for (int i = 0; i < index; ++i)
    {
        maximum_sum = max(maximum_sum, vec[i+(N-index)] + (i +1 ) );

        //cout << maximum_sum << " " << i  << " " << (i +1 )  << endl;
    }

    for (int i = index; i < N; ++i)
    {
        maximum_sum = max(maximum_sum, vec[i-index]+(i+1));
        //cout << maximum_sum << " " << i  << " " << (i+1)<< endl;
    }

    return maximum_sum;
}



void compute(int N)
{

    int maximum = 0;

    for (int i = 0; i < N; ++i)
    {
        cout <<  maximum_sum(N, i) << " ";
    }

    cout << endl;

    
}

int main() {
    //std::ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    //cin >>T;
    for (int t = 0; t < T; ++t)
    {
        int N;
        cin >> N;
        assert(N < 200005);
        for (int i = 0; i < N; ++i)
        {
            cin >> vec[i];
        }
        compute(N);
        //print(vec, N);
    }

    //
    //print(mat);

    ////////////// compute



    return 0;
}