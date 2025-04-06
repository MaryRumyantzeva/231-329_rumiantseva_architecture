#include "book.h"
#include <QJsonObject>
#include <QJsonValue>
#include <QDate>

Book::Book()
    : author(""), year(QDate()), genre(""), count(0), isAvailable(false) {}

void Book::fromJson(const QJsonObject &json) {
    // Заполняем поля объекта из данных JSON
    if (json.contains("author") && json["author"].isString()) {
        author = json["author"].toString();
    }
    if (json.contains("year") && json["year"].isString()) {
        year = QDate::fromString(json["year"].toString(), "yyyy");
    }
    if (json.contains("genre") && json["genre"].isString()) {
        genre = json["genre"].toString();
    }
    if (json.contains("count") && json["count"].isDouble()) {
        count = json["count"].toInt();
    }
    if (json.contains("isAvailable") && json["isAvailable"].isBool()) {
        isAvailable = json["isAvailable"].toBool();
    }
}
