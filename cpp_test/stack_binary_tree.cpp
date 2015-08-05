#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <stack>

using namespace std;


struct Node{
	int val;
	Node *left, *right;
	Node(int v = 0, Node *l = NULL, Node *r = NULL):
		val(v), left(l), right(r){
		}
};

void visit(Node * node){
	cout<<node->val<<endl;
}

void InorderTraversal(Node * root){
	stack<Node *> temp;
    if(root == NULL){
        return;
    }
    do{
        while(NULL != root){
            temp.push(root);
            root = root->left;
        }
        do{
            Node *top = temp.top();
            temp.pop();
            visit(top);
            if(top->right != NULL){
                root = top->right;
                //cout<<root->val<<endl;
                break;
            }
        }while(!temp.empty());

    }while(!temp.empty() || NULL != root);
	//while(temp.top()->left != NULL){
		//temp.push(temp.top()->left);
	//}
	//while(!temp.empty()){
        //Node * top = temp.top();
        //temp.pop();
		//visit(top);
		//if(top->right != NULL){
			//temp.push(top->right);
		//}

	//}
}

int main(int argc, char *argv[]){
	Node *root = new Node(3);
	root->left = new Node(2);
	root->right = new Node(5);
    root->right->left = new Node(4);
    root->right->right = new Node(6);
	InorderTraversal(root);
}
