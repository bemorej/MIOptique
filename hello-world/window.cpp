#include "window.h"
#include <QApplication>
#include <QPushButton>
#include <QString>
#include <QTextEdit>
#include <QFileDialog>
#include <QDebug>


void Window :: fibo_go()
{
	QString program = "./../test-prog/fibonacci";
	fibonacci->start(program);
	//fibo_info();
	QMessageBox::information(this, "fibonacci", "fibonacci.dat created");
}

void Window :: readfile(){
	QString filename="fibonacci.dat";
	QFile file(filename);
	if(!file.exists()){
		qDebug() << "NO existe el archivo "<<filename;
	}else{
		qDebug() << filename<<" encontrado...";
	}
	QString line;
	//ui->textEdit->clear();
	if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
		QTextStream stream(&file);
		while (!stream.atEnd()){
			line = stream.readLine();
			//ui->textEdit->setText(ui->textEdit->toPlainText()+line+"\n");
			qDebug() << "linea: "<<line;
		}
	}
	file.close();
}

void Window :: affiche_texte()
{
	QString fic_resultats = "./fibonacci.dat";
	QString fichier = QFileDialog::getOpenFileName(this, "Ouvrir un fichier", fic_resultats);
	//Window aff;
	//aff.setModal(true);
	//QTextEdit zoneTexte;
	//zoneTexte.setGeometry(100,100,400,200);
	//zoneTexte.setReadOnly(true);
	//QString texte;
	//QFile fichier("fibonacci.dat");

	//if(fichier.open(QIODevice::ReadOnly | QIODevice::Text))
	//{
	//	texte = fichier.readAll();
	//	fichier.close();
	//}
	//else texte = "Impossible d'ouvrir le fichier !";

	//zoneTexte.setText(texte);
	//zoneTexte.show();
	//aff.exec();
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
	affiche_resultat = new QPushButton( "Resultats",this   );
	fibonacci = new QProcess(this);
	//fibonacci->start(program);

	int wbutton = 80, hbutton = 30;
	int xbutton = (width-wbutton)/2, ybutton = (height-hbutton)/2;

	m_button->setGeometry(xbutton, ybutton, wbutton, hbutton);
	go->setGeometry(xbutton+150, ybutton, wbutton, hbutton);
	affiche_resultat->setGeometry(xbutton+150, ybutton-40, wbutton, hbutton);

	QObject::connect(m_button, SIGNAL(clicked()), qApp, SLOT(quit()));
	//QObject::connect(go, SIGNAL(clicked()), qApp, SLOT(quit()));
	//QObject::connect(go, SIGNAL(clicked()), qApp, SLOT(fibonacci()));
	//QObject::connect(go, SIGNAL(clicked()), qApp, SLOT(fibo_go()));
	QObject::connect(go, SIGNAL(clicked()), this, SLOT(fibo_go()));
	//QObject::connect(affiche_resultat, SIGNAL(clicked()), this, SLOT(affiche_texte()));
	QObject::connect(affiche_resultat, SIGNAL(clicked()), this, SLOT(readfile()));
	//connect(m_button, SIGNAL (clicked()), qApp, SLOT (quit()));
	//m_button->setGeometry(0, 0, 0, 0);
}

