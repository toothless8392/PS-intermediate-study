#include<iostream>
#include<queue>
#include<cstring>
#define pp std::pair<int, int>

const int y[4] = {1, 0, -1, 0};
const int x[4] = {0, 1, 0, -1};
int T, N, M, K, farm[55][55];
bool visited[55][55];

bool possible(int r, int c){
   return r >= 0 && r < N && c >= 0 && c < M;
}
void bfs(int r, int c){
   std::queue<pp> que;

   que.push({r, c});
   visited[r][c] = true;

   while(!que.empty()){
      pp cur = que.front();

      que.pop();
      for(int i = 0; i < 4; ++i){
         int R = cur.first + y[i];
         int C = cur.second + x[i];

         if(possible(R, C) && !visited[R][C] && farm[R][C] == 1){
            que.push({R, C});
            visited[R][C] = true;
         }
      }
   }
}

int main () {
   for(scanf("%d", &T); T > 0; --T){
      int warm = 0;

      memset(farm, 0, sizeof(farm));
      memset(visited, false, sizeof(visited));

      scanf("%d %d %d", &N, &M, &K);
      for(int i = 0; i < K; ++i){
         int r, c;

         scanf("%d %d", &r, &c);
         farm[r][c] = 1;
      }

      for(int i = 0; i < N; ++i)
      for(int u = 0; u < M; ++u){
         if(farm[i][u] == 1 && !visited[i][u]){
            ++warm;
            bfs(i, u);
         }
      }
      printf("%d\n", warm);
   }
   return 0;
}
