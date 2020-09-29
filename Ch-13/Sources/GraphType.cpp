
#ifndef GRAPHTYPE_CPP
#define GRAPHTYPE_CPP

//	C++ Plus Data Structures, Chapter 13.

//	Class Implementation.

#include "../Headers/GraphType.h"
#include "../../Ch-05/Sources/QueType.cpp"

template <class VertexType>
int IndexIs(VertexType *vertices, VertexType vertex)
{
    int index = 0;
    while (!(vertex == vertices[index]))
        index++;
    return index;
}

template <class VertexType>
GraphType<VertexType>::GraphType()
{
    numVertices = 0;
    maxVertices = 50;
    vertices = new VertexType[50];
    marks = new bool[50];
}
template <class VertexType>
GraphType<VertexType>::GraphType(int maxV)
{
    numVertices = 0;
    maxVertices = maxV;
    vertices = new VertexType[maxV];
    marks = new bool[maxV];
}
template <class VertexType>
GraphType<VertexType>::~GraphType()
{
    delete[] vertices;
    delete[] marks;
}

const int NULL_EDGE = 0;
template <class VertexType>
void GraphType<VertexType>::AddVertex(VertexType vertex)
{
    vertices[numVertices] = vertex;
    for (int index = 0; index < numVertices; index++)
    {
        edges[numVertices][index] = NULL_EDGE;
        edges[index][numVertices] = NULL_EDGE;
    }
    numVertices++;
}
template <class VertexType>
void GraphType<VertexType>::AddEdge(VertexType fromVertex,
                                    VertexType toVertex, int weight)
{
    int row;
    int col;
    row = IndexIs(vertices, fromVertex);
    col = IndexIs(vertices, toVertex);
    edges[row][col] = weight;
}

template <class VertexType>
int GraphType<VertexType>::GetWeight(VertexType fromVertex, VertexType toVertex)
{
    int row;
    int col;
    row = IndexIs(vertices, fromVertex);
    col = IndexIs(vertices, toVertex);
    return edges[row][col];
}
template <class VertexType>
void GraphType<VertexType>::GetToVertices(VertexType vertex,
                                          QueType<VertexType> &adjVertices)
{
    int fromIndex;
    int toIndex;
    fromIndex = IndexIs(vertices, vertex);
    for (toIndex = 0; toIndex < numVertices; toIndex++)
        if (edges[fromIndex][toIndex] != NULL_EDGE)
            adjVertices.Enqueue(vertices[toIndex]);
}

#endif //GRAPHTYPE_CPP