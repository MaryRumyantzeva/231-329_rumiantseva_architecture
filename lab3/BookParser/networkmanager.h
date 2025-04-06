#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrl>

class NetworkManager : public QObject {
    Q_OBJECT

public:
    static NetworkManager* instance(); // Singleton accessor

    void get(const QUrl& url);

signals:
    void replyReady(QNetworkReply *reply); // signal to send response to UI

private:
    explicit NetworkManager(QObject *parent = nullptr);
    QNetworkAccessManager *manager;

private slots:
    void onFinished(QNetworkReply *reply);
};

#endif // NETWORKMANAGER_H
