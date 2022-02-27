#include "tiktak.h"
#include <iostream>
using namespace std;

void tiktaktoe() {
    int x;
    int y;

    Tiktak_board game;
    cout << "Tik-Tak-Toe Time\n";
    while (game.get_winner() == "No" && game.openslots() == true) {
        game.render_board();
    inputl:
        cout << "Player" << (game.next_up + 1) << "\n";
        cin >> x;
        cin >> y;
        if (game.input(x, y, game.next_up) != true) {
            cout << "Error Try again\n";
            goto inputl;
        }
    };
    if (game.get_winner() == "Tie") {
        cout << "Tie\n";
    } else if (game.get_winner() == "0") {
        cout << "Player 1 Wins!";
    } else if (game.get_winner() == "1") {
        cout << "Player 2 Wins!";
    }
};



int main() {
    bool has_quit = false;
    string response;
    cout << "What game do you want to play?\n";
    cin >> response;
    if (response == "Nothing") {
        return 0;
    }
    else if (response == "Tiktaktoe") {
        tiktaktoe();
    }
}
