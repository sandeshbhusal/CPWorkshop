#include <iostream>
#include <vector>
#include <map>
using namespace std;
const int MAXSIZE = 1e7;


map<int, int> factorspair(int a){
	map <int, int>  factors;
	for(int x=2; x*x<=a; x++){
		while(a%x==0){
			factors[x] +=1;
			a/=x;
		}
	}
	if(a>1)factors[a]++;
	return factors;
}

int main(){
	int a;
	printf("Enter a number to find its factor: ");
	scanf("%d", &a);
	for(auto x: factorspair(a)){
		printf("%d\t%d\n",x.first,x.second);
	}
	return 0;
} 