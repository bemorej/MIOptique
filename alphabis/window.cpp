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

//void Window::affiche()
//{
//	QString filename="./../ying/toto";
//	QFile file( filename );
//	//QLabel *testLabel= new QLabel;
//
//	QString line;
//	if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
//		QTextStream stream(&file);
//		while (!stream.atEnd()){
//			line.append(stream.readLine()+"\n");
//		}
//		//testLabel->setText(line);
//		label->setText(line);
//	}
//	file.close();
//}

Window::Window(QWidget *parent) :
	QWidget(parent)
{
	/* Parametre fenetre */
	// Set size of the window
	int width = 1000, height = 600;
	setFixedSize(width, height);
	//resize(width,height);
	setWindowTitle(tr("MIOptique - Mon Interface Optique"));
	/* Parametre bouton */
	int wbutton = 80, hbutton = 30;
	//int xbutton = (width-wbutton)/2, ybutton = (height-hbutton)/2;
	
	QGridLayout *grid = new QGridLayout;
	grid->addWidget(GroupYing(), 0, 0);
	grid->addWidget(GroupMarjoFat(), 0, 1);
	setLayout(grid);

	/* Initialisation bouton */
	//afficherwindow2 = new QPushButton("afficherwindow2", this);
	//writeintofiletoto = new QPushButton("Write", this);
	exitButton = new QPushButton("Exit", this);
	
	//afficherwindow2->setGeometry(xbutton, ybutton, wbutton, hbutton);
	//writeintofiletoto->setGeometry(xbutton+50, ybutton, wbutton, hbutton);
	exitButton->setGeometry(width-wbutton-10, height-hbutton-10, wbutton, hbutton);



	//QObject::connect(afficherwindow2, SIGNAL(clicked()), this, SLOT(afficher_window2()));
	QObject::connect(exitButton, SIGNAL(clicked()), qApp, SLOT(quit()));
	//QObject::connect(writeintofiletoto, SIGNAL(clicked()), this, SLOT(writeintofile()));
	//QObject::connect(, SIGNAL(returnPressed()), this, SLOT(affiche()));
}

/* Programme Ying */
QGroupBox *Window::GroupYing()
{
	QGroupBox *yingGroup = new QGroupBox(tr("Ying"),this);

	ying_label = new QLabel("Entrer L#/S#/D# sep -", this);
	goButton  = new QPushButton( "Go",this);
	relai_goButton  = new QPushButton( "Go terminal",this);
	ying_process = new QProcess(this);

	echoLineEdit = new QLineEdit(this);
	echoLineEdit->setPlaceholderText("Placeholder Text");
	echoLineEdit->setFocus();

	/*  */
	QFile file("./../prog/ying/toto");
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
	/*  */

	//QLabel *echoLabel = new QLabel(tr("Mode:"),this);
	//QComboBox *echoComboBox = new QComboBox;
	//echoComboBox->addItem(tr("Normal"));
	//echoComboBox->addItem(tr("Password"));
	//echoComboBox->addItem(tr("PasswordEchoOnEdit"));
	//echoComboBox->addItem(tr("No Echo"));


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
	echoLayout->addWidget(goButton, 2, 2);
	echoLayout->addWidget(relai_goButton, 2, 3);
	echoLayout->addWidget(testLabel, 2, 1);
	yingGroup->setLayout(echoLayout);

	/* */
	QObject::connect(writeintofiletoto2, SIGNAL(clicked()), this, SLOT(buttonClicked()));
	QObject::connect(goButton, SIGNAL(clicked()), this, SLOT(go_ying()));
	QObject::connect(relai_goButton, SIGNAL(clicked()), this, SLOT(relai_go_ying()));
	return yingGroup;
}

QGroupBox *Window::GroupMarjoFat()
{
	QGroupBox *marjofatGroup= new QGroupBox(tr("Marjorie Fatima"),this);

	relai_goButton2 = new QPushButton("Go relai", this);
	writeintofilemj = new QPushButton("Write par", this);
	goButtonMJ = new QPushButton("Go", this);

	mjLineEdit = new QLineEdit(this);
	mjLineEdit->setPlaceholderText("Placeholder Text");
	mjLineEdit->setFocus();

	QGridLayout *MJLayout = new QGridLayout;
	MJLayout->addWidget(relai_goButton2, 0, 0);
	MJLayout->addWidget(mjLineEdit, 1, 0);
	MJLayout->addWidget(writeintofilemj, 2, 0);
	MJLayout->addWidget(goButtonMJ, 3, 0);
	marjofatGroup->setLayout(MJLayout);

	/* */
	QObject::connect(relai_goButton2, SIGNAL(clicked()), this, SLOT(relai_go_mj()));
	QObject::connect(writeintofilemj, SIGNAL(clicked()), this, SLOT(buttonClickedmj()));
	QObject::connect(goButtonMJ, SIGNAL(clicked()), this, SLOT(go_MJ()));
	return marjofatGroup;
}

void Window::go_ying()
{
	QString program = "./../prog/ying/a.out";
	ying_process->start(program);
	//QMessageBox::information(this, "fibonacci", "fibonacci.dat created");
}
void Window::go_MJ()
{
	QString program = "./../prog/marjofat/marjofat";
	MJ_process->start(program);
	QMessageBox::information(this, "fibonacci", "fibonacci.dat created");
}

void Window::relai_go_ying()
{
	QString program2 = "./../prog/ying/relai_ying";
	relai_ying_process->start(program2);
	//QMessageBox::information(this, "fibonacci", "fibonacci.dat created");
}

void Window::relai_go_mj()
{
	QString program2 = "./../prog/marjofat/relai_mj";
	relai_mj_process->start(program2);
	//QMessageBox::information(this, "fibonacci", "fibonacci.dat created");
}

void Window::afficher_window2()
{
	//Window2 *window = new Window2(this);
	//window->show();
	fenetre = new Window2();
	fenetre->show();
}

void Window::writeintofile()
{
	QString filename="./../prog/ying/toto";
	QFile file( filename );
	if ( file.open(QIODevice::ReadWrite) )
	{
		QTextStream stream( &file );
		stream << "something" << endl;
	}
}

void Window::writeintofile2(QString *text)
{
	QString filename="./../prog/ying/toto";
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
	QString filename="./../prog/ying/toto";
	QFile file( filename );
	if ( file.open(QIODevice::WriteOnly) )
	{
		QTextStream stream( &file );
		stream << text << endl;
		file.close();
	}
}

void Window::buttonClickedmj()
{
	const QString text = mjLineEdit -> text();
	QString filename="./../prog/marjofat/par";
	QFile file( filename );
	if ( file.open(QIODevice::WriteOnly) )
	{
		QTextStream stream( &file );
		stream << text << endl;
		file.close();
	}
}
