#include <stdio.h>
#include <stdlib.h>

int di[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dj[8] = {0, 0, -1, 1, -1, 1, -1, 1};

void dfs(int h, int w, int y, int x, int **map, int **visitMap) {
	int d;
	for(d=0;d<8;d++) {
		int ny = y + di[d];
		int nx = x + dj[d];
		
		if(ny < 0 || ny >= h || nx < 0 || nx >= w || map[ny][nx] == 0 || visitMap[ny][nx] == 1) continue;
		visitMap[ny][nx] = 1;
		dfs(h, w, ny, nx, map, visitMap);
	}
}

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
	data = ptr->data; // Get front Node Data
	queue->front = ptr->next; // Set the next node to front
	free(ptr);
	queue->count--;
	
	return data;
}

void bfs(int h, int w, int y, int x, int **map, int **visitMap) {
	Queue q;
	initQueue(&q);
	int initData[2] = {y, x};
	enqueue(&q, initData);
	
	while(!isEmpty(&q)) {
		int *data = dequeue(&q);
		
		int d;
		for(d=0;d<8;d++) {
			int ny = y + di[d];
			int nx = x + dj[d];
			
			if(ny < 0 || ny >= h || nx < 0 || nx >= w || map[ny][nx] == 0 || visitMap[ny][nx] == 1) continue;
			visitMap[ny][nx] = 1;
			int nextData[2] = {ny, nx};
			enqueue(&q, nextData);
		}
	}
}

int main() {
	
	while(1) {
		int w, h;
		int i, j;
		int result = 0;
		scanf("%d %d", &w, &h);
		
		if (w == 0 && h == 0) break;
		
		int **map = malloc(sizeof(int *) * h);
		for(i=0;i<h;i++) {
			map[i] = malloc(sizeof(int) * w);
		}
		int **visitMap = malloc(sizeof(int *) * h);
		for(i=0;i<h;i++) {
			visitMap[i] = malloc(sizeof(int) * w);
		}
		
		for(i=0;i<h;i++) {
			for(j=0;j<w;j++) {
				scanf("%d", &map[i][j]);
				visitMap[i][j] = 0;
			}
		}
		
		for(i=0;i<h;i++) {
			for(j=0;j<w;j++) {
				if(map[i][j] == 1 && visitMap[i][j] == 0) {
					result++;
					visitMap[i][j] = 1;
//					dfs(h, w, i, j, map, visitMap);
					bfs(h, w, i, j, map, visitMap);
				}
			}
		}
		
		printf("%d\n", result);
		
		for(i=0;i<h;i++) {
			free(map[i]);
			free(visitMap[i]);
		}
		
		free(map);
		free(visitMap);
	}
	
	return 0;
}
