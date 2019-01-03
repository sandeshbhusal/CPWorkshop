#include <iostream>
#include <ctime>
using namespace std;

int main(){
	int i = 0;
	for(int i=0; i<4e8; i++);
	printf("Time elapsed: %f secs \n", 1.0 * clock() / CLOCKS_PER_SEC);	//checks run time of the program
}
