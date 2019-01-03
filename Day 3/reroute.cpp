/*
    This file demonstrates the re-routing of IO through
    the C++ system.
*/

#include <iostream>

using namespace std;

int main(void){
    // The input file is called "input.txt"
    // and the output is called "output.txt"
    freopen("output.txt", "w", stdout);
    for(int i=0; i<100; i++){
        cout << "Here I am : " << i << endl;
    }
    return 0;
}