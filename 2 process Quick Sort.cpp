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
/*..............Seq Quick Sort.......................*/
int p(int *arr,int l,int r){
    int pivot=arr[l];
    int i=l;
    int j=r;
    while(i<j){
        while(arr[i]<=pivot)i++;
        while(arr[j]>pivot)j--;
        if(i<j)swap(arr[i],arr[j]);
    }
    swap(arr[l],arr[j]);
    return j;
}
int qsort(int *arr,int l,int r){
    if(l<r){
        int j=p(arr,l,r);
        qsort(arr,l,j-1);
        qsort(arr,j+1,r);
    }
    return 1;
}
/*.................................*/








int main(int argc, char** argv) {
    INIT
    if(rank==0){
        int n;cin>>n;int arr[n];for(int i=0;i<n;i++)cin>>arr[i];
        int j=p(arr,0,n-1);
        qsort(arr,0,j-1);
        send(n-j-1,1);
        send_array(arr+j+1,n-j-1,1);
        int n1;
        receive(n1,1);
        int brr[n1];
        receive_array(brr,n1,1);
        print_array(arr,j+1);
        print_array(brr,n1);
    }
    if(rank==1){
        int n;
        receive(n,0);
        int arr[n];
        receive_array(arr,n,0);
        qsort(arr,0,n-1);
        send(n,0);
        send_array(arr,n,0);
    }   
    FIN
    return 0;
}
