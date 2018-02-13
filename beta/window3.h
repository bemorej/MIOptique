#ifndef WINDOW3_H
#define WINDOW3_H
#include <QWidget>
#include <QProcess>
#include <QString>

class QPushButton;
class Window3 : public QWidget
{
    Q_OBJECT

    public:
        explicit Window3(QWidget *parent = 0);
public slots:
    void haguersondes_go();
    void haguersondes_go_gnu();
    private:
        QPushButton *m_button;
        QProcess *haguersondes;
        QProcess *haguersondes_gnu;
        QString *program;
        QPushButton *m_button2;


};
#endif // WINDOW3_H
