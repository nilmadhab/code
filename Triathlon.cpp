#include <bits/stdc++.h>
using namespace std;
struct data {
    int a,b,c;
    int sum;
};
bool cmp(data a1, data b1) {
    return a1.sum > b1.sum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<data> v(n);
    int x,y,z;
    for(int i=0;i<n;i++) {
        cin>>v[i].a>>v[i].b>>v[i].c;
        v[i].sum = v[i].b+v[i].c;
    }
    sort(v.begin(),v.end(),cmp);
    int ans = v[0].a+v[0].sum;
    int prev = v[0].a;
    for(int i=1;i<n;i++) {
        ans = max(ans,prev + v[i].a + v[i].sum);
        prev += v[i].a;
    }
    cout<<ans;
    return 0;
}