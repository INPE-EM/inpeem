#include "MainWindow.h"
#include "ui_MainWindow.h"

//#include <QLayout>
#include <QTabWidget>

//#include "ModelDefinitionsWidget.h"
//#include "Tab.h"
#include "CentralWidget.h"

qt::modelmanager::MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

	QIcon appIcon("icon.ico");
	this->setWindowIcon(appIcon);

	// remove the old translator
	qApp->removeTranslator(&translator);
	// load the new translator
	QString path = QApplication::applicationDirPath();
	// path.append("/langs/");
	if (translator.load(":/modelmanager_pt_br.qm")) 
		qApp->installTranslator(&translator);

	this->setCentralWidget(new CentralWidget(this));
}

qt::modelmanager::MainWindow::~MainWindow()
{
    delete ui;
}
