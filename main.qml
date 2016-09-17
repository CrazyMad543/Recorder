import QtQuick 2.3
import QtQuick.Controls 1.4
import CrazzyMad.RecordListModel 1.0

ApplicationWindow {
    property int idElement
    width: 500
    height: 500
    visible: true

    ListView {
        id: recordPanel
        anchors {
            top: parent.top
            left: parent.left
            topMargin: 10
            leftMargin: 10
        }
        model: listModel
        delegate: contactDelegate
        width: 230
        height: 360
        focus: true
    }

    RecordListModel {
        id: listModel
    }

    Component {
        id: contactDelegate
        MouseArea {
            width: 230
            height: 20
            Text {
                text: titleName;
                font.pixelSize: 16;
            }
            onClicked: {
                titleField.text =  titleName;
                descriptionField.text = descriptionName;
                idElement = index;
            }
        }
    }

    Button {
        id: buttonUpdateRecord
        text: qsTr("Update Record")
        anchors {
            top: recordPanel.bottom
            left: parent.left
            topMargin: 10
            leftMargin: 10
        }
        onClicked: listModel.updRecord(titleField.text, descriptionField.text, idElement);
        width: 230
        height: 30
    }

    Button {
        id: buttonNewRecord
        text: qsTr("New Record")
        anchors {
            top: buttonUpdateRecord.bottom
            left: parent.left
            topMargin: 10
            leftMargin: 10
        }
        onClicked: if(titleField.text !== "")
                       listModel.addRecord(titleField.text, descriptionField.text)
        width: 230
        height: 30    
    }

    Button {
        id: buttonDelRecord
        text: qsTr("Delete Record")
        anchors {
            top: buttonNewRecord.bottom
            left: parent.left
            topMargin: 10
            leftMargin: 10
        }
        width: 230
        height: 30
        onClicked: listModel.delRecord(idElement)
    }

    Label {
        id: titleLabel
        text: qsTr("Title:")
        width: 30
        anchors{
            top: parent.top
            left: recordPanel.right
            topMargin: 10
            leftMargin: 10
        }
        font.pixelSize: 16
    }

    TextField {
        id: titleField
        height: 25
        anchors {
            top: parent.top
            left: titleLabel.right
            right: parent.right
            rightMargin: 10
            topMargin: 10
            leftMargin: 10
        }
        font.pixelSize: 16
    }

    Label {
        id: descriptionLabel
        text: qsTr("Description:")
        anchors {
            top: titleLabel.bottom
            left: recordPanel.right
            topMargin: 10
            leftMargin: 10
        }
        font.pixelSize: 16
    }

    TextArea {
        id: descriptionField
        anchors {
            top: descriptionLabel.bottom
            bottom: parent.bottom
            left: recordPanel.right
            right: parent.right
            bottomMargin: 10
            leftMargin: 10
            rightMargin: 10
        }
        font.pixelSize: 16
    }
}

