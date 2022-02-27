#pragma once
#include <vector>
#include <string>
class Tiktak_board {
    std::vector<int> board = { 3,3,3,3,3,3,3,3,3 };
    int winner;
    std::vector<bool> open = { true, true, true, true, true, true, true, true, true };
public:
    int next_up;
    Tiktak_board();
    bool input(int x, int y, int in);
    int get_winner();
    bool openslots();
    void checkforwin(int x);
    void render_board();

};