#include "qapplication.h"
#include "aboutdialog.h"

AboutDialog::AboutDialog(QWidget *parent) {
    versionText = new QLabel(tr("Current version : ") + qApp->applicationVersion());
	aboutText = new QLabel(tr("Copyright Romain Neil - 2020"), this);
	compilTime = new QLabel(QString("Compile on ") + QString(__DATE__) + " at " + QString(__TIME__) + " with Qt v" + QT_VERSION_STR);

    l = new QVBoxLayout;

    l->addWidget(versionText);
    l->addWidget(aboutText);
    l->addWidget(compilTime);

    setLayout(l);

    setParent(parent);
    setModal(true);
    show();
}
