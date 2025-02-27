/*
    Representation of a graph using adjacency matrix.
*/

#include <bits/stdc++.h>

using namespace std;

int main(void){
    #ifndef ONLINE_JUDGE
        freopen("graph.txt", "r", stdin);
    #endif
    int n, m;
    cin >> n >> m;

    cout << "Graph contains: " << n << " nodes and " << m << " edges. "<< endl;
    int g[n+1][n+1];
    memset(g, 0, sizeof(g));
    while(m--){
        int a, b;
        cin >> a >> b;

        g[a][a] = 1;
        g[b][b] = 1;
        g[a][b] = 1;
        g[b][a] = 1;
    }

    cout << "  ";
    for(int i=1; i<=n; i++)
        cout << i <<  " ";
    cout << endl;
    for(int i=1; i<=n; i++){
        cout << i << " ";
        for(int j=1; j<=n; j++){
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
}
