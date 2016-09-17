#ifndef RECORD_H
#define RECORD_H

#include <QString>

class Record
{
public:
    Record(const QString &titleName, const QString &descriptionName) {
        title = titleName;
        description = descriptionName;
    }

    QString getTitle() const {
        return title;
    }

    QString getDescription() const {
        return description;
    }

    void setTitle(const QString& title) {
        this->title = title;
    }

    void setDescription(const QString& description) {
        this->description = description;
    }

private:
    QString title;
    QString description;
};

#endif // RECORD_H
