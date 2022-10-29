/**
* Implémentation classe abstraite WhitePiece
* \file   WhitePiece.cpp
* \author Francis Bilodeau-Lecomte
* \date   6 mai 2022
* Créé le 24 avril 2022
*/

#include "WhitePiece.hpp"

bool WhitePiece::preventsCheck(const Chess::Board& board, std::pair<int, int> move)
{
	Chess::Board newBoard = Chess::Board(board);
	newBoard.simulateMove(position_, move);
	newBoard.updateAvailablePositionsWhite(true);
	return !newBoard.isWhiteKingInCheck();
}