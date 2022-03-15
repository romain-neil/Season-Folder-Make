#include "foldercreatethread.h"

FolderCreateThread::FolderCreateThread(QObject *parent) : QThread(parent) {}

FolderCreateThread::~FolderCreateThread() {
	l.clear();
	prefix.clear();

	exit();
	wait();
}

void FolderCreateThread::setParams(QMap<std::size_t, QMap<int, QString>> &liste, QDir &dir, QString &p) {
	l = liste;
	d = dir;
	prefix = p;
}

void FolderCreateThread::run() {
	if(!l.empty()) {
		const auto& m1 = l.toStdMap();

		for(const auto& p1 : m1) {
			const auto& m2 = p1.second.toStdMap();

			for(const auto& p2 : m2) {
				d.setPath(p2.second);
				int nb = p2.first;

				QString path;

				for(int j = 1; j <= nb; j++) {
					path = d.absolutePath() + "/" + prefix + " " + QString::number(j);
					d.mkpath(path);
				}
			}
		}
	}
}
