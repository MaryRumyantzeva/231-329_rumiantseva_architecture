#include "networkmanager.h"

NetworkManager* NetworkManager::instance() {
    static NetworkManager instance; // thread-safe singleton
    return &instance;
}

NetworkManager::NetworkManager(QObject *parent)
    : QObject(parent), manager(new QNetworkAccessManager(this)) {
    connect(manager, &QNetworkAccessManager::finished, this, &NetworkManager::onFinished);
}

void NetworkManager::get(const QUrl &url) {
    QNetworkRequest request(url);
    manager->get(request);
}

void NetworkManager::onFinished(QNetworkReply *reply) {
    emit replyReady(reply); // forward to whoever listens (e.g., MainWindow)
}
