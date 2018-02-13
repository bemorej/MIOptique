#ifndef WINDOW5_H
#define WINDOW5_H
#include <QWidget>


class QPushButton;
class Window5 : public QWidget
{
    Q_OBJECT

    public:
        explicit Window5(QWidget *parent = 0);

    private:
        QPushButton *m_button;


};
#endif // WINDOW5_H
