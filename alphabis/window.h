#ifndef WINDOW_H
#define WINDOW_H
#include "window2.h"
#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QTextStream>
#include <QLabel>
#include <QGroupBox>
#include <QDebug>
#include <QFileDialog>
#include <QObject>
#include <QProcess>
#include <QMessageBox>
class QPushButton;
class Window : public QWidget
{
	Q_OBJECT
	public:
		explicit Window(QWidget *parent = 0);

	public slots:
		void afficher_window2();
		void writeintofile();
		void writeintofile2(QString *);
		void buttonClicked();
		void buttonClickedmj();
		//void affiche();
		void go_ying();
		void go_MJ();
		void relai_go_ying();
		void relai_go_mj();

	private:
		QGroupBox *GroupYing();
		QGroupBox *GroupMarjoFat();
		QPushButton *afficherwindow2;
		QPushButton *writeintofiletoto;
		QPushButton *writeintofiletoto2;
		QPushButton *writeintofilemj;
		QPushButton *exitButton;
		QPushButton *goButton;
		QPushButton *relai_goButton;
		QPushButton *relai_goButton2;
		QPushButton *goButtonMJ;
		QLineEdit *echoLineEdit;
		QLineEdit *mjLineEdit;
		//QLabel *label;
		QLabel *ying_label;
		//QLabel *ying_label;
		QProcess *ying_process;
		QProcess *relai_ying_process;
		QProcess *relai_mj_process;
		QProcess *MJ_process;
		Window2 *fenetre;
};
#endif // WINDOW_H
