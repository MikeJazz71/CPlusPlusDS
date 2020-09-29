
#ifndef GRAPHTYPE_H
#define GRAPHTYPE_H

//	C++ Plus Data Structures, Chapter 13.

//	Class Specification.

template <class VertexType>
class GraphType
{
    
public :
    GraphType();
    GraphType(int maxV);
    virtual ~GraphType();

    void MakeEmpty();
    void ClearMarks();
    void AddVertex(VertexType);
    void MarkVertex(VertexType);
    void AddEdge(VertexType, VertexType, int);

    bool IsFull() const;
    bool IsEmpty() const;
    bool IsMarked(VertexType);

    int GetWeight(VertexType, VertexType);
    void GetToVertices(VertexType, QueType<VertexType> &);

private:
    bool *marks;
    int numVertices;
    int maxVertices;
    int edges[50][50];
    VertexType *vertices;

};

#endif //GRAPHTYPE_H