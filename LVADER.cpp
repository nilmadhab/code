#include <iostream>
using namespace std;

//INT_MIN
#include<bits/stdc++.h>



void print(vector<int> v){
    for(auto i : v){
        cout << i << " ";
    }
    cout << "\n" ;
}


void print_vec_vec(vector< vector<int> > & vec)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        print(vec[i]);
    }

    cout << "\n" ;
}

void initialize(vector<int> &vec, int val)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        vec[i] = val;
    }
}





void compute(int CASE , int x1, int y1, int x2, int y2){
    
    int ROWS = x2-x1+1;
    int COLS = y2-y1+1;

    //cout << ROWS << " " <<COLS << '\n';

    vector<vector<int> > dp(ROWS);

    for (int i = 0; i < ROWS; ++i)
    {
        vector<int> temp(COLS);
        for (int j = 0; j < COLS; ++j)
        {
            temp[j] = 0;
        }
        dp[i] = temp;
    }

    dp[0][0] = 1;

    //print_vec_vec(dp);

    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < COLS; ++j)
        {
            if(i+j != 0)
            {
                if(i-1 >= 0){
                    dp[i][j] += dp[i-1][j];
                }
                if(j-1 >= 0){
                    dp[i][j] += dp[i][j-1];
                }
                if(i-1 >= 0 && j-1 >= 0){
                    dp[i][j] += dp[i-1][j-1];
                }
            }
        }
    }

    print_vec_vec(dp);

    cout << "CASE " << CASE << ": " <<  dp[ROWS-1][COLS-1] << "\n" ;

}
int main() {
    //std::ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    //T = 1;
    //vector<int> ar;
    for (int i = 0; i < T; ++i)
    {
        
        int x1, y1, x2 , y2;
        cin >> x1 >> y1 >> x2 >> y2 ;
        

        compute(i+1, x1, y1, x2 , y2);
    }

    return 0;
}