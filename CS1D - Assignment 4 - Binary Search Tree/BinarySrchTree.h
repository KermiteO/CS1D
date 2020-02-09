/*
 * BinarySrchTree.h
 *
 *  Created on: Feb 13, 2017
 *      Author: Kermite
 */

#ifndef BINARYSRCHTREE_H_
#define BINARYSRCHTREE_H_

#include <iostream>
#include <cstdlib>
#include <queue>
#include<stdio.h>
#include<math.h>
using namespace std;

class BinarySearchTree
{
    private:
        struct tree_node
        {
           tree_node* left;
           tree_node* right;
           int data;
        };
        tree_node* root;

    public:
        BinarySearchTree()
        {
           root = NULL;
        }

        bool isEmpty() const { return root==NULL; }
        void print_inorder();
        void inorder(tree_node* p);
        void print_preorder();
        void preorder(tree_node* p);
        void print_postorder();
        void postorder(tree_node* p);
        void breadthFirstOrder();
        void insert(int insertInt);
        void remove(int delInt);
        void PrintTree();
};




#endif /* BINARYSRCHTREE_H_ */
