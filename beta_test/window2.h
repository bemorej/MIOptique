#ifndef WINDOW2_H
#define WINDOW2_H

#include <QWidget>
#include <QProcess>
#include <QString>
#include <QFileDialog>
#include <QLineEdit>
class QPushButton;
class QProcess;
class QString;
class Window2 : public QWidget
{
    Q_OBJECT

    public:
        explicit Window2(QWidget *parent = 0);
    public slots:
        void marjofat_go();
        void writeintofile();
    private:
        QPushButton *m_button;
        QProcess *marjofat;
        QString *program;
        QPushButton *writeintofiletoto;
        QLineEdit *echoLineEdit;
};

#endif // WINDOW2_H
