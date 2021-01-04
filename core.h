#ifndef CORE_H
#define CORE_H

#include <cmath>
#include <QApplication>
#include <QMessageBox>
#include <QString>
#include <QSystemTrayIcon>
#include <QWidget>
#include <QMap>
#include <QSettings>
#include <QProgressBar>

class FenPrincipale;
class QDir;
class QMessageBox;

class Core : public QObject {

    public:

        Core();

        /**
         * @brief Return the current prefix
         * @author Romain Neil
		 * @since 2.2.1
         * @return QString
         */
		[[nodiscard]] QString getPrefix() const;

        /**
         * @brief Return true if this is the first start of the application
         * @author Romain Neil
		 * @since 2.2.1
         * @return true | false
         */
        [[nodiscard]] bool isFirstRun() const;

        /**
         * @brief Process logic for creatings the folders
         * @author Romain Neil
         * @param const QMap<int, QMap<int, QString>> &liste
         * @param const QDir &dir
         * @param const QString &prefix
		 * @since 2.2.0
         */
        void process(QMap<int, QMap<int, QString>> &liste, QDir &dir);

        /**
         * @brief Set first run to true
         * @author Romain Neil
		 * @since 2.2.3
         */
        void setFirstRun();

        /**
         * @brief Set the prefix
         * @author Romain Neil
         * @param QString p
		 * @since 2.2.1
         */
        void setPrefix(const QString& p);

    private:

        QSettings settings;

        QString currentVersion = qApp->applicationVersion();

        QString prefix;

        bool firstRun;
};

#endif // CORE_H
