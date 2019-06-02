import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 1.4
import QtQuick.Controls 2.5
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.3
import com.client 1.0

Window {

    visible: true
    color: "white"
    width: 640
    maximumWidth: 640
    height: 480
    maximumHeight: 480
    title: qsTr("Chatter Bug")


    Client{
        id: client
    }

    Column{
        Row{
           TextField{
               id: txtIP
               text: "Enter Valid IP"
               width: 360
           }

           Button{
               id: btnConnect
               text: "Connect"
               width: 140
               onClicked: {
                   client.clientConnect(txtIP.text.toString())
          }
        }

           Button{
               id: btnDisconnect
               text: "Disconnect"
               width: 140
               onClicked: {
                   client.clientDisconnect()
               }
           }
        }

        Row{

            TextField {
                id: txtMessage
                text: "Enter Message"
                width: 500
            }

            Button{
                id: btnSendMessage
                text: "Send Message"
                width: 140
                onClicked:{
                    client.clientWrite(txtMessage.text.toString())
                    txtMessage.text =''
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
                horizontalAlignment: TextEdit.AlignLeft
                verticalAlignment: TextEdit.AlignTop
                text: chatWindow.append(client.data)
               }
            }
        }
    }
}
