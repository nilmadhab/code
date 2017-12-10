#include <iostream>
using namespace std;

#define endl "\n"

//INT_MIN
#include<bits/stdc++.h>

#define ll long long

ll max(ll a, ll b){
    if(a > b) return a;
    return b;
}

vector< vector <int > > vec;

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

ll aux( int i , int x){

    assert(i < vec.size());

    return vec[i][0] + vec[i][1]*x + vec[i][2]*x*x + vec[i][3]*x*x*x;  
}

ll min(ll a , ll b){
    if(a  < b ) return a;

    return b;
}



void compute(int x )
{

    ll mini = aux(0, x);

    for (int i = 1; i < vec.size(); ++i)
    {
        mini = min( mini , aux(i, x)  );
    }

    cout << mini << endl;



}

bool check(int a0, int a1, int a2, int  a3 ,  int index){

    for (int i = 0; i < index; ++i)
    {
        if(vec[i][0] <= a0 && vec[i][1] <= a1 && vec[i][2] <= a2 
            && vec[i][3] <= a3)
        {
            return false;
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
    //T = 1;

    for (int t1 = 0; t1 < T; ++t1)
    {
        vec.clear();
        int  N, a0, a1, a2, a3;
        cin >> N ;
        for (int i = 0; i < N; ++i)
        {
            cin >> a0 >> a1 >> a2 >> a3;
            vector<int> temp(4);
            temp[0] = a0;
            temp[1] = a1;
            temp[2] = a2;
            temp[3] = a3;
            if(check(a0, a1, a2, a3 , vec.size() )){
                vec.push_back(temp);
            }
        }
        //print_graph(vec);
        int q;
        cin >> q;
        for (int i = 0; i < q; ++i)
        {
            int t;
            cin >> t;
            compute(t);
        }

    }

    return 0;
}