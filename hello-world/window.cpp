#include "window.h"
#include <QApplication>
#include <QPushButton>
#include <QString>

void Window :: fibo_go()
{
	QString program = "./../test-prog/fibonacci";
	fibonacci->start(program);
	//fibo_info();
	QMessageBox::information(this, "fibonacci", "fibonacci.dat created");

}

//void Window :: fibo_info()
//{
//	QMessageBox::information(this, "fibonacci", "fibonacci.dat created");
//}

Window::Window(QWidget *parent) :
	QWidget(parent)
{
	// Set size of the window
	int width = 500, height = 200 ;
	setFixedSize(width, height);

	//   // Create and position the button
	m_button = new QPushButton("Hello World", this);
	go  = new QPushButton( "Go",this   );
	fibonacci = new QProcess(this);
	//fibonacci->start(program);

	int wbutton = 80, hbutton = 30;
	int xbutton = (width-wbutton)/2, ybutton = (height-hbutton)/2;

	m_button->setGeometry(xbutton, ybutton, wbutton, hbutton);
	go->setGeometry(xbutton+150, ybutton, wbutton, hbutton);

	QObject::connect(m_button, SIGNAL(clicked()), qApp, SLOT(quit()));
	//QObject::connect(go, SIGNAL(clicked()), qApp, SLOT(quit()));
	//QObject::connect(go, SIGNAL(clicked()), qApp, SLOT(fibonacci()));
	//QObject::connect(go, SIGNAL(clicked()), qApp, SLOT(fibo_go()));
	QObject::connect(go, SIGNAL(clicked()), this, SLOT(fibo_go()));
	//connect(m_button, SIGNAL (clicked()), qApp, SLOT (quit()));
	//m_button->setGeometry(0, 0, 0, 0);
}

