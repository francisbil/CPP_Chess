/**
* Implémentation classe WelcomeWindow
* \file   WelcomeWindow.cpp
* \author Francis Bilodeau-Lecomte
* \date   6 mai 2022
* Créé le 24 avril 2022
*/

#include "WelcomeWindow.hpp"

WelcomeWindow::WelcomeWindow(QWidget *parent)
	: QDialog(parent)
{
	setWindowFlags(windowFlags() & ~Qt::WindowCloseButtonHint);
	setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
	setWindowTitle("Chess");
	setWindowIcon(QIcon("Images/WhiteKing.png"));

	auto mainWidget = new QWidget(this);
	mainWidget->setFixedSize(300, 220);

	auto mainLayout = new QVBoxLayout(mainWidget);
	mainLayout->setSpacing(0);
	mainLayout->setMargin(0);

	auto textLabel = new QLabel;
	QFont font("Berlin Sans FB", 30);
	textLabel->setFont(font);
	textLabel->setText("Choose a mode.");
	textLabel->setAlignment(Qt::AlignCenter);
	mainLayout->addWidget(textLabel);

	QPushButton* button1 = new QPushButton;
	button1->setText("Normal Mode");
	button1->setSizePolicy(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::MinimumExpanding);
	button1->setProperty("mode", QVariant::fromValue<int>(1));
	mainLayout->addWidget(button1);
	QObject::connect(button1, SIGNAL(clicked()), parent, SLOT(startGame()));
	QObject::connect(button1, SIGNAL(clicked()), this, SLOT(close()));

	QPushButton* button2 = new QPushButton;
	button2->setText("Polgar vs. Kasparov, 1996 (white to move)");
	button2->setSizePolicy(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::MinimumExpanding);
	button2->setProperty("mode", QVariant::fromValue<int>(2));
	mainLayout->addWidget(button2);
	QObject::connect(button2, SIGNAL(clicked()), parent, SLOT(startGame()));
	QObject::connect(button2, SIGNAL(clicked()), this, SLOT(close()));

	QPushButton* button3 = new QPushButton;
	button3->setText("Karpov vs. Ftacnik, 1988 (black to move)");
	button3->setSizePolicy(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::MinimumExpanding);
	button3->setProperty("mode", QVariant::fromValue<int>(3));
	mainLayout->addWidget(button3);
	QObject::connect(button3, SIGNAL(clicked()), parent, SLOT(startGame()));
	QObject::connect(button3, SIGNAL(clicked()), this, SLOT(close()));

	QPushButton* button4 = new QPushButton;
	button4->setText("Tinman vs. Lutz, 1995 (black to move)");
	button4->setSizePolicy(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::MinimumExpanding);
	button4->setProperty("mode", QVariant::fromValue<int>(4));
	mainLayout->addWidget(button4);
	QObject::connect(button4, SIGNAL(clicked()), parent, SLOT(startGame()));
	QObject::connect(button4, SIGNAL(clicked()), this, SLOT(close()));
}

void WelcomeWindow::keyPressEvent(QKeyEvent* e)
{
	if (e->key() == Qt::Key_Escape)
		return;

	QDialog::keyPressEvent(e);
}
