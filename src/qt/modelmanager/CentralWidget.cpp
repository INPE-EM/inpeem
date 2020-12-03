#include "CentralWidget.h"
#include "ui_CentralWidget.h"

#include "ModelDefinitionsWidget.h"

qt::modelmanager::CentralWidget::CentralWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CentralWidget)
{
    ui->setupUi(this);
	
	QPixmap img(":/img/inpeem.png");
	ui->label->setPixmap(img.scaled(QSize(250, 250), Qt::KeepAspectRatio, Qt::SmoothTransformation));

	QTabWidget *tabWidget = new QTabWidget(this);
	qt::modelmanager::ModelDefinitionsWidget *modelDefsTab = new 
								qt::modelmanager::ModelDefinitionsWidget(this);
	tabWidget->addTab(modelDefsTab, tr("Model Definitions"));
	ui->verticalLayout_2->layout()->addWidget(tabWidget);
}

qt::modelmanager::CentralWidget::~CentralWidget()
{
    delete ui;
}
