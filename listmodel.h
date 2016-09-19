#ifndef LISTMODEL_H
#define LISTMODEL_H

#include <QAbstractListModel>
#include "record.h"

class RecordListModel : public QAbstractListModel {
    Q_OBJECT
public:
    enum RecordRole {
        TitleRole = Qt::UserRole,
        DescriptionRole
    };

public:
    explicit RecordListModel(QObject *parent = 0);
    ~RecordListModel();

    Q_INVOKABLE void addRecord(const QString& title, const QString& description);
    Q_INVOKABLE void delRecord(int index);
    Q_INVOKABLE void updRecord(const QString& title, const QString& description, int inx);

    QVariant data(const QModelIndex &index, int role) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    Qt::ItemFlags flags(const QModelIndex &index) const;
    QHash<int, QByteArray> roleNames() const override;

private:
    QList<Record*> records;
};

#endif // LISTMODEL_H
