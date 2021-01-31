// MineSweeperConsole.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <variant>

using namespace std;

struct Blank{};
struct Unknown{};
struct Mine{};
struct GuessMine{};
struct GuessNotMine{};
struct Number { int num; };
using TileType = std::variant<Blank, Unknown, Mine, GuessMine, GuessNotMine, Number>;


int main()
{
    int size = 9;
    vector<vector<TileType>> board;

    for (int row = 0; row < size; row++)
    {
        vector<TileType> boardRow;
        for (int column = 0; column < size; column++)
        {
            boardRow.push_back(Unknown{});
        }
        board.push_back(boardRow);
    }

    std::cout << "Hello World!\n";

}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
