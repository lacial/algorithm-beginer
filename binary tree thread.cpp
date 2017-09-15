#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
class node{							//tree node
public:
    	int dat;
	node* left;node* right;
	int ltg;int rtg;
	node(int a,node* b,node* c){				           //init
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
	
	cout<<a->dat<<'L'<<endl;				              //output node dat
} 
void thread(node* a,node* pre){					        //thread & dfs
	if(a){
	thread(a->left,pre);
	    display(a);
		if(a->left!=0){
			a->left=pre;a->ltg=1;cout<<"l-";
		}
		if(pre!=0 && a->right!=0){
			pre->right=a;a->rtg=1;cout<<"r-";
		}
		cout<<"-----"<<endl;
		pre=a;
	thread(a->right,pre);
	}
}
int main(){
								                              //build binary tree node
	node tree6(6),tree5(5),tree4(4),tree3(3,&tree6),tree2(2,&tree4,&tree5),tree1(1,&tree2,&tree3);
	node pre(0);                                //build pre
	thread(&tree1,&pre);
	return 0;
}
