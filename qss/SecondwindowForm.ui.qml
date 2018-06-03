import QtQuick 2.4
import QtQuick.Controls 2.3

Item {
    width: 1640
    height: 480

    // Указываем кнопкам имя для доступа к ним
    property alias button1: button1
    property alias button2: button2

    // Слой с кнопками
    RowLayout {
        anchors.centerIn: parent

        // Первая кнопка
        Button {
            id: button1
        }

        // вторая кнопка
        Button {
            id: button2
        }
    }

    Button {
        id: button
        x: 113
        y: 220
        text: qsTr("Button")
    }

    Button {
        id: button3
        x: 409
        y: 220
        text: qsTr("Button")
    }
}
