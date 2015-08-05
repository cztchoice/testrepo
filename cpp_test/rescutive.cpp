#include <iostream>
#include <cstring>
#include <vector>
#include <string>

using namespace std;

struct Node{
    int value;
    Node * left;
    Node * right;
};

int findLevel(Node * root, int v){
    if(root == NULL){
        return -1;
    }
    int level = 0;
    if(root->value == v){
        return level;
    }
    level = findLevel(root->left, v);
    if(level == -1){
        level = findLevel(root->right, v);
    }
    if(level == -1){
        return -1;
    }
    else {
        return level + 1;
    }
}

Node* findLCA(Node *root, int left, int right){
    if(root == NULL){
        return NULL:
    }
    if(root->vaule == left || root->value == right){
        return root;
    }

    Node * l = findLCA(root->left, left, right);
    Node * r = findLCA(root->right, left, right);

    if(l != NULL && r != NULL){
        return root;
    }
    else{
        return l == NULL ? r : l;
    }
}

int main(int argc, char *argv[]){
    
}