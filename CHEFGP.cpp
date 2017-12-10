#include <iostream>
using namespace std;
#include <vector>
#include <math.h>
//https://www.codechef.com/ZCOPRAC/problems/ZCO12001
//#include<bits/stdc++.h>

/*

void print(vector<int> v){
    for(auto i : v){
        cout << i << " ";
    }
    cout << "\n" ;
}

*/

bool is_happy(string ar, int a, int b)
{
    for (int i = 0; i < ar.size(); ++i)
    {
        if(ar[i] == 'a'){
            int back = i - a;
            if(back < 0) continue;
            bool flag = false;
            for(int j = back; j < i ; j++){
                if(j >= 0 && ar[j] != 'a'){
                    flag = true;
                }
            }
            if(flag == false) return false;
        }

        if(ar[i] == 'b'){
            int back = i - b;
            if(back < 0) continue;
            bool flag = false;
            for(int j = back; j < i ; j++){
                if(j >= 0 && ar[j] != 'b'){
                    flag = true;
                }
            }
            if(flag == false) return false;
        }
    }

    return true;
}
string compute(string ar, int a, int b){

    int apple = 0;
    int banana = 0;

    for (int i = 0; i < ar.size(); ++i)
    {
        if(ar[i] == 'a'){
            apple +=1;
        }else{
            banana += 1;
        }
    }

    string ans = "";

    int num_of_change_for_apple = apple/a ;
    int num_of_change_for_banana = banana/b;

    if(apple%a == 0){
        num_of_change_for_apple -=1 ;
    }
    if(banana%b == 0){
        num_of_change_for_banana -=1;
    }

    //cout << num_of_change_for_apple << " " << num_of_change_for_banana
    //<< "num_of_change_for_apple  num_of_change_for_banana "<< endl;

    if(num_of_change_for_apple >= num_of_change_for_banana){
        vector<char> myVec;
        for (int i = 0; i < num_of_change_for_apple; ++i)
        {
            for (int j = 0; j < a; ++j )
            {
                myVec.push_back('a');
            }
            if(banana > 0){
                myVec.push_back('b');
                banana -=1;
            }else{
                myVec.push_back('*');
            }
        }
        for (int j = 0; j < apple - num_of_change_for_apple*a; ++j )
        {
            myVec.push_back('a');
        }

        // if there are still bananas left 
        // distribute it
        int ind = 0;
        while( ind+1 < myVec.size() && banana > 0){
            if(ind+1 < myVec.size() && myVec[ind] == 'a' && myVec[ind+1] == 'a' ){
                myVec.insert(myVec.begin()+ind+1, 'b');
                ind +=1;
                banana -=1;
            }
            ind +=1;
        }

        while(banana > 0){
            myVec.push_back('b');
            banana -=1;
        }

        std::string str(myVec.begin(),myVec.end());
        return str;
    }else{
        if(num_of_change_for_banana >= apple){
            std::vector<char> vec;
            for (int i = 0; i < num_of_change_for_banana; ++i)
            {
                for (int j = 0; j < b; ++j )
                {
                    vec.push_back('b');
                }
                if(apple > 0){
                    vec.push_back('a');
                    apple -=1;
                }else{
                    vec.push_back('*');
                }
            }
            for (int j = 0; j < banana - num_of_change_for_banana*b; ++j )
            {
                vec.push_back('b');
            }

            int ind = 0;
            while( ind+1 < vec.size() && apple > 0){
                if(ind+1 < vec.size() && vec[ind] == 'b' && vec[ind+1] == 'b' ){
                    vec.insert(vec.begin()+ind+1, 'a');
                    ind +=1;
                    apple -=1;
                }
                ind +=1;
            }

            while(apple > 0){
                vec.push_back('a');
                apple -=1;
            }

            std::string str(vec.begin(),vec.end());
            return str;
        }

    }
    


    return "nil the great";
    //cout << ans << endl;

}
int main() {
    //std::ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    //vector<int> ar;
    for (int i = 0; i < T; ++i)
    {
        string s ;
        cin >> s;
        int a,b;
        cin >> a >> b;
        cout << compute(s,a,b) << "\n";
        string ans = compute(s,a,b);
        //cout << is_happy(ans, a, b) << endl; 
    }
    
    //print(ar);

    
    
    return 0;
}