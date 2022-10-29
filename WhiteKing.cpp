/**
* Implémentation classe WhiteKing
* \file   WhiteKing.cpp
* \author Francis Bilodeau-Lecomte
* \date   6 mai 2022
* Créé le 24 avril 2022
*/

#include "WhiteKing.hpp"
#include "WhiteRook.hpp"

int WhiteKing::whiteKingCount = 0;

WhiteKing::WhiteKing(std::pair<int, int> position) : WhitePiece()
{
	if (whiteKingCount == 2)
		throw TooManyKingsException("You tried to instantiate a second white king!");
	imagePath_ = "Images/WhiteKing.png";
	position_ = position;
	whiteKingCount++;
}

WhiteKing::WhiteKing(const WhiteKing& other)
{
	position_ = other.position_;
	imagePath_ = other.imagePath_;
	for (std::list<std::pair<int, int>>::const_iterator it = other.cbegin(); it != other.cend(); it++)
	{
		availablePositions_.push_back(*it);
	}
}

WhiteKing::~WhiteKing()
{
	whiteKingCount--;
}

std::shared_ptr<Piece> WhiteKing::clone()
{
	return std::make_shared<WhiteKing>(*this);
}

void WhiteKing::findAvailablePositions(const Chess::Board& board, bool isOneMoveAhead)
{
	availablePositions_.clear();
	std::pair<int, int> position = position_;
	position.first -= 1;
	if (board.isValidPosition(position) && !board.hasWhitePiece(position))
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
	}
	position.second += 1;
	if (board.isValidPosition(position) && !board.hasWhitePiece(position))
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
	}
	position.first += 1;
	if (board.isValidPosition(position) && !board.hasWhitePiece(position))
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
	}
	position.first += 1;
	if (board.isValidPosition(position) && !board.hasWhitePiece(position))
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
	}
	position.second -= 1;
	if (board.isValidPosition(position) && !board.hasWhitePiece(position))
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
	}
	position.second -= 1;
	if (board.isValidPosition(position) && !board.hasWhitePiece(position))
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
	}
	position.first -= 1;
	if (board.isValidPosition(position) && !board.hasWhitePiece(position))
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
	}
	position.first -= 1;
	if (board.isValidPosition(position) && !board.hasWhitePiece(position))
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
	}
	if (board.hasWhitePiece(std::pair<int, int>(7, 7)))
	{
		std::shared_ptr<Piece> piece = board.getPiece(std::pair<int, int>(7, 7));
		if (dynamic_cast<WhiteRook*>(piece.get()) != nullptr)
		{
			if (!this->hasMoved() && !piece->hasMoved() && !board.hasWhitePiece(std::pair<int, int>(7, 5)) &&
				!board.hasBlackPiece(std::pair<int, int>(7, 5)) && !board.hasWhitePiece(std::pair<int, int>(7, 6)) &&
				!board.hasBlackPiece(std::pair<int, int>(7, 6)) && !board.isCoveredByBlack(position_) &&
				!board.isCoveredByBlack(std::pair<int, int>(7, 5)) && !board.isCoveredByBlack(std::pair<int, int>(7, 6)))
			{
				if (!isOneMoveAhead)
				{
					if (preventsCheck(board, std::pair<int, int>(7, 6)))
						availablePositions_.push_back(std::pair<int, int>(7, 6));
				}
				else
				{
					availablePositions_.push_back(std::pair<int, int>(7, 6));
				}
			}
		}
	}
	if (board.hasWhitePiece(std::pair<int, int>(7, 0)))
	{
		std::shared_ptr<Piece> piece = board.getPiece(std::pair<int, int>(7, 0));
		if (dynamic_cast<WhiteRook*>(piece.get()) != nullptr)
		{
			if (!this->hasMoved() && !piece->hasMoved() && !board.hasWhitePiece(std::pair<int, int>(7, 1)) &&
				!board.hasBlackPiece(std::pair<int, int>(7, 1)) && !board.hasWhitePiece(std::pair<int, int>(7, 2)) &&
				!board.hasBlackPiece(std::pair<int, int>(7, 2)) && !board.hasWhitePiece(std::pair<int, int>(7, 3)) &&
				!board.hasBlackPiece(std::pair<int, int>(7, 3)) && !board.isCoveredByBlack(position_) &&
				!board.isCoveredByBlack(std::pair<int, int>(7, 2)) && !board.isCoveredByBlack(std::pair<int, int>(7, 3)))
			{
				if (!isOneMoveAhead)
				{
					if (preventsCheck(board, std::pair<int, int>(7, 2)))
						availablePositions_.push_back(std::pair<int, int>(7, 2));
				}
				else
				{
					availablePositions_.push_back(std::pair<int, int>(7, 2));
				}
			}
		}
	}
}