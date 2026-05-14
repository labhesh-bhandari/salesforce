#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int ROW = 5;
const int COL = 5;

struct Node {
    int x, y;

    int g;
    int h;
    int f;

    Node* parent;

    Node(int x, int y, int g, int h, Node* parent = nullptr) {
        this->x = x;
        this->y = y;

        this->g = g;
        this->h = h;
        this->f = g + h;

        this->parent = parent;
    }
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->f > b->f;
    }
};

int grid[ROW][COL] = {
    {0,0,0,0,0},
    {1,1,0,1,0},
    {0,0,0,1,0},
    {0,1,0,0,0},
    {0,0,0,1,0}
};

// Manhattan distance
int heuristic(int x, int y, int gx, int gy) {
    return abs(x-gx) + abs(y-gy);
}

bool isValid(int x, int y) {
    return x>=0 && y>=0 && x<ROW && y<COL;
}

void printPath(Node* goalNode) {
    vector<pair<int,int>> path;

    while(goalNode) {
        path.push_back({goalNode->x, goalNode->y});
        goalNode = goalNode->parent;
    }

    reverse(path.begin(), path.end());

    cout<<"Path:\n";

    for(auto p : path) {
        cout<<"("<<p.first<<","<<p.second<<") ";
    }

    cout<<endl;
}

void aStar(int sx, int sy, int gx, int gy) {

    priority_queue<Node*, vector<Node*>, Compare> open;

    bool closed[ROW][COL] = {false};

    Node* start =
        new Node(
            sx,
            sy,
            0,
            heuristic(sx, sy, gx, gy)
        );

    open.push(start);

    int dx[] = {-1,1,0,0};
    int dy[] = {0,0,-1,1};

    while(!open.empty()) {

        Node* current = open.top();
        open.pop();

        int x = current->x;
        int y = current->y;

        if(closed[x][y])
            continue;

        closed[x][y] = true;

        if(x==gx && y==gy) {
            cout<<"Goal found!\n";
            printPath(current);
            return;
        }

        for(int i=0;i<4;i++) {

            int nx = x + dx[i];
            int ny = y + dy[i];

            if(!isValid(nx, ny))
                continue;

            if(grid[nx][ny]==1)
                continue;

            if(closed[nx][ny])
                continue;

            int newG = current->g + 1;

            int newH =
                heuristic(
                    nx,
                    ny,
                    gx,
                    gy
                );

            Node* neighbor =
                new Node(
                    nx,
                    ny,
                    newG,
                    newH,
                    current
                );

            open.push(neighbor);
        }
    }

    cout<<"No path exists\n";
}

int main() {

    int startX = 0;
    int startY = 0;

    int goalX = 4;
    int goalY = 4;

    aStar(
        startX,
        startY,
        goalX,
        goalY
    );

    return 0;
}