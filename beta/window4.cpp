#include "window4.h"
#include <QApplication>
#include <QPushButton>
#include <QString>
#include <QTextEdit>
#include <QFileDialog>
#include <QDebug>





Window4::Window4(QWidget *parent) :
    QWidget(parent)
{
    // Set size of the window
    int width = 500, height = 200 ;
    setFixedSize(width, height);
    m_button= new QPushButton("Hello World4", this);



    QObject::connect(m_button, SIGNAL(clicked()), qApp, SLOT(quit()));

}
