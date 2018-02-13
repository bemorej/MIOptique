#ifndef WINDOW_H
#define WINDOW_H
#include "window2.h"
#include "window3.h"
#include "window4.h"
#include "window5.h"
#include <QWidget>


class QPushButton;
class Window : public QWidget
{
    Q_OBJECT

    public:
        explicit Window(QWidget *parent = 0);

    public slots:

        void afficher_window2();
        void afficher_window3();
        void afficher_window4();
        void afficher_window5();

    private:
        QPushButton *afficherwindow2;
        QPushButton *afficherwindow3;
        QPushButton *afficherwindow4;
        QPushButton *afficherwindow5;
        Window2 *fenetre2;
        Window3 *fenetre3;
        Window4 *fenetre4;
        Window5 *fenetre5;
};

#endif // WINDOW_H
