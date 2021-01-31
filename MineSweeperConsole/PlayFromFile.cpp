#include <fstream>
#include <iostream>
#include <Windows.h>
#include "Logic.h"

using namespace std;

void PlayFromFile()
{


    while (true)
    {
        
        if (GetKeyState('C') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
        {
            ifstream readFile("readFile.txt");
            if (readFile.is_open())
            {
                vector<vector<TileType>> board;
                string line;
                getline(readFile, line);
                auto minesLeft = stoi(line);
                while (getline(readFile, line))
                {
                    vector<TileType> boardRow;
                    for (auto c : line)
                    {
                        if (c == '\n' || c == '\s')
                        {
                            continue;
                        }
                        if (c == Blank{}.toString().c_str()[0])
                        {
                            boardRow.push_back(Blank{});
                        }
                        else if (c == UnknownTile{}.toString().c_str()[0])
                        {
                            boardRow.push_back(UnknownTile{});
                        }
                        else if (c == Mine{}.toString().c_str()[0])
                        {
                            boardRow.push_back(Mine{});
                        }
                        else
                        {
                            int num = c - '0';
                            if (num >= 1 && num <= 8)
                            {
                                boardRow.push_back(Number(num));
                            }
                        }
                    }
                    board.push_back(boardRow);
                }
                readFile.close();

                bool symmetrical = true;
                for (auto boardRow : board)
                {
                    if (boardRow.size() != board.size())
                    {
                        cout << "The matrix has to be symmetrical\n";
                        symmetrical = false;
                    }
                }
                if (!symmetrical)
                {
                    continue;
                }

                auto newGuessBoard = getNewGuessBoard(board, minesLeft);

                ofstream writeFile;
                writeFile.open("writeFile.txt", ios::out | ios::trunc);
                if (writeFile.is_open())
                {
                    for (auto guessBoardRow : newGuessBoard)
                    {
                        for (auto guessBoardTile : guessBoardRow)
                        {
                            if (std::holds_alternative<UnknownTile>(guessBoardTile))
                            {
                                writeFile << UnknownTile{}.toString();
                            }
                            else if (std::holds_alternative<Blank>(guessBoardTile))
                            {
                                writeFile << Blank{}.toString();
                            }
                            else if (std::holds_alternative<Mine>(guessBoardTile))
                            {
                                writeFile << Mine{}.toString();
                            }
                            else if (std::holds_alternative<GuessMine>(guessBoardTile))
                            {
                                writeFile << GuessMine{}.toString();
                            }
                            else if (std::holds_alternative<GuessNotMine>(guessBoardTile))
                            {
                                writeFile << GuessNotMine{}.toString();
                            }
                            else if (std::holds_alternative<Number>(guessBoardTile))
                            {
                                auto number = std::get<Number>(guessBoardTile);
                                writeFile << number.num;

                            }
                        }
                        writeFile << "\n";
                    }
                    cout << "Check writeFile.txt";
                }
                else
                {
                    cout << "Failed to open writeFile.txt\n";
                }
                writeFile.close();
            }
            else
            {
                cout << "Failed to open readFile.txt\n";
            }
        }

    }
}