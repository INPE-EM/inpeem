#include "ModelDefinitionsWidget.h"
#include "ui_ModelDefinitionsWidget.h"

#include <QFileDialog>

qt::modelmanager::ModelDefinitionsWidget::ModelDefinitionsWidget(QWidget *parent) :
	QWidget(parent), ui(new Ui::ModelDefinitionsWidget)
{
	ui->setupUi(this);
	ui->pushButton->setAutoDefault(false);
	connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(selectDir()));
}

qt::modelmanager::ModelDefinitionsWidget::~ModelDefinitionsWidget()
{
	delete ui;
}

void qt::modelmanager::ModelDefinitionsWidget::selectDir()
{
	QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
					"/home",
					QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
	ui->label_2->setText(dir);
}