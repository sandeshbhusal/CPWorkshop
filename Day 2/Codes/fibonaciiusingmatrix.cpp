#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<vector<long long> > matrix;

matrix matmultiply(matrix a, matrix b){			//matrix multiplication
	matrix result(a.size());
	ll sum;
	for(int i=0;i < a.size(); i++){
		for(int j=0; j<b[0].size(); j++){
			sum=0;
			for(int k = 0; k< b.size(); k++){
				sum+= a[i][k]*b[k][j];
			}
			result[i].push_back(sum);
		}
	}
	return result;
}

matrix identitymatrix(ll n){					//returns identity matrix of n*n
	matrix v(n, std::vector<ll>(n,0));
	for(int i=0; i<n; i++){
		v[i][i]=1;
	}
	return v;
}

matrix matpow(matrix mat, ll n){				//matrix exponentiation using recursion
	if(n==0) return identitymatrix(mat.size());
	if(n==1)return mat;
	if(n%2==0)return matpow(matmultiply(mat,mat),n/2);
	return matmultiply(mat, matpow(matmultiply(mat,mat),n/2)); 
}

ll nthfib(ll n){								//nth number in fibonacci sequence using matrix multiplication 
	std::vector<std::vector<ll>  > v(2);
	v[0]={0,1};
	v[1]={1,1};
	std::vector<std::vector<ll>  > given(2);
	given[0]={0};
	given[1]={1};
	return matmultiply(matpow(v,n), given)[0][0];	
}

int main(){
	int a;
	printf("Enter n to get nth number of fibonacci sequence: ");
	scanf("%d", &a);
	printf("nth term in fibonacci sequence is: %lld \n", nthfib(a));
	cout<<1.0*clock()/CLOCKS_PER_SEC<<endl;
	return 0;
}

