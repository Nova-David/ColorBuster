import QtQuick
import QtQuick.Window

Window {
    id: game
    width: 800
    height: 600
    visible: true
    title: qsTr(_title)
    color: "#23252F"
    property string textcolor: "white"
    property var tileColors: ["#FF8370", "#00B1B0", "#FEC84D", "#E42256"];

    GameView {
        anchors.fill: parent;
    }
}
