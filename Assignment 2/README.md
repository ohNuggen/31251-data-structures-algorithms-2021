Assignment 2 - Binary Search Tree (35%)
Overview
Your task is to implement a BST class, where every vertex is denoted by a string, and every vertex has a weight. The class should allow the weight to be any numeric data type, such as int, float, or double.

For example, the following BST has 8 vertices. These vertices have weights of 1, 3, 5, 10, 20, 15, 30, 17.


The class should offer a reasonably effective suite of operations, including but not limited to:

Adding and removing nodes (and relevant edge adding and removal).

Depth-first and breadth-first traversals (Preorder, Inorder, Postorder, BFS).

Finding paths that meet certain conditions.

The Code
You are provided with two files:

tree.hpp: this includes most of the basic definitions you will need. You should define data structures to represent a Binary Search Tree and implement the functions so that they can work correctly. You may add new includes, classes, functions, and/or variables to the class per your need, as long as they do not interfere with the existing definitions. You must NOT change the class name, template, parameters, or return types of functions.

main.cpp: this includes a main function. You may write some code to test your data structures and function implementations for the class. This file will not be marked so you can do anything you like with it -- just ensure it does not cause any error. When the "run" button is pressed, it will compile and run main.cpp.

The code has been commented on to explain the purpose of each function. Remember to read over all the code before starting.

When the "mark" button is pressed, your code in tree.hpp will be run against the tests in Ed. The testing code can only mark your code when your code does not cause a program crash. If you get any error during compiling or your program cannot stop by itself, make sure you fix that problem first!

The basic data structures and the possibilities for implementing BSTs have been covered in Week 6 Lecture and Week 7 Tutorial. Some parts of the task may require you to develop some thinking because the lectures may not readily give you the solution. Don't hesitate to ask questions if you are unclear about the task requirements. 
