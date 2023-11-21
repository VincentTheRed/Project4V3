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

#include "Binary_Search_Tree.h"
#include <iostream>

using namespace std;

//Node constructor
Node::Node(int value) : data(value), leftChild(nullptr), rightChild(nullptr) {}

//BinarySearchTree constructor
Binary_Search_Tree::Binary_Search_Tree() : root(nullptr) {}

//BinarySearchTree destructor
Binary_Search_Tree::~Binary_Search_Tree() {
    deleteTree(root);
    root = nullptr;
}

//Insert a value into the tree
void Binary_Search_Tree::insert(int value) {
    insertNode(root, value);
}

//Delete a node from the tree
void Binary_Search_Tree::deleteNode(int value) {
    root = deleteNodeRecursively(root, value);
}

//Display tree in pre-order traversal
void Binary_Search_Tree::displayPreOrder() const {
    cout << "Pre-order traversal: ";
    displayPreOrder(root);
    cout << "\n";
}

//Display tree in in-order traversal
void Binary_Search_Tree::displayInOrder() const {
    cout << "In-order traversal: ";
    displayInOrder(root);
    cout << "\n";
}

//Display tree in post-order traversal
void Binary_Search_Tree::displayPostOrder() const {
    cout << "Post-order traversal: ";
    displayPostOrder(root);
    cout << "\n";
}

//Private method implementations..

void Binary_Search_Tree::deleteTree(Node* node) {
    if (node) {
        deleteTree(node->leftChild);
        deleteTree(node->rightChild);
        delete node;
    }
}

void Binary_Search_Tree::insertNode(Node*& node, int value) {
    if (!node) {
        node = new Node(value);
    } else if (value < node->data) {
        insertNode(node->leftChild, value);
    } else {
        insertNode(node->rightChild, value);
    }
}

Node* Binary_Search_Tree::deleteNodeRecursively(Node* node, int value) {
    if (node == nullptr) {
        return node;
    }
    if (value < node->data) {
        node->leftChild = deleteNodeRecursively(node->leftChild, value);
    } else if (value > node->data) {
        node->rightChild = deleteNodeRecursively(node->rightChild, value);
    } else {
        if (node->leftChild == nullptr) {
            Node* temp = node->rightChild;
            delete node;
            return temp;
        } else if (node->rightChild == nullptr) {
            Node* temp = node->leftChild;
            delete node;
            return temp;
        }
        Node* temp = findMinValueNode(node->rightChild);
        node->data = temp->data;
        node->rightChild = deleteNodeRecursively(node->rightChild, temp->data);
    }
    return node;
}

Node* Binary_Search_Tree::findMinValueNode(Node* node) {
    Node* current = node;
    while (current && current->leftChild != nullptr) {
        current = current->leftChild;
    }
    return current;
}

void Binary_Search_Tree::displayPreOrder(Node* node) const {
    if (node) {
        cout << node->data << " ";
        displayPreOrder(node->leftChild);
        displayPreOrder(node->rightChild);
    }
}

void Binary_Search_Tree::displayInOrder(Node* node) const {
    if (node) {
        displayInOrder(node->leftChild);
        cout << node->data << " ";
        displayInOrder(node->rightChild);
    }
}

void Binary_Search_Tree::displayPostOrder(Node* node) const {
    if (node) {
        displayPostOrder(node->leftChild);
        displayPostOrder(node->rightChild);
        cout << node->data << " ";
    }
}
