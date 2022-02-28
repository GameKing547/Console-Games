#include "Main.h"
Tiktak_board::Tiktak_board() {
    next_up = 0;
    winner = 4;
};
bool Tiktak_board::input(int x, int y, int in) {
    bool good;
    if (x > 3 || y > 3) {
        good = false;
        return good;
    }
    if (open[(3 * (y - 1) + x - 1)] == true) {
        board[(3 * (y - 1) + x - 1)] = in;
        open[(3 * (y - 1) + x - 1)] = false;
        good = true;
        checkforwin(in);
        next_up++;
        if (next_up > 1) {
            next_up = 0;
        };
    }
    else {
        good = false;
    }
    return good;
};
int Tiktak_board::get_winner() {
    return winner;
};
bool Tiktak_board::openslots() {
    bool pen = false;
    for (int i = 0; i < 9; i++) {
        if (open[i] == true) {
            pen = true;
        }
    }
    return pen;
}
void Tiktak_board::checkforwin(int x) {
    if (board[0] == board[1] && board[1] == board[2] && board[0] != 3) {
        winner = board[0];
    }
    else if (board[3] == board[4] && board[4] == board[5] && board[3] != 3) {
        winner = x;
    }
    else if (board[6] == board[7] && board[7] == board[8] && board[6] != 3) {
        winner = x;
    }
    else if (board[0] == board[3] && board[3] == board[6] && board[0] != 3) {
        winner = x;
    }
    else if (board[1] == board[4] && board[4] == board[7] && board[1] != 3) {
        winner = x;
    }
    else if (board[2] == board[5] && board[5] == board[8] && board[2] != 3) {
        winner = x;
    }
    else if (board[0] == board[4] && board[4] == board[8] && board[0] != 3) {
        winner = x;
    }
    else if (board[2] == board[4] && board[4] == board[6] && board[2] != 3) {
        winner = x;
    }
    else if (openslots() == false) {
        winner = 3;
    };
}

void Tiktak_board::render_board() {
    std::vector<char> aboard(9);
    for (int i = 0; i < 9; i++) {
        if (board[i] == 0) {
            aboard[i] = 'o';
        }
        else if (board[i] == 1) {
            aboard[i] = 'x';
        } else if (board[i] == 3) {
            aboard[i] = ' ';
        }
    }
    std::cout << aboard[0] << "|" << aboard[1] << "|" << aboard[2] << "\n";
    std::cout << "-+-+-\n";
    std::cout << aboard[3] << "|" << aboard[4] << "|" << aboard[5] << "\n";
    std::cout << "-+-+-\n";
    std::cout << aboard[6] << "|" << aboard[7] << "|" << aboard[8] << "\n";
}