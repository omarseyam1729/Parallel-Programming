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
using namespace std;
int main(int argc, char** argv) {
        int rank,size;
        MPI_Init(&argc, &argv);
        MPI_Comm_rank(MPI_COMM_WORLD, &rank);
        MPI_Comm_size(MPI_COMM_WORLD,&size);
        if(rank==0){
            int n;
            cin>>n;
            int *arr=new int[n];
            for(int i=0;i<n;i++)cin>>arr[i];
            int mid=n/2;
            int mid2=n-n/2;
            MPI_Send(&mid,1, MPI_INT, 1, 0, MPI_COMM_WORLD);
            MPI_Send(&mid2,1, MPI_INT, 2, 0, MPI_COMM_WORLD);
            MPI_Send(arr,mid, MPI_INT, 1, 0, MPI_COMM_WORLD);
            MPI_Send(arr+mid,n-mid, MPI_INT, 2, 0, MPI_COMM_WORLD);
            int *brr=new int[mid];int *crr=new int[mid];int *drr=new int[n];
            MPI_Recv(brr, mid, MPI_INT,1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            MPI_Recv(crr, n-mid, MPI_INT,2, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            merge(brr,brr+mid,crr,crr+n-mid,drr);
            for(int i=0;i<n;i++)cout<<drr[i]<<" ";
        }
        else if(rank==1){
            int n;
            MPI_Recv(&n, 1, MPI_INT,0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            int *arr=new int[n];
            MPI_Recv(arr, n, MPI_INT,0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            sort(arr,arr+n);
            MPI_Send(arr,n, MPI_INT, 0, 0, MPI_COMM_WORLD);
            
        }
        else{
            int n;
            MPI_Recv(&n, 1, MPI_INT,0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            int *arr=new int[n];
            MPI_Recv(arr, n, MPI_INT,0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            sort(arr,arr+n);
            MPI_Send(arr,n, MPI_INT, 0, 0, MPI_COMM_WORLD);
        }
        MPI_Finalize();
        return 0;
}
