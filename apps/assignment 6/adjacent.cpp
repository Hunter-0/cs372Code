
template <class ValueType>
class AdjacentList
{

public:
AdjacentList();
bool adjacent(ValueType x, ValueType y); // is there a node from x to y
vector<ValueType> neighbors(ValueType x); // Return a vector of neighbor nodes


};


template <class ValueType>
class AdjacentMatrix
{

public:
AdjacentMatrix();
void addEdge(ValueType source, ValueType dest);                                                                           
void addNode(ValueType x); //Add x to graph
void deleteEdge(ValueType source, ValueType dest);
void deleteNode(ValueType node);


};