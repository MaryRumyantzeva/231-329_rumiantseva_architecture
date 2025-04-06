#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QTextEdit>
#include <QPushButton>
#include "inetworkadapter.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr, INetworkAdapter *adapter = nullptr);
    ~MainWindow();

private slots:
    void sendRequest();
    void handleReply(QNetworkReply *reply);

private:
    QTextEdit *textEdit;
    QPushButton *fetchButton;
    INetworkAdapter *networkAdapter;
};


#endif // MAINWINDOW_H
