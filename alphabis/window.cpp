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

void Window::writeintofile2(QString *text)
{
	QString filename="./../ying/toto";
	QFile file( filename );
	if ( file.open(QIODevice::WriteOnly) )
	{
		QTextStream stream( &file );
		stream << text << endl;
		file.close();
	}
}

void Window::buttonClicked()
{
	const QString text = echoLineEdit -> text();
	QString filename="./../ying/toto";
	QFile file( filename );
	if ( file.open(QIODevice::WriteOnly) )
	{
		QTextStream stream( &file );
		stream << text << endl;
		file.close();
	}
}

void Window::affiche()
{
	QString filename="./../ying/toto";
	QFile file( filename );
	//QLabel *testLabel= new QLabel;

	QString line;
	if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
		QTextStream stream(&file);
		while (!stream.atEnd()){
			line.append(stream.readLine()+"\n");
		}
		//testLabel->setText(line);
		label->setText(line);
	}
	file.close();
}

Window::Window(QWidget *parent) :
	QWidget(parent)
{
	// Set size of the window
	int width = 500, height = 200 ;
	setFixedSize(width, height);
	afficherwindow2 = new QPushButton("afficherwindow2", this);
	writeintofiletoto = new QPushButton("Write", this);
	exitButton = new QPushButton("Exit", this);
	int wbutton = 80, hbutton = 30;
	int xbutton = (width-wbutton)/2, ybutton = (height-hbutton)/2;
	//
	//QLineEdit *edit = new QLineEdit("");

	
	afficherwindow2->setGeometry(xbutton, ybutton, wbutton, hbutton);
	writeintofiletoto->setGeometry(xbutton+50, ybutton, wbutton, hbutton);
	exitButton->setGeometry(width-wbutton-10, height-hbutton-10, wbutton, hbutton);

	/* */
	QGroupBox *echoGroup = new QGroupBox(tr("Ying"),this);


	QLabel *ying_label = new QLabel("Entrer L#/S#/D# sep -", this);

	QFile file("./../ying/toto");
	QLabel *testLabel= new QLabel;

	QString line;
	if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
		QTextStream stream(&file);
		while (!stream.atEnd()){

			line.append(stream.readLine()+"\n");
		}
		testLabel->setText(line);
	}
	file.close();
	//QLabel *echoLabel = new QLabel(tr("Mode:"),this);
	//QComboBox *echoComboBox = new QComboBox;
	//echoComboBox->addItem(tr("Normal"));
	//echoComboBox->addItem(tr("Password"));
	//echoComboBox->addItem(tr("PasswordEchoOnEdit"));
	//echoComboBox->addItem(tr("No Echo"));

	echoLineEdit = new QLineEdit(this);
	echoLineEdit->setPlaceholderText("Placeholder Text");
	echoLineEdit->setFocus();

	QString titi;

	//QObject::connect(echoLineEdit, SIGNAL(returnPressed()), echoLineEdit, SLOT(setText()));
	//titi = echoLineEdit->text();
	//
	//QString filename="./../ying/toto";
	//QFile file( filename );
	//if ( file.open(QIODevice::ReadWrite) )
	//{
	//	QTextStream stream( &file );
	//	stream << echoLineEdit->text();
	//	QObject::connect(echoLineEdit, SIGNAL(clicked(returnPressed())), this, SLOT(writeintofile2(stream)));
	//}

	//test NE COMPILE PAS
	//QObject::connect(echoLineEdit, &QLineEdit::textChanged, [](const QString& text)
	//		{
	//		QFile file("output.txt");

	//		if(file.open(QFile::WriteOnly | QFile::Text)) {
	//		QTextStream stream(&file);
	//		stream << text;
	//		}
	//		});
	//
	// vv Bouton box
	writeintofiletoto2 = new QPushButton("Write toto", this);

	QGridLayout *echoLayout = new QGridLayout;
	echoLayout->addWidget(ying_label, 0, 0);
	echoLayout->addWidget(echoLineEdit, 1, 0);
	echoLayout->addWidget(writeintofiletoto2, 1, 1);
	echoLayout->addWidget(testLabel, 2, 1);
	//echoLayout->addWidget(echoComboBox, 0, 1);

	echoGroup->setLayout(echoLayout);
	/* */


	QObject::connect(afficherwindow2, SIGNAL(clicked()), this, SLOT(afficher_window2()));
	QObject::connect(exitButton, SIGNAL(clicked()), qApp, SLOT(quit()));
	QObject::connect(writeintofiletoto, SIGNAL(clicked()), this, SLOT(writeintofile()));
	QObject::connect(writeintofiletoto2, SIGNAL(clicked()), this, SLOT(buttonClicked()));
	//QObject::connect(, SIGNAL(returnPressed()), this, SLOT(affiche()));
}
