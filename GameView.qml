import QtQuick

Rectangle {
    id: gameView;
    property int gameState: _controller.state
    property bool gameStarted: false
    color: game.color

//    Rectangle {
//        width: 50;
//        height: 50;
//        color: "yellow";
//        anchors.bottom: parent.bottom;
//        anchors.right: parent.right;
//        z: 10;

//        Text {
//            anchors.centerIn: parent;
//            text: "Press me";
//        }

//        MouseArea {
//            anchors.fill: parent;
//            onClicked:
//                switch(gameState) {
//                case 0: gameState = 1; break;
//                case 1: gameState = 2; break;
//                case "":
//                case 2: gameState = 0; break;
//                }
//        }
//    }

    Loader {
        id: gameLoader;
        anchors.fill: parent;
        sourceComponent: initState;
        onSourceComponentChanged: {
            animation.running = true;
            gameStarted = true
        }

        NumberAnimation {
            id: animation
            target: gameLoader.item
            property: "opacity"
            from: 0
            to: 1
            duration: 500
            easing.type: Easing.InExpo
        }
    }

    Component {
        id: initState;

        Rectangle {
            color: game.color
        }
    }

    Component {
        id: startScreen;

        StartScreen {
            color: game.color
        }
    }

    Component {
        id: gameScreen;

        GameScreen {
            color: game.color
        }
    }

    Component {
        id: gameOverScreen;

        GameOverScreen {
            color: game.color
        }
    }

    states: [
        State {
            when: gameState == 0
            PropertyChanges {
                target: gameLoader;
                sourceComponent: startScreen
            }
        },

        State {
            when: gameState == 1
            PropertyChanges {
                target: gameLoader;
                sourceComponent: gameScreen
            }
        },

        State {
            when: gameState == 2
            PropertyChanges {
                target: gameLoader;
                sourceComponent: gameOverScreen;
            }
        }

    ]
}
