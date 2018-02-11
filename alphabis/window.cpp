#include "window.h"
#include "window2.h"
#include <QApplication>
#include <QPushButton>
#include <QString>
#include <QTextEdit>
#include <QFileDialog>
#include <QDebug>
void Window::afficher_window2()
{
	Window2 *window = new Window2(this);
	//window->show();
	fenetre = new Window2();
	fenetre->show();
}
Window::Window(QWidget *parent) :
	QWidget(parent)
{
	// Set size of the window
	int width = 500, height = 200 ;
	setFixedSize(width, height);
	afficherwindow2 = new QPushButton("afficherwindow2", this);
	int wbutton = 80, hbutton = 30;
	int xbutton = (width-wbutton)/2, ybutton = (height-hbutton)/2;
	afficherwindow2->setGeometry(xbutton, ybutton, wbutton, hbutton);
	QObject::connect(afficherwindow2, SIGNAL(clicked()), this, SLOT(afficher_window2()));
}
