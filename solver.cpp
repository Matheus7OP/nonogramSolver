#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

struct Game {
	int dimension;
	vector< vector<int> > matrix, lines, columns;

	Game() {}
	Game(int _dimension) {
		this->dimension = _dimension;

		matrix.resize(dimension);		
		for(int i = 0; i < dimension; i++) matrix[i].resize(dimension, -1);

		lines.resize(dimension);		
		columns.resize(dimension);		
	}

	void showMatrix() {
		for(int i = 0; i < dimension; i++) {
			for(int j = 0; j < dimension; j++) printf("%d%c", matrix[i][j], j != (dimension-1) ? ' ' : '\n');
		}
	}
} game;

void readInput() {
	int dimension;

	cin >> dimension;
	getchar();
	
	game = Game(dimension);

	// lines
	for(int i = 0; i < dimension; i++) {
		string line, token;
		getline(cin, line);

		stringstream ss(line);
		while(ss >> token) game.lines[i].push_back( stoi(token) );
	}

	// columns
	for(int i = 0; i < dimension; i++) {
		string line, token;
		getline(cin, line);

		stringstream ss(line);
		while(ss >> token) game.columns[i].push_back( stoi(token) );
	}

	if( not cin.eof() ) {
		for(int i = 0; i < dimension; i++) {
			for(int j = 0; j < dimension; j++) cin >> game.matrix[i][j];
		}
	}

	game.showMatrix();
}

int main() {
	readInput();
	return 0;
}