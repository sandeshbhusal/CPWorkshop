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

int sumoffactors(int a){
	int mul=1;
	int div=1;
	for(auto x: factorspair(a)){
		mul*=(pow(x.first,x.second+1)-1);
		div*= x.first-1;
	}
	return mul/div;
}

int main(){
	sievefactors();
	int a;
	printf("Enter a number to find its sum of factors: ");
	scanf("%d", &a);
	printf("Sum of factors is: %d\n", sumoffactors(a));
	return 0;
}