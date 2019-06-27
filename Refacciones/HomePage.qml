import QtQuick 2.0
import QtQuick.Controls 2.2

Item {

    Label{
        text: "Ingresa Balero"
        anchors.left: parent.left
        anchors.right: textField.left
        anchors.top: parent.top
        anchors.margins: parent.height * .1
        height:  textField.height
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }

    TextField{
        id: textField
        anchors.right:  parent.right
        anchors.rightMargin:  parent.width * .05
        anchors.top: parent.top
        anchors.topMargin: parent.height * .1
        width: parent.width * 0.60
    }

    Button{
        id: analyzeButton
        text: "Analizar"
        anchors.top: textField.bottom
        anchors.topMargin: parent.height * .1
        anchors.horizontalCenter: parent.horizontalCenter
        width: parent.width * 0.20
    }

    TextArea{
        anchors.top: analyzeButton.bottom
        anchors.topMargin: parent.height * .01
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.leftMargin: parent.width * .05
        anchors.rightMargin: parent.width * .05
        anchors.bottom: parent.bottom
        text: "lkjasdfñjl"
    }
}
