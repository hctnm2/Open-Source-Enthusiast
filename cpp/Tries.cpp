#include <bits/stdc++.h>
using namespace  std;

class Trie{
public:
	class node{
   		public:
   			bool end;
   			node * next[26];
   			node(){
   				end=false;
   				for (int i = 0; i < 26; ++i)
   				{
   				next[i]=NULL;
   				}
   			}
	}; 
	node *trie;
	Trie(){
		trie=new node();
	}

	void insert(string word){
		int i=0;
		node* it =trie;
		while(i<word.size()){
			if(it->next[word[i]-'a'] == NULL)
				it->next[word[i]-'a']=new node();
			it=it->next[word[i]-'a'];
			i++;
		}
		it->end=true;
	}

	bool serach(string word){

		int i=0;
		node *it= trie;
		while(i<word.size()){
			if(it->next[word[i]-'a']==NULL)
				return false;
			it=it->next[word[i]-'a'];
			i++;
		}
		return it->end;
	}
};

int main(){

	Trie *myTrie=new Trie();

	vector<string> word ={"ayush","daasi"};

	for(auto w: word){
		myTrie->insert(w);
	}

	if(myTrie->serach("madhav")){
		cout<<"madhav found \n";
	}
	else{
		cout<<"not exist"<<endl;
	}

	if(myTrie->serach("ayush")){
		cout<<"ayush found \n";
	}
	else{
		cout<<"not exist"<<endl;
	}
	return 0;
}
