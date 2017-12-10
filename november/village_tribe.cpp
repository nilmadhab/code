#include <iostream>
using namespace std;

//INT_MIN
#include<bits/stdc++.h>

#define ll long long
vector<int> vec(50005);

ll max(ll a, ll b){
    if(a > b) return a;
    return b;
}

ll aux(int start, int end , int N){

    assert(start < N && end < N && start <= end );

    return (vec[end] - vec[start])*(end-start+1);
}

void compute(string s){

    int a = 0;
    int b = 0;
    char last = '*';
    int count  = 0;
    int N  = s.size();

    for (int i = 0; i < s.size(); ++i)
    {
        if(s[i] == 'A'){
            a += 1;
            last = 'A';
        }else if(s[i] == 'B'){
            b +=1;
            last = 'B';
        }else if(s[i] == '.'){
            if(i-1 >= 0 && i+1 < N ){
                if(s[i+1] == '.'){
                    count+=1;
                }else{
                    if(s[i+1] == 'A' && last == 'A'){
                        a += (count+1);
                    }else if(s[i+1] == 'B' && last == 'B'){
                        b += (count+1);
                    }
                    count = 0;
                }
            }
        }
    }

    cout << a << " " << b << "\n";
}

int main() {
    //std::ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;

    for (int i = 0; i < T; ++i)
    {

        string s;
        cin >> s;
        
        compute(s);
    }

    return 0;
}