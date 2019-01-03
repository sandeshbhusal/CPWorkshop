#include <iostream>
#include <cmath>
#include <vector>
#include <map>
using namespace std;
const int MAXSIZE = 1e7;

vector<int> factors(MAXSIZE+1);

void sievefactors(void){
	vector<int> nums(MAXSIZE+1);
	for(int i = 2; i<=MAXSIZE; i++){
		if(nums[i] == 0){
			factors[i] = i;
			for(int j = 2; i * j <= MAXSIZE; j++){
				nums[i * j] = 1;
				factors[i * j] = i;
			}
		}
	}
}

map<int, int> factorspair(int num){
	map<int, int> factorspair;
	while(num>1){
		factorspair[factors[num]] += 1;
		num /= factors[num];
	}
	return factorspair;
}

int numfactors(int a){ //including 1 and number itself
	int mul=1;
	for(auto x:factorspair(a)){
		mul*=(x.second+1);
	}
	return mul;
}

int productoffactors(int a){
	int b=numfactors(a)/2;
	return pow(a, b);
}


int main(){
	sievefactors();
	int a;
	printf("Enter a number to find its productoffactors of factors: ");
	scanf("%d", &a);
	printf("Product of factors is: %d\n", productoffactors(a));
	return 0;
}