#include <stdio.h>
#include <iostream>
using namespace std;
#include <vector>
#include <math.h>
#include <assert.h>
//#include<bits/stdc++.h>

unsigned long long s[2];
unsigned long long xorshift128plus() {
    unsigned long long x = s[0];
    const unsigned long long y = s[1];
    x ^= x << 23;
    s[1] = x ^ y ^ (x >> 17) ^ (y >> 26);
    return s[0] = y;
}

const int MX = 1000;

int C[MX][MX];
int H[MX][MX];

void print_matrix(int n){

    for (int i = 0; i < n; ++i)
    {
        for(int j = 0 ; j < n ; j++)
        {
            cout << C[i][j] << " ";
        }

        cout << "\n";
    }
    cout << "\n";
    for (int i = 0; i < n; ++i)
    {
        for(int j = 0 ; j < n ; j++)
        {
            cout << H[i][j] << " ";
        }

        cout << "\n";
    }
}

void sample_solution(int n){
    for (int i = 0; i < n; ++i)
    {
        for(int j = 0 ; j < n ; j++){
            if(i==j){
                cout << 0 ;
            }else{
                if(i ==0 || j == 0){
                    cout << 1;
                }else{
                    cout << 0;
                }
            }
        }

        cout << '\n';
    }
}



int main() {
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        int n, Cmax, Hmax;
        scanf("%d %d %d", &n, &Cmax, &Hmax);
        for (int i = 0; i < n; i++) {
            C[i][i] = 0;
            scanf("%llu %llu", &s[0], &s[1]);
            for (int j = i + 1; j < n; j++) {
                C[i][j] = C[j][i] = xorshift128plus() % (Cmax + 1);
            }
        }
        
        for (int i = 0; i < n; i++) {
            scanf("%llu %llu", &s[0], &s[1]);
            for (int j = 0; j < n; j++) {
                H[i][j] = xorshift128plus() % (Hmax + 1);
            }
        }
        //print_matrix(n);
        // solve here

        sample_solution(n);



    }
    
    return 0;
}
