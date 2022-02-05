#include <QApplication>
#include <QtWidgets>

#include "fenprincipale.h"

int main(int argc, char* argv[]) {
    QCoreApplication::addLibraryPath(".");
    QApplication app(argc, argv);

    QString locale = QLocale::system().name().section('_', 0, 0);
    QString appTranslationDir = QApplication::applicationDirPath() + "/translations/";

    QTranslator translator;
    translator.load(QString("qt_") + locale, QLibraryInfo::path(QLibraryInfo::TranslationsPath));
    QApplication::installTranslator(&translator);

    QTranslator appTranslator;

    if(appTranslator.load(appTranslationDir + "sfm_" + locale + ".qm")) {
         QApplication::installTranslator(&appTranslator);
    }

	QApplication::setOrganizationName("tutosfaciles48");
	QApplication::setOrganizationDomain("SeasonFolderMake");
	QApplication::setApplicationVersion("2.3.0");
    QApplication::setApplicationName("Season Folder Make");

    FenPrincipale fen;
    fen.show();

    return QApplication::exec();
}
