#include <iostream>
#include <vector>

using namespace std;

template <class N, class E> class Edge;

template <class N, class E>
class Node {
public:
    N info;
    vector< Edge<N,E> > edges;
    Node(N inf) {
        info = inf;
    }
};

template <class N, class E>
class Edge {
public:
    E value;
    Node<N,E> *destination;
    Edge(Node<N,E> *dest, E val) {
        value = val;
        destination = dest;
    }
};

template <class N, class E>
class Graph {
    vector< Node<N,E> *> nodes;
public:
    Graph(){};
    ~Graph(){};
    Graph & addNode(const N &inf);
    Graph & addEdge(const N &begin, const N &end, const E &val);
    Graph & removeEdge(const N &begin, const N &end);
    E & edgeValue(const N &begin, const N &end);
    unsigned numEdges(void) const {
        int nEdges = 0;
        typename vector< Node<N,E> *>::const_iterator it;
        for(it = nodes.begin(); it!=nodes.end(); it++){
            nEdges += (*it)->edges.size();
        }
        return nEdges;
    };
    unsigned numNodes(void) const{ return nodes.size(); };
    void print(std::ostream &os) const;
};

template <class N, class E>
std::ostream & operator<<(std::ostream &out, const Graph<N,E> &g);


// exception NodeAlreadyExists
template <class N>
class NodeAlreadyExists
{
public:
    N info;
    NodeAlreadyExists(N inf) { info=inf; }
};
template <class N>
std::ostream & operator<<(std::ostream &out, const NodeAlreadyExists<N> &no)
{ out << "Node already exists: " << no.info; return out; }

// exception NodeDoesNotExist
template <class N>
class NodeDoesNotExist {
public:
    N info;
    NodeDoesNotExist(N inf) {
        info = inf;
    }
};

template <class N>
class EdgeAlreadyExists {
public:
    N begin, end;
    EdgeAlreadyExists(N b, N e) : begin(b), end(e){ }
};

template <class N>
class EdgeDoesNotExist {
public:
    N begin, end;
    EdgeDoesNotExist(N b, N e) : begin(b), end(e){ }
};


template <class N>
std::ostream & operator<<(std::ostream &out, const EdgeAlreadyExists<N> &e){
    out << "Edge already exists: " << e.begin << " , " << e.end;
    return out;
}

template <class N>
std::ostream & operator<<(std::ostream &out, const EdgeDoesNotExist<N> &e){
    out << "Edge does not exist: " << e.begin << " , " << e.end;
    return out;
}

template <class N>
std::ostream & operator<<(std::ostream &out, const NodeDoesNotExist<N> &no)
{ out << "Node does not exist: " << no.info; return out; }

template <class N, class E>
Graph<N, E> & Graph<N, E>::addNode(const N &inf) {
    typename vector< Node<N,E> *>::const_iterator it;
    for(it = nodes.begin(); it != nodes.end(); it++){
        if((*it)->info == inf) throw NodeAlreadyExists<N>(inf);
    }
    nodes.push_back(new Node<N,E>(inf));
    return *this;
};

template <class N, class E>
Graph<N, E> & Graph<N, E>::addEdge(const N &begin, const N &end, const E &val) {

    bool foundBegin = false;
    bool foundEnd = false;

    Node<N,E> *nob = NULL;
    Node<N,E> *noe = NULL;

    typename vector<Node<N,E> *>::const_iterator it;
    typename vector<Edge<N,E>>::const_iterator itedge;

    for(it = nodes.begin(); it != nodes.end(); it++) {
        if ((*it)->info == begin) {
            foundBegin = true;
            nob = *it;
            for (itedge = nob->edges.begin(); itedge != nob->edges.end(); itedge++) {
                if ((*itedge).destination->info == end) throw EdgeAlreadyExists<N>(begin, end);
            }
            if(foundEnd) break;
        } else if((*it)->info == end){
            foundEnd = true;
            noe = *it;
            if(foundBegin) break;
        }
    }

    if(!foundBegin) throw NodeDoesNotExist<N>(begin);
    if(!foundEnd) throw NodeDoesNotExist<N>(end);

    Edge<N,E> edge1(noe, val);
    nob->edges.push_back(edge1);

    return *this;
}

template <class N, class E>
void Graph<N,E>::print(std::ostream &os) const
{
    typename vector< Node<N,E> *>::const_iterator it;
    typename vector< Edge<N,E> >::const_iterator itedge;
    for (it = nodes.begin(); it != nodes.end(); it++) {
        os << "( " << (*it)->info ;
        for (itedge = (*it)->edges.begin();  itedge != (*it)->edges.end(); itedge++) {
            os << "[ " <<  itedge->destination->info << " " << itedge->value << "] " ;
        }
        os << ") ";
    }
}

template <class N, class E>
E &Graph<N,E>::edgeValue(const N &begin, const N &end) {
    typename vector<Node<N,E>*>::iterator it;
    typename vector<Edge<N,E>>::iterator itedge;

    for(it = nodes.begin(); it != nodes.end(); it++){
        if((*it)->info == begin) {
            for (itedge = (*it)->edges.begin(); itedge != (*it)->edges.end(); itedge++) {
                if (itedge->destination->info == end) {
                    return itedge->value;
                }
            }
            throw EdgeDoesNotExist<N>(begin, end);
        }
    }
    throw NodeDoesNotExist<N>(begin);
}

template <class N, class E>
Graph<N,E> & Graph<N,E>::removeEdge(const N &begin, const N &end) {
    typename vector<Node<N,E>*>::iterator it;
    typename vector<Edge<N,E>>::iterator itedge;

    for(it = nodes.begin(); it != nodes.end(); it++){
        if((*it)->info == begin) {
            for (itedge = (*it)->edges.begin(); itedge != (*it)->edges.end(); itedge++) {
                if (itedge->destination->info == end) {
                    (*it)->edges.erase(itedge);
                    return *this;
                }
            }
            throw EdgeDoesNotExist<N>(begin, end);
        }
    }
    throw NodeDoesNotExist<N>(begin);
}

template <class N, class E>
std::ostream & operator<<(std::ostream &out, const Graph<N, E> &g)
{
    g.print(out);
    return out;
}
