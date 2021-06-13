#include <iostream>
#include <iomanip>

using namespace std;

/*   __    __
    |        |     |        |                    ___    ___
    |   or   | or |__ or __| or |___ or ___| or |    or    |
*/

const unsigned POSSIBLE_SIZE = 8;

const int possible_x[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
const int possible_y[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

void print_solution(int **, size_t);
bool check_on_board(int, int, int **, size_t);
bool knight_tour_sol(int, int, int **, int, size_t);

int main()
{
  size_t n = 0;
  while (n < 3) {
    cout << "Input the number: ";
    cin >> n;
  }

  int **board;

  board = new int * [n];
 

  // Initialize
  for (size_t i = 0; i < n; i++) {
    board[i] = new int[n];
    for (size_t j = 0; j < n; j++) board[i][j] = -1;
  }

  board[0][0] = 0;

  if (knight_tour_sol(0, 0, board, 1, n) == 0) 
    cout << endl << "No solutions.";
  else 
    print_solution(board, n);

  delete [] board[n];
  return 0;
}

bool check_on_board(int x, int y, int **board, size_t n) {
  return x >= 0 && x < n && y >= 0 &&  y < n && board[x][y] == -1;
}

bool knight_tour_sol(int sx, int sy, int **board, int moven, size_t n) {
  if (moven == n * n) return 1;

  for (int i = 0; i < POSSIBLE_SIZE; i++) {
    int nx = sx + possible_x[i];
    int ny = sy + possible_y[i];
    if (check_on_board(nx, ny, board, n)) {
      board[nx][ny] = moven;
      if (knight_tour_sol(nx, ny, board, moven + 1, n)) {
        return 1;
      }
      else board[nx][ny] = -1;
    }
  }

  return 0;
}

int num_size(size_t n) {
  int c;
  for (c = 0;n % 10 != 0; n /= 10, c++);
  return c;
}


void print_solution(int **board, size_t n) {
  int ns = num_size(n);
  for (int i = 0; i < n; i++) {
    cout << endl;
    for (int j = 0; j < n; j++)
      cout << right << setw(ns < 3 ? 3 : ns + 1) << board[i][j];
      // printf("%3d", board[i][j]);
  }
  cout << endl;
}