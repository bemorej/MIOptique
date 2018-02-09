#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QProcess>
#include <QString>
#include <QObject>
#include <QMessageBox>

class QPushButton;
class Window : public QWidget
{
	Q_OBJECT

	public:
		explicit Window(QWidget *parent = 0);
		//program = "./../testprog/fibonacci";
		//fibonacci = new QProcess(this);
	public slots:
		//void fibo_go(QString program);
		void fibo_go();
		//void fibo_info();
	private:
		QPushButton *m_button;
		QPushButton *go;
		QProcess *fibonacci;
		QString *program;
};

#endif // WINDOW_H
