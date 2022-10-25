#include <stdio.h>
#include <stdlib.h>

int di[4] = {-1, 1, 0, 0};
int dj[4] = {0, 0, -1, 1};

void dfs(int m, int n, int **map, int x, int y, int **visitMap) {
	
	int d;
	for(d=0;d<4;d++) {
		int nx = x + dj[d];
		int ny = y + di[d];
		
		if(nx < 0 || nx >= m || ny < 0 || ny >= n || visitMap[ny][nx] == 1 || map[ny][nx] == 0) continue;
		
		visitMap[ny][nx] = 1;
		dfs(m, n, map, nx, ny, visitMap);
	}
	return;
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

int bfs(int m, int n, int **map, int x, int y, int **visitMap) {
	Queue q;
	initQueue(&q);
	int initData[2] = {x, y};
	enqueue(&q, initData);
	
	while(!isEmpty(&q)) {
		int *data = dequeue(&q);
		printf("@@ %d %d\n", data[1], data[0]);
		
		int d;
		for(d=0;d<4;d++) {
			int nx = data[0] + dj[d];
			int ny = data[1] + di[d];
			
			if(nx < 0 || nx >= m || ny < 0 || ny >= n || map[ny][nx] == 0) {
				continue;
			}
			if (visitMap[ny][nx] == 1) {
				continue;
			}
			
			visitMap[ny][nx] = 1;
			int nextData[2] = {nx, ny};
			enqueue(&q, nextData);
			printf(">>>>>%d %d\n", ny, nx);
		}
	}
	printf("============================\n");
} 

int main() {
	
//	Queue q;
//	initQueue(&q);
//	
//	int data1[2] = {0, 0};
//	enqueue(&q, data1);
//	int data2[2] = {1, 0};
//	enqueue(&q, data2);
//	int data3[2] = {2, 0};
//	enqueue(&q, data3);
//	int data4[2] = {3, 0};
//	enqueue(&q, data4);
//	int data5[2] = {4, 0};
//	enqueue(&q, data5);
//	int data6[2] = {5, 0};
//	enqueue(&q, data6);
//	int data7[2] = {6, 0};
//	enqueue(&q, data7);
//	int data8[2] = {7, 0};
//	enqueue(&q, data8);
//	int data9[2] = {8, 0};
//	enqueue(&q, data9);
//	int data10[2] = {9, 0};
//	enqueue(&q, data10);
	
//	int i;
//	for(i=0;i<10;i++) {
//		int *data = dequeue(&q);
//		printf("%d\n", data[0]);
//	}
	int t, n, m, k, x, y;
	int startX, startY;
	
	scanf("%d", &t);
	
	while (t--) {
		scanf("%d %d %d", &m, &n, &k);
		int **map = malloc(sizeof(int *) * n);
		int **visitMap = malloc(sizeof(int *) * n);
		int wormCnt = 0;
		int i;
		for(i=0;i<n;i++) {
			map[i] = malloc(sizeof(int) * m);
			visitMap[i] = malloc(sizeof(int) * m);
		}
		
		int j;
		
		for(i=0;i<n;i++) {
			for(j=0;j<m;j++) {
				map[i][j] = 0;
				visitMap[i][j] = 0;
			}
		}
				
		for(i=0;i<k;i++) {
			scanf("%d %d", &x, &y);
			map[y][x] = 1;
		}
		
//		for(i=0;i<n;i++) {
//			for(j=0;j<m;j++) {
//				printf("%d ", map[i][j]);
//			}
//			printf("\n");
//		}
		
		for(i=0;i<n;i++) {
			for(j=0;j<m;j++) {
				if(map[i][j] == 1 && visitMap[i][j] == 0) {
					visitMap[i][j] = 1;
//					dfs(m, n, map, j, i, visitMap);
					printf("::::%d %d\n", i, j);
					bfs(m, n, map, j, i, visitMap);
					
					wormCnt++;
				}
			}
		}
		
		printf("%d\n", wormCnt);
		
		for(i=0;i<n;i++) {
			free(map[i]);
			free(visitMap[i]);
		}
		free(map);		
		free(visitMap);
	}
		
	
	return 0;
}
