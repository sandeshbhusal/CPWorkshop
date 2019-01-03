#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int main(void){
    
    #ifndef ONLINE_JUDGE
        freopen("graph.txt", "r", stdin);
    #endif

    int n, m;
    cin >> n >> m;  // Get nodes and edge count
    cout << "Graph contains " << n << " nodes and " << m << " edges " << endl;
    vector<int> g[n+1]; // Always pay attention here.
    while(m--){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    cout << "Finished reading all the edges. " << endl;
    cout << "Enter the node where BFS is to be initiated: " << endl;
    int startNode = 1;

    queue<int> q;
    q.push(startNode);

    vector<bool> visited(n+1, false);
    visited[startNode] = true;
    
    while(!q.empty()){
        vector<int> currentLayer;
        while(!q.empty()){
            currentLayer.push_back(q.front());
            q.pop();
        }
        // Display the current Layer of queue.
        queue<int> replace;
        for(auto x: currentLayer){
            cout << x << " ";
            visited[x] = true;
            for(auto child: g[x]){
                if(!visited[child])
                    replace.push(child);
            }
        }
        cout << endl;
        q = replace;
    }

    return 0;
}