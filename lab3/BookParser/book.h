#ifndef BOOK_H
#define BOOK_H

#include <QString>
#include <QDate>
#include <QJsonObject>
#include <QJsonValue>

class Book {
public:
    QString author;
    QDate year;
    QString genre;
    int count;
    bool isAvailable;

    Book();

    // Метод для десериализации данных из JSON
    void fromJson(const QJsonObject &json);
};

#endif // BOOK_H

