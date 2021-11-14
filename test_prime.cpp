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
#include <chrono>
#include<vector>
#include<cstring>
#include<bitset>
#include<cstdio>
#include <mpi.h>
#include <chrono>
#define mod 1000000007
#define bod 92233720368547750
#define FIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define receive(x,from)MPI_Recv(&x, 1, MPI_INT,from, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
#define send(y,to){int x=y;MPI_Send(&x,1, MPI_INT,to, 0, MPI_COMM_WORLD);}
#define init int size,rank;MPI_Init(&argc,&argv);MPI_Comm_size(MPI_COMM_WORLD,&size);MPI_Comm_rank(MPI_COMM_WORLD,&rank);
#define fin MPI_Finalize();
using namespace std;
int N=10000000;
int check_prime(int n){
    if(n==1)return 0;
    if(n==2)return 1;
    for(int i=2;i*i<=n;i++)if(n%i==0)return 0;
    return 1;
}
int main(int argc, char* argv[])
{    
    init 
    if(rank==0){
      
        int seg=N/size;
        int ret=0;
        for(int i=1;i<size;i++){
            int t;receive(t,i);ret+=t;
        }
        for(int i=1;i<seg;i++)ret+=check_prime(i);
        cout<<"The number of primes is "<<ret<<endl;
        auto end = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    cout <<"Time elapsed:"<<elapsed.count() << " ms";
    }
    else{
        int seg=N/size;
        int start=rank*seg;
        int end=(rank+1)*seg;
        int ret=0;
        for(int i=start;i<=end;i++)ret+=check_prime(i);
        send(ret,0);
    }
    fin
    return 0;
}