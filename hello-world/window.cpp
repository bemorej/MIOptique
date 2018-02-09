#include "window.h"
#include <QApplication>
#include <QPushButton>
#include <QString>

Window::Window(QWidget *parent) :
	QWidget(parent)
{
	// Set size of the window
	int width = 500, height = 200 ;
	setFixedSize(width, height);

	//   // Create and position the button
	QString program = "./../test-prog/fibonacci";
	m_button = new QPushButton("Hello World", this);
	go  = new QPushButton( "Go",this   );
	fibonacci = new QProcess(this);
	fibonacci->start(program);

	int wbutton = 80, hbutton = 30;
	int xbutton = (width-wbutton)/2, ybutton = (height-hbutton)/2;

	m_button->setGeometry(xbutton, ybutton, wbutton, hbutton);
	go->setGeometry(xbutton+50, ybutton+50, wbutton, hbutton);

	QObject::connect(m_button, SIGNAL(clicked()), qApp, SLOT(quit()));
	//QObject::connect(go, SIGNAL(clicked()), qApp, SLOT(quit()));
	QObject::connect(go, SIGNAL(clicked()), qApp, SLOT(fibonacci()));
	//connect(m_button, SIGNAL (clicked()), qApp, SLOT (quit()));
	//m_button->setGeometry(0, 0, 0, 0);
}

