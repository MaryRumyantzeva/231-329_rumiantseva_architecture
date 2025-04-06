#include <QApplication>
#include "mainwindow.h"
#include "networkmanageradapter.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    NetworkManagerAdapter *adapter = new NetworkManagerAdapter();
    MainWindow w(nullptr, adapter);
    w.show();

    return a.exec();
}
