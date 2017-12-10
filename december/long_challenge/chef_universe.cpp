#include <iostream>
using namespace std;
 
#define endl "\n"
 
//INT_MIN
#include<bits/stdc++.h>
 
//#include "/Users/nilmadhab/Desktop/code/library/useful_functions.cpp"
 
#define ll long long
vector<int> vec(200005);
 
 
ll max(ll a, ll b){
    if(a > b) return a;
    return b;
}
 
ll min(ll a, ll b){
    if(a > b) return b;
    return a;
}
 
int formula(int a, int b, int c, int x, int y, int z )
{
    int cost = 0;
    if(z >= x+y)
        cost = (x+y)*b + (z-x-y)*a;
    else if ((x+y+z)%2 == 0)
        cost = (x+ y + z)/2*b;
    else
        cost = (x+ y + z-1)/2*b + a ;

    return min(cost, a*(x+y+z));
}


void Sort(int &a, int &b, int &c){
    if (a > b) {
        std::swap(a, b);
    }
    if (a > c) {
        std::swap(a, c);
    }
    if (b > c) {
        std::swap(b, c);
    }
}

int  formula3D(int a, int b, int c, int x, int y, int z){

    int cost = 0 ;
    Sort(x,y, z);
    cost = formula(a, b,c,  x, y, z);
    cost = min(cost, c*x + formula(a,b,c, 0, y-x, z-x));
    int cost2 = INT_MAX;
    if(2*c <= 3*b || c <= 3*a || c<= a+b ){
        for(int i = 0; i< min(x,500); i++ ){
            cost2 = min(cost2, c*(x-i) + formula(a,b,c, i, y-x+i, z-x+i) );
        }

        for(int i = max(0,x-500); i< x; i++ ){
            cost2 = min(cost2, c*(x-i) + formula(a,b,c, i, y-x+i, z-x+i) );
        }
    }
    return min(min(cost, (x+y+z)*a),  cost2);

}

 
int main() {
    //std::ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin >>T;
    for (int t = 0; t < T; ++t)
    {
        int X,Y,Z, A,B, C;
        cin >> X >> Y >> Z >> A >> B >> C;
        cout << formula3D( A, B, C, X, Y, Z ) << endl;
        //print(vec, N);
    }
 
    //
    //print(mat);
 
    ////////////// compute
 
 
 
    return 0;
} 