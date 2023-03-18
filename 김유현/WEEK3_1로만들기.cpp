#include<iostream>
#include<cstring>

int N, cache[1000005];

int DP(int cur){
    if(cur == 1)
        return 0;

    int &ret = cache[cur];

    if(ret != -1)
        return ret;
    
    ret = 1000004;
    if(cur % 3 == 0)
        ret = std::min(ret, DP(cur / 3) + 1);
    if(cur % 2 == 0)
        ret = std::min(ret, DP(cur / 2) + 1);
    
    ret = std::min(ret, DP(cur - 1) + 1);
    
    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));

    scanf("%d", &N);
    printf("%d\n", DP(N));
}
