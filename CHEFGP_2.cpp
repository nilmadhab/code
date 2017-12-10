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

string aux(string ar, int length_primary, int length_secondary, char primary, char secondary,
   int num_of_change_for_primary, int total_primary_letters, int total_secondary_letters)
{
   vector<char> myVec;
   for (int i = 0; i < num_of_change_for_primary; ++i)
   {
        for (int j = 0; j < length_primary ; ++j )
        {
            myVec.push_back(primary);
        }
        if(total_secondary_letters > 0){
            myVec.push_back(secondary);
            total_secondary_letters -=1;
        }else{
            myVec.push_back('*');
        }
    }
    for (int j = 0; j < total_primary_letters - num_of_change_for_primary*length_primary; ++j )
    {
        myVec.push_back(primary);
    }

        // if there are still secondary items left 
        // distribute it
    int ind = 0;
    while( ind < myVec.size() && total_secondary_letters > 0)
    {
        int i = ind;
        if( myVec[ind] == secondary )
        {
            for ( i = ind; i < ind+length_secondary-1 && total_secondary_letters > 0; ++i)
            {
                if(total_secondary_letters > 0 ){
                    myVec.insert(myVec.begin()+i+1, secondary);
                
                    total_secondary_letters -=1;
                }
                
            }
            
        }
        ind = i + 1;
    }

    if(total_secondary_letters > 0){
        for (int i = 0; i < total_secondary_letters; ++i)
        {
            myVec.push_back(secondary);
            //total_secondary_letters -=1;
        }
    }
    

    std::string str(myVec.begin(),myVec.end());
    return str;
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
        string ans = aux(ar, a,b, 'a', 'b', num_of_change_for_apple, 
         apple, banana
            );
        return ans;
    }else{
        
        string ans = aux(ar, b, a, 'b', 'a', num_of_change_for_banana, 
         banana, apple
            );

        return ans;

    }
    
    cout << ans << endl;

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
        //string ans = compute(s,a,b);
        //cout << is_happy(ans, a, b) << endl; 
    }
    
    //print(ar);

    
    
    return 0;
}