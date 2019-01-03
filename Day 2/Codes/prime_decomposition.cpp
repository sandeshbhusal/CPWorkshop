#include <iostream>
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

map<int, int> factorpair(int num){
	map<int, int> factorspair;
	while(num>1){
		factorspair[factors[num]] += 1;
		num /= factors[num];
	}
	return factorspair;
}

int main(){
	sievefactors();
	int a;
	printf("Enter a number to find its factor: ");
	scanf("%d", &a);
	for(auto x: factorpair(a)){
		printf("%d\t%d\n",x.first,x.second);
	}
	return 0;
} 