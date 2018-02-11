#ifndef WINDOW_H
#define WINDOW_H
#include "window2.h"
#include <QWidget>
#include <QLineEdit>
class QPushButton;
class Window : public QWidget
{
	Q_OBJECT
	public:
		explicit Window(QWidget *parent = 0);

	public slots:
		void afficher_window2();
		void writeintofile();

	private:
		QPushButton *afficherwindow2;
		QPushButton *writeintofiletoto;
		Window2 *fenetre;
		QLineEdit *echoLineEdit;
};
#endif // WINDOW_H
