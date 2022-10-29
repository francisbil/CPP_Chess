/**
* Implémentation classe BlackQueen
* \file   BlackQueen.cpp
* \author Francis Bilodeau-Lecomte
* \date   6 mai 2022
* Créé le 24 avril 2022
*/

#include "BlackQueen.hpp"

BlackQueen::BlackQueen(std::pair<int, int> position) : BlackPiece()
{
	imagePath_ = "Images/BlackQueen.png";
	position_ = position;
}

BlackQueen::BlackQueen(const BlackQueen& other)
{
	position_ = other.position_;
	imagePath_ = other.imagePath_;
	for (std::list<std::pair<int, int>>::const_iterator it = other.cbegin(); it != other.cend(); it++)
	{
		availablePositions_.push_back(*it);
	}
}

std::shared_ptr<Piece> BlackQueen::clone()
{
	return std::make_shared<BlackQueen>(*this);
}

void BlackQueen::findAvailablePositions(const Chess::Board& board, bool isOneMoveAhead)
{
	availablePositions_.clear();

	std::pair<int, int> position = position_;
	position.first -= 1;
	while (board.isValidPosition(position) && !board.hasBlackPiece(position))
	{
		if (!isOneMoveAhead)
		{
			if (preventsCheck(board, position))
				availablePositions_.push_back(position);
		}
		else
		{
			availablePositions_.push_back(position);
		}
		if (board.hasWhitePiece(position))
		{
			break;
		}
		position.first -= 1;
	}

	position = position_;
	position.first += 1;
	while (board.isValidPosition(position) && !board.hasBlackPiece(position))
	{
		if (!isOneMoveAhead)
		{
			if (preventsCheck(board, position))
				availablePositions_.push_back(position);
		}
		else
		{
			availablePositions_.push_back(position);
		}
		if (board.hasWhitePiece(position))
		{
			break;
		}
		position.first += 1;
	}

	position = position_;
	position.second -= 1;
	while (board.isValidPosition(position) && !board.hasBlackPiece(position))
	{
		if (!isOneMoveAhead)
		{
			if (preventsCheck(board, position))
				availablePositions_.push_back(position);
		}
		else
		{
			availablePositions_.push_back(position);
		}
		if (board.hasWhitePiece(position))
		{
			break;
		}
		position.second -= 1;
	}

	position = position_;
	position.second += 1;
	while (board.isValidPosition(position) && !board.hasBlackPiece(position))
	{
		if (!isOneMoveAhead)
		{
			if (preventsCheck(board, position))
				availablePositions_.push_back(position);
		}
		else
		{
			availablePositions_.push_back(position);
		}
		if (board.hasWhitePiece(position))
		{
			break;
		}
		position.second += 1;
	}

	position = position_;
	position.first -= 1;
	position.second -= 1;
	while (board.isValidPosition(position) && !board.hasBlackPiece(position))
	{
		if (!isOneMoveAhead)
		{
			if (preventsCheck(board, position))
				availablePositions_.push_back(position);
		}
		else
		{
			availablePositions_.push_back(position);
		}
		if (board.hasWhitePiece(position))
		{
			break;
		}
		position.first -= 1;
		position.second -= 1;
	}

	position = position_;
	position.first -= 1;
	position.second += 1;
	while (board.isValidPosition(position) && !board.hasBlackPiece(position))
	{
		if (!isOneMoveAhead)
		{
			if (preventsCheck(board, position))
				availablePositions_.push_back(position);
		}
		else
		{
			availablePositions_.push_back(position);
		}
		if (board.hasWhitePiece(position))
		{
			break;
		}
		position.first -= 1;
		position.second += 1;
	}

	position = position_;
	position.first += 1;
	position.second += 1;
	while (board.isValidPosition(position) && !board.hasBlackPiece(position))
	{
		if (!isOneMoveAhead)
		{
			if (preventsCheck(board, position))
				availablePositions_.push_back(position);
		}
		else
		{
			availablePositions_.push_back(position);
		}
		if (board.hasWhitePiece(position))
		{
			break;
		}
		position.first += 1;
		position.second += 1;
	}

	position = position_;
	position.first += 1;
	position.second -= 1;
	while (board.isValidPosition(position) && !board.hasBlackPiece(position))
	{
		if (!isOneMoveAhead)
		{
			if (preventsCheck(board, position))
				availablePositions_.push_back(position);
		}
		else
		{
			availablePositions_.push_back(position);
		}
		if (board.hasWhitePiece(position))
		{
			break;
		}
		position.first += 1;
		position.second -= 1;
	}
}