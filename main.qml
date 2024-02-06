import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.12

Window {
    width: 440
    height: 380
    visible: true
    color: "aqua"

    title: qsTr("Client")

    Connections {
        target: client
        function onNewMessage(nm) {
            listModelMessages.append({
            message: nm + ""
                                     })
        }
    }

    ColumnLayout {
        anchors.fill: parent
        RowLayout {
            Layout.fillWidth: true
            TextField {
                id: textFieldIp
                placeholderText: qsTr("IP 127.0.0.1")
                Layout.fillWidth: true
                onAccepted: buttonConnect.clicked()
            }
            TextField {
                id: textFieldPort
                placeholderText: qsTr("8888")
                Layout.fillWidth: true
                onAccepted: buttonConnect.clicked()
            }
            Button {
                id: buttonConnect1
                text: qsTr("Connect")
                onClicked: client.connectToServer(textFieldIp.text, textFieldPort.text)
            }
        }

        //     RowLayout {
        //         Layout.fillWidth: true
        //     TextField {
        //             id: login
        //             placeholderText: qsTr("Login")
        //             Layout.fillWidth: true
        //             onAccepted: buttonConnect.clicked()
        //     }
        //     TextField {
        //                 id: password
        //                 placeholderText: qsTr("Password")
        //                 Layout.fillWidth: true
        //                 onAccepted: buttonConnect.clicked()
        //     }
        //     Button {
        //         id: buttonConnect
        //         text: qsTr("SighIn or SingUP ")
        //         onClicked: client.connectToServer(login.text, password.text)
        //     }
        // }
        // }
            RowLayout {
                Layout.fillWidth: true
                TextField {
                    id: textFieldMessage
                    placeholderText: qsTr("Your message ...")
                    Layout.fillWidth: true
                    onAccepted: buttonSend.clicked()
                }
                }
                Button {
                    id: buttonSend
                    text: qsTr("Send")
                    onClicked: {
                        client.sendMessage(textFieldMessage.text)
                        textFieldMessage.clear()
                    }
                }
            }
        // ListView {
        //     Layout.fillHeight: true
        //     Layout.fillWidth: true
        //     clip: true
        //     model: ListModel {
        //         id: listModelMessages
        //         ListElement {
        //         message: "Welcome to chat client"
        //         }
        //     }
        //     delegate: ItemDelegate {
        //         font.bold: true
        //         text: message
        //     }
        //     ScrollBar.vertical: ScrollBar {}
        // }

    }

