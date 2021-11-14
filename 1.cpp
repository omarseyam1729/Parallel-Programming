#include <iostream>
#include<climits>
#include<utility>
#include<set>
#include<algorithm>
#include<set>
#include<string>
#include<iterator>
#include<cmath>
#include<stack>
#include<queue>
#include<vector>
#include<cstring>
#include<bitset>
#include<cstdio>
#include <chrono>
#define mod 1000000007
#define bod 92233720368547750
#define FIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int N=1000000;
int check_prime(int n){
    if(n==1)return 0;
    if(n==2)return 1;
    for(int i=2;i*i<=n;i++)if(n%i==0)return 0;
    return 1;
}
signed main(){
int ret=0;
for(int i=1;i<=N;i++)ret+=check_prime(i);
cout<<ret;
}