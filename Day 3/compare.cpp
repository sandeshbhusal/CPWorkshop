#include <iostream>
#include <vector>
using namespace std;

int main(void){
    // Taking the test cases for 'n' nodes and 'm' edges.
    int n, m;
    for(int n=2; n < 10000000; n++){
        try{
            cout << "Testing for: " << n << " nodes " << endl;
            vector<int> graphVector[n];
            vector<vector<int> > pureGraph(n);
            int g[n][n];
            cout << "Created a vector matrix graph of size " << sizeof(graphVector) << " at " << &graphVector << endl;
            cout << "Created a pure vector graph of size " << sizeof(pureGraph) << " at " << &pureGraph << endl;
            cout << "Created a array graph of size " << sizeof(g) << " at " << &g << endl;
            cout << "------------" << endl;
            getc(stdin);
        }
        catch(...){
            cout << "Memory could not be allocated. Breaking program" << endl;
        }
    }
    return 0;
}