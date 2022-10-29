#pragma once

/**
* Déclaration classe WhiteRook
* \file   WhiteRook.hpp
* \author Francis Bilodeau-Lecomte
* \date   6 mai 2022
* Créé le 24 avril 2022
*/

#include <utility>
#include "WhitePiece.hpp"

class WhiteRook : public WhitePiece
{
public:
	WhiteRook(std::pair<int, int> position);
	WhiteRook(const WhiteRook& other);
	~WhiteRook() = default;
	void findAvailablePositions(const Chess::Board& board, bool isOneMoveAhead = false);
	virtual std::shared_ptr<Piece> clone();
};
