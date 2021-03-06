#include "window2.h"
#include <QApplication>
#include <QPushButton>
#include <QString>
#include <QTextEdit>
#include <QFileDialog>
#include <QStringList>
#include <QDebug>
#include <QLineEdit>
#include <QGroupBox>
#include <QLabel>
#include <QComboBox>
#include <QGridLayout>
void Window2 :: marjofat_go()
{
    QString program;
    program = "./../prog/marjofat/relai_mj";
    //marjofat->start("/bin/bash",QStringList() << "-c" << "/home/jbouton/upmc/mio/info/projet_info/MIOptique/prog/marjofat/relai_mj");
    //marjofat->start("xterm",QStringList() << "-e" << "/home/jbouton/upmc/mio/info/projet_info/MIOptique/prog/marjofat/relai_mj");
    //marjofat->start("xterm",QStringList() << "-e" << "./../prog/marjofat/relai_mj");
    marjofat->start("gnome-terminal", QStringList() << "-e" << "./../prog/marjofat/marjofat_relai");
    //marjofat->start(program);
    marjofat->waitForFinished();
    ////marjofat->write("/home/jbouton/upmc/mio/info/projet_info/MIOptique/prog/marjofat/marjofat_relai");
    //QString output = marjofat->readAllStandardOutput();
    //marjofat->close();
    //marjofat->waitForFinished();
    //QByteArray output = marjofat->readAll();
    //marjofat->close();

    //QProcess::startDetached("H:/mio/prog/marjofat/marjofat.exe");
    //QMessageBox::information(this, "marjofat", " created");
}
void Window2::writeintofile()
{
    QString filename="H:/mio/prog/marjofat/toto";
    QFile file( filename );
    if ( file.open(QIODevice::ReadWrite) )
    {
        QTextStream stream( &file );
        stream << "something"<<endl;
    }
}


Window2::Window2(QWidget *parent) :
    QWidget(parent)
{
    // Set size of the window
    int width = 500, height = 200 ;
    setFixedSize(width, height);    
    marjofat = new QProcess(this);
    writeintofiletoto = new QPushButton("Write", this);
    m_button= new QPushButton("conversion", this);
    //placement des boutons
    int wbutton = 80, hbutton = 30;
    writeintofiletoto->setGeometry(160, 16, wbutton, hbutton);
    m_button->setGeometry(5, 150, wbutton, hbutton);


    QGroupBox *echoGroup = new QGroupBox(tr("scanf"),this);
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

    QObject::connect(m_button, SIGNAL(clicked()), this, SLOT(marjofat_go()));
    QObject::connect(writeintofiletoto, SIGNAL(clicked()), this, SLOT(writeintofile()));
}



