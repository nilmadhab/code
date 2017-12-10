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
    cout << " | " ;
}




void compute(vector<int>  & vec){


    int N= vec.size();

    int included = vec[0]+vec[1];
    int excluded = vec[0];
    int ans1 = 0;
    int ans2 = 0;

    for (int i = 2; i < N-1; ++i)
    {
        int temp = included;
        included = min(included,excluded)+vec[i];
        excluded = temp;
        //cout << included << " " << excluded << endl;
    }

    ans1 = min(excluded + vec[N-1], included);

    


    included = vec[1]+vec[2];
    excluded = vec[1];

    for (int i = 3; i < N; ++i)
    {
        int temp = included;
        included = min(included,excluded)+vec[i];
        excluded = temp;
        //cout << included << " " << excluded << endl;
    }

    ans2 = min(included , excluded+vec[0]);

    //cout << ans1 << " " << ans2 << endl;

    cout << min(ans1, ans2) << '\n';

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
        
        int N ;
        cin >> N;
        vector<int>  info(N);
        for(int j= 0 ; j < N ; j ++){
            cin >> info[j];

        }

        compute(info);
    }
    
    

    
    
    return 0;
}