#pragma once

/**
* Déclaration classe WhiteQueen
* \file   WhiteQueen.hpp
* \author Francis Bilodeau-Lecomte
* \date   6 mai 2022
* Créé le 24 avril 2022
*/

#include <utility>
#include "WhitePiece.hpp"

class WhiteQueen : public WhitePiece
{
public:
	WhiteQueen(std::pair<int, int> position);
	WhiteQueen(const WhiteQueen& other);
	~WhiteQueen() = default;
	void findAvailablePositions(const Chess::Board& board, bool isOneMoveAhead = false);
	virtual std::shared_ptr<Piece> clone();
};