#include<bits/stdc++.h>
using namespace std;

typedef struct node{
    char maze[3][3];
    int x, y, step;
}node;

char dst[3][3] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', 'x'}
};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

bool check(char maze[3][3], char dst[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(maze[i][j] != dst[i][j]){
                return false;
            }
        }
    }
    return true;
}

string to_str(char maze[3][3]){
    string ans;
     for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            ans += maze[i][j];
        }
    }
    return ans;
}


char nums[10];

int main(){
    node src;
    unordered_set<string> vis;
    
    for(int i = 0; i < 9; i++){
        scanf("%s", nums);
        src.maze[i / 3][i % 3]  = nums[0];
        if(nums[0] == 'x'){
            src.x = i / 3;
            src.y = i % 3;   
        }
    }
    src.step = 0;
    
    // for(int i = 0; i < 3; i++){
    //     for(int j = 0; j < 3; j++){
    //         printf("%c ", src.maze[i][j]);
    //     }
    //     printf("\n");
    // }
    
    queue<node> q;
    q.push(src);
    vis.insert(to_str(src.maze));
    
    int ans = -1;
    while(!q.empty()){
        node t = q.front(); q.pop();
        if(check(t.maze, dst)){
            ans = t.step;
            break;
        }
        for(int i = 0; i < 4; i++){
            int nx = t.x + dx[i];
            int ny = t.y + dy[i];
            if(nx >= 0 && nx < 3 && ny >= 0 && ny < 3){
                node nt = t;
                swap(nt.maze[t.x][t.y], nt.maze[nx][ny]);
                if(!vis.count(to_str(nt.maze))){
                    vis.insert(to_str(nt.maze));
                    nt.x = nx;
                    nt.y = ny;
                    nt.step += 1;
                    q.push(nt);
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}