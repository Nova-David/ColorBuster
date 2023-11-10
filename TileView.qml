import QtQuick
import QtQuick.Window

Rectangle {
    id: tile
    property var mycolors: ['orange', 'green', 'yellow', 'red'];
    width: 70;
    height: 70;
    radius: 10
    clip: true
    scale: (hoverMe.containsMouse) ? 1.1 : 1

    property int xPos: model.index % board.size[0];
    property int yPos: Math.floor(model.index / board.size[0]);

    Behavior on scale {
        NumberAnimation {
            duration: 500
            easing.type: Easing.OutElastic
        }
    }

    Rectangle {
        color: "#aa000000";
        anchors {
            left: parent.left
            right: parent.right
            bottom: parent.bottom
        }
        height: parent.height * 0.1
    }

    MouseArea {
        anchors.fill: parent
        id: hoverMe
        onClicked: {
            shakeAnimation.running = true;
            console.log('[' + tile.xPos + ', ' + tile.yPos + ']' + ' ' + tile.mycolors[model.color]);
            _controller.onTouch(tile.xPos, tile.yPos);
        }
        hoverEnabled: true;
    }

    ParallelAnimation {
        id: shakeAnimation
        property int duration: 500

        SequentialAnimation {
            id: breathe;
            property int duration: shakeAnimation.duration

            NumberAnimation {
                target: tile; properties: "scale";
                to: 0.95; duration: breathe.duration/2;
                easing.type: Easing.OutCirc
            }

            NumberAnimation {
                target: tile; properties: "scale";
                to: 1; duration: breathe.duration/2;
                easing.type: Easing.InCirc
            }
        }

        SequentialAnimation {
            id: shake;
            loops: 4
            property int duration: shakeAnimation.duration

            NumberAnimation {
                target: tile; properties: "rotation";
                to: 5; duration: shake.duration / shake.loops / 4
            }

            NumberAnimation {
                target: tile; properties: "rotation";
                to: -5; duration: shake.duration / shake.loops / 2
            }


            NumberAnimation {
                target: tile; properties: "rotation";
                to: 0; duration: shake.duration / shake.loops / 4
            }

        }

        running: false;
    }




}
