import QtQuick
import QtQuick.Layouts 1.3

Rectangle {
    id: board
    color: "transparent"
    property int gap: 50
    property var size: [_controller.boardSize.width, _controller.boardSize.height];
    property int padding: 10
    property bool center: false

    Rectangle {
        color: "transparent"

        anchors.centerIn: center ? parent : undefined;

        height: (parent.height < parent.width) ? parent.height : width;
        width: (parent.width <= parent.height) ? parent.width : height;

        border.width: 3;
        border.color: "#99ffffff"
        radius: 10;

        Rectangle {
            anchors {
                fill: parent
                margins: board.padding;
            }

            color: "transparent"

            GridLayout {
                id: mainGrid;
                property int size: Math.min(parent.height, parent.width)
                property double ratio: board.size[1] / board.size[0];
                width: (ratio > 1) ? size * (1 / ratio) : size;
                height: (ratio < 1) ? size * ratio : size;
                columnSpacing: board.gap; rowSpacing: board.gap

                anchors.centerIn: parent;
                columns: board.size[0];
                rows: board.size[1];

                Repeater {
                    model: _tileList;

                    delegate: TileView {
                        Layout.fillWidth: true;
                        Layout.fillHeight: true;
//                        col: model.index % board.size[0];
//                        row: Math.floor(model.index / board.size[0]);
                        color: game.tileColors[model.color];

                        Component.onCompleted: {
//                            console.log(model.index, model.color);
//                            console.log("TileView index:", model.index, "col:", col, "row:", row);
                        }
                    }
                }
            }
        }
    }
}
