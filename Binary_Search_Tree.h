/***********************************************
 * Author: Vincent Bardinelli
 * Date: November 9, 2023
 * Class: CSDP 250 Fall 2023
 * Project 4
 *
 * Program Description:
 * This program implements a Binary Search Tree (BST). It includes functionalities
 * to insert and delete nodes, and perform different types of tree traversals
 * (pre-order, in-order, and post-order).
 * The program allows for dynamic data input and showcases the fundamental operations
 * that can be performed on a BST.
 ***********************************************/


#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

struct Node {
    int data;
    Node* leftChild;
    Node* rightChild;
    Node(int value);
};

class Binary_Search_Tree {
public:
    Binary_Search_Tree();
    ~Binary_Search_Tree();
    void insert(int value);
    void deleteNode(int value);
    void displayPreOrder() const;
    void displayInOrder() const;
    void displayPostOrder() const;

private:
    Node* root;
    void deleteTree(Node* node);
    void insertNode(Node*& node, int value);
    Node* deleteNodeRecursively(Node* node, int value);
    Node* findMinValueNode(Node* node);
    void displayPreOrder(Node* node) const;
    void displayInOrder(Node* node) const;
    void displayPostOrder(Node* node) const;
};

#endif
