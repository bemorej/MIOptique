#ifndef WINDOW4_H
#define WINDOW4_H
#include <QWidget>


class QPushButton;
class Window4 : public QWidget
{
    Q_OBJECT

    public:
        explicit Window4(QWidget *parent = 0);

    private:
        QPushButton *m_button;
	//QProcess fibonacci;


};
#endif // WINDOW4_H
