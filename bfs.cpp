#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main()
{
	vector<int> bfs;
	vector<vector<int>>adj={{1},{2,3},{1,4,5},{1,6,7},{2},{2},{3},{3}};   
//	for(auto i:adj)
//	{
//		for(auto j:i)
//		{
//			cout<<j<<" ";
//		}
//		cout<<" \n";
//	}
//	
	int vis[8]={0};
	vis[2]=1;
	queue<int>q;
	q.push(2);
	while(!q.empty())
	{
		int node=q.front();
		
		q.pop();
		if(node!=0)
		bfs.push_back(node);
	
		
		for(auto i:adj[node])
		{
			if(!vis[i])
			{
				vis[i]=1;
				q.push(i);
			}
		}
	}
		for(auto i:bfs)
		{
		cout<<i<<" ";
		}
	
}