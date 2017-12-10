#include <iostream>
using namespace std;
//https://www.codechef.com/ZCOPRAC/problems/ZCO12001
//#include<bits/stdc++.h>
#include <unordered_set>
#include <assert.h>  
#include <vector>

void print(vector<int> v){
    for(auto i : v){
        cout << i << " ";
    }
    cout << "\n" ;
}
void compute(vector<int> ar, int k){
    
    int N = ar.size();

    for (int i = 0; i < N; ++i)
    {
        /* code */
    }

    //printf("%d\n",ans-1 );

}

void modify(vector<int> & ar, int I, int X){

    assert (I >= 0 && I < ar.size());

    ar[I] += X;
}
void print_set(unordered_set<int> mySet){
    for (auto itr = mySet.begin(); itr != mySet.end(); ++itr) {
        cout << *itr << " ";
    }
    cout << "\n";
}
void query(vector<int> & ar, int I, int L, int R){
    // R-L+1 rays parraleel to X axis

    // jth ray eminates at (i - 0.5, L+ j - 1.5)
    int ans = 0;
    unordered_set<int> ump;
    int N = ar.size();
    for (int i = 1; i <= R-L+1; ++i)
    {
        float startx = I - 0.5-1;
        float starty = L + i - 1.5;
        //cout << startx << " " << starty << endl;

        for (int j = startx+0.5 ; j <  N ; ++j)
        {
            if(starty <= ar[j]){
                ump.insert(j);
                break;
            }
        }

        //print_set(ump);


    }

    cout << ump.size() << "\n";
}
int main() {
    //std::ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    vector<int> ar;
    for (int t1 = 0; t1 < T; ++t1)
    {
        int N,Q;
        cin >> N >> Q;
        vector<int> ar(N);
        for (int i = 0; i < N; ++i)
        {
            cin >> ar[i];
        }
        //print(ar);
        for (int i = 0; i < Q; ++i)
        {
            char type;
            int I,L,R,X;
            cin >> type ;//
            if(type == '+'){
                cin >> I >> X;
                modify(ar, I-1,X);
                //print(ar);
            }else{
                if (type == '?')
                {
                    cin >> I >> L >> R;
                }
                query(ar,I,L,R);
            }
           // cout << type << " " << I << " " << L << " " << R << endl;
        }
    }
    
    return 0;
}