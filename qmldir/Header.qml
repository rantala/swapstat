import QtQuick 1.1
import com.nokia.meego 1.0
import "file:///usr/lib/qt4/imports/com/nokia/meego/UIConstants.js" as UI

Rectangle {
	property alias text: label.text
	property bool refreshButtonVisible: true
	signal refreshClicked
	width: parent.width
	height: UI.HEADER_DEFAULT_HEIGHT_PORTRAIT
	clip: true
	color: "#5F20BD"
	z: 10
	Label {
		id: label
		width: parent.width - 2*UI.DEFAULT_MARGIN
		font.pixelSize: UI.FONT_XLARGE
		color: "white"
		z: parent.z + 1
		x: UI.DEFAULT_MARGIN
		y: 20
		font.family: UI.FONT_FAMILY_LIGHT
	}
	Image {
		id: refreshImage
		visible: refreshButtonVisible && platformWindow.active
		source: "image://theme/icon-s-refresh-inverse"
		anchors.right: parent.right
		anchors.rightMargin: UI.DEFAULT_MARGIN
		y: 20
		Behavior on opacity { NumberAnimation { easing.type: Easing.InOutQuad } }
	}
	Timer {
		id: imageTimer
		repeat: false
		interval: 1000
		onTriggered: {
			mouseArea.enabled = true
			refreshImage.opacity = 1
		}
	}
	MouseArea {
		id: mouseArea
		anchors.fill: parent
		onClicked: {
			mouseArea.enabled = false
			refreshImage.opacity = 0
			refreshClicked()
			imageTimer.restart()
		}
	}
}
