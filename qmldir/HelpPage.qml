import QtQuick 1.1
import com.nokia.meego 1.0
import "file:///usr/lib/qt4/imports/com/nokia/meego/UIConstants.js" as UI

Page {
	anchors.bottomMargin: UI.DEFAULT_MARGIN
	Header {
		id: header
		text: "SwapStat"
		refreshButtonVisible: false
	}
	tools: ToolBarLayout {
		ToolIcon {
			iconId: "toolbar-back"
			onClicked: pageStack.pop()
		}
	}
	Column {
		x: UI.DEFAULT_MARGIN
		width: parent.width - 2*UI.DEFAULT_MARGIN
		anchors.top: header.bottom
		anchors.topMargin: UI.DEFAULT_MARGIN
		spacing: 16
		Label {
			width: parent.width
			text: "SwapStat " + VERSION_STRING
			font.bold: true
		}
		Label {
			width: parent.width
			text: qsTr("Copyright (C) %1 %2")
				.arg("2011")
				.arg("Tommi Rantala <tt.rantala@gmail.com>")
		}
		Label {
			width: parent.width
			text: qsTr("Nokia N9 dedicates some RAM for use as in-memory compressed swap space. " +
				"SwapStat allows you to get access to the kernel based statistics provided for the swap device.")
		}
		Label {
			width: parent.width
			text: qsTr("The device node that provides the compressed swap is <tt>/dev/ramzswap0</tt>. " +
				"SwapStat uses the <tt>RZSIO_GET_STATS</tt> <tt>ioctl</tt> call to query the statistics.")
		}
	}
}
