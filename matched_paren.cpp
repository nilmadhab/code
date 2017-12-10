#include <iostream>
using namespace std;
//https://www.codechef.com/ZCOPRAC/problems/ZCO12001
#include<bits/stdc++.h>
void compute(vector<int> ar){
    vector<int> lis;
    int maxi = 0;
    int ind = 0;
    int curr_nested_len = 0;
    int curr_nested_ind = 0;
    int max_nested_len = 0;
    int maxi_nested_ind = 0;
    for (int i = 0; i < ar.size(); ++i)
    {
        if(ar[i] == 1){
            lis.push_back(1);
            if(lis.size() > maxi){
                maxi = lis.size();
                ind = i +1;
            }
            if(lis.size() == 1){
             curr_nested_len = 1;
             curr_nested_ind = i+1; 
         }else
         curr_nested_len +=1;  
     }else{
        lis.pop_back();
        curr_nested_len +=1;
    }

    if(curr_nested_len > max_nested_len){
            //#print  lis
        max_nested_len = curr_nested_len;
        maxi_nested_ind = curr_nested_ind;
    }
    


    

}

cout << maxi << " " <<  ind << " " << max_nested_len << " " << maxi_nested_ind << endl;
}
int main() {
    std::ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int> ar;
    for (int i = 0; i < N; ++i)
    {
        int a ;
        cin >> a;
        ar.push_back(a);
    }
    compute(ar);
    return 0;
}