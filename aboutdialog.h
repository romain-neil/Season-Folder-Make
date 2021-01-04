#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QString>

class AboutDialog : public QDialog {

    Q_OBJECT

    public:
        explicit AboutDialog(QWidget *parent = nullptr);

    private:

        QLabel *versionText;
        QLabel *aboutText;
        QLabel *compilTime;

        QVBoxLayout *l;
};

#endif // ABOUTDIALOG_H
