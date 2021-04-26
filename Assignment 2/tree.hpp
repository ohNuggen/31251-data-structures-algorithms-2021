#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <limits>
#include <utility> 
#include <algorithm>
#include <string>
#include <cstdlib>
#include <cmath>
#include <map>

using namespace std;

template <typename T> // the template allows the weight of vertex to take any numeric data type (denoted by T).
class BST {
    
    private:
        map<string, T> adj_list;
        int edges = 0;
	public:
        /* define your data structure to represent a binary search tree (bst) */



        /* test1 */
		BST(); // the contructor function.
		~BST(); // the destructor function.
		size_t num_vertices(); // returns the total number of vertices in the bst.
		size_t num_edges(); // returns the total number of edges in the bst.
        T sum_weight(); // return the total weight of all the vertices in the bst.

        /* test2 */
        void add_vertex(const string&, const T&); // adds a vertex, which has a weight, to the tree -- every vertex uses a string as its unique identifier.
        bool contains(const string&); // checks if a vertex is in the bst -- returns true if the bst contains the given vertex; otherwise, returns false.
        
        /* test3 */
        vector<string> get_vertices(); // returns a vector of all the vertices in the bst.
        vector<string> get_leaves(); // returns a vector of all the leaves in the bst.
                                     //     Leaves are the vertices that do not have any children in the bst.

        /* test4 */
        bool adjacent(const string&, const string&); // check if there is an edge between the two vertices in the bst -- returns true if the edge exists; otherwise, returns false.
		
        /* test5 */
        vector<pair<string,string>> get_edges(); // returns a vector of all the edges in the bst -- each edge is represented by a pair of vertices incident to the edge.
        
        /* test6 */
        vector<string> get_neighbours(const string&); // returns a vector of all the vertices, each of which is directly connected with the given vertex via an edge.
        size_t degree(const string&); // returns the degree of a vertex.

        /* test7 */
		vector<string> preorder_traversal(); // returns a vector of all the vertices in the visiting order of a preorder traversal over the bst.
		
        /* test8 */
        vector<string> inorder_traversal(); // returns a vector of all the vertices in the visiting order of an inorder traversal over the bst.
        
        /* test9 */
        vector<string> postorder_traversal(); // returns a vector of all the vertices in the visiting order of a postorder traversal over the bst.
        
        /* test10 */
        vector<string> breadth_first_traversal(); // returns a vector of all the vertices in the visiting order of a breadth first traversal over the bst.
		
        /* test11 */
        vector<string> path(const string&, const string&); // returns a vector of all the vertices in the path from the first vertex to the second vertex.
                                                            //     A path should include the source and destination vertices at the begining and the end, respectively.

        /* test12 */
        vector<string> path_with_largest_weight(); // returns a path that has the largest weight in the bst.
                                       //    The weight of a path is the sum of the weights of all the vertices (including the source and destination vertices) in the path.

        /* test13 */
        size_t height(); // returns the height of bst. Height of a tree is the number of edges that form the longest path from root to any leaf.

        /* test14 */
        void remove_vertex(const string&); // delete the given vertex from bst -- note that, all incident edges of the vertex should be deleted as well.
};

/* test1 */

template <typename T>
BST<T>::BST() {}

template <typename T>
BST<T>::~BST() {}


template <typename T>
size_t BST<T>::num_vertices() {
    return 0;
}

template <typename T>
size_t BST<T>::num_edges() {
    return 0;
}

template <typename T>
T BST<T>::sum_weight() {
    return 0;
}

/* test2 */

template <typename T>
void BST<T>::add_vertex(const string& u, const T& w) {

}

template <typename T>
bool BST<T>::contains(const string& u) {
    return false;
}

/* test3 */

template <typename T>
vector<string> BST<T>::get_vertices() {
    return vector<string>();
}

template <typename T>
vector<string> BST<T>::get_leaves() {
    return vector<string>();
}

/* test4 */

template <typename T>
bool BST<T>::adjacent(const string& u, const string& v) {
    return false;
}

/* test5 */

template <typename T>
vector<pair<string,string>> BST<T>::get_edges() {
    return vector<pair<string, string>>();
}

/* test6 */

template <typename T>
vector<string> BST<T>::get_neighbours(const string& u) {
    return vector<string>();
}

template <typename T>
size_t BST<T>::degree(const string& u) {
    return 0;
}

/* test7 */

template <typename T>
vector<string> BST<T>::preorder_traversal() {
    return vector<string>();
}

/* test8 */

template <typename T>
vector<string> BST<T>::inorder_traversal() {
    return vector<string>();
}

/* test9 */

template <typename T>
vector<string> BST<T>::postorder_traversal() {
    return vector<string>();
}

/* test10 */

template <typename T>
vector<string> BST<T>::breadth_first_traversal() {
    return vector<string>();
}

/* test11 */

template <typename T>
vector<string> BST<T>::path(const string& u, const string& v){
    return vector<string>();
}

/* test12 */

template <typename T>
vector<string> BST<T>::path_with_largest_weight(){
    return vector<string>();
}

/* test13 */

template <typename T>
size_t BST<T>::height() {
    return 0;
}

/* test14 */

template <typename T>
void BST<T>::remove_vertex(const string& u) {

}
