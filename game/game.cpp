#include <iostream>
#include "game.h"

void Game::displayMap()
{
    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            std::cout << m_map[x][y] << "" <<" | ";
        }
        std::cout << std::endl;
    }
}

void Game::playTurn()
{
    char a;
    int dx, dy;
    std::cout << "Joueur actif : " << m_player << std::endl;
    std::cout << "----------------------" << std::endl;
    std::cout << "Choisissez une case :" << std::endl;
    std::cin >> a;
    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            if (a == m_map[x][y])
            {
                m_map[x][y] = m_player;
                dx = x;
                dy = y;
            }
        }
    }
    winCheck(dx, dy);
    switchPlayer();
    clearConsole();
}

void Game::winCheck(int dx, int dy)
{
    int xcol = 0, xrow = 0, xdiag = 0, xrdiag = 0;
    for (int i = 0; i < 3; i++)
    {
        if (m_map[dx][i] == m_player)
        {
            xcol++;
        }else if (m_map[i][dy] == m_player)
        {
            xrow++;
        }else if (m_map[i][i] == m_player)
        {
            xdiag++;
        } 
    }
    for (int i = 3; i > 0; i--)
    {
        if (m_map[i][i] == m_player)
        {
            xrdiag++;
        } 
    }
    if (xcol == 3 || xrow == 3 || xdiag == 3 || xrdiag == 3)
    {
        std::cout << " Le joueur " << m_player << " remporte la partie !" << std::endl;
        end_game = true;
    }
    
    if(debug)
    {
        std::cout << "xcol:" << xcol << "xrow:" << xrow << "xdiag:" << xdiag << "xrdiag:" << xrdiag << std::endl;
    }
}

void Game::runGame()
{
    while(!end_game)
    {
        displayMap();
        playTurn();
    }
}

void Game::clearConsole()
{
    for (int i = 0; i < 20; i++)
    {
        std::cout << " " << std::endl;
    }
    
}

void Game::switchPlayer()
{
    if (m_player == 'X')
    {
        m_player = 'O';
    }else
    {
        m_player = 'X';
    }
}