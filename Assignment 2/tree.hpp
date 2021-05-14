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

using namespace std;

template <typename T> // the template allows the weight of vertex to take any numeric data type (denoted by T).
class BST {

	public:
        /* define your data structure to represent a binary search tree (bst) */
        
        struct Node 
        {
            string name;
            Node *parent = NULL;
            Node *left = NULL; 
            Node *right = NULL;
            T weight;
        }; 
        
        Node* root = NULL;

        /* test1 */
		BST(); // the contructor function.
		~BST(); // the destructor function.
        size_t count_vertices(Node* root); // counts number of vertices
		size_t num_vertices(); // returns the total number of vertices in the bst.
		size_t num_edges(); // returns the total number of edges in the bst.
        T add_nodes(Node *&root);
        T sum_weight(); // return the total weight of all the vertices in the bst.

        /* test2 */
        void add_vertex(const string&, const T&); // adds a vertex, which has a weight, to the tree -- every vertex uses a string as its unique identifier.
        bool search_node(Node* root, const string&);
        bool contains(const string&); // checks if a vertex is in the bst -- returns true if the bst contains the given vertex; otherwise, returns false.
        
        /* test3 */
        vector<string> get_vertices(); // returns a vector of all the vertices in the bst.
        vector<string> get_leaves(); // returns a vector of all the leaves in the bst.
                                     //     Leaves are the vertices that do not have any children in the bst.

        /* test4 */
        bool adj_check(Node* root, const string& u, const string& v);
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
        bool get_path(Node* root, vector<string>&, const string& );
        vector<string> path(const string&, const string&); // returns a vector of all the vertices in the path from the first vertex to the second vertex.
                                                            //     A path should include the source and destination vertices at the begining and the end, respectively.

        /* test12 */
        int max(int x, int y);
        Node* Bfind_leaf(Node* root);
        int get_weight(Node* root, const string& u);
        int max_path_sum(Node* root, T& w);
        vector<string> path_with_largest_weight(); // returns a path that has the largest weight in the bst.
                                       //    The weight of a path is the sum of the weights of all the vertices (including the source and destination vertices) in the path.

        /* test13 */
        size_t max_depth(Node* root);
        size_t height(); // returns the height of bst. Height of a tree is the number of edges that form the longest path from root to any leaf.

        /* test14 */
        struct Node* find_node(Node*, const string&);
        struct Node* min_value_node(Node*);
        struct Node* delete_node(Node*, Node*);
        void remove_vertex(const string&); // delete the given vertex from bst -- note that, all incident edges of the vertex should be deleted as well.
};

/* test1 */

template <typename T>
BST<T>::BST() {}

template <typename T>
BST<T>::~BST() {}

template <typename T>
size_t BST<T>::count_vertices(Node* root){
    if(root == NULL){ return 0; }
    int count = 1; // counts root as 1
    if(root->left != NULL){ // counts all of nodes on the left-> side of any node
        count += count_vertices(root->left);
    }
    if(root->right != NULL){ // counts all of nodes on the right-> side of any node
        count += count_vertices(root->right);
    }
    return count;
}

template <typename T>
size_t BST<T>::num_vertices() {
    int total = count_vertices(root);
    return total;
}

template <typename T>
size_t BST<T>::num_edges() {
    if(num_vertices() == 0){
        return 0;
    }
    return num_vertices() - 1;
}

template <typename T>
T BST<T>::add_nodes(Node *&root){
    if(root == NULL){
        return 0;
    }               // adds total weight of left side and right side.
    return root->weight + add_nodes(root->left) + add_nodes(root->right);
}

template <typename T>
T BST<T>::sum_weight() {
    T total = add_nodes(root);
    return total;
}

/* test2 */

template <typename T>
void BST<T>::add_vertex(const string& u, const T& w) {
    Node* new_node = new Node; // declaring a new_node object that stores u and w
    new_node->weight = w;
    new_node->name = u;

    if (root == NULL) { // if there are no nodes in root add new_node
        root = new_node; 
    }
    else {
        Node* current = root; // 
        while (true) {
            if (w < current->weight) { // if weight is less than the current nodes weight 
                if (current->left == NULL){ // AND the left of current node is NULL
                    new_node->parent = current; // our new_node with u and w values stored has current as a parent
                    current->left = new_node; // left of current is now our new_node with u and w value.
                    break;
                }
                else{ current = current->left; } 
            }
            else
            {
                if (current->right == NULL){ // if the right of current node is NULL
                    new_node->parent = current; //our new_node with u and w values stored has current as a parent
                    current->right = new_node; // right of current is now our new_node with u and w value.
                    break;
                }
                else{ current = current->right; }
            }
        }
    } 
}

template <typename T>
bool BST<T>::search_node(Node* root, const string& u){
    
    if(root == NULL){ return false; }
    if(root->name == u){ return true; } // if string value at root equals u
    if(root->left){ //searching left side, if found return true;
        if(search_node(root->left, u) == 1) { return true; } 
    }
    if(root->right){ //searching right side, if found return true;   
        if(search_node(root->right, u) == 1) { return true; }
    } 
    return false;
}

template <typename T>
bool BST<T>::contains(const string& u) {
    return search_node(root, u); 
}

/* test3 */

template <typename T>
vector<string> BST<T>::get_vertices() {
    
    vector<string> vertices; // empty vector containing our vertices
    queue<Node*> visited; // our traversal container

    if (!root) {
        return vertices;
    }
    visited.push(root);
    while(!visited.empty()){
        Node* current = visited.front(); // current changes to what is at the front of queue everytime it loops
        visited.pop(); // remove node that current took the value of
        vertices.push_back(current->name); // add the string to vertices
        if(current->left != NULL) { visited.push(current->left); } // add to visited so we can traverse through later
        if(current->right != NULL) { visited.push(current->right); } // add to visited so we can traverse through later
    }
    return vertices;
}

template <typename T>
vector<string> BST<T>::get_leaves() {
    
    vector<string> leaves; // empty vector containing our leaves
    queue<Node*> visited; // our traversal container
    
    if (!root) { return leaves; }
    visited.push(root);
    while(!visited.empty()){
        Node* current = visited.front(); // current changes to what is at the front of queue everytime it loops
        visited.pop(); // remove node that current took the value of
        if(current->left != NULL) { visited.push(current->left); } // add to visited so we can traverse through later
        if(current->right != NULL) { visited.push(current->right); } // add to visited so we can traverse through later
        if(current->left == NULL && current->right == NULL) // add leaves only if left and right are NULL
        { leaves.push_back(current->name); }
    }
    return leaves;
}

/* test4 */

template <typename T>
bool BST<T>::adj_check(Node* root, const string& u, const string& v){
    if(root == NULL){ return false; }
    if(root->left != NULL){ // ensure we aren't pointing at NULL, return true if u and v match, vice versa
        if((root->name == u && root->left->name == v) || root->name == v && root->left->name == u) { return true; } 
    }
    if(root->right != NULL){ // ensure we aren't pointing at NULL, return true if u and v match, vice versa
        if((root->name == u && root->right->name == v) || root->name == v && root->right->name == u) { return true; }
    }
    if(root->left){ // use recursion to check the left side of Node
        if(adj_check(root->left, u, v) == 1) { return true; }
    }
    if(root->right){ // use recursion to check the right side of Node
        if(adj_check(root->right, u, v) == 1) { return true; }
    }
    return false;
}

template <typename T>
bool BST<T>::adjacent(const string& u, const string& v) {
    return adj_check(root, u, v);
}

/* test5 */

template <typename T>
vector<pair<string,string>> BST<T>::get_edges() {
    vector<pair<string,string>> edges; // empty vector pair
    queue<Node*> visited;  // our traversal container

    visited.push(root);
    while(!visited.empty()){
        Node* current = visited.front(); // current starts at root
        visited.pop(); // remove node that current took the value of
        if(current->left != NULL){ // ensure we don't point outside of our BST
            if(adjacent(current->name, current->left->name) == true){ // if adjacent for node and left of node
                edges.push_back(make_pair(current->name, current->left->name)); // add to edges
                visited.push(current->left); // add to visited so we can traverse through later
            }
        }
        if(current->right != NULL){ // ensure we don't point outside of our BST
            if(adjacent(current->name, current->right->name) == true){ // if adjacent for node and right of node
                edges.push_back(make_pair(current->name, current->right->name)); // add to edges
                visited.push(current->right); // add to visited so we can traverse through later
            }
        }
    }
    return edges;
}

/* test6 */

template <typename T>
vector<string> BST<T>::get_neighbours(const string& u) {

    vector<string> neighbours; // empty vector containing strings
    queue<Node*> visited; // our traversal container
    
    visited.push(root);
    while(!visited.empty()){
        Node* current = visited.front(); // current changes to what is at the front of queue everytime it loops
        visited.pop(); // remove node that current took the value of
        if(current->name == u){ // only if current matches u
            if(current->parent != NULL) { neighbours.push_back(current->parent->name); } // check if has parent, add parent if it has one
            if(current->left != NULL) { neighbours.push_back(current->left->name);} // check if left not null, add name at left if it has one
            if(current->right != NULL) { neighbours.push_back(current->right->name);} // check if right not null, add name at right if it has one
        }
        else{ // if current is not equal to u continue to traverse through BST
        if(current->left != NULL) { visited.push(current->left); } 
        if(current->right != NULL) { visited.push(current->right); } 
        }
    } 
    return neighbours;
}

template <typename T>
size_t BST<T>::degree(const string& u) {
    return get_neighbours(u).size();
}

/* test7 */

template <typename T>
vector<string> BST<T>::preorder_traversal() {
    
    vector<string> vertices; // empty vector for strings
    stack<Node*> visited; // stack for our traversal list

    if (root == NULL) { return vertices; } // base condition
    visited.push(root); // remove node that current took the value of
    while(!visited.empty()){
        Node* current = visited.top(); // current becomes last thing on top of the stack every loop
        visited.pop(); // remove the value current 
        vertices.push_back(current->name); // add right away to the vertices
        if(current->right != NULL) { visited.push(current->right); } // add to visited so we can traverse through later
        if(current->left != NULL) { visited.push(current->left); } 
    }
    return vertices;
}

/* test8 */

template <typename T>
vector<string> BST<T>::inorder_traversal() {

    vector<string> vertices; // empty list of strings
    stack<Node*> visited; // stack for our traversal list
    Node* current = root;
    
    while (current != NULL || !visited.empty()) {
        while (current != NULL) { // to get to the very far left of our BST
            visited.push(current); // add to visited so we can traverse through to the very left of BST
            current = current->left;
        }
        current = visited.top(); 
        visited.pop();
        vertices.push_back(current->name);
        current = current->right;
    }
    return vertices;
}

/* test9 */

template <typename T>
vector<string> BST<T>::postorder_traversal() {

    vector<string> vertices; // empty vector for strings
    stack<Node*> v1; // requires two stacks for traversal
    stack<Node*> v2; //

    if(root == NULL) { return vertices; } // base condition incase root is null
    v1.push(root);
    Node* current;
    while(!v1.empty()){
        current = v1.top();
        v1.pop();
        v2.push(current);
        if(current->left != NULL) { v1.push(current->left); }
        if(current->right != NULL) { v1.push(current->right); }
    }
    while(!v2.empty()){
        current = v2.top();
        v2.pop();
        vertices.push_back(current->name);
    }
    return vertices;
}

/* test10 */

template <typename T>
vector<string> BST<T>::breadth_first_traversal() {

    vector<string> vertices;
    queue<Node*> visited;

    if(root == NULL) { return vertices; }
    visited.push(root);
    while(!visited.empty()){
        Node* current = visited.front();
        visited.pop();
        vertices.push_back(current->name);
        if(current->left != NULL) { visited.push(current->left); } // add to visited so we can traverse through later
        if(current->right != NULL) { visited.push(current->right); } 
    }
    return vertices;
}

/* test11 */

template <typename T>
bool BST<T>::get_path(Node* root, vector<string>& visited, const string& u){
    if(root == NULL) { return false; }
    visited.push_back(root->name); // add to queue
    if(root->name == u) { return true; } // if current node equals the string we're after
    if(get_path(root->left, visited, u) || get_path(root->right, visited, u)) { return true; } // check left, repeat steps ontop for left until found or return false to check right side string matches
    visited.pop_back();
    return false;
}

template <typename T>
vector<string> BST<T>::path(const string& u, const string& v){
    
    vector<string> path_one; // making two empty queues for a path for u and v
    vector<string> path_two;
    vector<string> real_path;
    get_path(root, path_one, u); // get the path of u
    get_path(root, path_two, v); // get the path of v
    int mid_point = -1;
    int i = 0, k = 0;
    while(i != path_one.size() || k != path_two.size())
    {
        if (i == k && path_one[i] == path_two[k]){ i++; k++; }
        else{ mid_point = k - 1; break; }
    }
    for(int i = path_one.size() -1; i > mid_point; i--)
        real_path.push_back(path_one[i]);
    for(int i = mid_point; i < path_two.size(); i++)
        real_path.push_back(path_two[i]);
    return real_path;
}

/* test12 */

template <typename T>
int BST<T>::max(int x, int y){
    return (x >= y) ? x : y; 
}

/*
template <typename T>
int BST<T>::get_weight(Node* root, const string& u){
    if(root == NULL) { return 0; } // base condition stops if null
    if(root->name == u) { return root->weight; } // return weight of the given string
    if(root->left) { 
        if(root->left != NULL){ return get_weight(root->left, u); } // do again but left side
    }
    if(root->right) { 
        if(root->right != NULL){ return get_weight(root->right, u); }
        return get_weight(root->right, u); } // do again but right side
} */

/*
template<typename T>
typename BST<T>::Node* BST<T>::find_leaf(Node* root){
    if(root == NULL) { return NULL; } 
    if(root->name == u){ return root; } // return root if u is found
    if(root->left && search_node(root->left, u)) { return find_node(root->left, u); } // search for the node with the string u
    if(root->right && search_node(root->right, u)) { return find_node(root->right, u); }
    return root;
} */

template <typename T>
int BST<T>::max_path_sum(Node* root, T& total){
    
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) { return root->weight; }
    int left_sum = max_path_sum(root->left, total);
    int right_sum = max_path_sum(root->right, total);
    if(root->left && root->right){
        total = max(total, left_sum + right_sum + root->weight);
        return max(left_sum, right_sum) + root->weight;
    }
    return (root->left != NULL) ? right_sum + root->weight : left_sum + root->weight;
} 

template <typename T>
vector<string> BST<T>::path_with_largest_weight(){
    
    int largest_weight = 0; // value of largest weight
    vector<string> heaviest_path; // where node string values will be stored of the heaviest path
    max_path_sum(root, largest_weight); // not answer just testing stuff returns largest possible path sum
    return heaviest_path;
}

/* test13 */

template <typename T>
size_t BST<T>::max_depth(Node* root){
    if(root == NULL) { return 0; }
    else{
        int left_depth = max_depth(root->left);
        int right_depth = max_depth(root->right);
        if(left_depth > right_depth) { return (left_depth + 1); }
        else { return (right_depth + 1); }
    }
}

template <typename T>
size_t BST<T>::height() {
    int depth = max_depth(root);
    return depth - 1;
}

/* test14 */

template<typename T>
typename BST<T>::Node* BST<T>::find_node(Node* root, const string& u){
    if(root == NULL) { return NULL; } 
    if(root->name == u){ return root; } // return root if u is found
    if(root->left && search_node(root->left, u)) { return find_node(root->left, u); } // search for the node with the string u
    if(root->right && search_node(root->right, u)) { return find_node(root->right, u); }
    return root;
}

template<typename T>
typename BST<T>::Node* BST<T>::min_value_node(Node* root){
     if(root->left == NULL) { return root; }
        return min_value_node(root->left);
}

template <typename T>
typename BST<T>::Node* BST<T>::delete_node(Node* root, Node* node_u){    
    if(root == NULL) { return root; }
        if(node_u->weight < root->weight && node_u->name != root->name){ 
                root->left = delete_node(root->left, node_u);
        }
        else if(node_u-> weight > root->weight && node_u->name != root->name){
                root->right = delete_node(root->right, node_u);
    }
    else{ 
        if(root->left == NULL && root->right == NULL){ return NULL; } // no child nodes from deleted node
        if(root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        if(root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = min_value_node(root->right);
        node_u->weight = temp->weight;
        node_u->name = temp->name;
        root->right = delete_node(root->right, temp);
    }
    return root;
}

template <typename T>
void BST<T>::remove_vertex(const string& u) {
    struct Node* node_u = find_node(root, u);
    if(node_u) root = delete_node(root, node_u);
};