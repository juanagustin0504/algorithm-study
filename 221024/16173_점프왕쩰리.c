#include <stdio.h>
#include <stdlib.h>

int isArrived = 0;

int dir[2][2] = {{1, 0}, {0, 1}}; // Down, Right

/**
 * - dfs
 * - Param
 * N		: Board Size
 * board 	: GameBoard
 * moveCnt	: number of moves
 * x		: currunt row index
 * y		: currunt column index
 */
void dfs(int N, int* board[], int moveCnt, int x, int y);

/**
 * - dfs
 * - Param
 * N		: Board Size
 * board 	: GameBoard
 * moveCnt	: Number of moves
 * x		: Currunt row index
 * y		: Currunt column index
 *
 * - Return	: Result
 */
int bfs(int N, int* board[], int moveCnt, int x, int y);

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

int main() {
	int i, j;
	int N;
	scanf("%d", &N);
	
	int **board = (int**) malloc(sizeof(int*) * N);
	for(i=0;i<N;i++) {
		board[i] = (int*) malloc(sizeof(int) * N);
	}
	
	for(i=0;i<N;i++) {
		for(j=0;j<N;j++) {
			scanf("%d", &board[i][j]);
		}
	}
	
	// DFS
//	dfs(N, board, board[0][0], 0, 0);
//	printf("%s", isArrived ? "HaruHaru" : "Hing");
	// BFS
	int result = bfs(N, board, board[0][0], 0, 0);
	printf("%s", result == 1 ? "HaruHaru" : "Hing");
	
	return 0;
}

void dfs(int N, int* board[], int moveCnt, int x, int y) {
	
	if(board[x][y] == 0 || isArrived) return;
	
	// Exit Condition (Important)
	if(board[x][y] == -1) {
		// Arrived
		isArrived = 1;
		return;
	}
	
	int i;
	for(i=0;i<2;i++) {
		int nx = x + (dir[0][i] * moveCnt);
		int ny = y + (dir[1][i] * moveCnt);
		
		// Out of the board
		if(nx >= N || ny >= N) continue;
		
		// Recursive funtion
		dfs(N, board, board[nx][ny], nx, ny);
	}
}

int bfs(int N, int* board[], int moveCnt, int x, int y) {
	if(board[x][y] == 0) return 0;
	
	Queue q;
	initQueue(&q);
	int data[3] = {x, y, moveCnt};
	enqueue(&q, data);
	int result = 0;
	
	while(!isEmpty(&q)) {
		int *curr = dequeue(&q);
		int i;
		for(i=0;i<2;i++) {
			int nx = curr[0] + (dir[0][i] * curr[2]);
			int ny = curr[1] + (dir[1][i] * curr[2]);
			
			printf("curr (%d, %d), next (%d, %d), i: %d\n", curr[0], curr[1], nx, ny, i);
			
			// Out of the board
			if(nx >= N || ny >= N) continue;
			
			if(nx == curr[0] && ny == curr[1]) goto label;
			
			if(board[nx][ny] == -1) {
				printf("Exit"); 
				result = 1;
				goto label;
			}
			
			int newData[3] = {nx, ny, board[nx][ny]};
			enqueue(&q, newData);
		}
	}
	label:
	
	return result;
}
