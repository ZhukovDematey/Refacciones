import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 2.2

Window {
    id:window
    visible: true
    width: Screen.desktopAvailableWidth * .40
    height: Screen.desktopAvailableHeight * .95
    title: "Analizador Refacciones Lamuño"

    StackView {
        id: stack

        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: footer.top
        anchors.top: parent.top
        initialItem: HomePage{

        }
    }

    Rectangle{
        id: footer

        color: "#999966"
        height: applicationFooterText.height
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        Label{
            id: applicationFooterText
            font.pointSize: 13
            anchors.left: parent.left
            anchors.right: parent.right
            text: "Analizador Refacciones Lamuño"
            horizontalAlignment: Text.AlignHCenter
        }
    }
}
