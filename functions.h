//functions will go here for movement
#include <vector>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
	int n = matrix.size();
	int a = 0;
	int b = n-1;
	while(a<b){
		for(int i=0;i<(b-a);++i){
			swap(matrix[a][a+i], matrix[a+i][b]);
			swap(matrix[a][a+i], matrix[b][b-i]);
			swap(matrix[a][a+i], matrix[b-i][a]);
		}
		++a;
		--b;
	}
}

void slideRight(vector<int> &row) {
	int right = row.size() - 1;
	int left = right - 1;
	
	while (left >= 0) {
		if (row[left] == 2048) {
			right = left - 1;
			left-=2;
			continue;
		}
		if (row[left] > 0 && row[right] != 2048 && row[right] == 0) {
			row[right] = row[left];
			row[left] = 0;
		}
		left--;
		if (row[right] > 0) {
			right--;
		}
	}
}

void combineRight(vector<int> &row) {
	for (int i = row.size() - 1; i >= 1; i--) {
		if (row[i] == row[i-1] && row[i] != 2048) {
			row[i] = row[i] + row[i-1];
			row[i-1] = 0;
		}
	}
}

void moveRight(vector<vector<int>> &matrix) {
	for (int i = 0; i  < matrix.size(); i++) {
		slideRight(matrix[i]);
		combineRight(matrix[i]);
		slideRight(matrix[i]);
	}
}

void moveUp(vector<vector<int>> &matrix) {
	rotate(matrix);
	moveRight(matrix);
	rotate(matrix);
	rotate(matrix);
	rotate(matrix);
}

void moveDown(vector<vector<int>> &matrix) {
	rotate(matrix);
	rotate(matrix);
	rotate(matrix);
	moveRight(matrix);
	rotate(matrix);
}

void moveLeft(vector<vector<int>> &matrix) {
	rotate(matrix);
	rotate(matrix);
	moveRight(matrix);
	rotate(matrix);
	rotate(matrix);
}

