#include <iostream>
using namespace std;
//https://www.codechef.com/ZCOPRAC/problems/ZCO12001
//#include<bits/stdc++.h>

#include <vector>


int min(int a, int b){
    if(a > b) return a;
    return b;
}
 
int rightSolver(vector<unsigned int> ar){
    
    int ind=0;
    
    for (int i = 0;i < ar.size(); i++) {
        /* code */
        if(ar[i] < ar[ind]){
            ind = i;
        }
    }

    //cout << ind+1 << "\n";
    
    return ind+1;
}

int wrongSolver(std::vector <unsigned int> a) {
    int n = a.size();
    std::vector<unsigned int> prefSum(n), sufSum(n);
    prefSum[0] = a[0];
    for (int i = 1; i < n; i++) {
        prefSum[i] = prefSum[i - 1] + a[i];
    }
    sufSum[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        sufSum[i] = sufSum[i + 1] + a[i];
    }
    unsigned int mn = prefSum[0] + sufSum[0];
    int where = 1;
    for (int i = 1; i < n; i++) {
        unsigned int val = prefSum[i] + sufSum[i];
        if (val < mn) {
            mn = val;
            where = i + 1;
        }
    }
    return where;
}


int wrongSolver_2(std::vector <unsigned int> a) {
    int n = a.size();
    
    unsigned int sum = 0;
    for (int i = 0; i < n; i++) {
        sum +=  a[i];
    }

    cout << "sum is " << sum << endl;
    unsigned int mn = sum + a[0];

    int where = 1;

    for (int i = 1; i < n; i++) {

        unsigned int val = a[i] + sum;

        if (val < mn) {

            mn = val;

            where = i + 1;

        }
    }
    return where;
}



void compute(int n){
    
    vector<unsigned int> ar(n);

    for (int i = 0; i < n; ++i)
    {
        ar[i] = 1;
    }

    for (int i = 0; i < 99988; ++i)
    {
        ar[i] = 42954;
    }

    

    ar[0] += 39786*0.5*1.6;
    /*
    unsigned int sum = 0;
    for (int i = 0; i < n; i++) {
        sum +=  ar[i];
    }
    */
    //cout << "sum is " << sum << endl;

   // cout << ar[0] + sum << endl;

    //ar[0] = 53184+1000;
    //ar[1] = 10;
    //print(ar);
    //667295
    //333648
    /*
    cout << rightSolver(ar) << endl;
    cout << wrongSolver(ar) << endl;
    cout << wrongSolver_2(ar) << endl;
    */

    //cout << print(ar) << endl;

    for(int i = 0 ; i < ar.size() ; i ++){
        cout << ar[i] << " ";
    }
    cout << "\n" ;
     

}
int main() {
    //std::ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    vector<int> ar;
    for (int i = 0; i < T; ++i)
    {
        int n;
        cin >> n;
        compute(n);
    }
    
    //print(ar);
    
    return 0;
}