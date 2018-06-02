import QtQuick 2.4
import QtQuick.Controls 2.3
import QtTest 1.2

Item {
    id: item1
    width: 400
    height: 400
    opacity: 1
    property alias image: image
    visible: true
    clip: false

    Text {
        id: text1
        x: 170
        y: 51
        width: 99
        height: 47
        text: qsTr("Time ")
        transformOrigin: Item.Center
        visible: true
        font.bold: true
        font.pixelSize: 14
    }

    Button {
        id: button
        x: 248
        y: 115
        text: qsTr("Button")
        transformOrigin: Item.Center
        opacity: 1
        font.italic: false
        wheelEnabled: false
        spacing: 5
        hoverEnabled: true
        focusPolicy: Qt.StrongFocus
        enabled: true
        highlighted: false
    }

    Image {
        id: image
        x: 0
        y: 0
        width: 400
        height: 400
        z: -1
        transformOrigin: Item.Center
        clip: false
        visible: true
        rotation: 0
        smooth: true
        antialiasing: false
        opacity: 1
        source: "../img/TWhoQi.jpg"
    }

    TextInput {
        id: textInput
        x: 37
        y: 190
        width: 80
        height: 20
        text: qsTr("Text Input")
        font.pixelSize: 12
    }

    Switch {
        id: switch1
        x: 278
        y: 8
        text: qsTr("Switch")
    }
}
