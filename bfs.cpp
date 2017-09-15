#include<iostream>
#include<string>
#include<cstdio>
#include<queue>
using namespace std;
class node{						//tree node
public:
    int dat;
	node* left;node* right;
	node(int a,node* b,node* c){			//init
	    dat=a;left=b;right=c;
	}
	node(int a){
	    dat=a;left=0;right=0;
	}
	node(int a,node* b){
	    dat=a;left=b;right=0;
	}
	~node(){}
};
queue<node*>q;
int process=0;
void display(node* a){
	cout<<a->dat<<'L'<<endl;			//output node dat
} 
void bfs(node* a){					//dfs
	if(q.empty()!=1){
	    display(a);
		if(a->left!=0){
			q.push(a->left);
		}
		if(a->right!=0){
			q.push(a->right);
		}
	q.pop();
	bfs(q.front());
	}
	return;
}
int main(){
							//build binary tree node
	node tree6(6),tree5(5),tree4(4),tree3(3,&tree6),tree2(2,&tree4,&tree5),tree1(1,&tree2,&tree3);
	q.push(&tree1);
	bfs(&tree1);
	return 0;
}
