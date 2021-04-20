#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>
#include <stack>
#include <limits>
#include <utility>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <map>

using namespace std;

template <typename T> // the template allows the weight of an edge to take any numeric data type (denoted by T).
class Graph
{

private:
    map<string, map<string, T>> adj_list;
    int edges = 0;

public:
    /* define your data structure to represent a weighted undirected graph */

    /* test1 */
    Graph();               // the contructor function.
    ~Graph();              // the destructor function.
    size_t num_vertices(); // returns the total number of vertices in the graph.
    size_t num_edges();    // returns the total number of edges in the graph.

    /* test2 */
    void add_vertex(const string &); // adds a vertex to the graph -- every vertex uses a string as its unique identifier.
    bool contains(const string &);   // checks if a vertex is in the graph -- returns true if the graph contains the given vertex; otherwise, returns false.

    /* test3 */
    vector<string> get_vertices(); // returns a vector of all the vertices in the graph.

    /* test4 */
    void add_edge(const string &, const string &, const T &); // adds a weighted edge to the graph -- the two strings represent the incident vertices; the third parameter represents the edge's weight.
    bool adjacent(const string &, const string &);            // check if there is an edge between the two vertices in the graph -- returns true if the edge exists; otherwise, returns false.

    /* test5 */
    vector<pair<string, string>> get_edges(); // returns a vector of all the edges in the graph -- each edge is represented by a pair of vertices incident to the edge.

    /* test6 */
    vector<string> get_neighbours(const string &); // returns a vector of all the vertices, each of which is directly connected with the given vertex by an edge.
    size_t degree(const string &);                 // returns the degree of a vertex.

    /* test7 */
    void remove_edge(const string &, const string &); // removes the edge between two vertices, if it exists.

    /* test8 */
    void remove_vertex(const string &); // delete the given vertex from the graph -- note that, all incident edges of the vertex should be deleted as well.

    /* test9 */
    vector<string> depth_first_traversal(const string &); // returns a vector of all the vertices in the visiting order of a depth-first traversal from the given vertex.

    /* test10 */
    vector<string> breadth_first_traversal(const string &); // returns a vector of all the vertices in the visiting order of a breadth-first traversal from the given vertex.

    /* test11 */
    bool contain_cycles(); // check if the graph contains any cycle -- returns true if there exists a path from a vertex to itself; otherwise, return false.

    /* test12 */
    Graph<T> minimum_spanning_tree(); // returns a spanning tree of the graph -- the returned tree is preferably a minimum spanning tree.
};

/* test1 */

template <typename T>
Graph<T>::Graph()
{
}

template <typename T>
Graph<T>::~Graph()
{
}

template <typename T>
size_t Graph<T>::num_vertices()
{
    return adj_list.size();
}

template <typename T>
size_t Graph<T>::num_edges()
{
    return edges;
}

/* test2 */

template <typename T>
void Graph<T>::add_vertex(const string &u)
{
    adj_list[u] = map<string, T>();
}

template <typename T>
bool Graph<T>::contains(const string &u)
{
    if (adj_list.count(u) == 1)
    {
        return true;
    }
    return false;
}

/* test3 */

template <typename T>
vector<string> Graph<T>::get_vertices()
{

    vector<string> vertexs;
    typename map<string, map<string, T>>::iterator it;

    for (it = adj_list.begin(); it != adj_list.end(); ++it)
    {
        vertexs.push_back(it->first);
    }
    return vertexs;
}

/* test4 */

template <typename T>
void Graph<T>::add_edge(const string &u, const string &v, const T &weight)
{

    if ((contains(u)) && (contains(v)) && (u != v))
    {            //
        edges++; //adds to our total amount of edges
    }
    adj_list[u][v] = weight; //unweighted need to do both ways
    adj_list[v][u] = weight;
}
template <typename T>
bool Graph<T>::adjacent(const string &u, const string &v)
{
    return (contains(u) && contains(v) ? adj_list[u][v] && adj_list[v][u] : false);
}

/* test5 */

template <typename T>
vector<pair<string, string>> Graph<T>::get_edges()
{

    vector<string> vertexs;
    vector<pair<string, string>> edge_list;

    for (auto x : adj_list)
    {
        for (auto y : x.second)
        {
            if (find(vertexs.begin(), vertexs.end(), y.first) != vertexs.end())
            {
                edge_list.push_back(make_pair(x.first, y.first));
            }
        }
        vertexs.push_back(x.first);
    }

    return edge_list;
}

/* test6 */

template <typename T>
vector<string> Graph<T>::get_neighbours(const string &u)
{

    vector<string> vertexs;

    if (contains(u))
    {
        for (auto it = adj_list[u].begin(); it != adj_list[u].end(); ++it)
        {
            vertexs.push_back(it->first);
        }
    }
    return vertexs;
}

template <typename T>
size_t Graph<T>::degree(const string &u)
{

    return adj_list[u].size();
}

/* test7 */

template <typename T>
void Graph<T>::remove_edge(const string &u, const string &v)
{

    if (contains(u) && contains(v))
    {
        adj_list[u].erase(v);
        edges--;
    }
    adj_list[v].erase(u);
}

/* test8 */

template <typename T>
void Graph<T>::remove_vertex(const string &u)
{

    for (auto x : adj_list[u])
    {
        adj_list[x.first].erase(u);
        edges--;
    }
    adj_list.erase(u);
}

/* test9 */

template <typename T>
vector<string> Graph<T>::depth_first_traversal(const string &u)
{

    vector<string> visited;
    vector<string> queue;

    queue.push_back(u);
    while (!queue.empty())
    {
        string current = queue.back();
        queue.pop_back();
        visited.push_back(current);
        for (auto x = adj_list[current].rbegin(); x != adj_list[current].rend(); x++)
        {
            if (find(visited.begin(), visited.end(), x->first) == visited.end() && find(queue.begin(), queue.end(), x->first) == queue.end())
            {
                queue.push_back(x->first);
            }
        }
    }

    return visited; // return visited
}

/* test10 */

template <typename T>
vector<string> Graph<T>::breadth_first_traversal(const string &u)
{

    vector<string> visited;
    deque<string> queue;

    queue.push_back(u);
    while (!queue.empty())
    {
        string current = queue.back();
        queue.pop_back();
        visited.push_back(current);
        for (auto x = adj_list[current].begin(); x != adj_list[current].end(); x++)
        {
            if (find(visited.begin(), visited.end(), x->first) == visited.end() && find(queue.begin(), queue.end(), x->first) == queue.end())
            {
                queue.push_front(x->first);
            }
        }
    }

    return visited; // return visited
}

/* test11 */

template <typename T>
bool Graph<T>::contain_cycles()
{

    vector<string> visited;
    vector<pair<string, string>> queue; // (vertex, parent)

    queue.push_back(make_pair(adj_list.begin()->first, ""));
    while (!queue.empty())
    {
        string current = queue.back().first;
        string parent = queue.back().second;
        queue.pop_back();
        visited.push_back(current);

        for (auto x : adj_list[current])
        {
            if (find(visited.begin(), visited.end(), x.first) == visited.end() && find(queue.begin(), queue.end(), x.first) == queue.end())
            { // (search through visited, value = x at first position) == visited.end()
                queue.push_back(make_pair(x.first, current));
            }

            else if (x.first != parent) //does not allow anything smaller than 3
            {
                return true; // if the graph contains a cycle
            }
        }
    }
    return false;
}

/* test12 */

template <typename T>
Graph<T> Graph<T>::minimum_spanning_tree()
{
    return Graph<T>();
}