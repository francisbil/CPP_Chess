/**
* Implémentation classe abstraite BlackPiece
* \file   BlackPiece.cpp
* \author Francis Bilodeau-Lecomte
* \date   6 mai 2022
* Créé le 24 avril 2022
*/

#include "BlackPiece.hpp"
#include "WhitePiece.hpp"

bool BlackPiece::preventsCheck(const Chess::Board& board, std::pair<int, int> move)
{
	Chess::Board newBoard = Chess::Board(board);
	newBoard.simulateMove(position_, move);
	newBoard.updateAvailablePositionsBlack(true);
	return !newBoard.isBlackKingInCheck();
}