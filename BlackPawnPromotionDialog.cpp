/**
* Implémentation classe BlackPawnPromotionDialog
* \file   BlackPawnPromotionDialog.cpp
* \author Francis Bilodeau-Lecomte
* \date   6 mai 2022
* Créé le 24 avril 2022
*/

#include "BlackPawnPromotionDialog.hpp"

BlackPawnPromotionDialog::BlackPawnPromotionDialog(std::pair<int, int> position, QWidget* parent)
	: QDialog(parent)
{
	setWindowFlags(windowFlags() & ~Qt::WindowCloseButtonHint);
	setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
	setWindowTitle("Black Pawn Promotion");
	setWindowIcon(QIcon("Images/WhiteKing.png"));

	auto mainWidget = new QWidget(this);
	mainWidget->setFixedSize(360, 140);

	auto mainLayout = new QVBoxLayout(mainWidget);
	mainLayout->setSpacing(0);
	mainLayout->setMargin(0);

	auto textLabel = new QLabel;
	QFont font("Berlin Sans FB", 30);
	textLabel->setFont(font);
	textLabel->setText("Promote to : ");
	textLabel->setAlignment(Qt::AlignCenter);
	mainLayout->addWidget(textLabel);

	auto buttonLayout = new QHBoxLayout();
	buttonLayout->setSpacing(0);
	buttonLayout->setMargin(0);
	mainLayout->addLayout(buttonLayout);

	QPushButton* button1 = new QPushButton;
	button1->setSizePolicy(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::MinimumExpanding);
	button1->setFixedSize(90, 90);
	button1->setFlat(true);
	button1->setIcon(QIcon(QString::fromStdString("Images/BlackQueen.png")));
	button1->setIconSize(QSize(90, 90));
	button1->setProperty("piece", QVariant::fromValue<char>('Q'));
	button1->setProperty("color", QVariant::fromValue<char>('B'));
	button1->setProperty("position", QVariant::fromValue<std::pair<int, int>>(position));
	buttonLayout->addWidget(button1);
	QObject::connect(button1, SIGNAL(clicked()), parent, SLOT(handlePawnPromotion()));
	QObject::connect(button1, SIGNAL(clicked()), this, SLOT(close()));

	QPushButton* button2 = new QPushButton;
	button2->setSizePolicy(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::MinimumExpanding);
	button2->setFixedSize(90, 90);
	button2->setFlat(true);
	button2->setIcon(QIcon(QString::fromStdString("Images/BlackKnight.png")));
	button2->setIconSize(QSize(90, 90));
	button2->setProperty("piece", QVariant::fromValue<char>('K'));
	button2->setProperty("color", QVariant::fromValue<char>('B'));
	button2->setProperty("position", QVariant::fromValue<std::pair<int, int>>(position));
	buttonLayout->addWidget(button2);
	QObject::connect(button2, SIGNAL(clicked()), parent, SLOT(handlePawnPromotion()));
	QObject::connect(button2, SIGNAL(clicked()), this, SLOT(close()));

	QPushButton* button3 = new QPushButton;
	button3->setSizePolicy(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::MinimumExpanding);
	button3->setFixedSize(90, 90);
	button3->setFlat(true);
	button3->setIcon(QIcon(QString::fromStdString("Images/BlackRook.png")));
	button3->setIconSize(QSize(90, 90));
	button3->setProperty("piece", QVariant::fromValue<char>('R'));
	button3->setProperty("color", QVariant::fromValue<char>('B'));
	button3->setProperty("position", QVariant::fromValue<std::pair<int, int>>(position));
	buttonLayout->addWidget(button3);
	QObject::connect(button3, SIGNAL(clicked()), parent, SLOT(handlePawnPromotion()));
	QObject::connect(button3, SIGNAL(clicked()), this, SLOT(close()));

	QPushButton* button4 = new QPushButton;
	button4->setSizePolicy(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::MinimumExpanding);
	button4->setFixedSize(90, 90);
	button4->setFlat(true);
	button4->setIcon(QIcon(QString::fromStdString("Images/BlackBishop.png")));
	button4->setIconSize(QSize(90, 90));
	button4->setProperty("piece", QVariant::fromValue<char>('B'));
	button4->setProperty("color", QVariant::fromValue<char>('B'));
	button4->setProperty("position", QVariant::fromValue<std::pair<int, int>>(position));
	buttonLayout->addWidget(button4);
	QObject::connect(button4, SIGNAL(clicked()), parent, SLOT(handlePawnPromotion()));
	QObject::connect(button4, SIGNAL(clicked()), this, SLOT(close()));
}

void BlackPawnPromotionDialog::keyPressEvent(QKeyEvent* e)
{
	if (e->key() == Qt::Key_Escape)
		return;

	QDialog::keyPressEvent(e);
}
