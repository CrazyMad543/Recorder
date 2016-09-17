import QtQuick 2.0

Item {
    property alias listModel: listModel

    ListModel {
        id: listModel
    }

    function addRecord(title, description) {
        listModel.append({"title": title, "description": description});
    }

    function delRecord(id) {
        listModel.remove(id)
    }
}

