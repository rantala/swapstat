import QtQuick 1.1
import com.nokia.meego 1.0
import com.nokia.extras 1.0
import rantala.ramzswap 1.0
import "file:///usr/lib/qt4/imports/com/nokia/meego/UIConstants.js" as UI

Page {
	id: mainpage
	property ZRamInfoModel zmodel
	anchors.bottomMargin: UI.DEFAULT_MARGIN
	Header {
		id: header
		text: "SwapStat"
		onRefreshClicked: zmodel.update()
	}
	Text {
		id: cfLabel
		width: parent.width
		anchors.topMargin: 50
                anchors.top: header.bottom
		text: qsTr("Swap Compression Factor:")
		horizontalAlignment: Text.AlignHCenter
		font.pixelSize: 34
		font.family: UI.FONT_FAMILY_LIGHT
	}
	Text {
		id: cf
		anchors.top: cfLabel.bottom
		anchors.topMargin: UI.DEFAULT_MARGIN
		width: parent.width
		text: zmodel.compressionFactor + "x"
		font.bold: true
		font.pixelSize: 54
		horizontalAlignment: Text.AlignHCenter
		font.family: UI.FONT_FAMILY
	}
	Text {
		id: originalDataSize
		anchors.top: cf.bottom
		anchors.topMargin: UI.DEFAULT_MARGIN + 10
		anchors.horizontalCenter: cf.horizontalCenter
		font.pixelSize: 28
		font.family: UI.FONT_FAMILY_LIGHT
		text: qsTr("Original data size: <b>%1</b>MB")
			.arg(Math.floor(zmodel.originalDataSize / (1024*1024)))
	}
	Text {
		id: compressedDataSize
		anchors.top: originalDataSize.bottom
		anchors.topMargin: UI.DEFAULT_MARGIN
		anchors.horizontalCenter: cf.horizontalCenter
		font.pixelSize: 28
		font.family: UI.FONT_FAMILY_LIGHT
		text: qsTr("Compressed data size: <b>%1</b>MB")
			.arg(Math.floor(zmodel.compressedDataSize / (1024*1024)))
	}
	Text {
		id: swapIs
		anchors.top: compressedDataSize.bottom
		anchors.topMargin: UI.DEFAULT_MARGIN
		text: zmodel.backingSwapName != "" ?
			qsTr("Swap type: <b>Disk Backed</b>") :
			qsTr("Swap type: <b>In-Memory</b>")
		font.pixelSize: 28
		font.family: UI.FONT_FAMILY_LIGHT
		anchors.horizontalCenter: cf.horizontalCenter
	}
}
