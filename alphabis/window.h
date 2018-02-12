#ifndef WINDOW_H
#define WINDOW_H
#include "window2.h"
#include <QWidget>
#include <QLineEdit>
#include <QTextStream>
#include <QLabel>
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
		void affiche();

	private:
		QPushButton *afficherwindow2;
		QPushButton *writeintofiletoto;
		QPushButton *writeintofiletoto2;
		QPushButton *exitButton;
		Window2 *fenetre;
		QLineEdit *echoLineEdit;
		QLabel *label;
};
#endif // WINDOW_H
