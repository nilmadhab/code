#include <iostream>
using namespace std;
#include<bits/stdc++.h>
#define ll long long

int max_cost = 0;

void print(vector<int> v){
    for(auto i : v){
        cout << i << " ";
    }
    cout << "\n" ;
}

 ll skew(vector<int> & ar1, vector<int > & ar2)
{
    int N = ar1.size();
    sort(ar1.begin(), ar1.end());
    sort(ar2.begin(), ar2.end());

    return ar1[N-1] + ar2[N-1];
}


ll swap(vector<int> & ar1, vector<int > & ar2)
{
    /*
    cout << "ar1 & ar2 " << "\n";
        print(ar1);
        print(ar2);
    */

    int N = ar1.size();
    vector<int> c1 = ar1;
    vector<int> c2 = ar2;

    // swap first and last of 1st and second array

    ll skew0 = skew(ar1, ar2);

    int temp = c1[0];
    c1[0] = c2[N-1];
    c2[N-1] = temp;

    ll skew1 = skew(c1, c2);


    vector<int> c3 = ar1;
    vector<int> c4 = ar2;

    temp = c4[0];
    c4[0] = c3[N-1];
    c3[N-1] = temp;
    ll skew2 = skew(c3, c4);

    //cout << " c1 & c2 " << "\n";
    //print(c1);
    //print(c2);
    //cout << " c3 & c4 " << "\n";
    //print(c3);
    //print(c4);

    if(skew0 < skew1 && skew0 < skew2){
        return skew0;
    }

    

    if(skew1 <= skew2 && skew1 <= skew0)
    {
        ar1= c1;
        ar2 = c2;
        return skew1;
    }else{
        if(skew2 <= skew1 && skew2 <= skew0)
        {
            ar1= c3;
            ar2 = c4;
            return skew2;
        }
        

    }

    return skew0;




}



int compute(vector<int> & ar1, vector<int > & ar2, int K){


    if(ar1.size() == 1){
        return ar1[0] + ar2[0];
    }

    
    ll mini = LLONG_MAX;
    for (int i = 0; i < K; ++i)
    {
        mini = min(mini,swap(ar1, ar2));
        
    }

    return mini;



}
int main() {
    //std::ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N,K;
    
    cin >> N >> K;

    vector<int> ar1(N);
    vector<int> ar2(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> ar1[i];
    }

    for (int i = 0; i < N; ++i)
    {
        cin >> ar2[i];
    }

    sort(ar1.begin(), ar1.end());
    sort(ar2.begin(), ar2.end());
    
    cout << compute(ar1, ar2, K) << endl;
    
    
    

    
    
    return 0;
}