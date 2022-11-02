#include <stdio.h>
#include <stdlib.h>

int di[4] = {1, -1, 0, 0};
int dj[4] = {0, 0, -1, 1};

int isArrived = 0;
int resultLength = 0;

typedef struct Node {
	int *data;
	struct Node *next;
}Node;

typedef struct Queue {
	Node *front;
	Node *rear;
	int count; // Count of Nodes
}Queue;

void initQueue(Queue *queue) {
	queue->front = queue->rear = NULL;
	queue->count = 0;
}

int isEmpty(Queue *queue) {
	return queue->count == 0;
}

void enqueue(Queue *queue, int *data) {
	Node *newNode = (Node *) malloc(sizeof(Node)); // Create New Node
	newNode->data = data;
	newNode->next = NULL;
	
	if(isEmpty(queue)) { // Empty Queue
		queue->front = newNode;
	} else {
		queue->rear->next = newNode;
	}
	queue->rear = newNode;
	queue->count++;
}

int *dequeue(Queue *queue) {
	int *data;
	Node *ptr;
	if(isEmpty(queue)) { // Queue is Empty
		return 0;
	}
	
	ptr = queue->front; // Get front Node
	data = ptr->data; // Get data
	queue->front = ptr->next; // Set the next node to front
	free(ptr);
	queue->count--;
	
	return data;
}

int bfs(int n, int m, int **map, int y, int x, int **visitMap, int length, int **brokenMap) {
	Queue q;
	initQueue(&q);
	
	int inputData[4] = {y, x, length, 0};
	
	enqueue(&q, inputData);
	
	visitMap[y][x] = 1;
	brokenMap[y][x] = 1;
	
	while(!isEmpty(&q)) {
		printf("\n===get queue===\n");
		int *data = dequeue(&q);
		int dataY = data[0];
		int dataX = data[1];
		int dataLength = data[2];
		int isBroken = data[3];
		printf("Queue Data : %d %d %d %d\nMap: %d\n", dataY, dataX, dataLength, isBroken, map[dataY][dataX]);
		dataLength++;
		if(dataY == n - 1 && dataX == m - 1) {
			isArrived = 1;
			resultLength = dataLength;
			break;
		}
		int d;
		for(d=0;d<4;d++) {
			int ny = dataY + di[d];
			int nx = dataX + dj[d];
			printf("(%d, %d) -----> (%d, %d)\n", dataY, dataX, ny, nx);
			if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if((visitMap[ny][nx] == 1 && !isBroken) || (brokenMap[ny][nx] == 1 && isBroken)) continue;
			if(map[ny][nx] == 0) {
				printf("ENQUEUE (%d, %d) -----> (%d, %d) length : %d\n", dataY, dataX, ny, nx, dataLength);
				if(isBroken) {
					brokenMap[ny][nx] = 1;
					int newData[4] = {ny, nx, dataLength, isBroken};
					enqueue(&q, newData);
				} 
				if(!isBroken) {
					visitMap[ny][nx] = 1;
					int newData[4] = {ny, nx, dataLength, isBroken};
					enqueue(&q, newData);
				}
				
			}
			
			else if(map[ny][nx] == 1 && isBroken == 0) {
				brokenMap[ny][nx] = 1;
				printf("ENQUEUE (%d, %d) -----> (%d, %d) length : %d\n", dataY, dataX, ny, nx, dataLength);
				int newData[4] = {ny, nx, dataLength, 1};
				enqueue(&q, newData);
			}
			
			else {
				printf("???\n");
				printf("Queue Data : %d %d %d %d\nMap: %d\n", ny, nx, dataLength, isBroken, map[ny][nx]);
			}
			
		}
	}
}

int main() {
	int n, m, i, j;
	
	scanf("%d %d", &n, &m);
	int map[1001][1001] = {0,};
	int visitMap[1001][1001] = {0,}; 
	int brokenMap[1001][1001] = {0,};
	
	for(i=0;i<n;i++) {
		for(j=0;j<m;j++) {
			scanf(" %c", &map[i][j]);
			visitMap[i][j] = 0;
			brokenMap[i][j] = 0;
			map[i][j] -= 48;
		}
	}
	
	bfs(n, m, map, 0, 0, visitMap, 0, brokenMap);
	
	if(!isArrived) printf("-1");
	else printf("%d", resultLength);
	
	return 0;
}
