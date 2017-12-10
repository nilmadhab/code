#include <iostream>
using namespace std;

//INT_MIN
#include<bits/stdc++.h>

#define ll long long



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

    cout << " \n " ;
}

void initialize(vector<int> &vec, int val)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        vec[i] = val;
    }
}



ll floorSqrt(ll x)
{
    // Base cases
    //cout << x << " x  " << endl;
    if (x == 0 || x == 1)
       return x;
 
    // Do Binary Search for floor(sqrt(x))
    ll start = 1, end = x, ans;   
    while (start <= end) 
    {        
        ll mid = start + (end-start) / 2;
 
        // If x is a perfect square
        if (mid*mid == x)
            return mid;
 
        // Since we need floor, we update answer when mid*mid is 
        // smaller than x, and move closer to sqrt(x)
        if (mid*mid < x) 
        {
            start = mid + 1;
            ans = mid;
        } 
        else // If mid*mid is greater than x
            end = mid - 1;        
    }
    return ans;
}

ll min(ll a, ll b){
    if(a < b) return a;
    return b;
}

ll max(ll a, ll b){
    if(a > b) return a;
    return b;
}


ll compute_naive(ll a){

    

    ll count = 0;
    ll greater = floorSqrt(a-1);
    ll i = greater;
    for (i=greater; i >= 1; --i)
    {
        if(a - i*i <= 700){
            count += a-i*i;
        }else{
            break;
        }
        
    }

    count += 700*(i-1);
    
    //cout  << greater << " " << "greater <<  << less" << endl;
    //count = (greater)*700 +  (a - greater*greater);
    return count;

}

int main() {
//std::ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;

    
    for (int i = 0; i < T; ++i)
    {

        ll a;
        cin >> a;

        cout << compute_naive(a) << "\n";
    }

    return 0;
}