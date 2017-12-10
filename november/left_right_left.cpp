#include <iostream>
using namespace std;

//INT_MIN
#include<bits/stdc++.h>

#define ll long long
vector<int> ar(1000005);


void fix(int & smallest, int & largest, int i, int N){
    if(i >= N) return;
    if(ar[i] < ar[i+1]){
        // going right next step
        smallest = ar[i];
    }else{
        largest = ar[i];
    }
}

bool compute(int ans, int N)
{

    int i = 1;
    bool left_allowed = true;
    bool right_allowed = true;
    if(N <= 2){
        return true;
    }
    int largest = ar[0];
    int smallest = ar[0];
    while(i < N){
        //cout << ar[i] << endl;
        if(i == 1){
            if(ar[i] > largest){
                largest = ar[i];
                left_allowed = false;
            }else{
                smallest = ar[i];
                right_allowed = false;
            }
        }else{
            if(!left_allowed){
                if(ar[i] < smallest || (i+1 < N && ar[i+1] < smallest) ) {
                    return false;
                }
            } 

            if(!right_allowed){
                if(ar[i] > largest || (i+1 < N && ar[i+1] > largest ) ) {
                    return false;
                }
            }


            if(left_allowed){
                if(ar[i] > smallest){
                    left_allowed = false;
                    fix(smallest, largest, i, N);
                }else{
                    largest = smallest;
                    smallest = ar[i];
                }
            }else if(right_allowed)
            {
                if(ar[i] < largest){
                    right_allowed = false;
                    fix(smallest, largest, i ,N);
                }else{
                    smallest = largest;
                    largest = ar[i];
                }
            }else if(i+1 < N && !left_allowed && !right_allowed){
                fix(smallest, largest, i ,N);
            }

        }

        //cout << smallest << " " << largest << " smallest largest " << left_allowed << " " << right_allowed << " left and right allowed " << endl;
        i+=1;
    }
    return ar[N-1] == ans ;
}

int main() {
    //std::ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;

    for (int i1 = 0; i1 < T; ++i1)
    {

        int N, ans;
        cin >> N >> ans;
        for (int i = 0; i < N; ++i)
        {
            cin >> ar[i]; 
        }
        
        if(compute(ans, N)){
            cout << "YES" << "\n";
        }else{
            cout << "NO" << "\n";
        }
    }

    return 0;
}