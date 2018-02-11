#include "window2.h"
#include <QApplication>
#include <QPushButton>
#include <QString>
#include <QTextEdit>
#include <QFileDialog>
#include <QDebug>
Window2::Window2(QWidget *parent) :
	QWidget(parent)
{
	//Set size of the window
	int width = 500, height = 200 ;
	setFixedSize(width, height);
	m_button= new QPushButton("Hello World", this);
	QObject::connect(m_button, SIGNAL(clicked()), qApp, SLOT(quit()));
}

