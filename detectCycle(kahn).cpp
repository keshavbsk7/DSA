#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<vector<int>>adj={{},{},{3},{1,2},{0,1},{0,2}};
bool topo(int v)
{
	int indegree[v]={0};
	for(int i=0;i<v;i++)
	{
		for(auto it:adj[i]){
			indegree[it]++;
		}
	}
	queue<int> q;
	for(int i=0;i<v;i++)
	{
		if(indegree[i]==0) q.push(i);
	}
	int count=0;
	while(!q.empty())
	{
		int node=q.front();
		q.pop();
		count++;
		for(auto i:adj[node])
		{
			indegree[i]--;
			if(indegree[i]==0) q.push(i);
		}
	}
	if(count==v) return false;
	return true;
}
int main()
{
	vector<int>res;
	cout<<topo(6);
	
}