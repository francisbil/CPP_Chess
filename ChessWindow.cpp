/**
* Implémentation classe ChessWindow
* \file   ChessWindow.cpp
* \author Francis Bilodeau-Lecomte
* \date   6 mai 2022
* Créé le 24 avril 2022
*/

#include <utility>
#include <iostream>
#include "ChessWindow.hpp"
#include "Piece.hpp"
#include "WhitePawnPromotionDialog.hpp"
#include "BlackPawnPromotionDialog.hpp"
#include "WelcomeWindow.hpp"

using namespace Ui;

ChessWindow::ChessWindow(QWidget *parent) :
	QMainWindow(parent)
{
	WelcomeWindow window = WelcomeWindow(this);
	window.setModal(true);
	window.exec();

	auto mainWidget = new QWidget(this);
	mainWidget->setObjectName("mainwidget");
	mainWidget->setFixedSize(720, 720);
	
	auto mainLayout = new QGridLayout(mainWidget);
	mainLayout->setSpacing(0);
	mainLayout->setMargin(0);
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			QPushButton* button = new QPushButton;
			button->setProperty("position", QVariant::fromValue<std::pair<int, int>>(std::pair<int, int>(i, j)));
			button->setFlat(true);
			button->setSizePolicy(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::MinimumExpanding);
			button->setFixedSize(90, 90);
			button->setStyleSheet("border: 1px solid black");
			QObject::connect(button, SIGNAL(clicked()), this, SLOT(buttonPressed()));
			mainLayout->addWidget(button, i, j);
			buttons_[i][j] = button;
		}
	}

	mainWidget->setStyleSheet("#mainwidget { background-image: url(Images/Chessboard.png) } ");

	setCentralWidget(mainWidget);
	setWindowTitle("Chess");
	setWindowIcon(QIcon("Images/WhiteKing.png"));

	drawAllPieces();

	QObject::connect(board_, SIGNAL(pieceToDelete(std::pair<int, int>)), this, SLOT(undrawPiece(std::pair<int, int>)));
	QObject::connect(board_, SIGNAL(pieceToDraw(std::shared_ptr<Piece>)), this, SLOT(drawPiece(std::shared_ptr<Piece>)));
	QObject::connect(board_, SIGNAL(gameOver(char)), this, SLOT(gameOverWindow(char)));
	QObject::connect(board_, SIGNAL(promoteWhitePawn(std::pair<int, int>)), this, SLOT(whitePawnPromotionWindow(std::pair<int, int>)));
	QObject::connect(board_, SIGNAL(promoteBlackPawn(std::pair<int, int>)), this, SLOT(blackPawnPromotionWindow(std::pair<int, int>)));
	QObject::connect(board_, SIGNAL(colorAvailablePosition(std::pair<int, int>)), this, SLOT(colorButton(std::pair<int, int>)));
	QObject::connect(board_, SIGNAL(resetButtons()), this, SLOT(uncolorButtons()));
}

ChessWindow::~ChessWindow()
{
	delete board_;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			delete buttons_[i][j];
		}
	}
}

void ChessWindow::buttonPressed()
{
	board_->updateState(QObject::sender()->property("position").value<std::pair<int, int>>());
}

void ChessWindow::handlePawnPromotion()
{
	char piece = QObject::sender()->property("piece").value<char>();
	char color = QObject::sender()->property("color").value<char>();
	std::pair<int, int> position = QObject::sender()->property("position").value<std::pair<int, int>>();
	board_->replacePiece(position, color, piece);
}

void ChessWindow::drawPiece(const std::shared_ptr<Piece> piece)
{
	buttons_[piece->getPosition().first][piece->getPosition().second]->setIcon(QIcon(QString::fromStdString(piece->getImagePath())));
	buttons_[piece->getPosition().first][piece->getPosition().second]->setIconSize(QSize(90, 90));
}

void ChessWindow::undrawPiece(std::pair<int, int> position)
{
	buttons_[position.first][position.second]->setIcon(QIcon());
}

void ChessWindow::drawAllPieces()
{
	for (auto it = board_->cbegin(); it != board_->cend(); it++)
	{
		drawPiece(it->second);
	}
}

void ChessWindow::gameOverWindow(char winner)
{
	QMessageBox* messageBox = new QMessageBox(this);
	messageBox->setWindowTitle("Game over");
	std::string message;
	if (winner == 'W')
	{
		message = "White has won! Press OK to quit game.";
	}
	else if (winner == 'B')
	{
		message = "Black has won! Press OK to quit game.";
	}
	else if (winner == 'D')
	{
		message = "Draw (stalemate)! Press OK to quit game.";
	}
	messageBox->setText(QString::fromStdString(message));
	messageBox->setWindowIcon(QIcon("Images/WhiteKing.png"));
	messageBox->setFixedWidth(500);
	messageBox->setStandardButtons(QMessageBox::Ok);
	QSpacerItem* horizontalSpacer = new QSpacerItem(100, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
	QGridLayout* layout = (QGridLayout*)messageBox->layout();
	layout->addItem(horizontalSpacer, layout->rowCount(), 0, 1, layout->columnCount());
	QObject::connect(messageBox, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(close()));
	messageBox->exec();
}

void ChessWindow::whitePawnPromotionWindow(std::pair<int, int> position)
{
	WhitePawnPromotionDialog dialog = WhitePawnPromotionDialog(position, this);
	dialog.setModal(true);
	dialog.exec();
}

void ChessWindow::blackPawnPromotionWindow(std::pair<int, int> position)
{
	BlackPawnPromotionDialog dialog = BlackPawnPromotionDialog(position, this);
	dialog.setModal(true);
	dialog.exec();
}

void ChessWindow::colorButton(std::pair<int, int> position)
{
	buttons_[position.first][position.second]->setFlat(false);
	buttons_[position.first][position.second]->setStyleSheet("background-color: rgb(255, 238, 141); border: 1px solid black");
}

void ChessWindow::uncolorButtons()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			buttons_[i][j]->setFlat(true);
			buttons_[i][j]->setStyleSheet("border: 1px solid black");
		}
	}
}

void ChessWindow::startGame()
{
	int mode = QObject::sender()->property("mode").value<int>();
	board_ = new Chess::Board(mode);
}

