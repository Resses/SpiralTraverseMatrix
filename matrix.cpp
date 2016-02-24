#include <iostream>
using namespace std;

const int N = 5;

void print(int matrix[][N]);
void fill(int matrix[][N]);

int main() {
	int matrix[N][N];
	fill(matrix);
	return 0;
}

void print(int matrix[][N]){
	for (int x = 0; x < N; x++){
		for(int y = 0; y < N; y++){
			cout << matrix[x][y] << " ";
		}
		cout << endl;
	}
	cout << endl;
}


//To traverse a matrix as a spiral, what I do is first go across the top row. 
//Then from where you're left off, go down n-1 and then left n-1
//Then go up and then right n-2
//do that until n = 0
void fill(int matrix[][N]){
	int i,j;
	i = j = 0;
	enum Direction {DOWN, LEFT, UP, RIGHT};
	//initialize all values to 0. Not necessary, but for printing purposes...
	for (int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			matrix[i][j] = 0;
		}
	}
	//fill first row
	for(j = 0; j < N; j++){
		matrix[0][j] = 1;
	}
	j--;
	print(matrix);
	//now i = 0; j=n-1;
	int n = N - 1;
	int d = DOWN;
	while(n > 0){
		for(int a = 0; a < 2; a++){
			int k;
			if (d == DOWN){
				for(k = 0; k< n; k++){
					matrix[i+k+1][j] = 1;
				}
				i = i+k;
				print(matrix);					
			}
			else if (d == LEFT){
				for(k = 0; k< n; k++){
					matrix[i][j - k - 1] = 1;
				}
				j = j - k;
				print(matrix);
			}
			else if (d == UP){
				for(k = 0; k< n; k++){
					matrix[i-k-1][j] = 1;
				}
				i = i - k;
				print(matrix);
			}
			else if (d == RIGHT){
				for(k = 0; k< n; k++){
					matrix[i][j+k+1] = 1;
				}
				j = j + k;
				print(matrix);
			}
			d = (d+1)%4;
		}
		n--;
	}//end while
}
