#include<vector>

std::vector<int> eratos(int n){
    std::vector<bool> isprime(n+1,true);
    std::vector<int> prime;
    for(int i=2;i<n;++i){
        if(!isprime[i]) continue;
        prime.push_back(i);
        for(int j=i*2;j<=n;j+=i) isprime[j] = false;
    }
    return prime;
}
