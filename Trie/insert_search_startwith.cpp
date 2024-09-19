#include<iostream>
using namespace std;
struct Node
{
	Node *links[26];
	bool flag=false;
	bool containsKey(char ch)
	{
		return (links[ch-'a']!=NULL);
	}
	void put(char ch,Node* node)
	{
		links[ch-'a']=node;
	}
	Node* get(char ch)
	{
		return links[ch-'a'];
	}
	void setEnd()
	{
		flag=true;
	}
	bool isEnd()
	{
		return flag;
	}
};
class trie
{
	private:struct Node* root;
	public:
	trie()
	{
		root=new Node();
	}
	void insert(string word)
	{
		struct Node* node=root;
		
		for(int i=0;i<word.length();i++)
		{
			//cout<<"jtf";

			if(!node->containsKey(word[i]))
			{
			//	cout<<"ht";
				node->put(word[i],new Node());
			}
			node=node->get(word[i]);
			
		}
		node->setEnd();
	}
	bool search(string word)
	{
		Node* node=root;
		for(int i=0;i<word.length();i++)
		{
			if(!node->containsKey(word[i])) return false;
			node=node->get(word[i]);
		}
		return node->isEnd();
	}
	
};
int main()
{
	trie *t = new trie();
	t->insert("apple");
	t->insert("apps");
	t->insert("bds");
	
	cout<<t->search("bdsg");
	return 0;
}