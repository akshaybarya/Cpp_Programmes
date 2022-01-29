//Print Nodes At A distance K 
#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int val;
        Node* left;
        Node* right;

        Node(int data){
            val = data;
            left = NULL;
            right = NULL;
        }
};

int printNodesAtk(Node* root, Node* target, int k){
    if(root == NULL){
        return -1;
    }

    if(root == target){
        printSubtree(root,k);
        return 0;
    }

    int dl = printNodesAtk(root->left, target, k);
    if(dl != -1){
        if(dl + 1 == k){
            cout<<root->val<<" ";
        }else{
            printSubtree(root->left, k-dl-2);
        }
    }

    int dr = printNodesAtk(root->right, target, k);

    if(dr != -1){
        if(dr + 1 == k){
            cout<<root->val<<" ";
        }else{
            printSubtree(root->right, k-dr-2);
        }
    }

    return -1;
}

void printSubtree(Node* root, int k){
    if(root == NULL or k < 0)return ;
    if(k == 0){
        cout << root->val << " ";
        return;
    }
    printSubtree(root->left, k-1);
    printSubtree(root->right, k-1);    
}

int main(){

    return 0;
}
