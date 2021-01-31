#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include "../MineSweeperConsole/Logic.h"
#include "../MineSweeperConsole/Logic.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(getNeighborIndexes1)
		{
			auto indexPairs = getNeighborIndexes(2, 3, 9);
			Assert::AreEqual((int) indexPairs.size(), 8);
			Assert::IsTrue(std::count(indexPairs.begin(), indexPairs.end(), IndexPair(1, 3)));
			Assert::IsTrue(std::count(indexPairs.begin(), indexPairs.end(), IndexPair(3, 3)));
			Assert::IsTrue(std::count(indexPairs.begin(), indexPairs.end(), IndexPair(2, 2)));
			Assert::IsTrue(std::count(indexPairs.begin(), indexPairs.end(), IndexPair(2, 4)));
			Assert::IsTrue(std::count(indexPairs.begin(), indexPairs.end(), IndexPair(1, 2)));
			Assert::IsTrue(std::count(indexPairs.begin(), indexPairs.end(), IndexPair(1, 4)));
			Assert::IsTrue(std::count(indexPairs.begin(), indexPairs.end(), IndexPair(3, 2)));
			Assert::IsTrue(std::count(indexPairs.begin(), indexPairs.end(), IndexPair(3, 4)));
		}

		TEST_METHOD(getNeighborIndexes2)
		{
			auto indexPairs = getNeighborIndexes(0, 8, 9);
			Assert::AreEqual((int)indexPairs.size(), 3);
			Assert::IsTrue(std::count(indexPairs.begin(), indexPairs.end(), IndexPair(0, 7)));
			Assert::IsTrue(std::count(indexPairs.begin(), indexPairs.end(), IndexPair(1, 7)));
			Assert::IsTrue(std::count(indexPairs.begin(), indexPairs.end(), IndexPair(1, 8)));
		}

		TEST_METHOD(getFrontierIndexes1)
		{
			vector<vector<TileType>> board{ {Blank{}, Number(1), UnknownTile{}},
											{Blank{}, Number(1), UnknownTile{}},
											{Blank{}, Number(1), Number(1)} };
			auto indexPairs = getFrontierIndexes(board);
			Assert::AreEqual((int)indexPairs.size(), 2);
			Assert::IsTrue(std::count(indexPairs.begin(), indexPairs.end(), IndexPair(0, 2)));
			Assert::IsTrue(std::count(indexPairs.begin(), indexPairs.end(), IndexPair(1, 2)));
		}

		TEST_METHOD(getFrontierIndexes2)
		{
			vector<vector<TileType>> board{ {Blank{}, Number(1), UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, Number(1)},
											{Blank{}, Number(1), UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}},
											{Blank{}, Number(1), Number(1), Number(2), UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}},
											{Blank{}, Blank{}, Blank{}, Number(1), Number(1), Number(2), UnknownTile{}, UnknownTile{}, UnknownTile{}},
											{Blank{}, Blank{}, Blank{}, Blank{}, Blank{}, Number(1), UnknownTile{}, UnknownTile{}, UnknownTile{}},
											{Blank{}, Blank{}, Blank{}, Blank{}, Number(1), Number(2), UnknownTile{}, UnknownTile{}, UnknownTile{}},
											{Number(1), Number(1), Number(2), Number(1), Number(2), UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}},
											{UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}},
											{UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}}
										};
			auto indexPairs = getFrontierIndexes(board);
			Assert::AreEqual((int)indexPairs.size(), 21);
			Assert::IsTrue(std::count(indexPairs.begin(), indexPairs.end(), IndexPair(0, 2)));
			Assert::IsTrue(std::count(indexPairs.begin(), indexPairs.end(), IndexPair(0, 7)));
			Assert::IsTrue(std::count(indexPairs.begin(), indexPairs.end(), IndexPair(1, 2)));
			Assert::IsTrue(std::count(indexPairs.begin(), indexPairs.end(), IndexPair(1, 3)));
			Assert::IsTrue(std::count(indexPairs.begin(), indexPairs.end(), IndexPair(1, 4)));
			Assert::IsTrue(std::count(indexPairs.begin(), indexPairs.end(), IndexPair(1, 7)));
			Assert::IsTrue(std::count(indexPairs.begin(), indexPairs.end(), IndexPair(1, 8)));
			Assert::IsTrue(std::count(indexPairs.begin(), indexPairs.end(), IndexPair(2, 4)));
			Assert::IsTrue(std::count(indexPairs.begin(), indexPairs.end(), IndexPair(2, 5)));
			Assert::IsTrue(std::count(indexPairs.begin(), indexPairs.end(), IndexPair(2, 6)));
			Assert::IsTrue(std::count(indexPairs.begin(), indexPairs.end(), IndexPair(3, 6)));
			Assert::IsTrue(std::count(indexPairs.begin(), indexPairs.end(), IndexPair(4, 6)));
			Assert::IsTrue(std::count(indexPairs.begin(), indexPairs.end(), IndexPair(5, 6)));
			Assert::IsTrue(std::count(indexPairs.begin(), indexPairs.end(), IndexPair(6, 5)));
			Assert::IsTrue(std::count(indexPairs.begin(), indexPairs.end(), IndexPair(6, 6)));
			Assert::IsTrue(std::count(indexPairs.begin(), indexPairs.end(), IndexPair(7, 0)));
			Assert::IsTrue(std::count(indexPairs.begin(), indexPairs.end(), IndexPair(7, 1)));
			Assert::IsTrue(std::count(indexPairs.begin(), indexPairs.end(), IndexPair(7, 2)));
			Assert::IsTrue(std::count(indexPairs.begin(), indexPairs.end(), IndexPair(7, 3)));
			Assert::IsTrue(std::count(indexPairs.begin(), indexPairs.end(), IndexPair(7, 4)));
			Assert::IsTrue(std::count(indexPairs.begin(), indexPairs.end(), IndexPair(7, 5)));
		}

		TEST_METHOD(guessIsOk1)
		{
			vector<vector<TileType>> board{ {Blank{}, Number(1), GuessMine{}},
											{Blank{}, Number(1), UnknownTile{}},
											{Blank{}, Number(1), Number(1)} };

			Assert::IsTrue(guessIsOk(board, 0, 2));
			board[1][2] = GuessMine{};
			Assert::IsFalse(guessIsOk(board, 1, 2));
			board[1][2] = GuessNotMine{};
			Assert::IsFalse(guessIsOk(board, 1, 2));
			board[1][2] = UnknownTile{};
			board[0][2] = GuessNotMine{};
			Assert::IsTrue(guessIsOk(board, 0, 2));
			board[1][2] = GuessMine{};
			Assert::IsTrue(guessIsOk(board, 1, 2));
		}

		TEST_METHOD(guessIsOk2)
		{
			vector<vector<TileType>> board{ {Blank{}, Number(1), GuessNotMine{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, Number(1)},
											{Blank{}, Number(1), GuessMine{}, GuessNotMine{}, GuessNotMine{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}},
											{Blank{}, Number(1), Number(1), Number(2), GuessMine{}, GuessNotMine{}, GuessNotMine{}, UnknownTile{}, UnknownTile{}},
											{Blank{}, Blank{}, Blank{}, Number(1), Number(1), Number(2), GuessNotMine{}, UnknownTile{}, UnknownTile{}},
											{Blank{}, Blank{}, Blank{}, Blank{}, Blank{}, Number(1), GuessMine{}, UnknownTile{}, UnknownTile{}},
											{Blank{}, Blank{}, Blank{}, Blank{}, Number(1), Number(2), GuessNotMine{}, UnknownTile{}, UnknownTile{}},
											{Number(1), Number(1), Number(2), Number(1), Number(2), GuessMine{}, GuessNotMine{}, UnknownTile{}, UnknownTile{}},
											{GuessNotMine{}, GuessMine{}, GuessNotMine{}, GuessMine{}, GuessNotMine{}, GuessNotMine{}, UnknownTile{}, UnknownTile{}, UnknownTile{}},
											{UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}}
										};
			for (int row = 0; row < board.size(); row++)
			{
				for (int col = 0; col < board.size(); col++)
				{
					Assert::IsTrue(guessIsOk(board, row, col));
				}
			}
			board[7][0] = GuessMine{};
			Assert::IsFalse(guessIsOk(board, 7, 0));
		}

		TEST_METHOD(getGuesses1)
		{
			vector<vector<TileType>> board{ {Blank{}, Number(1), UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}},
											{Blank{}, Number(1), UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}},
											{Blank{}, Number(1), Number(1), Number(2), UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}},
											{Blank{}, Blank{}, Blank{}, Number(1), Number(1), Number(2), UnknownTile{}, UnknownTile{}, UnknownTile{}},
											{Blank{}, Blank{}, Blank{}, Blank{}, Blank{}, Number(1), UnknownTile{}, UnknownTile{}, UnknownTile{}},
											{Blank{}, Blank{}, Blank{}, Blank{}, Number(1), Number(2), UnknownTile{}, UnknownTile{}, UnknownTile{}},
											{Number(1), Number(1), Number(2), Number(1), Number(2), UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}},
											{UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}},
											{UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}}
										};
			auto indexPairs = getFrontierIndexes(board);
			auto guesses = getGuesses(board, indexPairs);
			Assert::AreEqual((int) guesses.size(), 3);
			vector<vector<TileType>> guessBoard1{	{Blank{}, Number(1), GuessNotMine{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}},
													{Blank{}, Number(1), GuessMine{}, GuessNotMine{}, GuessNotMine{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}},
													{Blank{}, Number(1), Number(1), Number(2), GuessMine{}, GuessNotMine{}, GuessMine{}, UnknownTile{}, UnknownTile{}},
													{Blank{}, Blank{}, Blank{}, Number(1), Number(1), Number(2), GuessNotMine{}, UnknownTile{}, UnknownTile{}},
													{Blank{}, Blank{}, Blank{}, Blank{}, Blank{}, Number(1), GuessNotMine{}, UnknownTile{}, UnknownTile{}},
													{Blank{}, Blank{}, Blank{}, Blank{}, Number(1), Number(2), GuessMine{}, UnknownTile{}, UnknownTile{}},
													{Number(1), Number(1), Number(2), Number(1), Number(2), GuessMine{}, GuessNotMine{}, UnknownTile{}, UnknownTile{}},
													{GuessNotMine{}, GuessMine{}, GuessNotMine{}, GuessMine{}, GuessNotMine{}, GuessNotMine{}, UnknownTile{}, UnknownTile{}, UnknownTile{}},
													{UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}}
												};

			auto firstGuess = guesses[0];
			for (int row = 0; row < firstGuess.size(); row++)
			{
				for (int col = 0; col < firstGuess.size(); col++)
				{
					Assert::AreEqual(guessBoard1[row][col].index(), firstGuess[row][col].index());
				}
			}

			vector<vector<TileType>> guessBoard2{	{Blank{}, Number(1), GuessNotMine{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}},
													{Blank{}, Number(1), GuessMine{}, GuessNotMine{}, GuessNotMine{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}},
													{Blank{}, Number(1), Number(1), Number(2), GuessMine{}, GuessNotMine{}, GuessNotMine{}, UnknownTile{}, UnknownTile{}},
													{Blank{}, Blank{}, Blank{}, Number(1), Number(1), Number(2), GuessMine{}, UnknownTile{}, UnknownTile{}},
													{Blank{}, Blank{}, Blank{}, Blank{}, Blank{}, Number(1), GuessNotMine{}, UnknownTile{}, UnknownTile{}},
													{Blank{}, Blank{}, Blank{}, Blank{}, Number(1), Number(2), GuessNotMine{}, UnknownTile{}, UnknownTile{}},
													{Number(1), Number(1), Number(2), Number(1), Number(2), GuessMine{}, GuessMine{}, UnknownTile{}, UnknownTile{}},
													{GuessNotMine{}, GuessMine{}, GuessNotMine{}, GuessMine{}, GuessNotMine{}, GuessNotMine{}, UnknownTile{}, UnknownTile{}, UnknownTile{}},
													{UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}}
			};


			auto secondGuess = guesses[1];
			for (int row = 0; row < secondGuess.size(); row++)
			{
				for (int col = 0; col < secondGuess.size(); col++)
				{
					Assert::AreEqual(guessBoard2[row][col].index(), secondGuess[row][col].index());
				}
			}


			vector<vector<TileType>> guessBoard3{	{Blank{}, Number(1), GuessNotMine{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}},
													{Blank{}, Number(1), GuessMine{}, GuessNotMine{}, GuessNotMine{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}},
													{Blank{}, Number(1), Number(1), Number(2), GuessMine{}, GuessNotMine{}, GuessNotMine{}, UnknownTile{}, UnknownTile{}},
													{Blank{}, Blank{}, Blank{}, Number(1), Number(1), Number(2), GuessNotMine{}, UnknownTile{}, UnknownTile{}},
													{Blank{}, Blank{}, Blank{}, Blank{}, Blank{}, Number(1), GuessMine{}, UnknownTile{}, UnknownTile{}},
													{Blank{}, Blank{}, Blank{}, Blank{}, Number(1), Number(2), GuessNotMine{}, UnknownTile{}, UnknownTile{}},
													{Number(1), Number(1), Number(2), Number(1), Number(2), GuessMine{}, GuessNotMine{}, UnknownTile{}, UnknownTile{}},
													{GuessNotMine{}, GuessMine{}, GuessNotMine{}, GuessMine{}, GuessNotMine{}, GuessNotMine{}, UnknownTile{}, UnknownTile{}, UnknownTile{}},
													{UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}}
			};
			auto thirdGuess = guesses[2];
			for (int row = 0; row < thirdGuess.size(); row++)
			{
				for (int col = 0; col < thirdGuess.size(); col++)
				{
					Assert::AreEqual(guessBoard3[row][col].index(), thirdGuess[row][col].index());
				}
			}
		}

		TEST_METHOD(getGuesses2)
		{
			vector<vector<TileType>> board{ {Blank{}, Number(1), Number(1), Number(1), Blank{}, Blank{}, Number(2), Mine{}, UnknownTile{}},
											{Blank{}, Number(1), Mine{}, Number(2), Number(1), Number(1), Number(2), Mine{}, Number(2)},
											{Blank{}, Number(1), Number(1), Number(2), Mine{}, Number(1), Number(1), Number(1), Number(1)},
											{Blank{}, Blank{}, Blank{}, Number(1), Number(1), Number(2), Number(1), Number(2), Number(1)},
											{Blank{}, Blank{}, Blank{}, Blank{}, Blank{}, Number(1), Mine{}, Number(3), Mine{}},
											{Blank{}, Blank{}, Blank{}, Blank{}, Number(1), Number(2), Number(2), Number(3), Mine{}},
											{Number(1), Number(1), Number(2), Number(1), Number(2), Mine{}, Number(1), Number(1), Number(1)},
											{Number(1), Mine{}, Number(2), Mine{}, Number(2), Number(1), Number(1),  Blank{}, Blank{}},
											{Number(1), Number(1), Number(2), Number(1), Number(1), Blank{}, Blank{}, Blank{}, Blank{}}
			};
			auto indexPairs = getFrontierIndexes(board);
			auto guesses = getGuesses(board, indexPairs);
			Assert::AreEqual((int)guesses.size(), 1);
			vector<vector<TileType>> guessBoard1{	{Blank{}, Number(1), Number(1), Number(1), Blank{}, Blank{}, Number(2), Mine{}, GuessNotMine{}},
													{Blank{}, Number(1), Mine{}, Number(2), Number(1), Number(1), Number(2), Mine{}, Number(2)},
													{Blank{}, Number(1), Number(1), Number(2), Mine{}, Number(1), Number(1), Number(1), Number(1)},
													{Blank{}, Blank{}, Blank{}, Number(1), Number(1), Number(2), Number(1), Number(2), Number(1)},
													{Blank{}, Blank{}, Blank{}, Blank{}, Blank{}, Number(1), Mine{}, Number(3), Mine{}},
													{Blank{}, Blank{}, Blank{}, Blank{}, Number(1), Number(2), Number(2), Number(3), Mine{}},
													{Number(1), Number(1), Number(2), Number(1), Number(2), Mine{}, Number(1), Number(1), Number(1)},
													{Number(1), Mine{}, Number(2), Mine{}, Number(2), Number(1), Number(1),  Blank{}, Blank{}},
													{Number(1), Number(1), Number(2), Number(1), Number(1), Blank{}, Blank{}, Blank{}, Blank{}}
			};

			auto firstGuess = guesses[0];
			for (int row = 0; row < firstGuess.size(); row++)
			{
				for (int col = 0; col < firstGuess.size(); col++)
				{
					Assert::AreEqual(guessBoard1[row][col].index(), firstGuess[row][col].index());
				}
			}
		}

		TEST_METHOD(mergeGuesses1)
		{
			vector<vector<TileType>> board{ {Blank{}, Number(1), UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}},
											{Blank{}, Number(1), UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}},
											{Blank{}, Number(1), Number(1), Number(2), UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}},
											{Blank{}, Blank{}, Blank{}, Number(1), Number(1), Number(2), UnknownTile{}, UnknownTile{}, UnknownTile{}},
											{Blank{}, Blank{}, Blank{}, Blank{}, Blank{}, Number(1), UnknownTile{}, UnknownTile{}, UnknownTile{}},
											{Blank{}, Blank{}, Blank{}, Blank{}, Number(1), Number(2), UnknownTile{}, UnknownTile{}, UnknownTile{}},
											{Number(1), Number(1), Number(2), Number(1), Number(2), UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}},
											{UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}},
											{UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}}
										 };
			auto indexPairs = getFrontierIndexes(board);

			vector<vector<TileType>> guessBoard1{	{Blank{}, Number(1), GuessNotMine{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}},
													{Blank{}, Number(1), GuessMine{}, GuessNotMine{}, GuessNotMine{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}},
													{Blank{}, Number(1), Number(1), Number(2), GuessMine{}, GuessNotMine{}, GuessMine{}, UnknownTile{}, UnknownTile{}},
													{Blank{}, Blank{}, Blank{}, Number(1), Number(1), Number(2), GuessNotMine{}, UnknownTile{}, UnknownTile{}},
													{Blank{}, Blank{}, Blank{}, Blank{}, Blank{}, Number(1), GuessNotMine{}, UnknownTile{}, UnknownTile{}},
													{Blank{}, Blank{}, Blank{}, Blank{}, Number(1), Number(2), GuessMine{}, UnknownTile{}, UnknownTile{}},
													{Number(1), Number(1), Number(2), Number(1), Number(2), GuessMine{}, GuessNotMine{}, UnknownTile{}, UnknownTile{}},
													{GuessNotMine{}, GuessMine{}, GuessNotMine{}, GuessMine{}, GuessNotMine{}, GuessNotMine{}, UnknownTile{}, UnknownTile{}, UnknownTile{}},
													{UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}}
			};

			vector<vector<TileType>> guessBoard2{	{Blank{}, Number(1), GuessNotMine{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}},
													{Blank{}, Number(1), GuessMine{}, GuessNotMine{}, GuessNotMine{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}},
													{Blank{}, Number(1), Number(1), Number(2), GuessMine{}, GuessNotMine{}, GuessNotMine{}, UnknownTile{}, UnknownTile{}},
													{Blank{}, Blank{}, Blank{}, Number(1), Number(1), Number(2), GuessMine{}, UnknownTile{}, UnknownTile{}},
													{Blank{}, Blank{}, Blank{}, Blank{}, Blank{}, Number(1), GuessNotMine{}, UnknownTile{}, UnknownTile{}},
													{Blank{}, Blank{}, Blank{}, Blank{}, Number(1), Number(2), GuessNotMine{}, UnknownTile{}, UnknownTile{}},
													{Number(1), Number(1), Number(2), Number(1), Number(2), GuessMine{}, GuessMine{}, UnknownTile{}, UnknownTile{}},
													{GuessNotMine{}, GuessMine{}, GuessNotMine{}, GuessMine{}, GuessNotMine{}, GuessNotMine{}, UnknownTile{}, UnknownTile{}, UnknownTile{}},
													{UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}}
			};


			vector<vector<TileType>> guessBoard3{	{Blank{}, Number(1), GuessNotMine{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}},
													{Blank{}, Number(1), GuessMine{}, GuessNotMine{}, GuessNotMine{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}},
													{Blank{}, Number(1), Number(1), Number(2), GuessMine{}, GuessNotMine{}, GuessNotMine{}, UnknownTile{}, UnknownTile{}},
													{Blank{}, Blank{}, Blank{}, Number(1), Number(1), Number(2), GuessNotMine{}, UnknownTile{}, UnknownTile{}},
													{Blank{}, Blank{}, Blank{}, Blank{}, Blank{}, Number(1), GuessMine{}, UnknownTile{}, UnknownTile{}},
													{Blank{}, Blank{}, Blank{}, Blank{}, Number(1), Number(2), GuessNotMine{}, UnknownTile{}, UnknownTile{}},
													{Number(1), Number(1), Number(2), Number(1), Number(2), GuessMine{}, GuessNotMine{}, UnknownTile{}, UnknownTile{}},
													{GuessNotMine{}, GuessMine{}, GuessNotMine{}, GuessMine{}, GuessNotMine{}, GuessNotMine{}, UnknownTile{}, UnknownTile{}, UnknownTile{}},
													{UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}}
												};

			vector<vector<vector<TileType>>> guesses{ guessBoard1, guessBoard2, guessBoard3 };

			auto newBoard = mergeGuesses(guesses, indexPairs, board);

			vector<vector<TileType>> compareBoard{	{Blank{}, Number(1), GuessNotMine{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}},
													{Blank{}, Number(1), GuessMine{}, GuessNotMine{}, GuessNotMine{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}},
													{Blank{}, Number(1), Number(1), Number(2), GuessMine{}, GuessNotMine{}, UnknownTile{}, UnknownTile{}, UnknownTile{}},
													{Blank{}, Blank{}, Blank{}, Number(1), Number(1), Number(2), UnknownTile{}, UnknownTile{}, UnknownTile{}},
													{Blank{}, Blank{}, Blank{}, Blank{}, Blank{}, Number(1), UnknownTile{}, UnknownTile{}, UnknownTile{}},
													{Blank{}, Blank{}, Blank{}, Blank{}, Number(1), Number(2), UnknownTile{}, UnknownTile{}, UnknownTile{}},
													{Number(1), Number(1), Number(2), Number(1), Number(2), GuessMine{}, UnknownTile{}, UnknownTile{}, UnknownTile{}},
													{GuessNotMine{}, GuessMine{}, GuessNotMine{}, GuessMine{}, GuessNotMine{}, GuessNotMine{}, UnknownTile{}, UnknownTile{}, UnknownTile{}},
													{UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}, UnknownTile{}}
			};

			for (int row = 0; row < compareBoard.size(); row++)
			{
				for (int col = 0; col < compareBoard.size(); col++)
				{
					Assert::AreEqual(compareBoard[row][col].index(), newBoard[row][col].index());
				}
			}
		}
	};
}
