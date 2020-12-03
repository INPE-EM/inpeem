#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTranslator>

namespace Ui {
class MainWindow;
}

namespace qt 
{
	namespace modelmanager
	{
		class MainWindow : public QMainWindow
		{
			Q_OBJECT

		public:
			explicit MainWindow(QWidget *parent = nullptr);
			~MainWindow();

		private:
			Ui::MainWindow *ui;
			QTranslator translator;
		};
	}
}

#endif // MAINWINDOW_H
