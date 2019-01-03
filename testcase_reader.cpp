#include <iostream>
using namespace std;

int main(void){
    /*
        Test file structure:
        First line: No of test cases.(n)
        (n) lines each contain two integers, a and b
    */

    freopen("testcase.txt", "r", stdin);
    int testCaseCount;
    cin >> testCaseCount;
    while(testCaseCount--){
        int a, b;
        cin >> a >> b;
        cout << a << " " << b << endl;
    }
    return 0;
}