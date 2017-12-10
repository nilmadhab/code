#include <iostream>
using namespace std;
#include <vector>
#include <math.h>
#include <assert.h>

int max_cost = 0;

void print(vector<int> v){
    for(auto i : v){
        cout << i << " ";
    }
    cout << "\n" ;
}




int compute(vector<vector<int> >  & vec, int R, int C, int d){


    for (int i = 0; i < R; ++i)
    {
        print(vec[i]);
    }


    vector<vector<vector<int> > >   dp(R);
    for(int j= 0 ; j < R ; j ++){
        vector<vector<int> > temp(C);
        for (int k = 0; k < C; ++k)
        {
            vector<int> temp2(d);
            for (int i = 0; i < d; ++i)
            {
                temp2[i] = 0;
            }
            temp[k] = temp2;
        }
        dp[j] = temp;

    }

    if(vec[0][0] == 0) return 0;

    dp[0][0] = 1;

    for (int i = 0; i < min(R,d); ++i)
    {
        for (int j = 0; j < min(R,d) ; ++j)
        {
            if(i+j != 0 && ar[i][j] != 0){
                if(i > 0 ) dp[i][j] += dp[i-1][j];
                if(j > 0 ) dp[i][j] += dp[i][j-1];
            }
        }
    }
    




    

}
int main() {
    //std::ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    T = 1;
    //vector<int> ar;
    for (int i = 0; i < T; ++i)
    {
        
        int R,C, d;
        cin >> R >> C >> d;

        vector<vector<int> >   info(R);
        for(int j= 0 ; j < R ; j ++){
            vector<int> temp(C);
            for (int k = 0; k < C; ++k)
            {
                cin >> temp[k];
            }
            info[j] = temp;

        }

        compute(info, R,C, d);
    }
    
    

    
    
    return 0;
}