/*
    Representation of a graph using adj list.
*/

#include <iostream>
#include <vector>

using namespace std;

int main(void){
    
    #ifndef ONLINE_JUDGE 
        freopen("graph.txt", "r", stdin);
    #endif

    int n, m;
    cin >> n >> m;  // n = no. of nodes, m = no. of edges.
    vector<int> g[n+1];   // Denotes the graph
    while(m--){
        // Read all edges in the graph
        int a, b;
        cin >> a >> b;  // a, b is an edge in the graph
        g[a].push_back(b);  // as the graph is undirected, 'a' is connected to 'b'
        g[b].push_back(a);  // and 'b' is connected to 'a'. What would be the case if the graph was 'directed'?
    }
    // Print the graph:
    cout << "Printing connected components: " << endl;
    n++;
    while((n)-- > 1){
        // 'n' denotes a particular node
        cout << n << " is connected to nodes: ";
        for(auto x: g[n])
            cout << x << " , "; // Run a foreach loop
        cout << n << endl;
    }
    return 0;
}