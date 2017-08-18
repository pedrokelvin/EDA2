#include<bits/stdc++.h>

using namespace std;

typedef struct Arv{
    struct Arv *right;
    struct Arv *left;
    int value;

}Tree;

Tree *getTree(int value){

    Tree *New = (Tree *) malloc(sizeof(Tree));
    New->value = value;
    New->left = NULL;
    New->right = NULL;

    return New;
}

Tree *insertTree(Tree *root, int value){

    if(!root)
    {
        root = getTree(value);
        return root;
    }
    else if(value > root->value)
        root->right = insertTree(root->right,value);
    else if(value < root->value)
        root->left = insertTree(root->left,value);

} // It's a binary tree, it's assumed the user will not enter with an existing value more than once

void *order(Tree *root){

    if(root){
        order(root->left);
        cout << root->value << " ";
        order(root->right);
    }
}

int main(){

    Tree *coconut = (Tree *) malloc(sizeof(Tree));
    coconut = NULL;

    coconut = insertTree(coconut,10);
    coconut = insertTree(coconut,4);
    coconut = insertTree(coconut,5);
    coconut = insertTree(coconut,16);
    coconut = insertTree(coconut,11);
    coconut = insertTree(coconut,1);
    order(coconut);
    cout << endl;

    return 0;
}
