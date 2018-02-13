#include "window3.h"
#include <QApplication>
#include <QPushButton>
#include <QString>
#include <QTextEdit>
#include <QFileDialog>
#include <QDebug>



void Window3 :: haguersondes_go()
{
    QString program = "g/haguersondes/gnuplot/binary/relai";
    //haguersondes->start(program);
    haguersondes->start("gnome-terminal", QStringList() << "-e" << "./../prog/sht/a.out");

    //QMessageBox::information(this, "optique", " created");
}
void Window3 :: haguersondes_go_gnu()
{
    QString program = "g/haguersondes/gnuplot/binary/relai";
    //haguersondes->start(program);
    haguersondes_gnu->start("gnuplot", QStringList() << "./../prog/sht/out.gnu");

    //QMessageBox::information(this, "optique", " created");
}

Window3::Window3(QWidget *parent) :
    QWidget(parent)
{
    // Set size of the window
    int width = 500, height = 200 ;
    setFixedSize(width, height);
    m_button= new QPushButton("optique", this);
    m_button2= new QPushButton("gnuplot", this);
    m_button2->setGeometry(0, 40, 40, 40);
    haguersondes = new QProcess(this);
    haguersondes_gnu = new QProcess(this);


    QObject::connect(m_button, SIGNAL(clicked()), this, SLOT(haguersondes_go()
    ));

}
