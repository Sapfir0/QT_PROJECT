import QtQuick 2.0

Item {
    Consider {
        id: consider
        color: "black"
        width: 150; height: 75

        Text{
            id: buttonLabel
            anchors.centerIn: parent
            text: "button label"
        }
    }
}
