/**
* Tests pour le modèle (classe Board)
* \file   BoardTests.cpp
* \author Francis Bilodeau-Lecomte
* \date   6 mai 2022
* Créé le 24 avril 2022
*/

#include "Board.hpp"
#include "Piece.hpp"
#include "WhiteKing.hpp"
#include "WhiteQueen.hpp"
#include "WhiteRook.hpp"

#if __has_include("gtest/gtest.h")
#include "gtest/gtest.h"
#endif
#ifdef TEST

namespace Chess
{
	TEST(Board, movement)
	{
		// This test verifies that after a move, the model removes the piece from the old square and puts it on the new square.

		Board* board = new Board(1);
		board->updateState(std::pair<int, int>(6, 4));
		board->updateState(std::pair<int, int>(4, 4));
		bool hasPiece1 = board->pieces_.find(std::pair<int, int>(6, 4)) != board->pieces_.end();
		bool hasPiece2 = board->pieces_.find(std::pair<int, int>(4, 4)) != board->pieces_.end();

		EXPECT_FALSE(hasPiece1);
		EXPECT_TRUE(hasPiece2);
		delete board;
	}

	TEST(Board, castling)
	{
		// This test verifies that after castling, the king and the rook are on the right squares.

		Board* board = new Board(1);
		board->updateState(std::pair<int, int>(6, 4));
		board->updateState(std::pair<int, int>(5, 4));
		board->updateState(std::pair<int, int>(1, 0));
		board->updateState(std::pair<int, int>(2, 0));
		board->updateState(std::pair<int, int>(7, 5));
		board->updateState(std::pair<int, int>(5, 3));
		board->updateState(std::pair<int, int>(1, 1));
		board->updateState(std::pair<int, int>(2, 1));
		board->updateState(std::pair<int, int>(7, 6));
		board->updateState(std::pair<int, int>(5, 7));
		board->updateState(std::pair<int, int>(1, 2));
		board->updateState(std::pair<int, int>(2, 2));
		board->updateState(std::pair<int, int>(7, 4));
		board->updateState(std::pair<int, int>(7, 6));
		bool isWhiteKing = dynamic_cast<WhiteKing*>(board->pieces_.at(std::pair<int, int>(7, 6)).get()) != nullptr;
		bool isWhiteRook = dynamic_cast<WhiteRook*>(board->pieces_.at(std::pair<int, int>(7, 5)).get()) != nullptr;

		EXPECT_TRUE(isWhiteKing);
		EXPECT_TRUE(isWhiteRook);
		delete board;
	}

	TEST(Board, promotion)
	{
		// This test verifies that after pawn promotion to a queen, the pawn is indeed replaced by a queen.

		Board* board = new Board(1);
		board->updateState(std::pair<int, int>(6, 7));
		board->updateState(std::pair<int, int>(4, 7));
		board->updateState(std::pair<int, int>(1, 7));
		board->updateState(std::pair<int, int>(3, 7));
		board->updateState(std::pair<int, int>(6, 6));
		board->updateState(std::pair<int, int>(4, 6));
		board->updateState(std::pair<int, int>(3, 7));
		board->updateState(std::pair<int, int>(4, 6));
		board->updateState(std::pair<int, int>(4, 7));
		board->updateState(std::pair<int, int>(3, 7));
		board->updateState(std::pair<int, int>(0, 7));
		board->updateState(std::pair<int, int>(2, 7));
		board->updateState(std::pair<int, int>(0, 6));
		board->updateState(std::pair<int, int>(0, 5));
		board->updateState(std::pair<int, int>(2, 7));
		board->updateState(std::pair<int, int>(2, 6));
		board->updateState(std::pair<int, int>(3, 7));
		board->updateState(std::pair<int, int>(2, 7));
		board->updateState(std::pair<int, int>(2, 6));
		board->updateState(std::pair<int, int>(2, 5));
		board->updateState(std::pair<int, int>(2, 7));
		board->updateState(std::pair<int, int>(1, 7));
		board->updateState(std::pair<int, int>(2, 5));
		board->updateState(std::pair<int, int>(2, 4));
		board->updateState(std::pair<int, int>(1, 7));
		board->updateState(std::pair<int, int>(0, 7));
		board->replacePiece(std::pair<int, int>(0, 7), 'W', 'Q');
		bool isWhiteQueen = dynamic_cast<WhiteQueen*>(board->pieces_.at(std::pair<int, int>(0, 7)).get()) != nullptr;

		EXPECT_TRUE(isWhiteQueen);
		delete board;
	}

	TEST(Board, enPassant)
	{
		// This test verifies that a pawn can capture another pawn "en passant".

		Board* board = new Board(1);
		board->updateState(std::pair<int, int>(6, 0));
		board->updateState(std::pair<int, int>(4, 0));
		board->updateState(std::pair<int, int>(1, 7));
		board->updateState(std::pair<int, int>(2, 7));
		board->updateState(std::pair<int, int>(4, 0));
		board->updateState(std::pair<int, int>(3, 0));
		board->updateState(std::pair<int, int>(1, 1));
		board->updateState(std::pair<int, int>(3, 1));
		std::shared_ptr<Piece> whitePawn = board->pieces_.at(std::pair<int, int>(3, 0));
		bool canCapture = false;
		for (auto it = whitePawn->cbegin(); it != whitePawn->cend(); it++)
		{
			if ((*it) == std::pair<int, int>(2, 1))
			{
				canCapture = true;
				break;
			}
		}

		EXPECT_TRUE(canCapture);
		delete board;
	}
}

#endif
