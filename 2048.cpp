#include <cstdio>
#include <iostream>
#include <random>
#include <string>
#include <cstdlib>


void print_board(int board[][4]) {
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            printf("%d ", board[row][col]);
        }
        printf("\n");
    }
}


void spawn(int board[][4]) {
    int choices[] = {2, 4};

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distribution(0, 3);
    std::uniform_int_distribution<> distribution2(0, 1);


    while (true) {
        int row = distribution(gen);
        int col = distribution(gen);

        // printf("%d %d\n", row, col);
        if (board[row][col] == 0) {
            int choice = distribution2(gen);
            board[row][col] = choices[choice];
            break;
        }
    }
}


void move_up(int board[][4]) {
    for (int row = 3; row > 0; row--) {
        for (int col = 0; col < 4; col++) {
            if (board[row - 1][col] == board[row][col]) {
                printf(".\b");
                board[row - 1][col] += board[row][col];
                board[row][col] = 0;
            } else if (board[row - 1][col] == 0) {
                board[row - 1][col] = board[row][col];
                board[row][col] = 0;
            }
        }
    }
}

void move_down(int board[][4]) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 4; col++) {
            if (board[row + 1][col] == board[row][col]) {
                board[row + 1][col] += board[row][col];
                board[row][col] = 0;
            } else if (board[row + 1][col] == 0) {
                board[row + 1][col] = board[row][col];
                board[row][col] = 0;
            }
        }
    }
}


void move_left(int board[][4]) {
    for (int col = 1; col < 4; col++) {
        for (int row = 0; row < 4; row++) {
            if (board[row][col - 1] == board[row][col]) {
                board[row][col - 1] += board[row][col];
                board[row][col] = 0;
            }

            int col2 = col;

            while (board[row][col2 - 1] == 0 && col2 > 0) {
                board[row][col2 - 1] = board[row][col2];
                board[row][col2] = 0;
                col2 --;
            }
        }
    }
}


void move_right(int board[][4]) {
    for (int col = 0; col < 3; col++) {
        for (int row = 0; row < 4; row++) {
            if (board[row][col + 1] == board[row][col]) {
                board[row][col + 1] += board[row][col];
                board[row][col] = 0;
            }

        }
    }

    for (int col = 3; col > 0; col--) {
        for (int row = 0; row < 4; row++) {
            int col2 = col;
            printf("%d", row);
            while (board[row][col2 + 1] == 0 && col2 > 0) {
                board[row][col2 + 1] = board[row][col];
                board[row][col2] = 0;

                col2--;
            }
        }
    }
}


int main() {
    int board[4][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };

    system("clear");

    spawn(board);
    spawn(board);
    print_board(board);

    while (true) {
        std::string dir; std::cin >> dir;

        if (dir == "w") { // up
            move_up(board);
        } else if (dir == "s") { // down
            move_down(board);
        } else if (dir == "a") { // left
            move_left(board);
        } else if (dir == "d") {
            move_right(board);
        }

        spawn(board);
        system("clear");
        print_board(board);
    }
}

