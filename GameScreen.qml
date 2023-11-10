import QtQuick
import QtQuick.Layouts 1.3

Rectangle {
    ColumnLayout {
        anchors.fill: parent

        Rectangle {
            Layout.alignment: Qt.AlignTop || Qt.AlignHCenter
            Layout.fillWidth: true
            implicitHeight: score.implicitHeight + scoreLabel.implicitHeight;
            color: game.color

            Text {
                id: scoreLabel
                anchors.horizontalCenter: parent.horizontalCenter;
                anchors.leftMargin: 5;
                text: "SCORE"
                font.letterSpacing: 4
                horizontalAlignment: Text.AlignHCenter
                lineHeight: 2
                font.styleName: "Light Italic"
                font.weight: Font.Thin
                font.pointSize: 10
                color: game.textcolor;
            }

            Text {
                anchors.horizontalCenter: parent.horizontalCenter;
                anchors.top: scoreLabel.bottom;
                anchors.topMargin: -20;
                id: score
                text: _score.current;
                font.pointSize: 40;
                color: "#8CAD95"
            }
        }

        BoardView {
            Layout.fillHeight: true
            Layout.fillWidth: true
            id: boardView
            size: [_controller.boardSize.width, _controller.boardSize.height];
            gap: 10;
            padding: 15;
            center: true;
        }

        Rectangle {
            Layout.alignment: Qt.AlignBottom
            Layout.fillWidth: true;
            height: 100;
            color: game.color

            Rectangle {
                anchors.centerIn: parent;
                id: button
                radius: 10
                width: 180;
                opacity: hoverArea.containsMouse ? 0.8 : 0.5;
                height: 50;
                color: "#FFCB3749";
                border {
                    width: 2
                    color: "#AACB3749"
                }

                Text {
                    anchors.centerIn: parent;
                    text: "RESTART"
                    font.pointSize: 20;
                    font.weight: Font.Thin
                    color: game.textcolor
                }

                MouseArea {
                    id: hoverArea
                    anchors.fill: parent;
                    hoverEnabled: true;
                    onClicked: {
                        _controller.tryAgain();
                    }
                }

                Behavior on opacity {
                    NumberAnimation {
                        duration: 400
                        easing.type: Easing.InOutCubic;
                    }
                }
            }
        }

    }
}
