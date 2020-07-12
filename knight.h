#ifndef KNIGHT_H
#define KNIGHT_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <iomanip>

// Bàn cờ 8x8
const int board_size = 8;
//row và col nhập tử bàn phím
int start_row, start_col;

class knight
{
public:
	knight(int row, int col);
	void print();
	void insert(int row, int col);
	void moveTheKnight();
	void firstMoveChoice(int row, int col);
	void secondMoveChoice(int row, int col);
	void thirdMoveChoice(int row, int col);
	void fourthMoveChoice(int row, int col);
	void fifthMoveChoice(int row, int col);
	void sixthMoveChoice(int row, int col);
	void seventhMoveChoice(int row, int col);
	void eighthMoveChoice(int row, int col);
	bool isMove(int row, int col);
	bool canMove(int row, int col);
	void print_file();

private:
	// Biến đếm nước đi của quân mã
	int count;
	// Vị trí hiện tại của quân mã
	int curr_row, curr_col;
	// Bàn cờ với kích thước 8x8
	int knight_square[board_size][board_size];
};

//Biến lưu các nước quân mã chạy qua
int board[8][8];
class knight2
{
public:
	//vị trí hàng và cột của quân mã hiện tại
	int r, c;
	//Vị trí nước đi có thể đi được
	int choice[8];

	//Tổng số khả năng đi
	int sumPos;
	//Số nước đi có thể đi, trừ đi những nước các quân mã khác đã chạy qua
	int Possible();
	//Tìm nước đi tiếp theo ít khả năng nhất
	knight2 Heuristic();
	void printFile();
};
void menu();
#endif