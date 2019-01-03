#include <iostream>
#include <vector>
using namespace std;

int main(void){
    int a, b;
    a = 10, b = 13;
    auto lambdaFunction = [](int a, int b){
        return a+b;
    };
    cout << "Output of lambda function: " << lambdaFunction(a, b) << endl;

    vector<int> p{1, 2, 3, 4, 5};
    cout << "Elements in the array: " << endl;
    for(int x:p){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}