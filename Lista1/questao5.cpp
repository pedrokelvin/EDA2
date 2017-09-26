#include <bits/stdc++.h>
using namespace std;

typedef struct Arv{
    struct Arv *right, *left;
    int value;
}Tree;

Tree *getTree(int value){

    Tree *New = (Tree *) malloc(sizeof(Tree));
    New->value = value;
    New->left = NULL;
    New->right = NULL;

    return New;
}

Tree *insertTree(Tree *node, int value){

    if(!node)
        return getTree(value);
    else if(value > node->value)
        node->right = insertTree(node->right,value);
    else
        node->left = insertTree(node->left,value);
}

void Visit(Tree *node)
{
    cout << node->value << " ";
}

void *preOrder(Tree *node){

    if(node){
        Visit(node);
        preOrder(node->left);
        preOrder(node->right);
    }
}

void *inOrder(Tree *node){

    if(node){
        inOrder(node->left);
        Visit(node);
        inOrder(node->right);
    }
}

void *postOrder(Tree *node){

    if(node){
        postOrder(node->left);
        postOrder(node->right);
        Visit(node);
    }
}

int main(){

    Tree *root = (Tree *) malloc(sizeof(Tree)); //Cria raiz
    root = NULL;

    int T, x;
    cin >> T; //Numero de elementos a serem inseridos na arvore

    while(T--)
    {
        cin >> x;
        root = insertTree(root,x); //Insere elementos na arvore
    }
    cout << "Pre Ordem: ";
    preOrder(root);
    cout << endl << "Em ordem: ";
    inOrder(root);
    cout << endl << "Pos ordem: ";
    postOrder(root);
    cout << endl;

    return 0;
}
