#include "listmodel.h"
#include "QDebug"

RecordListModel::RecordListModel(QObject *parent) : QAbstractListModel(parent) {

}

RecordListModel::~RecordListModel() {
    qDeleteAll(records);
    records.clear();
}

void RecordListModel::updRecord(const QString &title, const QString &description, int inx) {
    beginResetModel();
    records.at(inx)->setTitle(title);
    records.at(inx)->setDescription(description);

    auto modelIndex = index(inx);
    emit dataChanged(modelIndex, modelIndex);
    endResetModel();
}

QHash<int, QByteArray> RecordListModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[TitleRole] = "titleName";
    roles[DescriptionRole] = "descriptionName";
    return roles;
}

bool RecordListModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    if(index.row() > 0 && index.row() < records.size()) {
        switch(role) {
            case TitleRole:
                records[index.row()]->setTitle(value.toString());
                break;
            case DescriptionRole:
                records[index.row()]->setDescription(value.toString());
                break;
            default:
                break;
        }
        emit dataChanged(index, index);
    }
    return true;
}

void RecordListModel::addRecord(const QString& title, const QString& description) {
    Record *rec = new Record(title, description);
    int index = records.size();
    beginInsertRows(QModelIndex(), index, index);
    records.append(rec);
    endInsertRows();
}

void RecordListModel::delRecord(const int index) {
    beginRemoveRows(QModelIndex(), index, index);
    records.removeAt(index);
    endRemoveRows();
}

Qt::ItemFlags RecordListModel::flags(const QModelIndex &index) const {
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

QVariant RecordListModel::data(const QModelIndex &index, int role) const {
    if(!index.isValid())
        return QVariant();
    if(index.row() < 0 || index.row() >= records.size())
        return QVariant();
    Record *item = records.at(index.row());
    switch(role) {
        case TitleRole:
            return item->getTitle();
        case DescriptionRole:
            return item->getDescription();
        default:
            return QVariant();
    }
}

int RecordListModel::rowCount(const QModelIndex &) const {
    return records.size();
}

