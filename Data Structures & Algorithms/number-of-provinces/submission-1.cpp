class Solution {
public:
    void dfs(vector<vector<int>>& isConnected,int node,vector<bool> &vis){
        int n = isConnected.size();
        vis[node] = true;
        for(int i = 0;i<n;i++){
            if(!vis[i]&&isConnected[node][i]){
                dfs(isConnected,i,vis);
            }
        }
    }

    void bfs(vector<vector<int>>& isConnected,vector<bool> &vis,int node){
        int n = isConnected.size();

        queue<int> q;
        q.push(node);
        vis[node] = true;

        while(!q.empty()){
            int temp = q.front();
            q.pop();

            for(int i = 0;i<n;i++){
                if(!vis[i] && isConnected[temp][i]==1){
                    vis[i]=true;
                    q.push(i);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int count = 0;
        vector<bool> vis(n,false);
        for(int V = 0;V<n;V++){
            if(!vis[V]){
                count++;
                // dfs(isConnected,V,vis);
                bfs(isConnected,vis,V);
            }
        }
        return count;
    }
};