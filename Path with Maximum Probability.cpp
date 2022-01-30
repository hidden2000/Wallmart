class Solution {
public:
   void dfs(vector<pair<int,double>> adj[],bool *visited,int node){
           visited[node]=1;
        for(auto k:adj[node]){
            if(!visited[k.first])
                dfs(adj,visited,k.first);
                }
    }
    
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        // first step construct an adjacency list 
        vector<pair<int,double>> adj[n];
        for(int i=0;i<edges.size();i++){
               int u=edges[i][0];
               int v=edges[i][1];
               double w=succProb[i];
              adj[u].push_back({v,w});
              adj[v].push_back({u,w});
         }
  
        bool visited[n];
        memset(visited,0,n);
        dfs(adj,visited,start);
        if(visited[end]==0)
            return 0;
        
        
        memset(visited,0,n);
        double key[n]; 
      for(int i=0;i<n;i++){
                key[i]=0;
        
        }
        priority_queue<pair<double,int>>pq;
        pq.push({1.0,start});
              key[start]=1.0; 
        for(int i=0;i<n;i++){
            int u=pq.top().second;
            pq.pop();
            visited[u]=1;
            
            for(auto k:adj[u]){
                 int v=k.first;
                double w=k.second;
              
                if(!visited[v]&&w*key[u]>key[v]){
                        key[v]=key[u]*w;
                      pq.push({key[v],v});
                    }
                      }
        }
        
        return key[end];
                
    }

};