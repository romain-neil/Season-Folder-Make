#include <QDir>
#include <QJsonObject>
#include <QTableWidget>

#include "core.h"

Core::Core() {
    firstRun = settings.value("firstRun", true).toBool();
    prefix = settings.value("prefix", "Saison").toString();

    settings.setValue("firstRun", false);
}

QString Core::getPrefix() const {
    return this->prefix;
}

bool Core::isFirstRun() const {
    return this->firstRun;
}

void Core::process(QMap<std::size_t, QMap<int, QString>> &liste, QDir &dir) {
    if(!liste.empty()) {
        const auto& m1 = liste.toStdMap();
        for(const auto& p1 : m1) {
            const auto& m2 = p1.second.toStdMap();
            for(const auto& p2 : m2) {
                dir.setPath(p2.second);
                int nb = p2.first;

                QString path;

                for(int j = 1; j <= nb; j++) {
                    path = dir.absolutePath() + "/" + prefix + " " + QString::number(j);
                    dir.mkpath(path);
                }
            }
        }
    }
}

void Core::setFirstRun() {
    settings.setValue("firstRun", true);
}

void Core::setPrefix(const QString& p) {
    settings.setValue("prefix", p);
}
