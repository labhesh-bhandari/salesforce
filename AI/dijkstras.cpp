#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
    
    // Creating adjacency list with weights of edges
    unordered_map<int, list<pair<int, int>>> adj;

    for(int i = 0; i < edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];

        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }

    // Distance vector
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    // Min heap {distance, node}
    priority_queue<pair<int, int>, 
                   vector<pair<int, int>>, 
                   greater<pair<int, int>>> minHeap;

    minHeap.push({0, src});

    while(!minHeap.empty()){

        auto top = minHeap.top();

        int currDist = top.first;
        int currNode = top.second;

        minHeap.pop();

        for(auto neighbour : adj[currNode]){

            int nextNode = neighbour.first;
            int edgeWeight = neighbour.second;

            if(currDist + edgeWeight < dist[nextNode]){

                dist[nextNode] = currDist + edgeWeight;

                minHeap.push({dist[nextNode], nextNode});
            }
        }
    }

    return dist;
}


int main(){

    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> edges(E, vector<int>(3));

    cout << "Enter edges (u v weight):\n";

    for(int i = 0; i < E; i++){
        cin >> edges[i][0] 
            >> edges[i][1] 
            >> edges[i][2];
    }

    int src;

    cout << "Enter source vertex: ";
    cin >> src;

    vector<int> result = dijkstra(V, edges, src);

    cout << "\nShortest distances from source " << src << ":\n";

    for(int i = 0; i < V; i++){

        cout << "Vertex " << i << " : ";

        if(result[i] == INT_MAX){
            cout << "Not reachable";
        }
        else{
            cout << result[i];
        }

        cout << endl;
    }

    return 0;
}