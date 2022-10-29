/**
* Implémentation classe Board
* \file   Board.cpp
* \author Francis Bilodeau-Lecomte
* \date   6 mai 2022
* Créé le 24 avril 2022
*/

#include <QDebug>
#include <QMessageBox>
#include <iostream>

#include "Board.hpp"
#include "WhiteKing.hpp"
#include "WhiteQueen.hpp"
#include "WhiteBishop.hpp"
#include "WhiteKnight.hpp"
#include "WhiteRook.hpp"
#include "WhitePawn.hpp"
#include "BlackKing.hpp"
#include "BlackQueen.hpp"
#include "BlackBishop.hpp"
#include "BlackKnight.hpp"
#include "BlackRook.hpp"
#include "BlackPawn.hpp"

Chess::Board::Board(int mode) : enPassant_(std::pair<int, int>(-1, -1))
{
	switch (mode)
	{
		case 1:
			createPieces1();
			selectedPiece_ = pieces_.at(std::pair<int, int>(7, 4));
			currentState_ = Chess::Board::State::WHITES_TURN;
			break;
		case 2:
			createPieces2();
			selectedPiece_ = pieces_.at(std::pair<int, int>(4, 7));
			currentState_ = Chess::Board::State::WHITES_TURN;
			break;
		case 3:
			createPieces3();
			selectedPiece_ = pieces_.at(std::pair<int, int>(2, 4));
			currentState_ = Chess::Board::State::BLACKS_TURN;
			break;
		case 4:
			createPieces4();
			selectedPiece_ = pieces_.at(std::pair<int, int>(3, 1));
			currentState_ = Chess::Board::State::BLACKS_TURN;
			break;
	}
	updateAvailablePositionsWhite();
}

Chess::Board::Board(const Chess::Board& other)
{
	for (const auto& [position, piece] : other.pieces_)
	{
		pieces_[position] = piece->clone();
	}
	currentState_ = Chess::Board::State::WHITES_TURN;
	selectedPiece_ = (other.getSelectedPiece())->clone();
}

Chess::Board::~Board()
{
	for (const auto& [position, piece] : pieces_)
	{
		emit pieceToDelete(piece->getPosition());
	}
}

void Chess::Board::createWhiteKing(std::pair<int, int> position)
{
	try
	{
		pieces_[position] = std::make_shared<WhiteKing>(position);
	}
	catch (TooManyKingsException& e)
	{
		QMessageBox* messageBox = new QMessageBox();
		messageBox->critical(0, "Error!", e.what());
	}
}

void Chess::Board::createWhiteQueen(std::pair<int, int> position)
{
	pieces_[position] = std::make_shared<WhiteQueen>(position);
}

void Chess::Board::createWhiteBishop(std::pair<int, int> position)
{
	pieces_[position] = std::make_shared<WhiteBishop>(position);
}

void Chess::Board::createWhiteKnight(std::pair<int, int> position)
{
	pieces_[position] = std::make_shared<WhiteKnight>(position);
}

void Chess::Board::createWhiteRook(std::pair<int, int> position)
{
	pieces_[position] = std::make_shared<WhiteRook>(position);
}

void Chess::Board::createWhitePawn(std::pair<int, int> position)
{
	pieces_[position] = std::make_shared<WhitePawn>(position);
}

void Chess::Board::createBlackKing(std::pair<int, int> position)
{
	try
	{
		pieces_[position] = std::make_shared<BlackKing>(position);
	}
	catch (TooManyKingsException& e)
	{
		QMessageBox* messageBox = new QMessageBox();
		messageBox->critical(0, "Error!", e.what());
	}
}

void Chess::Board::createBlackQueen(std::pair<int, int> position)
{
	pieces_[position] = std::make_shared<BlackQueen>(position);
}

void Chess::Board::createBlackBishop(std::pair<int, int> position)
{
	pieces_[position] = std::make_shared<BlackBishop>(position);
}

void Chess::Board::createBlackKnight(std::pair<int, int> position)
{
	pieces_[position] = std::make_shared<BlackKnight>(position);
}

void Chess::Board::createBlackRook(std::pair<int, int> position)
{
	pieces_[position] = std::make_shared<BlackRook>(position);
}

void Chess::Board::createBlackPawn(std::pair<int, int> position)
{
	pieces_[position] = std::make_shared<BlackPawn>(position);
}

void Chess::Board::createPieces1()
{
	createWhiteKing(std::pair<int, int>(7, 4));
	createWhiteQueen(std::pair<int, int>(7, 3));
	createWhiteBishop(std::pair<int, int>(7, 2));
	createWhiteBishop(std::pair<int, int>(7, 5));
	createWhiteKnight(std::pair<int, int>(7, 1));
	createWhiteKnight(std::pair<int, int>(7, 6));
	createWhiteRook(std::pair<int, int>(7, 0));
	createWhiteRook(std::pair<int, int>(7, 7));
	createWhitePawn(std::pair<int, int>(6, 0));
	createWhitePawn(std::pair<int, int>(6, 1));
	createWhitePawn(std::pair<int, int>(6, 2));
	createWhitePawn(std::pair<int, int>(6, 3));
	createWhitePawn(std::pair<int, int>(6, 4));
	createWhitePawn(std::pair<int, int>(6, 5));
	createWhitePawn(std::pair<int, int>(6, 6));
	createWhitePawn(std::pair<int, int>(6, 7));
	createBlackKing(std::pair<int, int>(0, 4));
	createBlackQueen(std::pair<int, int>(0, 3));
	createBlackBishop(std::pair<int, int>(0, 2));
	createBlackBishop(std::pair<int, int>(0, 5));
	createBlackKnight(std::pair<int, int>(0, 1));
	createBlackKnight(std::pair<int, int>(0, 6));
	createBlackRook(std::pair<int, int>(0, 0));
	createBlackRook(std::pair<int, int>(0, 7));
	createBlackPawn(std::pair<int, int>(1, 0));
	createBlackPawn(std::pair<int, int>(1, 1));
	createBlackPawn(std::pair<int, int>(1, 2));
	createBlackPawn(std::pair<int, int>(1, 3));
	createBlackPawn(std::pair<int, int>(1, 4));
	createBlackPawn(std::pair<int, int>(1, 5));
	createBlackPawn(std::pair<int, int>(1, 6));
	createBlackPawn(std::pair<int, int>(1, 7));
}

void Chess::Board::createPieces2()
{
	createWhiteKing(std::pair<int, int>(4, 7));
	createWhiteRook(std::pair<int, int>(3, 7));
	createBlackKing(std::pair<int, int>(2, 3));
	createBlackKnight(std::pair<int, int>(6, 4));
	createBlackRook(std::pair<int, int>(5, 0));
}

void Chess::Board::createPieces3()
{
	createWhiteKing(std::pair<int, int>(2, 4));
	createWhiteRook(std::pair<int, int>(1, 5));
	createBlackKing(std::pair<int, int>(5, 7));
	createBlackKnight(std::pair<int, int>(2, 1));
}

void Chess::Board::createPieces4()
{
	createWhiteKing(std::pair<int, int>(3, 1));
	createWhiteRook(std::pair<int, int>(5, 6));
	createWhiteBishop(std::pair<int, int>(3, 2));
	createBlackKing(std::pair<int, int>(2, 4));
	createBlackRook(std::pair<int, int>(4, 7));
}

void Chess::Board::deletePiece(std::pair<int, int> position)
{
	pieces_.erase(position);
}

void Chess::Board::updateState(std::pair<int, int> position)
{
	//qDebug() << "(" << position.first << ", " << position.second << ")";
	switch (currentState_)
	{
		case Chess::Board::State::WHITES_TURN:
			if (hasWhitePiece(position))
			{
				selectedPiece_ = pieces_.at(position);
				currentState_ = Chess::Board::State::WHITE_MOVE;
				for (auto it = selectedPiece_->cbegin(); it != selectedPiece_->cend(); it++)
				{
					emit colorAvailablePosition(*it);
				}
			}
			break;
		case Chess::Board::State::WHITE_MOVE:
			if (selectedPiece_->isValidMove(position))
			{
				movePiece(selectedPiece_->getPosition(), position);
				if (dynamic_cast<WhitePawn*>(selectedPiece_.get()) != nullptr && position.first == 0)
				{
					emit promoteWhitePawn(position);
				}
				updateAvailablePositionsWhite();
				if (isBlackKingCheckmate())
				{
					emit gameOver('W');
				}
				else if (isStalemate())
				{
					emit gameOver('D');
				}
				currentState_ = Chess::Board::State::BLACKS_TURN;
				emit resetButtons();
			}
			else if (hasWhitePiece(position))
			{
				selectedPiece_ = pieces_.at(position);
				emit resetButtons();
				for (auto it = selectedPiece_->cbegin(); it != selectedPiece_->cend(); it++)
				{
					emit colorAvailablePosition(*it);
				}
			}
			break;
		case Chess::Board::State::BLACKS_TURN:
			if (hasBlackPiece(position))
			{
				selectedPiece_ = pieces_.at(position);
				currentState_ = Chess::Board::State::BLACK_MOVE;
				for (auto it = selectedPiece_->cbegin(); it != selectedPiece_->cend(); it++)
				{
					emit colorAvailablePosition(*it);
				}
			}
			break;
		case Chess::Board::State::BLACK_MOVE:
			if (selectedPiece_->isValidMove(position))
			{
				movePiece(selectedPiece_->getPosition(), position);
				if (dynamic_cast<BlackPawn*>(selectedPiece_.get()) != nullptr && position.first == 7)
				{
					emit promoteBlackPawn(position);
				}
				updateAvailablePositionsBlack();
				if (isWhiteKingCheckmate())
				{
					emit gameOver('B');
				}
				else if (isStalemate())
				{
					emit gameOver('D');
				}
				currentState_ = Chess::Board::State::WHITES_TURN;
				emit resetButtons();
			}
			else if (hasBlackPiece(position))
			{
				selectedPiece_ = pieces_.at(position);
				emit resetButtons();
				for (auto it = selectedPiece_->cbegin(); it != selectedPiece_->cend(); it++)
				{
					emit colorAvailablePosition(*it);
				}
			}
			break;
	}
}

bool Chess::Board::isValidPosition(std::pair<int, int> position) const
{
	if (position.first < 0 || position.first > 7 || position.second < 0 || position.second > 7)
	{
		return false;
	}
	return true;
}

bool Chess::Board::hasWhitePiece(std::pair<int, int> position) const
{
	if (pieces_.find(position) != pieces_.end())
	{
		if (dynamic_cast<WhitePiece*>(pieces_.at(position).get()))
			return true;
	}
	return false;
}

bool Chess::Board::hasBlackPiece(std::pair<int, int> position) const
{
	if (pieces_.find(position) != pieces_.end())
	{
		if (dynamic_cast<BlackPiece*>(pieces_.at(position).get()))
			return true;
	}
	return false;
}

bool Chess::Board::isCoveredByWhite(std::pair<int, int> position1) const
{
	for (const auto& [position, piece] : pieces_)
	{
		if (dynamic_cast<WhitePiece*>(piece.get()) != nullptr)
		{
			if (piece->isValidMove(position1))
			{
				return true;
			}
		}
	}
	return false;
}

bool Chess::Board::isCoveredByBlack(std::pair<int, int> position1) const
{
	for (const auto& [position, piece] : pieces_)
	{
		if (dynamic_cast<BlackPiece*>(piece.get()) != nullptr)
		{
			if (piece->isValidMove(position1))
			{
				return true;
			}
		}
	}
	return false;
}

bool Chess::Board::isWhiteKingInCheck() const
{
	return isCoveredByBlack(getWhiteKingsPosition());
}

bool Chess::Board::isBlackKingInCheck() const
{
	return isCoveredByWhite(getBlackKingsPosition());
}

bool Chess::Board::isWhiteKingCheckmate() const
{
	for (const auto& [position, piece] : pieces_)
	{
		if (dynamic_cast<WhitePiece*>(piece.get()) != nullptr)
		{
			if (piece->canMove())
			{
				return false;
			}
		}
	}
	std::pair<int, int> kingsPosition = getWhiteKingsPosition();
	return isCoveredByBlack(kingsPosition);
}

bool Chess::Board::isBlackKingCheckmate() const
{
	for (const auto& [position, piece] : pieces_)
	{
		if (dynamic_cast<BlackPiece*>(piece.get()) != nullptr)
		{
			if (piece->canMove())
			{
				return false;
			}
		}
	}
	std::pair<int, int> kingsPosition = getBlackKingsPosition();
	return isCoveredByWhite(kingsPosition);
}

bool Chess::Board::isStalemate() const
{
	bool isWhiteStalemate = true;

	if (isCoveredByBlack(getWhiteKingsPosition()))
		isWhiteStalemate = false;

	for (const auto& [position, piece] : pieces_)
	{
		if (dynamic_cast<WhitePiece*>(piece.get()) != nullptr)
		{
			if (piece->canMove())
			{
				isWhiteStalemate = false;
			}
		}
	}

	bool isBlackStalemate = true;

	if (isCoveredByWhite(getBlackKingsPosition()))
		isBlackStalemate = false;

	for (const auto& [position, piece] : pieces_)
	{
		if (dynamic_cast<BlackPiece*>(piece.get()) != nullptr)
		{
			if (piece->canMove())
			{
				isBlackStalemate = false;
			}
		}
	}

	return isWhiteStalemate || isBlackStalemate;
}

void Chess::Board::updateAvailablePositionsWhite(bool isOneMoveAhead)
{
	for (const auto& [position, piece] : pieces_)
	{
		if (dynamic_cast<WhitePiece*>(piece.get()) != nullptr && dynamic_cast<WhiteKing*>(piece.get()) == nullptr)
			piece->findAvailablePositions(*this, isOneMoveAhead);
	}
	for (const auto& [position, piece] : pieces_)
	{
		if (dynamic_cast<BlackPiece*>(piece.get()) != nullptr && dynamic_cast<BlackKing*>(piece.get()) == nullptr)
			piece->findAvailablePositions(*this, isOneMoveAhead);
	}
	for (const auto& [position, piece] : pieces_)
	{
		if (dynamic_cast<WhiteKing*>(piece.get()) != nullptr)
			piece->findAvailablePositions(*this, isOneMoveAhead);
	}
	for (const auto& [position, piece] : pieces_)
	{
		if (dynamic_cast<BlackKing*>(piece.get()) != nullptr)
			piece->findAvailablePositions(*this, isOneMoveAhead);
	}
}

void Chess::Board::updateAvailablePositionsBlack(bool isOneMoveAhead)
{
	for (const auto& [position, piece] : pieces_)
	{
		if (dynamic_cast<BlackPiece*>(piece.get()) != nullptr && dynamic_cast<BlackKing*>(piece.get()) == nullptr)
			piece->findAvailablePositions(*this, isOneMoveAhead);
	}
	for (const auto& [position, piece] : pieces_)
	{
		if (dynamic_cast<WhitePiece*>(piece.get()) != nullptr && dynamic_cast<WhiteKing*>(piece.get()) == nullptr)
			piece->findAvailablePositions(*this, isOneMoveAhead);
	}
	for (const auto& [position, piece] : pieces_)
	{
		if (dynamic_cast<BlackKing*>(piece.get()) != nullptr)
			piece->findAvailablePositions(*this, isOneMoveAhead);
	}
	for (const auto& [position, piece] : pieces_)
	{
		if (dynamic_cast<WhiteKing*>(piece.get()) != nullptr)
			piece->findAvailablePositions(*this, isOneMoveAhead);
	}
}

void Chess::Board::movePiece(std::pair<int, int> oldPosition, std::pair<int, int> newPosition)
{
	if (dynamic_cast<WhitePawn*>(pieces_.at(oldPosition).get()) != nullptr && newPosition == enPassant_)
	{
		pieces_[newPosition] = std::move((pieces_.find(oldPosition))->second);
		deletePiece(oldPosition);
		std::pair<int, int> pawnPos = newPosition;
		pawnPos.first += 1;
		deletePiece(pawnPos);
		pieces_.at(newPosition)->setHasMoved(true);
		pieces_.at(newPosition)->setPosition(newPosition);
		emit pieceToDelete(oldPosition);
		emit pieceToDelete(pawnPos);
		emit pieceToDraw(pieces_.at(newPosition));
		return;
	}

	if (dynamic_cast<BlackPawn*>(pieces_.at(oldPosition).get()) != nullptr && newPosition == enPassant_)
	{
		pieces_[newPosition] = std::move((pieces_.find(oldPosition))->second);
		deletePiece(oldPosition);
		std::pair<int, int> pawnPos = newPosition;
		pawnPos.first -= 1;
		deletePiece(pawnPos);
		pieces_.at(newPosition)->setHasMoved(true);
		pieces_.at(newPosition)->setPosition(newPosition);
		emit pieceToDelete(oldPosition);
		emit pieceToDelete(pawnPos);
		emit pieceToDraw(pieces_.at(newPosition));
		return;
	}

	enPassant_ = std::pair<int, int>(-1, -1);

	if (oldPosition == std::pair<int, int>(7, 4) && newPosition == std::pair<int, int>(7, 6))
	{
		if (dynamic_cast<WhiteKing*>(pieces_.at(oldPosition).get()) != nullptr)
		{
			pieces_[newPosition] = std::move((pieces_.find(oldPosition))->second);
			pieces_[std::pair<int, int>(7, 5)] = std::move((pieces_.find(std::pair<int, int>(7, 7)))->second);
			deletePiece(oldPosition);
			deletePiece(std::pair<int, int>(7, 7));
			pieces_.at(newPosition)->setHasMoved(true);
			pieces_.at(std::pair<int, int>(7, 5))->setHasMoved(true);
			pieces_.at(newPosition)->setPosition(newPosition);
			pieces_.at(std::pair<int, int>(7, 5))->setPosition(std::pair<int, int>(7, 5));
			emit pieceToDelete(oldPosition);
			emit pieceToDelete(std::pair<int, int>(7, 7));
			emit pieceToDraw(pieces_.at(newPosition));
			emit pieceToDraw(pieces_.at(std::pair<int, int>(7, 5)));
			return;
		}
	}

	if (oldPosition == std::pair<int, int>(7, 4) && newPosition == std::pair<int, int>(7, 2))
	{
		if (dynamic_cast<WhiteKing*>(pieces_.at(oldPosition).get()) != nullptr)
		{
			pieces_[newPosition] = std::move((pieces_.find(oldPosition))->second);
			pieces_[std::pair<int, int>(7, 3)] = std::move((pieces_.find(std::pair<int, int>(7, 0)))->second);
			deletePiece(oldPosition);
			deletePiece(std::pair<int, int>(7, 0));
			pieces_.at(newPosition)->setHasMoved(true);
			pieces_.at(std::pair<int, int>(7, 3))->setHasMoved(true);
			pieces_.at(newPosition)->setPosition(newPosition);
			pieces_.at(std::pair<int, int>(7, 3))->setPosition(std::pair<int, int>(7, 3));
			emit pieceToDelete(oldPosition);
			emit pieceToDelete(std::pair<int, int>(7, 0));
			emit pieceToDraw(pieces_.at(newPosition));
			emit pieceToDraw(pieces_.at(std::pair<int, int>(7, 3)));
			return;
		}
	}

	if (oldPosition == std::pair<int, int>(0, 4) && newPosition == std::pair<int, int>(0, 6))
	{
		if (dynamic_cast<BlackKing*>(pieces_.at(oldPosition).get()) != nullptr)
		{
			pieces_[newPosition] = std::move((pieces_.find(oldPosition))->second);
			pieces_[std::pair<int, int>(0, 5)] = std::move((pieces_.find(std::pair<int, int>(0, 7)))->second);
			deletePiece(oldPosition);
			deletePiece(std::pair<int, int>(0, 7));
			pieces_.at(newPosition)->setHasMoved(true);
			pieces_.at(std::pair<int, int>(0, 5))->setHasMoved(true);
			pieces_.at(newPosition)->setPosition(newPosition);
			pieces_.at(std::pair<int, int>(0, 5))->setPosition(std::pair<int, int>(0, 5));
			emit pieceToDelete(oldPosition);
			emit pieceToDelete(std::pair<int, int>(0, 7));
			emit pieceToDraw(pieces_.at(newPosition));
			emit pieceToDraw(pieces_.at(std::pair<int, int>(0, 5)));
			return;
		}
	}

	if (oldPosition == std::pair<int, int>(0, 4) && newPosition == std::pair<int, int>(0, 2))
	{
		if (dynamic_cast<BlackKing*>(pieces_.at(oldPosition).get()) != nullptr)
		{
			pieces_[newPosition] = std::move((pieces_.find(oldPosition))->second);
			pieces_[std::pair<int, int>(0, 3)] = std::move((pieces_.find(std::pair<int, int>(0, 0)))->second);
			deletePiece(oldPosition);
			deletePiece(std::pair<int, int>(0, 0));
			pieces_.at(newPosition)->setHasMoved(true);
			pieces_.at(std::pair<int, int>(0, 3))->setHasMoved(true);
			pieces_.at(newPosition)->setPosition(newPosition);
			pieces_.at(std::pair<int, int>(0, 3))->setPosition(std::pair<int, int>(0, 3));
			emit pieceToDelete(oldPosition);
			emit pieceToDelete(std::pair<int, int>(0, 0));
			emit pieceToDraw(pieces_.at(newPosition));
			emit pieceToDraw(pieces_.at(std::pair<int, int>(0, 3)));
			return;
		}
	}

	if (dynamic_cast<WhitePawn*>(pieces_.at(oldPosition).get()) != nullptr && oldPosition.first == 6 && newPosition.first == 4)
	{
		std::pair<int, int> pos = oldPosition;
		pos.first -= 1;
		enPassant_ = pos;
	}
	else if (dynamic_cast<BlackPawn*>(pieces_.at(oldPosition).get()) != nullptr && oldPosition.first == 1 && newPosition.first == 3)
	{
		std::pair<int, int> pos = oldPosition;
		pos.first += 1;
		enPassant_ = pos;
	}

	if (pieces_.find(newPosition) != pieces_.end())
	{
		deletePiece(newPosition);
	}
	pieces_[newPosition] = std::move((pieces_.find(oldPosition))->second);
	deletePiece(oldPosition);
	pieces_.at(newPosition)->setHasMoved(true);
	pieces_.at(newPosition)->setPosition(newPosition);
	emit pieceToDelete(oldPosition);
	emit pieceToDraw(pieces_.at(newPosition));
}

void Chess::Board::simulateMove(std::pair<int, int> oldPosition, std::pair<int, int> newPosition)
{
	if (dynamic_cast<WhitePawn*>(pieces_.at(oldPosition).get()) != nullptr && newPosition == enPassant_)
	{
		pieces_[newPosition] = std::move((pieces_.find(oldPosition))->second);
		deletePiece(oldPosition);
		std::pair<int, int> pawnPos = newPosition;
		pawnPos.first += 1;
		deletePiece(pawnPos);
		pieces_.at(newPosition)->setHasMoved(true);
		pieces_.at(newPosition)->setPosition(newPosition);
		return;
	}

	if (dynamic_cast<BlackPawn*>(pieces_.at(oldPosition).get()) != nullptr && newPosition == enPassant_)
	{
		pieces_[newPosition] = std::move((pieces_.find(oldPosition))->second);
		deletePiece(oldPosition);
		std::pair<int, int> pawnPos = newPosition;
		pawnPos.first -= 1;
		deletePiece(pawnPos);
		pieces_.at(newPosition)->setHasMoved(true);
		pieces_.at(newPosition)->setPosition(newPosition);
		return;
	}

	enPassant_ = std::pair<int, int>(-1, -1);

	if (oldPosition == std::pair<int, int>(7, 4) && newPosition == std::pair<int, int>(7, 6))
	{
		if (dynamic_cast<WhiteKing*>(pieces_.at(oldPosition).get()) != nullptr)
		{
			pieces_[newPosition] = std::move((pieces_.find(oldPosition))->second);
			pieces_[std::pair<int, int>(7, 5)] = std::move((pieces_.find(std::pair<int, int>(7, 7)))->second);
			deletePiece(oldPosition);
			deletePiece(std::pair<int, int>(7, 7));
			pieces_.at(newPosition)->setHasMoved(true);
			pieces_.at(std::pair<int, int>(7, 5))->setHasMoved(true);
			pieces_.at(newPosition)->setPosition(newPosition);
			pieces_.at(std::pair<int, int>(7, 5))->setPosition(std::pair<int, int>(7, 5));
			return;
		}
	}

	if (oldPosition == std::pair<int, int>(7, 4) && newPosition == std::pair<int, int>(7, 2))
	{
		if (dynamic_cast<WhiteKing*>(pieces_.at(oldPosition).get()) != nullptr)
		{
			pieces_[newPosition] = std::move((pieces_.find(oldPosition))->second);
			pieces_[std::pair<int, int>(7, 3)] = std::move((pieces_.find(std::pair<int, int>(7, 0)))->second);
			deletePiece(oldPosition);
			deletePiece(std::pair<int, int>(7, 0));
			pieces_.at(newPosition)->setHasMoved(true);
			pieces_.at(std::pair<int, int>(7, 3))->setHasMoved(true);
			pieces_.at(newPosition)->setPosition(newPosition);
			pieces_.at(std::pair<int, int>(7, 3))->setPosition(std::pair<int, int>(7, 3));
			return;
		}
	}

	if (oldPosition == std::pair<int, int>(0, 4) && newPosition == std::pair<int, int>(0, 6))
	{
		if (dynamic_cast<BlackKing*>(pieces_.at(oldPosition).get()) != nullptr)
		{
			pieces_[newPosition] = std::move((pieces_.find(oldPosition))->second);
			pieces_[std::pair<int, int>(0, 5)] = std::move((pieces_.find(std::pair<int, int>(0, 7)))->second);
			deletePiece(oldPosition);
			deletePiece(std::pair<int, int>(0, 7));
			pieces_.at(newPosition)->setHasMoved(true);
			pieces_.at(std::pair<int, int>(0, 5))->setHasMoved(true);
			pieces_.at(newPosition)->setPosition(newPosition);
			pieces_.at(std::pair<int, int>(0, 5))->setPosition(std::pair<int, int>(0, 5));
			return;
		}
	}

	if (oldPosition == std::pair<int, int>(0, 4) && newPosition == std::pair<int, int>(0, 2))
	{
		if (dynamic_cast<BlackKing*>(pieces_.at(oldPosition).get()) != nullptr)
		{
			pieces_[newPosition] = std::move((pieces_.find(oldPosition))->second);
			pieces_[std::pair<int, int>(0, 3)] = std::move((pieces_.find(std::pair<int, int>(0, 0)))->second);
			deletePiece(oldPosition);
			deletePiece(std::pair<int, int>(0, 0));
			pieces_.at(newPosition)->setHasMoved(true);
			pieces_.at(std::pair<int, int>(0, 3))->setHasMoved(true);
			pieces_.at(newPosition)->setPosition(newPosition);
			pieces_.at(std::pair<int, int>(0, 3))->setPosition(std::pair<int, int>(0, 3));
			return;
		}
	}

	if (dynamic_cast<WhitePawn*>(pieces_.at(oldPosition).get()) != nullptr && oldPosition.first == 6 && newPosition.first == 4)
	{
		std::pair<int, int> pos = oldPosition;
		pos.first -= 1;
		enPassant_ = pos;
	}
	else if (dynamic_cast<BlackPawn*>(pieces_.at(oldPosition).get()) != nullptr && oldPosition.first == 1 && newPosition.first == 3)
	{
		std::pair<int, int> pos = oldPosition;
		pos.first += 1;
		enPassant_ = pos;
	}

	if (pieces_.find(newPosition) != pieces_.end())
	{
		deletePiece(newPosition);
	}
	pieces_[newPosition] = std::move((pieces_.find(oldPosition))->second);
	deletePiece(oldPosition);
	pieces_.at(newPosition)->setHasMoved(true);
	pieces_.at(newPosition)->setPosition(newPosition);
}

void Chess::Board::replacePiece(std::pair<int, int> position, char color, char piece)
{
	deletePiece(position);
	if (color == 'W')
	{
		switch (piece)
		{
		case 'Q':
			createWhiteQueen(position);
			break;
		case 'K':
			createWhiteKnight(position);
			break;
		case 'R':
			createWhiteRook(position);
			break;
		case 'B':
			createWhiteBishop(position);
			break;
		}
	}
	else if (color == 'B')
	{
		switch (piece)
		{
		case 'Q':
			createBlackQueen(position);
			break;
		case 'K':
			createBlackKnight(position);
			break;
		case 'R':
			createBlackRook(position);
			break;
		case 'B':
			createBlackBishop(position);
			break;
		}
	}
	emit pieceToDraw(pieces_.at(position));
}

std::shared_ptr<Piece> Chess::Board::getSelectedPiece() const
{
	return selectedPiece_;
}

std::pair<int, int> Chess::Board::getEnPassant() const
{
	return enPassant_;
}

std::pair<int, int> Chess::Board::getWhiteKingsPosition() const
{
	for (const auto& [position, piece] : pieces_)
	{
		if (dynamic_cast<WhiteKing*>(piece.get()) != nullptr)
		{
			return piece->getPosition();
		}
	}
	return std::pair<int, int>(-1, -1);
}

std::pair<int, int> Chess::Board::getBlackKingsPosition() const
{
	for (const auto& [position, piece] : pieces_)
	{
		if (dynamic_cast<BlackKing*>(piece.get()) != nullptr)
		{
			return piece->getPosition();
		}
	}
	return std::pair<int, int>(-1, -1);
}

std::unordered_map<std::pair<int, int>, std::shared_ptr<Piece>>::const_iterator Chess::Board::cbegin()
{
	return pieces_.cbegin();
}

std::unordered_map<std::pair<int, int>, std::shared_ptr<Piece>>::const_iterator Chess::Board::cend()
{
	return pieces_.cend();
}

std::shared_ptr<Piece> Chess::Board::getPiece(std::pair<int, int> position) const
{
	return pieces_.at(position);
}