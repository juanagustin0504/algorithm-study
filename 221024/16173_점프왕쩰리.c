#include <stdio.h>
#include <stdlib.h>

int isArrived = 0;

int dir[2][2] = {{1, 0}, {0, 1}}; // Down, Right

/**
 * - dfs, bfs -
 *
 * - Param -
 * N		: Board Size
 * board 	: GameBoard
 * moveCnt	: number of moves
 * x		: currunt row index
 * y		: currunt column index
 */
void dfs(int N, int* board[], int moveCnt, int x, int y);
void bfs(int N, int* board[], int moveCnt, int x, int y);

typedef struct Node {
	int data;
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

void enqueue(Queue *queue, int data) {
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

int dequeue(Queue *queue) {
	int data;
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
	dfs(N, board, board[0][0], 0, 0);
	// BFS
//	bfs(N, board, board[0][0], 0, 0);
	
	printf("%s", isArrived ? "HaruHaru" : "Hing");
	
	
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
