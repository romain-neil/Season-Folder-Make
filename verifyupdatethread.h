#ifndef VERIFYUPDATETHREAD_H
#define VERIFYUPDATETHREAD_H

#include <QThread>
#include <QtNetwork/QtNetwork>
#include <QMessageBox>

class VerifyUpdateThread : public QThread {

	public:
		explicit VerifyUpdateThread(QObject *parent = nullptr);
		~VerifyUpdateThread() override;

		QNetworkReply* getReply();

	public slots:

		static void onRequestError(QNetworkReply::NetworkError err);

		void onRequestFinished();

	protected:

		void run() override;

	private:

		QNetworkAccessManager *m_nam;
		QNetworkReply *reply{};

		static QString getUpdateUrl();

};

#endif // VERIFYUPDATETHREAD_H
