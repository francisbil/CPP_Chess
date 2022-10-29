#pragma once

/**
* Déclaration classe abstraite Piece
* \file   Piece.hpp
* \author Francis Bilodeau-Lecomte
* \date   6 mai 2022
* Créé le 24 avril 2022
*/

#include <list>
#include <utility>
#include "Board.hpp"

class Piece
{
public:
	Piece();
	virtual ~Piece() = default;
	virtual std::shared_ptr<Piece> clone() = 0;
	virtual void findAvailablePositions(const Chess::Board& board, bool isOneMoveAhead = false) = 0;
	bool isValidMove(std::pair<int, int> position) const;
	bool canMove();
	std::list<std::pair<int, int>>::const_iterator cbegin() const;
	std::list<std::pair<int, int>>::const_iterator cend() const;
	std::pair<int, int> getPosition() const;
	std::string getImagePath() const;
	bool hasMoved() const;
	void setPosition(std::pair<int, int> newPosition);
	void setHasMoved(bool hasMoved);
protected:
	std::pair<int, int> position_;
	std::list<std::pair<int, int>> availablePositions_;
	std::string imagePath_;
	bool hasMoved_;
};