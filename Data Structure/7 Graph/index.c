#include <stdio.h>
#include <stdlib.h>

// Creating Queue for Breath First Seacrh Alog for Graph
struct queue
{
  int items[40];
  int front;
  int rear;
};

struct node
{
  int vertex;
  struct node *next;
};

struct graph
{
  int numVertices;
  int *visited;
  struct node **adjList;
};

// Crate Node
struct node *createNode(int v)
{
  struct node *newNode = malloc(sizeof(struct node));
  newNode->vertex = v;
  newNode->next = NULL;
  return newNode;
}

// Create Graph
struct graph *createGraph(int vertices)
{
  struct graph *myGraph = malloc(sizeof(struct graph));
  myGraph->numVertices = vertices;
  myGraph->adjList = malloc(vertices * sizeof(struct node *));
  myGraph->visited = malloc(vertices * sizeof(int));

  for (int i = 0; i < vertices; i++)
  {
    myGraph->adjList[i] = NULL;
    myGraph->visited[i] = 0;
  }
  return myGraph;
}

// Add edges between nodes/vertices
void addEdge(struct graph *graph, int source, int destination)
{
  // This is undirected graph so connect both source to destination and destination to source
  // Add edge from source to destination
  struct node *newNode = createNode(destination);
  newNode->next = graph->adjList[source];
  graph->adjList[source] = newNode;
  // Add edge from destination to source
  newNode = createNode(source);
  newNode->next = graph->adjList[destination];
  graph->adjList[destination] = newNode;
}

// Depth First Search Alog
void DFS(struct graph *graph, int vertex)
{
  struct node *adjList = graph->adjList[vertex];
  struct node *temp = adjList;
  graph->visited[vertex] = 1;

  while (temp != NULL)
  {
    int connectedVertex = temp->vertex;
    if (graph->visited[connectedVertex] == 0)
    {
      DFS(graph, connectedVertex);
    }
    temp = temp->next;
  }
}

// Print Graph
void printGraph(struct graph *graph)
{
  for (int v = 0; v < graph->numVertices; v++)
  {
    struct node *temp = graph->adjList[v];
    printf(" \n Vertex %d\n: ", v);
    while (temp)
    {
      printf(" %d --> ", temp->vertex);
      temp = temp->next;
    }
    printf(" X ");
    printf("\n");
  }
}

// <<<<<<<<<<<<<<<<<< QUEUE FUNCTIONS >>>>>>>>>>>>>>>>> //

// Creating new instance of Queue and Return
struct queue *createQueue()
{
  struct queue *newQ = malloc(sizeof(struct queue));
  newQ->front = -1;
  newQ->rear = -1;
  return newQ;
}

// Check is queue is empty of not
int isEmpty(struct queue *q)
{
  if (q->rear == -1)
    return 1;
  else
    return 0;
}

// Enqueu element in queue
void enqueue(struct queue *q, int item)
{
  if (q->rear == sizeof(q->items) / sizeof(q->items[0]) - 1)
    printf(" Queue is Full. \n");
  else
  {
    if (q->front == -1)
      q->front = 0;
    q->rear++;
    q->items[q->rear] = item;
  }
}

// Dequeue element from queue
int dequeue(struct queue *q)
{
  int item;
  if (isEmpty(q))
  {
    printf(" Queue is empty.\n");
    item = -1;
  }
  else
  {
    item = q->items[q->front];
    q->front++;
    if (q->front > q->rear)
    {
      printf(" Resetting Queue. \n");
      q->front = q->rear = -1;
    }
  }
  return item;
}

// Print Queue
void printQueue(struct queue *q)
{
  int i = q->front;
  if (isEmpty(q))
  {
    printf(" Queue is empty.");
  }
  else
  {
    printf("\n Queue Contains \n");
    while (i < q->rear + 1)
    {
      printf(" %d - ", q->items[i]);
      i++;
    }
  }
}

// Breath First Search Alog
void BFS(struct graph *g, int startVertex)
{
  // Crating Queue Instence
  struct queue *thisQueue = createQueue();
  // Marking starting Vertes as a visited
  g->visited[startVertex] = 1;
  enqueue(thisQueue,startVertex);

  while (!isEmpty(thisQueue))
  {
    printQueue(thisQueue);
    int currentVertex = dequeue(thisQueue);
    printf(" Visited Vertex %d \n", currentVertex);

    struct node *temp = g->adjList[currentVertex];

    while (temp)
    {
      int adjVertex = temp->vertex;

      if (g->visited[adjVertex] == 0)
      {
        g->visited[adjVertex] == 1;
        enqueue(thisQueue, adjVertex);
      }
      temp = temp->next;
    }
  }
}

int main()
{
  struct graph *newGraph = createGraph(4);

  // addEdge(newGraph, 0, 1);
  // addEdge(newGraph, 0, 2);
  // addEdge(newGraph, 0, 3);
  // addEdge(newGraph, 1, 2);

  addEdge(newGraph, 0, 1);
  addEdge(newGraph, 0, 2);
  addEdge(newGraph, 1, 2);
  addEdge(newGraph, 1, 4);
  addEdge(newGraph, 1, 3);
  addEdge(newGraph, 2, 4);
  addEdge(newGraph, 3, 4);

  // printGraph(newGraph);



  // DFS(newGraph, 0);
  printf(" <<<<<<<<<<<<<<< Extre >>>>>>>>>>>>>>>>>>>>");
  BFS(newGraph,0);
  return 0;
}