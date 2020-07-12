#include "knight.h"
#include "knight.cpp"

using namespace std;

int main()
{
    srand(time(NULL));
    int t;
    do
    {

        menu();
        cout << "Pick from choices 1, 2, or 3, depending on what you want from the menu: ";
        cin >> t;
        switch (t)
        {
        case 1:
        {
            // Nhập vị trí quân mã đầu tiên
            cout << "Enter the start position for the row: ";
            cin >> start_row;
            cout << "Enter the start position for the col: ";
            cin >> start_col;
            // Khởi tạo bàn cờ với vị trị quân mã đầu tiên
            knight tour(start_row, start_col);
            // Tìm đường đi ngẫu nhiên của quân mã
            tour.moveTheKnight();
            tour.print();
            tour.print_file();
            break;
        }
        case 2:
        {
            int count = 0;
            knight2 horse;
            // Nhập vị trí quân mã đầu tiên
            cout << "Enter the start position for the row: ";
            cin >> start_row;
            cout << "Enter the start position for the col: ";
            cin >> start_col;
            cout << endl;
            
            //Quân mã đầu tiên trên bàn cờ ở vị trí đã nhập
            horse.r = start_row; 
            horse.c = start_col;

            while (count < 64)
            {
                //Tăng thứ tự nước đi
                count++;                         
                board[horse.r][horse.c] = count; //Ghi thứ tự quân mã tiếp theo đi trên bàn cờ tại vị trí quân mã đó
                if (count != 64)
                    horse = horse.Heuristic(); //Tìm vị trí đi tiếp theo, không trùng vị trí cũ của quân mã trước và những vị trí quân mã khác đã đi qua
            }

            //In ra bàn cờ với thứ tự từng nước đi
            for (int r = 0; r < 8; r++)
            {
                cout << "\t\t\t\t\t";
                for (int c = 0; c < 8; c++)
                {
                    cout << "|" << setw(3) << board[r][c];
                }
                cout << "\n";
            }
            horse.printFile();
            for (int i = 0; i < 8;i++ )
            {
                for (int j = 0; j < 8;j++)
                {
                    board[i][j] = 0;
                }
            }
            break;
        }
        default:
            break;
        }
        cout << "\t\t/////////////////////////////////////////////////////////////////////" << endl;
    } while (t != 3);
    return 0;
}
