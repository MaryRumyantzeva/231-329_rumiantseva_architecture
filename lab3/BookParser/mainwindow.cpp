#include "mainwindow.h"
#include "networkmanager.h"
#include "book.h"
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

        if (doc.isArray()) {
            QJsonArray array = doc.array();
            QList<Book> books;

            for (const QJsonValue &val : array) {
                if (val.isObject()) {
                    QJsonObject obj = val.toObject();
                    Book book = Book::fromJson(obj);
                    books.append(book);
                    output += book.toString() + "\n";
                }
            }
        } else if (doc.isObject()) {
            Book book = Book::fromJson(doc.object());
            output += book.toString();
        }

        textEdit->setText(output);

    } else {
        textEdit->setText("Error: " + reply->errorString());
    }

    reply->deleteLater();
}
