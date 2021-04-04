//
// Created by Kylian Lee on 2021/04/04.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int adj[20001][20001];
int cost[20001];
bool visited[20001];

int solution(int n, vector<vector<int>> edge);

int main() {

    cout << solution(6, {{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}}) << endl;

    return 0;
}

int solution(int n, vector<vector<int>> edge){
    queue<int> bfsQ;

    for(int i = 0; i < 20001; i++){
        visited[i] = false;
        cost[i] = 0;
    }

    for(int i = 0; i < 20001; i++){
        for(int j = 0; j < 20001; j++){
            adj[i][j] = 0;
        }
    }

    for(int i = 0; i < edge.size(); i++){
        adj[edge[i][0]][edge[i][1]] = 1;
        adj[edge[i][1]][edge[i][0]] = 1;
    }

    bfsQ.push(1);
    visited[1] = true;
    cost[1] = 0;

    int preNode;

    while(!bfsQ.empty()){
        for(int i = 1; i <= n; i++){
            preNode = bfsQ.front();
            if(adj[preNode][i] == 1 && !visited[i]){
                bfsQ.push(i);
                visited[i] = true;
                cost[i] = cost[preNode] + 1;
            }
        }
        bfsQ.pop();
    }

    int count, max = 0;

    for(int i = 1; i <= n; i++){
        if(cost[i] > max) {
            max = cost[i];
            count = 1;
        }
        else if(cost[i] == max)
            count++;

    }

    return count;

}
