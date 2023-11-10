import QtQuick
import QtQuick.Layouts 1.3
Rectangle {
    Rectangle {
        anchors.bottom: rowElement.top
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottomMargin: 60

        Text{
            anchors.centerIn: parent
            text: "ColorBuster"
            font.letterSpacing: 8
            font.styleName: "Light Italic"
            font.weight: Font.Thin
            font.pointSize: 60
            color: "#8CAD95"
        }
    }

    Row {
        id: rowElement
        anchors.centerIn: parent
        spacing: 50
        padding: 20

        Rectangle {
            width: 180
            height: 180
            radius: 10
            color: firstHover.containsMouse ? "#228CAD95" : "#22ffffff"
            border.width: 2
            border.color: firstHover.containsMouse ? "#668CAD95" : "#66ffffff"
            opacity: firstHover.containsMouse ? 0.8 : 0.6

            Text {
                anchors.centerIn: parent
                text: "8x8"
                font.letterSpacing: 4
                font.styleName: "Light Italic"
                font.weight: Font.Thin
                font.pointSize: 25
                color: game.textcolor
            }

            MouseArea {
                id: firstHover
                anchors.fill: parent;
                hoverEnabled: true;
                onClicked: {
                    _controller.chooseBoard(8, 8);
                }
            }

//            Behavior on color {
//                NumberAnimation {
//                    duration: 400
//                    easing.type: Easing.InOutCubic;
//                }
//            }
        }

        Rectangle {
            width: 180
            height: 180
            radius: 10
            color: secondHover.containsMouse ? "#228CAD95" : "#22ffffff"
            border.width: 2
            border.color: secondHover.containsMouse ? "#668CAD95" : "#66ffffff"
            opacity: secondHover.containsMouse ? 0.8 : 0.6

            Text {
                anchors.centerIn: parent
                text: "9x9"
                font.letterSpacing: 4
                font.styleName: "Light Italic"
                font.weight: Font.Thin
                font.pointSize: 25
                color: game.textcolor
            }

            MouseArea {
                id: secondHover
                anchors.fill: parent;
                hoverEnabled: true;
                onClicked: {
                    _controller.chooseBoard(9, 9);
                }
            }
        }

        Rectangle {
            width: 180
            height: 180
            radius: 10
            color: thirdHover.containsMouse ? "#228CAD95" : "#22ffffff"
            border.width: 2
            border.color: thirdHover.containsMouse ? "#668CAD95" : "#66ffffff"
            opacity: thirdHover.containsMouse ? 0.8 : 0.6

            Text {
                anchors.centerIn: parent
                text: "10x10"
                font.letterSpacing: 4
                font.styleName: "Light Italic"
                font.weight: Font.Thin
                font.pointSize: 25
                color: game.textcolor
            }

            MouseArea {
                id: thirdHover
                anchors.fill: parent;
                hoverEnabled: true;
                onClicked: {
                    _controller.chooseBoard(10, 10);
                }
            }
        }


    }
}
