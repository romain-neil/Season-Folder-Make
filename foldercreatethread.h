#ifndef FOLDERCREATETHREAD_H
#define FOLDERCREATETHREAD_H

#include <QThread>
#include <QDir>
#include <QMap>
#include <QString>

class FolderCreateThread : public QThread {

	public:

		explicit FolderCreateThread(QObject *parent = nullptr);
		~FolderCreateThread() override;

		void setParams(QMap<int, QMap<int, QString>> &liste, QDir &dir, QString &p);

	protected:

		void run() override;

	private:

		QMap<int, QMap<int, QString>> l;
		QDir d;
		QString prefix;

};

#endif // FOLDERCREATETHREAD_H
