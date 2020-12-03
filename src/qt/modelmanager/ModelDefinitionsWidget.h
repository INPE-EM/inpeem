#ifndef MODELDEFINITIONSWIDGET_H
#define MODELDEFINITIONSWIDGET_H

#include <QWidget>

namespace Ui {
	class ModelDefinitionsWidget;
}

namespace qt
{
	namespace modelmanager
	{
		class ModelDefinitionsWidget : public QWidget
		{
			Q_OBJECT

		public:
			explicit ModelDefinitionsWidget(QWidget *parent = nullptr);
			virtual ~ModelDefinitionsWidget();

		private slots:
			void selectDir();

		private:
			Ui::ModelDefinitionsWidget *ui;
		};
	}
}

#endif MODELDEFINITIONSWIDGET_H
