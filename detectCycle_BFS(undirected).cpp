#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<vector<int>> adj={{2,3},{1,5},{1,4,6},{3},{2,7},{3,7},{5,6}};
bool detectcycle(int src,int vis[])
{
	vis[src]=1;
	queue<pair<int,int>>q;
	q.push({src,-1});
	while(!q.empty())
	{
		int node=q.front().first;
		int parent=q.front().second;
		q.pop();
		for(auto i:adj[node])
		{
			if(!vis[i])
			{
				vis[i]=1;
				q.push({i,node});
			}
			else if(parent!=i) 
			{
				return true;
			}
			
		}
		
	}
	return false;
}
int main()
{
	int vis[8]={0};
	cout<<detectcycle(1,vis);
}