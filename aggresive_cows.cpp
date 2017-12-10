#include <iostream>
using namespace std;
//http://www.spoj.com/problems/AGGRCOW/
// Done 
#include<bits/stdc++.h>

void print(string s, vector<long> v){
    cout << s << " " ;
    for(auto i : v){
        cout << i << " ";
    }
    cout << "\n" ;
}

void print(string s, vector<bool> v){
    cout << s << " " ;
    for(auto i : v){
        cout << i << " ";
    }
    cout << "\n" ;
}


bool aux(vector<long>& ar, long x, int C){
    

    int count  = 0;
    int ind = 0;
    int N = ar.size();

    while(count < C && ind < N ){

        int next = ind +1;
        while(next < N && ar[next] - ar[ind] < x){
            next +=1;
        }
        ind = next;
        count += 1;


    }
    //cout << count << " " <<  C << " " << x << endl;
    if(count < C){
        return false;
    }else{
        return true;
    }
    
    
    
}
void compute(vector<long> ar, int C){
    sort(ar.begin(), ar.end());
    long low = 0;
    int N = ar.size();
    long high = ar[N-1]-ar[0];
    
    long mid =  low + (high-low)/2;

    while(low < high){
         mid = low + (high-low)/2;
        if(aux(ar, mid, C)){
            if(!aux(ar, mid+1,C) ){
                // got the answer
                cout << mid << "\n";
                return;
            }else{
               low = mid+1; 
            }
            
        }else{
            high= mid-1;
        }
    }

   if(low == 0){
    cout << -1 << "\n";
   }else{
    cout << low << "\n";
   }
    

}
int main() {
    //std::ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    
    for (int i = 0; i < T; ++i)
    {
        int N,C ;
        vector<long> ar;
        cin >> N >> C;
        for (int j = 0; j < N; ++j)
        {
            long a;
            cin >> a;
            ar.push_back(a);
        }

        compute(ar, C);
        
    }
    
    return 0;
}