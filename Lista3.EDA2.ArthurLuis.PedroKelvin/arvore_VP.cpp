#include <bits/stdc++.h>
//source: https://github.com/zyi23/Red-Black-Tree/blob/master/rbtree.cpp

using namespace std;
#define __TEST__

int rotacoes = 0;


template <class T>
class rbtree;

template <class T>
struct _rbTreeNode{
    friend class rbtree<T>;
    T getkey(){
        return key;
    }
private:
    T key;
    _rbTreeNode<T> *left;
    _rbTreeNode<T> *right;
    _rbTreeNode<T> *p;
    bool color; // true == vermelho  &&  false == preto
};

template <class T>
class rbtree{

public:
    rbtree()
        :nil( new _rbTreeNode<T> ), root( nil ) { nil->left = 0; nil->p = 0; nil->right = 0; nil->color = false; }
    void insert( T key );
     _rbTreeNode<T> * search( T key );
    void erase( T key );

#ifdef __TEST__
    void display();
#endif

private:

#ifdef __TEST__
    void _display( _rbTreeNode<T> * );
#endif


    void leftRotate(  _rbTreeNode<T> * );
    void rightRotate(  _rbTreeNode<T> * );
    
    void rbDelete(  _rbTreeNode<T> * );
    void rbDeleteFixup(  _rbTreeNode<T> * );
    
    void rbInsertFixup( _rbTreeNode<T> * );
    
    _rbTreeNode<T>* treeSuccessor(  _rbTreeNode<T> * );
    
    _rbTreeNode<T> *nil;            //空结点
    _rbTreeNode<T> *root;

};

template <class T>
void rbtree<T>::insert( T key ){
    _rbTreeNode<T>* t = new _rbTreeNode<T>;
    t->key = key;
    _rbTreeNode<T>* x = root;
    _rbTreeNode<T>* y = nil;
    while( x != nil ){
        y = x;
        if( key < x->key )
            x = x->left;
        else
            x = x->right;
    }
    t->p = y;
    if( y == nil )
        root = t;
    else{
        if ( t->key < y->key )
            y->left = t;
        else
            y->right = t;
    }
    t->left = nil;
    t->right = nil;
    t->color = true;
    rbInsertFixup( t );
}

template <class T>
_rbTreeNode<T> * rbtree<T>::search( T key ){
    _rbTreeNode<T> * x = root;
    while( x != nil && key != x->key ){
        if( key < x->key )
            x = x->left;
        else
            x = x->right;
    }
    return x;
}

template <class T>
void rbtree<T>::erase( T key ){
    _rbTreeNode<T> * x = search( key );
    if( x != nil )
        rbDelete( x );
}

template <class T>
_rbTreeNode<T> * rbtree<T>::treeSuccessor( _rbTreeNode<T> *x ){
    if( x->right != nil ){
        while( x->left != nil )
            x = x->left;
        return x;
    }
    _rbTreeNode<T> * y = x->p;
    while( y != nil && x == y->right ){
        x = y;
        y = y->p;
    }
    return y;
}

template <class T>
void rbtree<T>::leftRotate( _rbTreeNode<T> *x ){ 
    rotacoes++;
    _rbTreeNode<T> * y = x->right;
    if( x->p == nil )
        root = y;
    else{
        if( x == x->p->left )
            x->p->left = y;
        else
            x->p->right = y;
    }
    y->p = x->p;
    x->right = y->left;
    y->left->p = x;
    y->left = x;
    x->p = y;
}

template <class T>
void rbtree<T>::rightRotate( _rbTreeNode<T> *x ){
    rotacoes++;
    _rbTreeNode<T> * y = x->left;
    if( x->p == nil )
        root = y;
    else{
        if( x->p->left == x )
            x->p->left = y;
        else
            x->p->right = y;
    }
    y->p = x->p;
    x->left = y->right;
    y->right->p = x;
    y->right = x;
    x->p = y;
}


template <class T>
void rbtree<T>::rbInsertFixup( _rbTreeNode<T> *z ){
    while( z->p->color  == true ){
        if( z->p == z->p->p->left ){
            _rbTreeNode<T> * y = z->p->p->right;
            if( y->color == true ){
                z->p->color = false;
                y->color = false;
                z->p->p->color = true;
                z = z->p->p;
            }
            else{
                if( z == z->p->right ){
                    z = z->p;
                    leftRotate( z );
                }//
                z->p->color = false;
                z->p->p->color = true;
                z->p->right->color = false;
                rightRotate( z->p->p );
            }
        }
        else{
            _rbTreeNode<T> * y = z->p->p->left;
            if( y->color == true ){
                z->p->color = false;
                y->color = false;
                z->p->p->color = true;
                z = z->p->p;
            }
            else{
                if( z == z->p->left ){
                    z = z->p;
                    rightRotate( z );
                }
                z->p->color = false;
                z->p->p->color = true;
                z->p->left->color = false;
                leftRotate( z->p->p );
            }
        }
    }
    root->color = false;
}


template <class T>
void rbtree<T>::rbDelete( _rbTreeNode<T> *z ){
    _rbTreeNode<T> * x = nil;
    _rbTreeNode<T> * y = nil;
    if( z->left == nil || z->right == nil )
        y = z;
    else
        y = treeSuccessor( z );
    if( y->left != nil )
        x = y->left;
    else
        x = y->right;
    x->p = y->p;
    if( y->p == nil )
        root = x;
    else{
        if( y == y->p->left )
            y->p->left = x;
        else
            y->p->right = x;
    }
    if( y != z )
        z->key = y->key;
    if( y->color == false )
        rbDeleteFixup( x );
    delete y;
}

template <class T>
void rbtree<T>::rbDeleteFixup(_rbTreeNode<T> * x){
    while( x != root && x->color == false ){
        _rbTreeNode<T> * w = 0;
        if( x->p->left == x ){
            w = x->p->right;
            if( w->color == true ){
                w->color = false;
                x->p->color = true;
                leftRotate( x->p );
                w = x->p->right;
            }
            if( w->left->color == false && w->right->color == false ){
                w->color = true;
                x = x->p;
            }
            else{
                if( w->right->color == false ){
                    w->left->color = false;
                    w->color = true;
                    rightRotate( w );
                    w = x->p->right;
                }
                w->color = x->p->color;
                x->p->color = false;
                w->right->color = false;
                leftRotate( x->p );
                x = root;
            }
        }
        else{
            w = x->p->left;
            if( w->color == true ){
                w->color = false;
                x->p->color = true;
                rightRotate( x->p );
                w = x->p->left;
            }
            if( w->right->color == false && w->left->color == false ){
                w->color = true;
                x = x->p;
            }
            else{
                if( w->left->color == false ){
                    w->right->color = false;
                    w->color = true;
                    leftRotate( w );
                    w = x->p->left;
                }
                w->color = x->p->color;
                x->p->color = false;
                w->left->color = false;
                rightRotate( x->p );
                x = root;
            }
        }
    }
    x->color = false;
}

int main(){
    rbtree<int> test;
    srand( time(NULL) );
    auto begin = chrono::high_resolution_clock::now();

    for( int i = 0; i < 1000; ++i ){
        test.insert( rand() % 10000 );
    }

    auto end = chrono::high_resolution_clock::now();
    cout << "Tempo de execucao (Vermelha Preta): " << (long double)chrono::duration_cast<chrono::nanoseconds>(end-begin).count()/1000000000 << "s" << endl;

    cout << "Rotacoes Vermelha Preta: " << rotacoes << endl << endl;

    return 0;
}