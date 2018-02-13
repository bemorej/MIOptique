#include "window.h"
#include "window2.h"
#include "window3.h"
#include "window4.h"
#include "window5.h"
#include <QApplication>
#include <QPushButton>
#include <QString>
#include <QTextEdit>
#include <QFileDialog>
#include <QDebug>


void Window::afficher_window2()
{
    fenetre2 = new Window2();
    fenetre2->show();
}
void Window::afficher_window3()
{
    fenetre3 = new Window3();
    fenetre3->show();
}
void Window::afficher_window4()
{
    fenetre4 = new Window4();
    fenetre4->show();
}
void Window::afficher_window5()
{
    fenetre5 = new Window5();
    fenetre5->show();
}

Window::Window(QWidget *parent) :
    QWidget(parent)
{
    // Set size of the window
    int width = 400, height = 300;
    setFixedSize(width, height);
    afficherwindow2 = new QPushButton("Marjorie et Fatima", this);
    afficherwindow3 = new QPushButton("Hager, Sondes et Thina", this);
    afficherwindow4 = new QPushButton("Ying", this);
    afficherwindow5 = new QPushButton("Fibonacci", this);
    setWindowTitle(tr("MIOptique - Mon Interface Optique"));

    //placement des boutons
    int wbutton = 150, hbutton = 30;
    afficherwindow2->setGeometry(5, 5, wbutton, hbutton);
    afficherwindow3->setGeometry(5, 150, wbutton, hbutton);
    afficherwindow4->setGeometry(200, 5, wbutton, hbutton);
    afficherwindow5->setGeometry(200,150, wbutton, hbutton);


    QObject::connect(afficherwindow2, SIGNAL(clicked()), this, SLOT(afficher_window2()));
    QObject::connect(afficherwindow3, SIGNAL(clicked()), this, SLOT(afficher_window3()));
    QObject::connect(afficherwindow4, SIGNAL(clicked()), this, SLOT(afficher_window4()));
    QObject::connect(afficherwindow5, SIGNAL(clicked()), this, SLOT(afficher_window5()));


}

