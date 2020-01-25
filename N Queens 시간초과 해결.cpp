//[���� 9663] N-Queen

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
#include <set>

using namespace std;

int N;
int queenset{ 0 };
vector<vector<int>> board;

void initBoard(int N) {
	board.clear();
	for (int i{ 0 }; i < N; i++) {
		board.push_back(vector<int>(N, 0));
	}
}

void nextQueen(vector<int> V) {
	/*
	//V�� �ִ� ��� �� �߰�	
	vector<vector<int>> tmpBoard = board;
	for (int i{ 0 }; i < V.size(); i++) {
		tmpBoard[i][V[i]] = 1;
			
		//���δ� �߰��ʿ���� - ������ �� row�� �ϳ��� ��ĥ�� ����
		
		//���� �߰�
		for (int p{ 0 }; p < N; p++) {
			tmpBoard[p][V[i]] = 1;
		}
		
	//�밢�� �߰�
		
		//��������
		for (int x{ 0 }; x < V.size(); x++) {
			for (int y{ 0 }; y < x; y++) {
				if (V[x] - (x - y) >= 0 && V[x] - (x - y) < N) {
					tmpBoard[y][V[x]-(x-y)] = 1;
				}
				if (V[x] + (x - y) >= 0 && V[x] + (x - y) < N) {
					tmpBoard[y][V[x] + (x - y)] = 1;
				}
			}
		}

		//�Ʒ�������
		for (int x{ 0 }; x < V.size(); x++) {
			for (int y{ x+1 }; y < N; y++) {
				if (V[x] - (y - x) >= 0 && V[x] - (y - x) < N) {
					tmpBoard[y][V[x] - (y - x)] = 1;
				}
				if (V[x] + (y - x) >= 0 && V[x] + (y - x) < N) {
					tmpBoard[y][V[x] + (y - x)] = 1;
				}
			}
		}
		
	}
	//���� ������ temp ���� ����
	vector<int> temp;
	for (int j{ 0 }; j < N; j++) {
		if (tmpBoard[V.size()][j] == 0) temp.push_back(j);
	}*/

	//���� ������ temp ���� ����
	vector<int> temp;
	for (int i{ 0 }; i < N; i++) {
		int count{ 0 };
		for (int v{ 0 }; v < V.size(); v++) {
			if (V[v] == i || abs(i - V[v]) == V.size() - v)break;
			else count++;
		}
		if (count == V.size()) temp.push_back(i);
	}

	if (temp.size() != 0) {

		if (V.size() == N - 1) {		
			queenset += temp.size();
			return;
		}
		else {
			for (auto t : temp) {
				vector<int> VV = V;
				VV.push_back(t);
				nextQueen(VV);
			}
		}
	}

	return;
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	if (N == 1) {
		cout << "1";
		return 0;
	}
	 
	initBoard(N);

	for (int i{ 0 }; i < N; i++) {
		nextQueen({ i });
	}

	cout << queenset;

	system("pause");
	return 0;
}