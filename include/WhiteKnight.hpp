#pragma once

/**
* Déclaration classe WhiteKnight
* \file   WhiteKnight.hpp
* \author Francis Bilodeau-Lecomte
* \date   6 mai 2022
* Créé le 24 avril 2022
*/

#include <utility>
#include "WhitePiece.hpp"

class WhiteKnight : public WhitePiece
{
public:
	WhiteKnight(std::pair<int, int> position);
	WhiteKnight(const WhiteKnight& other);
	~WhiteKnight() = default;
	void findAvailablePositions(const Chess::Board& board, bool isOneMoveAhead = false);
	virtual std::shared_ptr<Piece> clone();
};
