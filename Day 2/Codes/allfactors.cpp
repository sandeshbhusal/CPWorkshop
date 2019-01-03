#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <bitset>
using namespace std;
const int MAXSIZE = 1e7;

vector<int> factors(MAXSIZE+1);

void sievefactors(void){							//initializes vector factors with greatest prime divisor of given index
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

map<int, int> factorpair(int num){					//generates pairs of prime factors and exponents
	map<int, int> factorspair;
	while(num>1){
		factorspair[factors[num]] += 1;
		num /= factors[num];
	}
	return factorspair;
}

set<int> allfactors(int num){						//uses combination to generate all factors
	vector<int> v;
	v.push_back(1);
	for(auto x:factorpair(num)){
		for(int i= 1; i<=x.second; i++){
			v.push_back(pow(x.first, i));
		}
	}
	int mul;
	set<int>vec;
	int ab=v.size();
	for(int i=1; i<pow(2, ab);i++){
		bitset<19> b(i);
		mul=1;
		for(int j= 0; j<ab; j++){
			if(b[j])mul*=v[j];
		}
		if(num % mul==0)
		vec.insert(mul);
	}
	return vec;
}

int main(){
	sievefactors();
	int a;
	printf("Enter a number to find its factors: ");
	scanf("%d", &a);
	for(auto x: allfactors(a)){
		printf("%d\t",x);
	}
	printf("\n");
	return 0;
} 