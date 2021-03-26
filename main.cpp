#include <QApplication>
#include <QtWidgets>

#include "fenprincipale.h"

int main(int argc, char* argv[]) {
    QCoreApplication::addLibraryPath(".");
    QApplication app(argc, argv);

    QString locale = QLocale::system().name().section('_', 0, 0);
    QString appTranslationDir = QApplication::applicationDirPath() + "/translations/";

    QTranslator translator;
    translator.load(QString("qtbase_") + locale, QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    QApplication::installTranslator(&translator);

    QTranslator appTranslator;

    if(appTranslator.load(appTranslationDir + locale + ".qm")) {
        QApplication::installTranslator(&appTranslator);
    }

	QApplication::setOrganizationName("tutosfaciles48");
	QApplication::setOrganizationDomain("SeasonFolderMake");
	QApplication::setApplicationVersion("2.3.0");
    QApplication::setApplicationName("Season Folder Make");

#ifdef QT_DEBUG
    foreach (const QString &path, app.libraryPaths())
        qDebug() << path;
    	qDebug() << __FILE__;

    qDebug() << "C++ standard: " << __cplusplus;
    qDebug() << "Locale : " << locale << ", translation path: " << appTranslationDir;
#endif

    FenPrincipale fen;
    fen.show();

    return QApplication::exec();
}
