#ifndef GAME_H
#define GAME_H

class Game
{
    public:
    Game() = default;
    void displayMap();
    void playTurn();
    void runGame();
    void clearConsole();
    void switchPlayer();
    void winCheck(int dx, int dy);

    private:
    char m_player = 'X';
    char m_map[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    bool end_game = false;
    bool debug = true;
};

#endif // GAME_H