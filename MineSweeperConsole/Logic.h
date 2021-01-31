#pragma once

#include <vector>
#include <variant>
#include <string>

using namespace std;

struct Blank
{
    bool operator==(const Blank& pair)
    {
        return true;
    }

    std::string toString()
    {
        return "B";
    }
};
struct Unknown
{
    bool operator==(const Unknown& pair)
    {
        return true;
    }

    std::string toString()
    {
        return "U";
    }
};
struct Mine
{
    bool operator==(const Mine& pair)
    {
        return true;
    }

    std::string toString()
    {
        return "M";
    }
};
struct GuessMine
{
    bool operator==(const GuessMine& pair)
    {
        return true;
    }

    std::string toString()
    {
        return "G";
    }
};
struct GuessNotMine
{
    bool operator==(const GuessNotMine& pair)
    {
        return true;
    }

    std::string toString()
    {
        return "N";
    }
};
struct Number
{
    int num; 
    Number(int n)
    {
        num = n;
    }

    bool operator==(const Number& number)
    {
        return (num == number.num);
    }

    std::string toString()
    {
        return std::to_string(num);
    }
};
using TileType = std::variant<Blank, Unknown, Mine, GuessMine, GuessNotMine, Number>;

struct IndexPair
{
    int row;
    int col;

    IndexPair(int r, int c)
    {
        row = r;
        col = c;
    }

    bool operator==(const IndexPair& pair)
    {
        return (row == pair.row && col == pair.col);
    }
};

vector<vector<TileType>> getNewGuessBoard(vector<vector<TileType>> knownBoard);

vector<vector<TileType>> mergeGuesses(vector<vector<vector<TileType>>> guesses, vector<IndexPair> frontierIndexes, vector<vector<TileType>> knownBoard);

vector<vector<vector<TileType>>> getGuesses(vector<vector<TileType>> knownBoard, vector<IndexPair> frontierIndexes);

bool guessIsOk(vector<vector<TileType>> guessBoard, int row, int col);

vector<IndexPair> getFrontierIndexes(vector<vector<TileType>> knownBoard);

vector<IndexPair> getNeighborIndexes(int row, int col, int size);