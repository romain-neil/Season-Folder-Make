#include <iostream>
#include "verifyupdatethread.h"

VerifyUpdateThread::VerifyUpdateThread(QObject *parent) : QThread(parent) {
	this->m_nam = new QNetworkAccessManager();
}

VerifyUpdateThread::~VerifyUpdateThread() {
	delete this->m_nam;
}

QNetworkReply* VerifyUpdateThread::getReply() {
	return reply;
}

void VerifyUpdateThread::onRequestError(QNetworkReply::NetworkError err) {
	QMessageBox::critical(nullptr, tr("Erreur"), tr("Une erreur est survenue lors de la requête au serveur de mise à jour. Merci de réessayer plus tard."));

#ifdef QT_DEBUG
	qDebug() << err;
#endif
}

void VerifyUpdateThread::onRequestFinished() {
	if(reply->error() == QNetworkReply::NoError) {
		QByteArray data = reply->readAll();

		qDebug() << "Données recues :";
		std::cout << data.toStdString() << std::endl;
	} else {
		//Error occured
		QMessageBox::critical(nullptr, tr("Erreur"), tr("Une erreur est survenue lors de la recherche de mise à jour. Merci de réessayer plus tard"));
	}

	reply->close();
}

void VerifyUpdateThread::run() {
	QNetworkRequest req;

	req.setUrl(VerifyUpdateThread::getUpdateUrl());
	req.setRawHeader("User-Agent", "SFM Web Client v1.0");

	reply = this->m_nam->get(req);

	connect(reply, SIGNAL(finished()), this, SLOT(onRequestFinished()));
	connect(reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(onRequestError(QNetworkReply::NetworkError)));
}

QString VerifyUpdateThread::getUpdateUrl() {
	return QString("https://dl.tutosfaciles48.fr/softwares/sfm/update.json");
}
