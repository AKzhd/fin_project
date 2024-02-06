import QtQuick 6.6
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Window {
    width: 440
    height: 380
    visible: true
    color: "#7fff00"
    title: qsTr("Server")


    Connections {
        target: server
        function onNewMessage(ba) {
            listModelMessages.append({
                                         message: ba + ""
                                     })
        }
    }

    ColumnLayout {
        anchors.fill: parent
        ListView {
            Layout.fillHeight: true
            Layout.fillWidth: true
            clip: true
            model: ListModel {
                id: listModelMessages
                // ListElement {

                //     message: "Welcome to chat server"
                // }
            }
            delegate: ItemDelegate {
                text: message
            }
            ScrollBar.vertical: ScrollBar {}
        }



        RowLayout {
        Layout.fillWidth: true
        TextField {
            id: user
            placeholderText: qsTr("Login User")
            placeholderTextColor: "#0000ff"
            Layout.fillWidth: true
            onAccepted: buttonSend.clicked()
        }
        Button {
            id: buttonSendBan
            highlighted: true
            text: qsTr("BAN")
            onClicked: {
                //server.sendMessage(textFieldMessage.text)
                //textFieldMessage.clear()
            }
        }
        }

        RowLayout {
            Layout.fillWidth: true
            TextField {
                id: textFieldMessage
                placeholderText: qsTr("Your message ...")
                placeholderTextColor: "#0000ff"
                Layout.fillWidth: true
                onAccepted: buttonSend.clicked()
            }


            Button {
                id: buttonSend
                highlighted: true
                text: qsTr("Send")
                onClicked: {
                    server.sendMessage(textFieldMessage.text)
                    textFieldMessage.clear()
                }
            }
        }
    }
}
