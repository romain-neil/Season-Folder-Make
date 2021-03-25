#ifndef FENPRINCIPALE_H
#define FENPRINCIPALE_H

#include <QWidget>
#include <iostream>

#include <QMainWindow>
#include "foldercreatethread.h"
#include "verifyupdatethread.h"

class QDialog;
class QGridLayout;
class QGroupBox;
class QLineEdit;
class QMenu;
class QPalette;
class QPushButton;
class QStringList;
class QSpinBox;
class QTableWidget;
class QTableWidgetItem;

class AboutDialog;
class Core;

#include <QMap>

/**
 * @since 1.0.0
 */
class FenPrincipale : public QMainWindow {

    Q_OBJECT

    public:
        FenPrincipale();

        Core *c;

    public slots:

        /**
         * @brief mSelectFolder
         * @author Romain Neil
		 * @since 2.2.1
         */
        void mSelectFolder();

        /**
         * @brief mAddFolder
         * @author Romain Neil
		 * @since 2.2.1
         */
        void mAddFolder();

        /**
         * @brief mAboutPopup
         * @author Romain neil
		 * @since 2.2.1
         */
        void mAboutPopup();

        /**
         * @brief mCheckForUpdates
         * @author Romain Neil
		 * @since 2.2.3
         */
        void mCheckForUpdates();

        /**
         * @brief Show success message dialog
         * @author Romain Neil
         * @since 2.4.0
         */
        void mShowSuccess();

		/**
		 * @brief Function called when update verification is done
		 * @author Romain Neil
		 * @since 2.5.0
		 */
		void mUpdateFinished();

        /**
         * @brief Set the prefix to the user specified input
         * @author Romain Neil
		 * @since 2.2.0
         */
        void mSetPrefix();

        /**
         * @brief Run the main process to create dirs
         * @author Romain Neil
		 * @since 2.2.0
         */
        void mRun();

        /**
         * @brief mVerifyDir
         * @param url
         * @author Romain Neil
		 * @since 2.2.1
         */
        void mVerifyDir(const QString &url);

    private:

        /**
         * @brief Create correspondant actions
         * @author Romain Neil
		 * @since 2.2.1
         */
        void createActions();

        /**
         * @brief Create menus
         * @author Romain Neil
		 * @since 2.2.1
         */
        void createMenus();

        AboutDialog *aboutDialog{};

        QMap<int, QMap<int, QString>> liste;

        int totalItems{};

        FolderCreateThread *folderCreationThread{};
		VerifyUpdateThread *verifyUpdateThread{};

        QAction *actQuitter{};
        QAction *actAbout{};
		QAction *actAboutQt{};
		QAction *m_actionChangeLang{};
		QAction *actSetPrefix{};
		QAction *actVerifyUpdate{};

        QDialog *diagAbout{};

        QGridLayout *fSelect;
        QGridLayout *layout;
        QGridLayout *recap;

        QGroupBox *folderSelectionGr;
        QGroupBox *listeGr;

        QMenu *menuFile{};
        QMenu *menuSettings{};
		QMenu *menuHelp{};

        QLineEdit *folder;

        QVector<QTableWidgetItem *>listeItems;

        QSpinBox *nbFolder2Create;

        QPushButton *selectFolder;
        QPushButton *addSelectedFolder;
        QPushButton *startBtn;

        QTableWidget *tableWidget{};

        QWidget *widget;


};

#endif // FENPRINCIPALE_H
