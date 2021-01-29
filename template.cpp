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
#include <mpi.h>
#define mod 1000000007
#define bod 92233720368547750
#define FIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define TEST freopen("1.txt","r",stdin);
#define receive(x,from)MPI_Recv(&x, 1, MPI_INT,from, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
#define send(y,to){int x=y;MPI_Send(&x,1, MPI_INT,to, 0, MPI_COMM_WORLD);}
#define INIT int size,rank;MPI_Init(&argc,&argv);MPI_Comm_size(MPI_COMM_WORLD,&size);MPI_Comm_rank(MPI_COMM_WORLD,&rank);
#define FIN MPI_Finalize();
using namespace std;
/*.....................................*/
void send_array(int *arr,int n,int to){
MPI_Send(arr,n, MPI_INT,to, 0, MPI_COMM_WORLD);
}
void receive_array(int *arr,int n,int from){
MPI_Recv(arr, n, MPI_INT,from, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
}
void print_array(int *arr,int n){
    for(int i=0;i<n;i++)cout<<arr[i]<<" ";
}
int main(int argc,char **argv){
INIT
/* write your code here */
FIN
return 0;
}
