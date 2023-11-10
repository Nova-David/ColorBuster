import QtQuick

Rectangle {
    Text {
        id: tryAgain
        anchors.centerIn: parent;
        text: "TRY AGAIN?"
        font.letterSpacing: 4
        font.styleName: "Light Italic"
        font.weight: Font.Thin
        font.pointSize: 40
        color: hoverArea2.containsMouse ? "#8CAD95" : game.textcolor

        MouseArea {
            id: hoverArea2;
            anchors.fill: parent;
            hoverEnabled: true;
            onClicked: {
                _controller.tryAgain();
            }
        }
    }

    transitions: [
        Transition {
            from: "*"; to: "*"

            PropertyAnimation {
                targets: tryAgain;
                properties: "color"; duration: 500;
                easing.type: Easing.InOutCubic;
            }
        }
    ]
}
