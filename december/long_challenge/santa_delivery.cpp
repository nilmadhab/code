#include <iostream>
using namespace std;

#define endl "\n"

//INT_MIN
#include<bits/stdc++.h>

//#include "/Users/nilmadhab/Desktop/code/library/useful_functions.cpp"

#define ll long long
#define SPACE " "
vector<int> vec(100005);

vector<int> bag(51);
vector<vector< int> > child_info(501);


ll max(ll a, ll b){
    if(a > b) return a;
    return b;
}

ll min(ll a, ll b){
    if(a > b) return b;
    return a;
}

int findChildIndexWithNewPresent(int P, int N)
{
    for (int i = 0; i < N; ++i)
    {
        if(child_info[i][3] == P){
            return i;
        }
    }
    return 0;
}

int findChildIndexWithOldPresent(int P, int N)
{
    for (int i = 0; i < N; ++i)
    {
        if(child_info[i][2] == P){
            return i;
        }
    }
    return 0;
}

void compute(int N, int G, int B, int X, int Y)
{
    cout << 1 << SPACE <<  0 << endl;
    cout << 2 << SPACE << child_info[0][3] << endl;
    for (int i = 0; i < N; ++i)
    {
        if(child_info[i][2] == child_info[i][3]){
            
        }else{
            cout << 1 << SPACE << i+1 << endl; // go to child i
            cout << 3 << SPACE << child_info[i][3] << endl; // put down new gift
            cout << 2 << SPACE << child_info[i][2] << endl; // pick up earlier gift
            if(i+1 < N && child_info[i][2] == child_info[i+1][3]){
                // no need to go to santa's house
            }else{
                cout << 1 << SPACE << 0 << endl; // go to santa's house
                cout << 3 << SPACE << child_info[i][2] << endl; // put down earlier gift
                if(i+1 < N){
                    cout << 2 << SPACE << child_info[i+1][3] << endl; // pick up next child's gift
                }
            }
            
        }

    }
    cout << 1 << SPACE <<  0 << endl;
    cout << 0 << endl;
}

int main() {
    //std::ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin >>T;
    for (int t = 0; t < T; ++t)
    {
        int N, G, B, X, Y;
        cin >> N >>  G >>  B >>  X >>  Y;
        
        for (int i = 0; i < G; ++i)
        {
            cin >> bag[i];
        }
        for (int i = 0; i < N; ++i)
        {
            vector<int> temp(4);
            cin >> temp[0] >> temp[1] >> temp[2] >> temp[3] ;
            child_info[i] = temp;
        }
        compute( N, G, B, X, Y);
    }

    //
    //print(mat);

    ////////////// compute



    return 0;
}