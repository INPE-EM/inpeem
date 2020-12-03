#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H

#include <QWidget>

namespace Ui {
class CentralWidget;
}

namespace qt
{
	namespace modelmanager
	{
		class CentralWidget : public QWidget
		{
			Q_OBJECT

		public:
			explicit CentralWidget(QWidget *parent = nullptr);
			~CentralWidget();

		private:
			Ui::CentralWidget *ui;
		};
	}
}

#endif // CENTRALWIDGET_H
