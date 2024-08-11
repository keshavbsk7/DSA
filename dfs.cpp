#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>>adj={{1},{2,3},{1,4,5},{1,6,7},{2},{2},{3},{3}};
void d_fs(int node,int vis[],vector<int>&dfs)
{
	vis[node]=1;
	
	dfs.push_back(node);
	for(auto i:adj[node])
	{
		if(!vis[i]){
		
		d_fs(i,vis,dfs);
	}
}
}
int main()
{
	vector<int> dfs;
	
	int vis[8]={0};
	d_fs(7,vis,dfs);
	
	for(auto i:dfs)
	{
		cout<<i<<" ";
	}



}