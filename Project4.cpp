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
#include <ctime>

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    Binary_Search_Tree bst;
    int numberOfElements;
    int* elements;

    do {
        cout << "Enter the total numbers (35-99): ";
        cin >> numberOfElements;
        if (cin.fail() || numberOfElements < 35 || numberOfElements >= 100) {
            cout << "Invalid input. Please enter a number between 35 and 99.\n";
            cin.clear(); //Clear the error flag
            char ch;
            while (cin.get(ch) && ch != '\n'); //Discard invalid input
        }
    } while (numberOfElements < 35 || numberOfElements >= 100);

    elements = new int[numberOfElements];
    for (int i = 0; i < numberOfElements; ++i) {
        int number = rand() % 100;
        elements[i] = number;
        bst.insert(number);
    }

    cout << "Original numbers: ";
    for (int i = 0; i < numberOfElements; i++) {
        cout << elements[i] << " ";
    }
    cout << "\n";

    bst.displayPreOrder();
    bst.displayInOrder();
    bst.displayPostOrder();

    delete[] elements; //Deallocate dynamic array
    return 0;
}

