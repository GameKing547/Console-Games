#include "Main.h"
using namespace std;

void tiktaktoe() {
    int x;
    int y;

    Tiktak_board game;
    cout << "Tik-Tak-Toe Time\n";
    while (game.get_winner() == 4 && game.openslots() == true) {
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
    if (game.get_winner() == 3) {
        game.render_board();
        cout << "Tie\n";
    } else if (game.get_winner() == 0) {
        game.render_board();
        cout << "Player 1 Wins!\n";
    } else if (game.get_winner() == 1) {
        game.render_board();
        cout << "Player 2 Wins!\n";
    }
};
void rph() {
    Rps_board game;
    game.playround("Rock");
}
int pickgame(bool &quit) {
     string response;
    cout << "What game do you want to play?\n";
ask:
    cin >> response;
    if (response == "Nothing") {
        quit = true;
        return 0;
    }
    else if (response == "Tiktaktoe") {
        tiktaktoe();
        quit = false;
        return 0;
    }
    else if (response == "Rock-Paper-Scissors") {
        rph();
        quit = false;
        return 0;
    } else {
        cout << "Sorry I didnt understand that could you try again?\n";
        goto ask;
    }
}



int main() {
    bool quitgame;// = false;
    string input;
askgame:
    pickgame(quitgame);
    if (quitgame == true) {
        return 0;
    }
        cout << "Want to play again?\n";
ask_to_play_again:
    cin >> input;
    if (input == "Yes") {
        goto askgame;
    }
    else if (input == "No") {
        return 0;
    }
    else {
        cout << "Sorry I didnt understand that could you try again?\n";
        goto ask_to_play_again;
    };

}
