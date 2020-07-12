#include "knight.h"
using namespace std;

////////////////////////////////////////////////////////////////////////////////
/*Class "knight"*/
// Bước đi tiếp theo của quân mã
int nr_move, nc_move;

/*Tọa độ tương ứng nước đi tiếp theo của quân mã sử dụng trong hàm "canMove"*/
const int x_inc[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int y_inc[8] = {1, -1, 2, -2, -2, 2, -1, 1};

// Hàm khởi tạo bàn cờ với vị trí bắt đầu được nhập từ bàn phím
knight::knight(int row, int col)
{
	count = 1;
	curr_row = start_row;
	curr_col = start_col;
	for (int row = 0; row < board_size; row++)
	{
		for (int col = 0; col < board_size; col++)
		{
			knight_square[row][col] = 0;
		}
	}
	knight_square[curr_row][curr_col] = count;
	count++;
}

// Hàm thêm vị trí của quân mã vào bàn cờ
void knight::insert(int row, int col)
{
	cout << "Step number " << count << " is: "
		 << "(" << row << "," << col << ")" << endl;
	knight_square[row][col] = count;
	curr_row = row;
	curr_col = col;
	count++;
}

// Hàm in kết quả ra màn hình console
void knight::print()
{
	for (int row = 0; row < board_size; row++)
	{
		cout << "\t\t\t\t\t";
		for (int col = 0; col < board_size; col++)
		{
			cout << "|" << setw(3) << knight_square[row][col];
			if (col == 7)
				cout << endl;
		}
	}
}

// Hàm in kết quả ra file "out.txt"
void knight::print_file()
{
	fstream out;
	out.open("output.txt", ios_base::out | ios_base::app);
	out << "Random walk solution: " << endl;
	out << "The Knight start at (" << start_row << "," << start_col << ")";
	out << " end at (" << curr_row << "," << curr_col << ")" << endl;
	out << "Go thurough " << (count - 1) << " steps!" << endl;
	for (int row = 0; row < board_size; row++)
	{
		out << "\t\t\t\t\t";
		for (int col = 0; col < board_size; col++)
		{
			out << "|" << setw(3) << knight_square[row][col];
			if (col == 7)
				out << "\n";
		}
	}
	out.close();
}

/*Hàm kiểm tra bước đi được chọn bởi thuật toán có hợp lệ hay không.
Nếu bước đi hợp lệ trả về "true" và ngược lại trả về "false"*/
bool knight::isMove(int row, int col)
{
	if (row < 0 || row >= board_size)
		return false;
	else if (col < 0 || col >= board_size)
		return false;
	else if (knight_square[row][col] != 0)
		return false;
	else
		return true;
}

/*Hàm kiểm tra quân mã có thể tiếp tục đi tiếp hay không.
Nếu có 1 trong 8 khả năng có thể đi tiếp trả về "true", ngược lại trả về "false"*/
bool knight::canMove(int row, int col)
{
	for (int i = 0; i < 8; i++)
	{
		if ((row + x_inc[i]) >= 0 && (col + y_inc[i]) >= 0 &&
			(row + x_inc[i]) < board_size && (col + y_inc[i]) < board_size && knight_square[row + x_inc[i]][col + y_inc[i]] == 0)
			return true;
	}
	return false;
}

/*Hàm thực hiện hành trình của quân mã dựa vào thuật toán ngẫu nhiên*/
void knight::moveTheKnight()
{
	while (canMove(curr_row, curr_col))
	{

		int randommove = 1 + rand() % 8;
		switch (randommove)
		{
		case 1:
			firstMoveChoice(curr_row, curr_col);
			break;
		case 2:
			secondMoveChoice(curr_row, curr_col);
			break;
		case 3:
			thirdMoveChoice(curr_row, curr_col);
			break;
		case 4:
			fourthMoveChoice(curr_row, curr_col);
			break;
		case 5:
			fifthMoveChoice(curr_row, curr_col);
			break;
		case 6:
			sixthMoveChoice(curr_row, curr_col);
			break;
		case 7:
			seventhMoveChoice(curr_row, curr_col);
			break;
		case 8:
			eighthMoveChoice(curr_row, curr_col);
			break;
		default:
			cout << "No more possible moves! " << endl;
		}
	}
	if (count == 64)
	{
		cout << "complete!" << endl;
	}
	else
	{
		cout << "Cannot find close tour!" << endl;
	}
}

/*Một quân mã trên bàn cờ có tối đa 8 khả năng có thể đi tiếp
các hàm sau mô tả từng khả năng có thể xảy ra(firstMoveChoice->eighthMoveChoice)*/

/*Khả năng thứ nhất trong 8 khả năng có thể đi của quân mã*/
void knight::firstMoveChoice(int row, int col)
{
	nr_move = 1;
	nc_move = 2;

	/*Kiểm tra bước đi có hợp lệ hay không. Nếu bước đi là hợp lệ
	tiến hành thêm bước đi vào bàn cờ*/
	if (isMove(row + nr_move, col + nc_move))
	{
		curr_row = row + nr_move;
		curr_col = col + nc_move;
		insert(curr_row, curr_col);
	}
}

/*Khả năng thứ 2 trong 8 khả năng có thể đi của quân mã*/
void knight::secondMoveChoice(int row, int col)
{
	nr_move = 2;
	nc_move = 1;

	if (isMove(row + nr_move, col + nc_move))
	{
		curr_row = row + nr_move;
		curr_col = col + nc_move;
		insert(curr_row, curr_col);
	}
}

/*Khả năng thứ 3 trong 8 khả năng có thể đi của quân mã*/
void knight::thirdMoveChoice(int row, int col)
{
	nr_move = 2;
	nc_move = -1;

	if (isMove(row + nr_move, col + nc_move))
	{
		curr_row = row + nr_move;
		curr_col = col + nc_move;
		insert(curr_row, curr_col);
	}
}

/*Khả năng thứ 4 trong 8 khả năng có thể đi của quân mã*/
void knight::fourthMoveChoice(int row, int col)
{
	nr_move = 1;
	nc_move = -2;

	if (isMove(row + nr_move, col + nc_move))
	{
		curr_row = row + nr_move;
		curr_col = col + nc_move;
		insert(curr_row, curr_col);
	}
}

/*Khả năng thứ 5 trong 8 khả năng có thể đi của quân mã*/
void knight::fifthMoveChoice(int row, int col)
{
	nr_move = -1;
	nc_move = -2;

	if (isMove(row + nr_move, col + nc_move))
	{
		curr_row = row + nr_move;
		curr_col = col + nc_move;
		insert(curr_row, curr_col);
	}
}

/*Khả năng thứ 6 trong 8 khả năng có thể đi của quân mã*/
void knight::sixthMoveChoice(int row, int col)
{
	nr_move = -2;
	nc_move = -1;

	if (isMove(row + nr_move, col + nc_move))
	{
		curr_row = row + nr_move;
		curr_col = col + nc_move;
		insert(curr_row, curr_col);
	}
}

/*Khả năng thứ 7 trong 8 khả năng có thể đi của quân mã*/
void knight::seventhMoveChoice(int row, int col)
{
	nr_move = -2;
	nc_move = 1;

	if (isMove(row + nr_move, col + nc_move))
	{
		curr_row = row + nr_move;
		curr_col = col + nc_move;
		insert(curr_row, curr_col);
	}
}

/*Khả năng cuối trong 8 khả năng có thể đi của quân mã*/
void knight::eighthMoveChoice(int row, int col)
{
	nr_move = -1;
	nc_move = 2;

	if (isMove(row + nr_move, col + nc_move))
	{
		curr_row = row + nr_move;
		curr_col = col + nc_move;
		insert(curr_row, curr_col);
	}
}
////////////////////////////////////////////////////////////////////////////////

/*Class knight2*/

//Các vị trí mã có thể chạy qua, phải kết hợp với vị trí hàng và cột của quân mã
const int y[] = {-1, -2, -2, -1, 1, 2, 2, 1},
		  x[] = {2, 1, -1, -2, -2, -1, 1, 2};

//Hàm Possible() trả về số khả năng đi, trong đó đã bỏ qua vị trí những quân mã khác trên bàn cờ đã đi
//Hàm tìm số khả năng có thể đi trong 8 khả năng
int knight2::Possible()
{
	sumPos = 0;
	for (int i = 0; i < 8; i++)
	{ //Nếu vị trí quân mã chạy qua (Kết hợp hàng, cột với x, y trên) không âm (ra khỏi bàn cờ) &&&& vị trí đó chưa có quân mã nào chạy qua trên bàn cờ
		if (((r + y[i] >= 0) && (r + y[i] <= 8 - 1)) && ((c + x[i] >= 0) && (c + x[i] <= 8 - 1) && (board[r + y[i]][c + x[i]] == 0)))
		{
			//Vị trí những nước có thể đi, giá trị này dùng để lấy ra vị trí từ y và x thỏa mãn điều kiện trên
			choice[sumPos] = i;
			sumPos++;
			//Thì ta xem như đó là 1 khả năng
		}
	}
	//Trả về tổng số khả năng
	return sumPos;
}

/*Hàm Heuristic() trả về 1 quân mã lưu vị trí tiếp theo mà quân mã đã gọi hàm này sẽ đi, vị trí này có ít khả năng đi nhất, trong đó đã loại trừ vị trí cũ mà quân mã trước đó 
đã đi*/
//Tìm nước đi tiếp theo ít khả năng nhất
knight2 knight2::Heuristic()
{
	Possible();
	//Tạo mảng quân mã có kích thước bằng với số khả năng đi
	knight2 knightArr[8];
	//Lấy khả năng đi đầu tiên là vị trí có ít khả năng đi nhất
	knightArr[0].r = r + y[choice[0]];
	knightArr[0].c = c + x[choice[0]];
	knightArr[0].Possible();

	for (int i = 1; i < sumPos ; i++)
	{
		//Lấy phần tử vị trí quân mã có thể đi tiếp theo, kiểm tra xem có ít khả năng hơn vị trí quân mã lúc đầu không
		knightArr[i].r = r + y[choice[i]];
		knightArr[i].c = c + x[choice[i]];
		knightArr[i].Possible();
		if (knightArr[0].sumPos >= knightArr[i].sumPos)
		{
			knightArr[0] = knightArr[i];
		}
	}
	//Trả về vị trí quân mã đi qua mà vị trí đó có ít khả năng đi nhất
	return knightArr[0];
}

// Hàm in kết quả ra file "out.txt"
void knight2::printFile()
{
	fstream out;
	out.open("output.txt", ios_base::out | ios_base::app);
	out << "Heuristic solution: " << endl;
	out << "The Knight start at (" << start_row << "," << start_col << ")";
	out << " end at (" << r << "," << c << ")" << endl;
	for (int r = 0; r < 8; r++)
	{
		out << "\t\t\t\t\t";
		for (int c = 0; c < 8; c++)
		{
			out << "|" << setw(3) << board[r][c];
		}
		out << "\n";
	}
	out.close();
}
void menu()
{
	cout << "\t\t*******************************************************************" << endl;
	cout << "\t\t                                MENU                               " << endl;
	cout << "\t\t*******************************************************************" << endl;
	cout << "\t\t1. Move the knight randomly." << endl;
	cout << "\t\t2. Move the knight to the square with the least ability moves" << endl;
	cout << "\t\t3. Exit" << endl;
	cout << "\t\t*******************************************************************" << endl;
}
