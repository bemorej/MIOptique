#ifndef WINDOW2_H
#define WINDOW2_H
#include <QWidget>
class QPushButton;
class Window2 : public QWidget
{
	Q_OBJECT
	public:
		explicit Window2(QWidget *parent = 0);
	private:
		QPushButton *m_button;
};
#endif // WINDOW2_H
