#include "mainwindow.h"
#include "networkmanager.h"
#include <QVBoxLayout>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

MainWindow::MainWindow(QWidget *parent, INetworkAdapter *adapter)
    : QMainWindow(parent), networkAdapter(adapter) {

    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout();

    fetchButton = new QPushButton("Fetch Data", this);
    textEdit = new QTextEdit(this);
    textEdit->setReadOnly(true);

    layout->addWidget(fetchButton);
    layout->addWidget(textEdit);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
    setWindowTitle("API Client Example");

    // Connect UI and adapter
    connect(fetchButton, &QPushButton::clicked, this, &MainWindow::sendRequest);
    connect(networkAdapter, &INetworkAdapter::replyReady, this, &MainWindow::handleReply);
}
MainWindow::~MainWindow() {}

void MainWindow::sendRequest() {
    QUrl url("http://localhost/book");
    NetworkManager::instance()->get(url);
}

void MainWindow::handleReply(QNetworkReply *reply) {
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray response = reply->readAll();
        QJsonDocument doc = QJsonDocument::fromJson(response);

        QString output;

        if (doc.isObject()) {
            QJsonObject obj = doc.object();
            for (const QString &key : obj.keys()) {
                output += QString("%1: %2\n").arg(key, obj.value(key).toVariant().toString());
            }
        } else if (doc.isArray()) {
            QJsonArray array = doc.array();
            for (const QJsonValue &val : array) {
                if (val.isObject()) {
                    QJsonObject obj = val.toObject();
                    for (const QString &key : obj.keys()) {
                        output += QString("%1: %2\n").arg(key, obj.value(key).toVariant().toString());
                    }
                    output += "\n";
                }
            }
        }

        textEdit->setText(output);

    } else {
        textEdit->setText("Error: " + reply->errorString());
    }
    reply->deleteLater();
}
