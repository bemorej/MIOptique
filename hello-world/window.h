#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QProcess>
#include <QString>

class QPushButton;
class Window : public QWidget
{
	public:
		explicit Window(QWidget *parent = 0);
		//QString program = "./../testprog/fibonacci";
		//fibonacci = new QProcess(this);
	//private slots:
	//	void fibo_go()
	//	{
	//		fibonacci->start(&program);
	//	}
	private:
		QPushButton *m_button;
		QPushButton *go;
		QProcess *fibonacci;
		//QString *program;
};

#endif // WINDOW_H
