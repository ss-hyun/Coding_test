#include<iostream>
#include <vector>
#include <string>
#include <iterator>
#include <memory.h>

using namespace std;

char code[5][5];
string message, key, cipher;
int loc_alpha[26];

void print_code() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++)
			cout << code[i][j] << ' ';
		cout << endl;
	}
}

void fill_code() {
	memset(loc_alpha, -1, sizeof(loc_alpha));
	loc_alpha[9] = 500;
	int i = 0;

	for (char k : key) {
		if (loc_alpha[k - 'A'] < 0) {
			loc_alpha[k - 'A'] = i;
			code[i / 5][i % 5] = k;
			i++;
		}
	}

	for (int j = 0; j < 26; j++) {
		if (loc_alpha[j] < 0) {
			loc_alpha[j] = i;
			code[i / 5][i % 5] = 'A' + j;
			i++;
		}
	}

	//print_code();
}

string move_right(int col, int row1, int row2) {
	string s = "";
	row1++; row2++;
	if (row1 == 5) row1 = 0;
	if (row2 == 5) row2 = 0;
	s += code[col][row1];
	s += code[col][row2];
	return s;
}

string move_down(int row, int col1, int col2) {
	string s = "";
	col1++; col2++;
	if (col1 == 5) col1 = 0;
	if (col2 == 5) col2 = 0;
	s += code[col1][row];
	s += code[col2][row];
	return s;
}

string row_swap(int col1, int row1, int col2, int row2) {
	string s = "";
	s += code[col1][row2];
	s += code[col2][row1];
	return s;
}

string encryption(char a, char b) {
	int aloc = loc_alpha[a - 'A'], bloc = loc_alpha[b - 'A'];
	if (aloc / 5 == bloc / 5)
		return move_right(aloc / 5, aloc % 5, bloc % 5);
	else if (aloc % 5 == bloc % 5)
		return move_down(aloc % 5, aloc / 5, bloc / 5);
	else
		return row_swap(aloc / 5, aloc % 5, bloc / 5, bloc % 5);
}

void playfair() {
	string::iterator iter = message.begin();

	while (iter != message.end()) {
		if (iter + 1 == message.end()) {
			cipher += encryption(*iter, 'X');
			break;
		}
		else if (*iter == *(iter + 1)) {
			if (*iter != 'X')
				cipher += encryption(*iter, 'X');
			else
				cipher += encryption(*iter, 'Q');
			iter++;
		}
		else {
			cipher += encryption(*iter, *(iter + 1));
			iter += 2;
		}
	}
}

int main(int argc, char** argv)
{
	cin >> message;
	cin >> key;

	fill_code();
	playfair();

	cout << cipher;

	return 0;
}