#include <iostream>
using namespace std;

#define endl "\n"

#define START 97

//INT_MIN
#include<bits/stdc++.h>

#define ll long long
vector<int> vec(50005);

ll max(ll a, ll b){
    if(a > b) return a;
    return b;
}

int longestPalSubstr( string str )
{
    int n = str.size(); // get length of input string
 
    // table[i][j] will be false if substring str[i..j]
    // is not palindrome.
    // Else table[i][j] will be true
    //cout << str << " " << n << endl;

    bool table[n][n];
    memset(table, 0, sizeof(table));
 
    // All substrings of length 1 are palindromes
    int maxLength = 1;
    for (int i = 0; i < n; ++i)
        table[i][i] = true;
 
    // check for sub-string of length 2.
    int start = 0;
    for (int i = 0; i < n-1; ++i)
    {
        if (str[i] == str[i+1])
        {
            table[i][i+1] = true;
            start = i;
            maxLength = 2;
        }
    }
 
    // Check for lengths greater than 2. k is length
    // of substring
    for (int k = 3; k <= n; ++k)
    {
        // Fix the starting index
        for (int i = 0; i < n-k+1 ; ++i)
        {
            // Get the ending index of substring from
            // starting index i and length k
            int j = i + k - 1;
 
            // checking for sub-string from ith index to
            // jth index iff str[i+1] to str[j-1] is a
            // palindrome
            if (table[i+1][j-1] && str[i] == str[j])
            {
                table[i][j] = true;
 
                if (k > maxLength)
                {
                    start = i;
                    maxLength = k;
                }
            }
        }
    }
 
    return maxLength; // return length of LPS
}

void aux(int N){

    //string part = full.substr(start);
    if(N == 1){
        cout << 1 << " " << "a" << endl;
        return;
    }
    if(N == 2){
        cout << 1 << " " << "ab" << endl;
        return;
    }
    if(N == 3){
        cout << 2 << " " << "aab" << endl;
        return;
    }
    if(N == 4){
        cout << 2 << " " << "aabb" << endl;
        return;
    }
    if(N == 5){
        cout << 3 << " " << "aaaba" << endl;
        return;
    }
    if(N == 6){
        cout << 3 << " " << "aaabab" << endl;
        return;
    }
    if(N == 7){
        cout << 3 << " " << "aaababb" << endl;
        return;
    }
    if(N == 8){
        cout << 3 << " " << "aaababbb" << endl;
        return;
    }

    string ans(N, ' ');

    for (int i = 0; i < 4; ++i)
    {
        ans[i] = 'a';
    }
    int i = 0;
    while(i < N){
        if(i < N) ans[i++] = 'b';
        if(i < N) ans[i++] = 'b';
        if(i < N) ans[i++] = 'a';

        if(i < N) ans[i++] = 'b';
        if(i < N) ans[i++] = 'a';
        if(i < N) ans[i++] = 'a';
    }

    //cout << longestPalSubstr(ans) << endl;
    cout <<  4 << " " << ans << endl;

}

void compute(int N, int A)
{
    //cout << N << " " << A << "  N and A " << endl;
    string ans(N, ' ');
    if(A == 1){
        for (int i = 0; i < N; ++i)
        {
            ans[i] = char(START);
        }
        cout << N << " " << ans << endl;
        return;
    }
    if(A == 2){
        aux(N);
        return;
    }

    int start = 0;
    for (int i = 0; i < N/3; ++i)
    {
        start = i*3;
        ans[start++] = 'a';
        ans[start++] = 'b';
        ans[start++] = 'c';

    }
    if(start < N){
        ans[start++] = 'a';
    }
    if(start < N){
        ans[start++] = 'b';
    }
    //cout << longestPalSubstr(ans) << endl;
    cout << 1 << " " << ans << endl;
    return;
}

int main() {
    //std::ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;

    for (int i = 0; i < T; ++i)
    {

        int  N, A;
        cin >> N >> A;
        
        compute(N, A);
    }
    //aaaa bbabaabb
    // aaaa longest
    string check = "aaaa bba baa bbabaabbabaabbabaabbabaa";
    //cout << longestPalSubstr(check) << endl;

    return 0;
}