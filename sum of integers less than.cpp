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
int N=10;
int main(int argc, char* argv[])
{
    MPI_Init(&argc, &argv); 
	int rank,size;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	if(rank==0){
		int sum=0;
		for(int i=1;i<size;i++){
			int temp;
			MPI_Recv(&temp, 1, MPI_INT,i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			sum+=temp;
		}
		for(int i=0;i<N/size;i++){sum+=i;}
		cout<<sum;
	}
	else{
		int start=rank*(N/size);
		int sum=0;
		for(int i=start;i<start+N/size;i++){sum+=i;}
		MPI_Send(&sum,1, MPI_INT, 0, 0, MPI_COMM_WORLD);
	}
    MPI_Finalize(); 
    return 0;
}
