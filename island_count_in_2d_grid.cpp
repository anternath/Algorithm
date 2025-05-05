class Solution {
    public:
        bool visit[105][105]={false};
        pair<int,int> ar[4]={{-1,0},{0,-1},{1,0},{0,1}};
        bool valid(int i,int j){
            if(i<0 || i>=n || j<0 || j>=m){
                return false;
            }
            else return true;
        }
        int n,m;
        bool check= false;
        void component(vector<vector<int>> grid,int i, int j){
            queue<pair<int,int>>q;
            q.push({i,j});
            visit[i][j]=true;
            while(!q.empty()){
                pair<int,int> p= q.front();
                q.pop();
                i = p.first;
                j= p.second;
               for(int k=0; k<4; k++){
                int ci= ar[k].first + i;
                int cj = ar[k].second + j;
                if(valid(ci,cj)==true){
                    if(grid[ci][cj]==0){
                        if(ci==0|| ci==(n-1) || cj==0 || cj==(m-1) ){
                            check=true;
                        }
                    }
                }
                if(valid(ci,cj)==true && visit[ci][cj]==false && grid[ci][cj]==0 ){
                if(ci==0|| ci==(n-1) || cj==0 || cj==(m-1) ){
                            visit[ci][cj]=true;
                            check=true;
                        }
                else{
                    q.push({ci,cj});
                    visit[ci][cj]=true;
                }
               }
               }
            }
        }
        int closedIsland(vector<vector<int>>& grid) {
            int cnt=0;
           n=grid.size();
           m=grid[0].size();
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    if(visit[i][j]==false && grid[i][j]==0){
                        if(i==0|| i==(n-1) || j==0 || j==(m-1) ){
                            visit[i][j]=true;
                        }
                        else{
                            component(grid,i,j);
                            if(check==false){
                                cnt++;
                            }
                            else{
                                check=false;
                            }
                        }
                    }
                    else{
                        grid[i][j]==true;
                    }
                }
            }
            return cnt;
        }
    };