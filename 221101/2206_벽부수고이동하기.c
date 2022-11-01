#include <stdio.h>
#include <stdlib.h>

int di[4] = {1, -1, 0, 0};
int dj[4] = {0, 0, -1, 1};

int isArrived = 0;
int resultLength = 0;

typedef struct Node {
	int x;
	int y;
	int length;
	int breakingX;
	int breakingY;
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

void enqueue(Queue *queue, int y, int x, int length, int breakingY, int breakingX) {
	Node *newNode = (Node *) malloc(sizeof(Node)); // Create New Node
	newNode->y = y;
	newNode->x = x;
	newNode->length = length;
	newNode->breakingY = breakingY;
	newNode->breakingX = breakingX;
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
	Node *ptr;
	if(isEmpty(queue)) { // Queue is Empty
		return 0;
	}
	
	ptr = queue->front; // Get front Node
	int y = ptr->y;
	int x = ptr->x;
	int length = ptr->length;
	int breakingY = ptr->breakingY;
	int breakingX = ptr->breakingX;
	queue->front = ptr->next; // Set the next node to front
	free(ptr);
	queue->count--;
	
	int data[5] = {y, x, length, breakingY, breakingX};
	
	return data;
}

int bfs(int n, int m, int **map, int y, int x, int **visitMap, int length) {
	Queue q;
	initQueue(&q);
	
	enqueue(&q, y, x, length, 0, 0);
	int breakingX = 0, breakingY = 0;
	
	visitMap[y][x] = 1;
	
	while(!isEmpty(&q)) {
//		printf("\n===get queue===\n");
		int *data = dequeue(&q);
		int dataY = data[0];
		int dataX = data[1];
		int dataLength = data[2];
		int dataBreakingY = data[3];
		int dataBreakingX = data[4];
		visitMap[dataY][dataX] = 1;
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
//			printf("(%d, %d) -----> (%d, %d)\n", dataY, dataX, ny, nx);
//			printf("DATA(%d, %d)\n", dataBreakingY, dataBreakingX);
			if(ny < 0 || ny >= n || nx < 0 || nx >= m || visitMap[ny][nx] == 1 || (!(dataBreakingY == 0 && dataBreakingX == 0) && map[ny][nx] == 1) || isArrived) continue;
			if(map[ny][nx] == 0 || (map[ny][nx] == 1 && (dataBreakingY == 0 && dataBreakingX == 0))) {
				if(map[ny][nx] == 1) {
					breakingY = ny;
					breakingX = nx;
//					printf("\n===breaking===\n");
				}
//				printf("ENQUEUE (%d, %d) -----> (%d, %d) length : %d\n", dataY, dataX, ny, nx, dataLength);
//				visitMap[ny][nx] = 1;
				enqueue(&q, ny, nx, dataLength, breakingY, breakingX);
			}
			
		}
	}
}

int main() {
	int n, m, i, j;
	
	scanf("%d %d", &n, &m);
	int **map = malloc(sizeof(int *) * n);
	int **visitMap = malloc(sizeof(int *) * n);
	
	for(i=0;i<n;i++) {
		map[i] = malloc(sizeof(int) * m);
		visitMap[i] = malloc(sizeof(int) * m);
	}
	for(i=0;i<n;i++) {
		for(j=0;j<m;j++) {
			scanf(" %c", &map[i][j]);
			visitMap[i][j] = 0;
			map[i][j] -= 48;
		}
	}
	
	bfs(n, m, map, 0, 0, visitMap, 0);
	
	if(!isArrived) printf("-1");
	else printf("%d", resultLength);
	
	return 0;
}
