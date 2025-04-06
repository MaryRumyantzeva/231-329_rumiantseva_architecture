#ifndef INETWORKADAPTER_H
#define INETWORKADAPTER_H

#include <QObject>
#include <QUrl>
#include <QNetworkReply>

class INetworkAdapter : public QObject {
    Q_OBJECT
public:
    explicit INetworkAdapter(QObject *parent = nullptr) : QObject(parent) {}
    virtual void get(const QUrl &url) = 0;

signals:
    void replyReady(QNetworkReply *reply);
};

#endif // INETWORKADAPTER_H
