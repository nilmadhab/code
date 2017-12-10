#include <iostream>
using namespace std;

//INT_MIN
#include<bits/stdc++.h>

#define ll long long




void compute(int N , vector<int> vec){


    int i = 0;
    int num_countries = 0;
    int sum = 0;

    while(i < N){

        int num = vec[i];
        num_countries +=1;
        sum += num;
        for (int j = i+1; j < i + num; ++j)
        {
            if(vec[j] != num){
                cout << "Invalid Data" << endl;
                return;
            }
        }
        i += num;
    }
  
    cout << num_countries << endl;


}

int main() {
    //std::ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;

    for (int i = 0; i < T; ++i)
    {   

        int N;
        cin >> N;
        vector<int> vec(N);
        for (int i = 0; i < N; ++i)
        {
            cin >> vec[i];
        }
        
        compute(N, vec);
    }

    return 0;
}