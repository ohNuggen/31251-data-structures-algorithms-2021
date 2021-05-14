#include "tree.hpp"

int main(){

	BST<int> t;

    t.add_vertex("C", 5);
    t.add_vertex("A", 1);
    t.add_vertex("D", 3);
    t.add_vertex("H", 10);
    t.add_vertex("G", 20);
    t.add_vertex("F", 15);
    t.add_vertex("B", 30);
    t.add_vertex("E", 17); 

    /*
    t.add_vertex("v1", 15);
    t.add_vertex("v4", 5);
    t.add_vertex("v0", 10);
    t.add_vertex("v3", 30);
    t.add_vertex("v2", 17);
    t.add_vertex("v5", 1);
    t.add_vertex("v7", 3);
    t.add_vertex("v6", 20); */

    //t.remove_vertex("F"); not deleting properly?
    
    
	cout << "Number of Vertices: " << t.num_vertices() << endl;
	cout << "Number of Edges: " << t.num_edges() << endl;
	cout << "Sum of the weights: " << t.sum_weight() << endl;

    cout << "G and F adjacent: " << t.adjacent("G", "F") << endl; 
    //real answer = 1

    cout << "F and G adjacent: " << t.adjacent("F", "G") << endl; 
    //real answer = 1

    cout << "F and B adjacent: " << t.adjacent("F", "B") << endl; 
    //real answer = 0

    cout << "Preorder Traversal Order: ";
    for(auto x : t.preorder_traversal()){
        cout << x << " ";    
    }
    cout << endl;

    cout << "Inorder Traversal Order: ";
    for(auto x : t.inorder_traversal()){
        cout << x << " ";    
    }
    cout << endl;

    cout << "Postorder Traversal Order: ";
    for(auto x : t.postorder_traversal()){
        cout << x << " ";    
    }
    cout << endl;

    cout << "Breath First Traversal: ";
    for(auto x : t.breadth_first_traversal()){
        cout << x << " ";    
    }
    cout << endl;

    cout << "Nodes :";
    for ( auto const& x : t.get_vertices() ) {
        cout << x << " ";
    }
    cout << endl;

    cout << "Nodes sum:";
    cout <<t.get_vertices().size()<< endl;

    cout << "leaves :";
    for ( auto const& x : t.get_leaves() ) {
        cout << x << " ";
    }
    cout << endl;
    
    /*
    cout << "Path for C to H: ";
    for(auto x : t.path("C", "H")){
        cout << x << " ";
    }
    cout << endl;
    
    cout << "Path for D to F: ";
    for(auto x : t.path("D", "F")){
        cout << x << " ";
    }
    cout << endl;

    cout << "Path for C to B: ";
    for(auto x : t.path("C", "B")){
        cout << x << " ";
    }
    cout << endl;*/

    /*
    num_vertices() == 8

    num_edges() == 7

    get_vertices == {"A", "B", "C", "D", "E", "F", "G", "H"}

    get_leaves== {"B", "D", "E"}

    adjacent("G", "B") == true        adjacent("F", "B") == false

    get_edges() == {("C", "A"), ("C", "H"), ("A", "D"), ("H", "G"), ("G", "F"), ("G", "B"), ("F", "E")}

    get_neighbours("G") == {"H", "F", "B"}

    degree("F") == 2

    path("D", "F") == {"D", "A", "C", "H", "G", "F"}

    path_with_largest_weight() == {"E", "F", "G", "B"} or {"B", "G", "F", "E"}

    height() == 4
    */
    for (auto x:t.get_edges() ) {
        cout << x.first << x.second << " ";   
    }
     cout << endl;
     
    t.remove_vertex("H");
     cout << endl;
    cout << "Postorder Traversal Order: ";
    for(auto x : t.postorder_traversal()){
        cout << x << " ";    
    }
    cout << endl;

    for (auto x:t.get_edges() ) {
        cout << x.first << x.second << " ";   
    }
     cout << endl;
}