#ifndef BOOK_H
#define BOOK_H

#include <QString>
#include <QJsonObject>

class Book {
public:
    QString author;
    int count;
    QString genre;
    int id;
    bool is_available;
    QString year;

    static Book fromJson(const QJsonObject &obj) {
        Book book;
        book.author = obj.value("author").toString();
        book.count = obj.value("count").toInt();
        book.genre = obj.value("genre").toString();
        book.id = obj.value("id").toInt();
        book.is_available = obj.value("is_available").toBool();
        book.year = obj.value("year").toString();
        return book;
    }

    QString toString() const {
        return QString("ID: %1\nAuthor: %2\nGenre: %3\nCount: %4\nAvailable: %5\nYear: %6\n")
            .arg(id)
            .arg(author)
            .arg(genre)
            .arg(count)
            .arg(is_available ? "Yes" : "No")
            .arg(year);
    }
};

#endif // BOOK_H
