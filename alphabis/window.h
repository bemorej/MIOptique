#ifndef WINDOW_H
#define WINDOW_H
#include "window2.h"
#include <QWidget>
class QPushButton;
class Window : public QWidget
{
	Q_OBJECT
	public:
		explicit Window(QWidget *parent = 0);
		public slots:
			void afficher_window2();
	private:
		QPushButton *afficherwindow2;
		Window2 *fenetre;
};
#endif // WINDOW_H
