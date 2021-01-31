#include "Logic.h"

vector<vector<vector<TileType>>> getGuesses(vector<vector<TileType>> knownBoard, vector<IndexPair> frontierIndexes)
{
    vector<vector<vector<TileType>>> guesses;

    auto guessVector = knownBoard;
    int indexIntoFrontierIndexes = 0;
    while (true)
    {
        auto row = frontierIndexes[indexIntoFrontierIndexes].row;
        auto col = frontierIndexes[indexIntoFrontierIndexes].col;
        auto tile = guessVector[row][col];

        // Update with new guess
        // Unknown
        if (std::holds_alternative<Unknown>(tile))
        {
            guessVector[row][col] = GuessMine{};
        }
        // GuessMine
        else if (std::holds_alternative<GuessMine>(tile))
        {
            guessVector[row][col] = GuessNotMine{};
        }
        // GuessNotMine
        else if (std::holds_alternative<GuessNotMine>(tile))
        {
            guessVector[row][col] = Unknown{};
        }

        tile = guessVector[row][col];

        // We have to go back to the previous frontier value and change that since we have run out of options for this tile
        if (tile.index() == 1)
        {
            // We have searched all possible combinations for the entire frontier
            if (indexIntoFrontierIndexes == 0)
            {
                break;
            }

            indexIntoFrontierIndexes--;
            continue;
        }
        // This value looks promising
        else if (guessIsOk(guessVector, row, col))
        {
            if (indexIntoFrontierIndexes < frontierIndexes.size() - 1)
            {
                // Continue to the next frontier value
                indexIntoFrontierIndexes++;
                continue;
            }
        }
        // We have not tried everything for this tile so we go back to this value again
        else
        {
            continue;
        }

        // We made it through the frontier so this is a possible guess for all the frontier values
        if (indexIntoFrontierIndexes == frontierIndexes.size() - 1)
        {
            auto copiedVector = guessVector;
            guesses.push_back(copiedVector);
            // Now we go back again
            guessVector[row][col] = Unknown{};
            indexIntoFrontierIndexes--;
        }
    }

    return guesses;
}

bool guessIsOk(vector<vector<TileType>> guessBoard, int row, int col)
{
    // Go through all the neighbors for this new guess
    auto neighborIndexes = getNeighborIndexes(row, col, guessBoard.size());
    for (auto indexPair : neighborIndexes)
    {
        // If the neighbor is a number we need to make sure this new guess is not disqualified by this number
        auto tile = guessBoard[indexPair.row][indexPair.col];
        if (std::holds_alternative<Number>(tile))
        {
            auto number = std::get<Number>(tile);

            auto mines = 0;
            auto unknowns = 0;

            // We check the neighbors of the guess's neighbor to make sure to make sure the number of mines added to the number of unknowns is different from what this number says
            auto checkNeighborIndexes = getNeighborIndexes(indexPair.row, indexPair.col, guessBoard.size());
            for (auto checkIndexPair : checkNeighborIndexes)
            {
                auto checkTile = guessBoard[checkIndexPair.row][checkIndexPair.col];
                if (std::holds_alternative<Mine>(checkTile) || std::holds_alternative<GuessMine>(checkTile))
                {
                    mines++;
                }
                else if (std::holds_alternative<Unknown>(checkTile))
                {
                    unknowns++;
                }
            }

            if (mines > number.num || mines + unknowns < number.num)
            {
                return false;
            }
        }
    }

    return true;
}

vector<IndexPair> getFrontierIndexes(vector<vector<TileType>> knownBoard)
{
    vector<IndexPair> frontierIndexes;
    for (int row = 0; row < knownBoard.size(); row++)
    {
        auto knownBoardRow = knownBoard[row];
        for (int col = 0; col < knownBoardRow.size(); col++)
        {
            auto tileType = knownBoardRow[col];
            // Unknown
            if (std::holds_alternative<Unknown>(tileType))
            {
                auto neighborIndexes = getNeighborIndexes(row, col, knownBoard.size());
                for (auto indexPair : neighborIndexes)
                {
                    auto neighborTile = knownBoard[indexPair.row][indexPair.col];
                    // Number
                    if (std::holds_alternative<Number>(neighborTile))
                    {
                        frontierIndexes.push_back(IndexPair(row, col));
                        break;
                    }
                }
            }

        }
    }
    return frontierIndexes;
}

vector<IndexPair> getNeighborIndexes(int row, int col, int size)
{
    vector<IndexPair> neighborIndexes;
    if (row > 0)
    {
        neighborIndexes.push_back(IndexPair(row - 1, col));
    }
    if (row < size - 1)
    {
        neighborIndexes.push_back(IndexPair(row + 1, col));
    }
    if (col > 0)
    {
        neighborIndexes.push_back(IndexPair(row, col - 1));
    }
    if (col < size - 1)
    {
        neighborIndexes.push_back(IndexPair(row, col + 1));
    }
    if (row > 0 && col > 0)
    {
        neighborIndexes.push_back(IndexPair(row - 1, col - 1));
    }
    if (row > 0 && col < size - 1)
    {
        neighborIndexes.push_back(IndexPair(row - 1, col + 1));
    }
    if (row < size - 1 && col > 0)
    {
        neighborIndexes.push_back(IndexPair(row + 1, col - 1));
    }
    if (row < size - 1 && col < size - 1)
    {
        neighborIndexes.push_back(IndexPair(row + 1, col + 1));
    }

    return neighborIndexes;
}
