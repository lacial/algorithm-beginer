#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
class node{							//tree node
public:
    	int dat;
	node* left;node* right;
	node(int a,node* b,node* c){				//init
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
void display(node* a){
	cout<<a->dat<<'L'<<endl;				//output node dat
} 
void dfs(node* a){					        //dfs
	if(a){
	dfs(a->left);
	    display(a);
	dfs(a->right);
	}
}
int main(){
								//build binary tree node
	node tree6(10),tree5(10),tree4(4),tree3(12,&tree6),tree2(11,&tree4,&tree5),tree1(10,&tree2,&tree3);
	dfs(&tree1);
	return 0;
}
