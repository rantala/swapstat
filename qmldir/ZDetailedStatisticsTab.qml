import QtQuick 1.1
import com.nokia.meego 1.0
import com.nokia.extras 1.0
import rantala.ramzswap 1.0
import "file:///usr/lib/qt4/imports/com/nokia/meego/UIConstants.js" as UI

Page {
	id: mainpage
	property StatisticsModel statModel
	anchors.bottomMargin: UI.DEFAULT_MARGIN
	Header {
		id: header
		text: "SwapStat"
		onRefreshClicked: statModel.update()
	}
	Component {
		id: sectionHeading
		Item {
			width: parent.width
			height: sectionLabel.height
			Label {
				id: sectionLabel
				width: parent.width
				text: section
				font.bold: true
				font.pixelSize: 32
			}
		}
	}
	ListView {
                id: zView
                anchors.top: header.bottom
		anchors.topMargin: UI.DEFAULT_MARGIN
                width: parent.width - UI.DEFAULT_MARGIN
                height: parent.height - header.height
                x: UI.DEFAULT_MARGIN
                model: statModel
                delegate: ListDelegate {
                        height: UI.LIST_ITEM_HEIGHT_SMALL - 20
			titleWeight: subtitleWeight
                }
		section.property: "section"
		section.criteria: ViewSection.FullString
		section.delegate: sectionHeading
        }
        ScrollDecorator {
                flickableItem: zView
        }
}
