/**
* Implémentation classe abstraite Piece
* \file   Piece.cpp
* \author Francis Bilodeau-Lecomte
* \date   6 mai 2022
* Créé le 24 avril 2022
*/

#include "Piece.hpp"

Piece::Piece() : imagePath_(""), hasMoved_(false) {}

bool Piece::isValidMove(std::pair<int, int> position) const
{
	std::list<std::pair<int, int>>::const_iterator it;
	it = std::find(availablePositions_.cbegin(), availablePositions_.cend(), position);
	if (it != availablePositions_.cend())
	{
		return true;
	}
	return false;
}

bool Piece::canMove()
{
	return !(availablePositions_.empty());
}

std::list<std::pair<int, int>>::const_iterator Piece::cbegin() const
{
	return availablePositions_.cbegin();
}

std::list<std::pair<int, int>>::const_iterator Piece::cend() const
{
	return availablePositions_.cend();
}

std::pair<int, int> Piece::getPosition() const
{
	return position_;
}

std::string Piece::getImagePath() const
{
	return imagePath_;
}

bool Piece::hasMoved() const
{
	return hasMoved_;
}

void Piece::setPosition(std::pair<int, int> newPosition)
{
	position_ = newPosition;
}

void Piece::setHasMoved(bool hasMoved)
{
	hasMoved_ = hasMoved;
}

