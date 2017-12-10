#include <iostream>
using namespace std;

#define endl "\n"

//INT_MIN
#include<bits/stdc++.h>

//#include "/Users/nilmadhab/Desktop/code/library/useful_functions.cpp"

#define ll long long
vector<int> vec(100005);
vector<int> BITree(100005);
//vector<int> cache(100005);
map< pair<int, int> > cache;

int N;


int getXOR(int index)
{
    int sum = 0; // Iniialize result

    // index in BITree[] is 1 more than the index in arr[]
    index = index + 1;

    // Traverse ancestors of BITree[index]
    while (index>0)
    {
        // Add current element of BITree to sum
        sum ^= BITree[index];

        // Move index to parent node in getSum View
        index -= index & (-index);
    }
    return sum;
}

// Updates a node in Binary Index Tree (BITree) at given index
// in BITree. The given value 'val' is added to BITree[i] and 
// all of its ancestors in tree.
void updateBIT( int index, int oldVal, int val)
{
    // index in BITree[] is 1 more than the index in arr[]
    index = index + 1;

    // Traverse all ancestors and add 'val'
    while (index <= N)
    {
    // Add 'val' to current node of BI Tree
    BITree[index] ^= oldVal^val;
    if(BITree[index] == )

    // Update index to that of parent in update View
    index += index & (-index);
    }
}

void compute(int last, int XOR)
{
    ll ans = 0;
    int Xor = vec[0];
    if(Xor == XOR) ans +=1;
    for (int j = 1; j <= last; ++j)
    {
        if(getXOR(j) == XOR)
            ans +=1;
    }

    cout << ans << endl;
    
}

void allXORSbyNaive()
{
    ll ans = 0;
    int Xor = vec[0];

    cout << Xor << " ";
    for (int j = 1; j < N; ++j)
    {
        Xor ^= vec[j];
        cout << Xor << " ";
    }

    cout  << endl;
    
}

void allXORSbyBIT()
{
    ll ans = 0;
    int Xor = getXOR(0);
    cout << Xor << " ";
    for (int j = 1; j < N; ++j)
    {
        cout << getXOR(j) << " ";
    }

    cout  << endl;
    
}

int main() {
    //std::ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int  Q;
    cin >> N >> Q;
    for (int i = 0; i < N; ++i)
    {
        cin >> vec[i];
    }

    for (int i=1; i<=N; i++)
        BITree[i] = 0;

    for (int i=0; i<N; i++)
        updateBIT(i, 0, vec[i]);

    //allXORSbyNaive();
    //allXORSbyBIT();

    for (int i = 0; i < Q; ++i)
    {
        int type, b, c;
        cin >> type >> b >> c;

        if(type == 1)
        {
            
            int oldVal = vec[b-1];
            vec[b-1] = c;
            updateBIT(b-1, oldVal, c);
            //allXORSbyNaive();
            //allXORSbyBIT();
        }else{
            compute(b-1, c);
        }

    }

    //
    //print(mat);

    ////////////// compute



    return 0;
}