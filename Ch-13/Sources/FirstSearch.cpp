
#ifndef FIRSTSEARCH_CPP
#define FIRSTSEARCH_CPP

#include <iostream>

#include "GraphType.cpp"
#include "../../Ch-09/Sources/PQType.cpp"
#include "../../Ch-05/Sources/QueType.cpp"
#include "../../Ch-06/Sources/StackType.cpp"

template <class VertexType>
void DepthFirstSearch(GraphType<VertexType> graph,
                      VertexType startVertex, VertexType endVertex)
{
    using namespace std;
    StackType<VertexType> stack;
    QueType<VertexType> vertexQ;
    bool found = false;
    VertexType vertex;
    VertexType item;
    graph.ClearMarks();
    stack.Push(startVertex);
    do
    {
        stack.Pop(vertex);
        if (vertex == endVertex)
        {
            cout << vertex;
            found = true;
        }
        else
        {
            if (!graph.IsMarked(vertex))
            {
                graph.MarkVertex(vertex);
                cout << vertex;
                graph.GetToVertices(vertex, vertexQ);
                while (!vertexQ.IsEmpty())
                {
                    vertexQ.Dequeue(item);
                    if (!graph.IsMarked(item))
                        stack.Push(item);
                }
            }
        }
    } while (!stack.IsEmpty() && !found);
    if (!found)
        cout << "Path not found." << endl;
}

template <class VertexType>
void BreadthFirstSearch(GraphType<VertexType> graph,
                        VertexType startVertex, VertexType endVertex)
// Assumption: VertexType is a type for which the "==" and
// "<<" operators are defined.
{
    using namespace std;
    QueType<VertexType> queue;
    QueType<VertexType> vertexQ;
    bool found = false;
    VertexType vertex;
    VertexType item;
    graph.ClearMarks();
    queue.Enqueue(startVertex);
    do
    {
        queue.Dequeue(vertex);
        if (vertex == endVertex)
        {
            cout << vertex;
            found = true;
        }
        else
        {
            if (!graph.IsMarked(vertex))
            {
                graph.MarkVertex(vertex);
                cout << vertex;
                graph.GetToVertices(vertex, vertexQ);
                while (!vertexQ.IsEmpty())
                {
                    vertexQ.Dequeue(item);
                    if (!graph.IsMarked(item))
                        queue.Enqueue(item);
                }
            }
        }
    } while (!queue.IsEmpty() && !found);
    if (!found)
        cout << "Path not found." << endl;
}

template <class VertexType>
struct ItemType
{
    bool operator<(ItemType otherItem);
    // "<" means shorter distance.
    bool operator==(ItemType otherItem);
    bool operator<=(ItemType otherItem);
    VertexType fromVertex;
    VertexType toVertex;
    int distance;
};

template <class VertexType>
void ShortestPath(GraphType<VertexType> graph,
                  VertexType startVertex)
{
    using namespace std;
    ItemType item;
    int minDistance;
    PQType<VertexType> pq(10);
    QueType<VertexType> vertexQ;
    VertexType vertex;
    graph.ClearMarks();
    item.fromVertex = startVertex;
    item.toVertex = startVertex;
    item.distance = 0;
    pq.Enqueue(item);
    cout << "Last Vertex Destination Distance" << endl;
    cout << "-----------------------------------" << endl;
    do
    {
        pq.Dequeue(item);
        if (!graph.IsMarked(item.toVertex))
        {
            graph.MarkVertex(item.toVertex);
            cout << item.fromVertex;
            cout << " ";
            cout << item.toVertex;
            cout << " " << item.distance << endl;
            item.fromVertex = item.toVertex;
            minDistance = item.distance;
            graph.GetToVertices(item.fromVertex, vertexQ);
            while (!vertexQ.IsEmpty())
            {
                vertexQ.Dequeue(vertex);
                if (!graph.IsMarked(vertex))
                {
                    item.toVertex = vertex;
                    item.distance = minDistance +
                                    graph.GetWeight(item.fromVertex, vertex);
                    pq.Enqueue(item);
                }
            }
        }
    } while (!pq.IsEmpty());
}

#endif //FIRSTSEARCH_CPP