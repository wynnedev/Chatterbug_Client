import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 1.4
import QtQuick.Controls 2.5
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.3
import com.client 1.0

Window {

    signal testSignal();
    visible: true
    color: "white"
    width: 640
    height: 480
    title: qsTr("Chatter Bug")

    Client{
        id: client
    }

    ColorDialog{
        id: colorDialog
        title: "Send Message"
        color: "green"
        onAccepted: { console.log("Accepted:") }
        onRejected: { console.log("Rejected: " + color) }
    }

    FontDialog{
        id: fontDialog
        title: "Send Message"
        onAccepted: { console.log("Accepted:") }
        onRejected: { console.log("Rejected: " + color) }
    }

    Column{
        Row{
           TextField{
               id: txtIP
               text: "Enter Valid IP"
               width: 500
           }

           Button{
               id: btnConnect
               text: "Connect"
               width: 140
               onClicked: client.clientConnect(txtIP.text.toString())
           }

        }

        Row{
            Button{
                id: btnColor
                text: "Color"
                onClicked: {
                    colorDialog.open()
                }
            }

            Button{
                id: btnFont
                text: "Font"
                onClicked: {
                    fontDialog.open()
                }
            }

            TextField {
                id: txtMessage
                text: "Enter Message"
                width: 300
            }

            Button{
                id: btnSendMessage
                text: "Send Message"
                width: 140
                onClicked:{
                }
            }
        }

        Rectangle{
            width: 640
            height: 400
            ScrollView{
                id: scrollView
                anchors.fill: parent

            TextArea {
                id: chatWindow
                font: fontDialog.font
                color: colorDialog.color
                horizontalAlignment: TextEdit.AlignLeft
                verticalAlignment: TextEdit.AlignTop
               }
            }
        }
    }
}

