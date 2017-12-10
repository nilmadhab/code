#include <studio.h>
using namespace std;


const int N = 1100001;
int arr[N];

int main() {
    //std::ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < N; ++i)
    {
        arr[i] = 0;
    }
    int M;
    cin >> M;
    for (int i = 0; i < M; ++i)
    {
        int a , b;
        cin >> a >> b;
        
        if(a < b)
            arr[a] = 1;
        else
            arr[b] = 1;
    }
    int ans = 0;
    for (int i = 0; i < N; ++i)
    {
        if(arr[i] > 0){
            ans +=1;
        }
    }
    cout << ans << "\n";
    return 0;
}