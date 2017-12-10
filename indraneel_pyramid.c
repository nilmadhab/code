#include<stdio.h>

#define N 1100001
int arr[N];

int main() {
    
    for (int i = 0; i < N; ++i)
    {
        arr[i] = 0;
    }
    int M;
    scanf("%d", &M);
    for (int i = 0; i < M; ++i)
    {
        int a , b;

        scanf("%d", &a);
        scanf("%d", &b);
        
        if(a < b)
            arr[a] += 1;
        else
            arr[b] += 1;
    }
    int ans = 1;
    for (int i = 0; i < N; ++i)
    {
        if(arr[i] > 0){
            while(arr[i] > 0 && i >= ans){
                ans +=1;
                arr[i] -=1;
            }
            
        }
    }
    printf("%d\n", ans-1);
    return 0;
}