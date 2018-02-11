#include "window.h"
#include "window2.h"
#include <QApplication>
#include <QPushButton>
#include <QString>
#include <QTextEdit>
#include <QFileDialog>
#include <QDebug>
#include <QLineEdit>
#include <QGroupBox>
#include <QLabel>
#include <QComboBox>
#include <QGridLayout>
void Window::afficher_window2()
{
	//Window2 *window = new Window2(this);
	//window->show();
	fenetre = new Window2();
	fenetre->show();
}

void Window::writeintofile()
{
	QString filename="./../ying/toto";
	QFile file( filename );
	if ( file.open(QIODevice::ReadWrite) )
	{
		QTextStream stream( &file );
		stream << "something" << endl;
	}
}

Window::Window(QWidget *parent) :
	QWidget(parent)
{
	// Set size of the window
	int width = 500, height = 200 ;
	setFixedSize(width, height);
	afficherwindow2 = new QPushButton("afficherwindow2", this);
	writeintofiletoto = new QPushButton("Write", this);
	int wbutton = 80, hbutton = 30;
	int xbutton = (width-wbutton)/2, ybutton = (height-hbutton)/2;
	//
	//QLineEdit *edit = new QLineEdit("");

	
	afficherwindow2->setGeometry(xbutton, ybutton, wbutton, hbutton);
	writeintofiletoto->setGeometry(xbutton+50, ybutton, wbutton, hbutton);
	/* */
	QGroupBox *echoGroup = new QGroupBox(tr("Ying"),this);

	//QLabel *echoLabel = new QLabel(tr("Mode:"),this);
	//QComboBox *echoComboBox = new QComboBox;
	//echoComboBox->addItem(tr("Normal"));
	//echoComboBox->addItem(tr("Password"));
	//echoComboBox->addItem(tr("PasswordEchoOnEdit"));
	//echoComboBox->addItem(tr("No Echo"));

	echoLineEdit = new QLineEdit(this);
	echoLineEdit->setPlaceholderText("Placeholder Text");
	echoLineEdit->setFocus();

	echoLineEdit->text();
	//echoLineEdit->setGeometry(,,20,20);

	QGridLayout *echoLayout = new QGridLayout;
	echoLayout->addWidget(echoLineEdit, 0, 0);
	//echoLayout->addWidget(echoComboBox, 0, 1);

	echoGroup->setLayout(echoLayout);
	/* */


	QObject::connect(afficherwindow2, SIGNAL(clicked()), this, SLOT(afficher_window2()));
	QObject::connect(writeintofiletoto, SIGNAL(clicked()), this, SLOT(writeintofile()));
}
