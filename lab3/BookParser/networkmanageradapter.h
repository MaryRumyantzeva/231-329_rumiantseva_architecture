#ifndef NETWORKMANAGERADAPTER_H
#define NETWORKMANAGERADAPTER_H

#include "inetworkadapter.h"
#include "networkmanager.h"

class NetworkManagerAdapter : public INetworkAdapter {
    Q_OBJECT
public:
    explicit NetworkManagerAdapter(QObject *parent = nullptr) : INetworkAdapter(parent) {
        connect(NetworkManager::instance(), &NetworkManager::replyReady,
                this, &NetworkManagerAdapter::onReplyReceived);
    }

    void get(const QUrl &url) override {
        NetworkManager::instance()->get(url);
    }

private slots:
    void onReplyReceived(QNetworkReply *reply) {
        emit replyReady(reply);
    }
};

#endif // NETWORKMANAGERADAPTER_H
