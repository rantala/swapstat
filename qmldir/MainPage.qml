import QtQuick 1.1
import com.nokia.meego 1.0
import rantala.ramzswap 1.0

Page {
	id: mainpage

	StatisticsModel {
		id: sModel
	}

	HelpPage {
		id: helpPage
		visible: false
	}

	Connections {
		target: platformWindow
		onActiveChanged: sModel.update()
	}

	Menu {
		id: toolsMenu
		MenuLayout {
			MenuItem {
				text: qsTr("About")
				onClicked: pageStack.push(helpPage)
			}
		}
	}

	tools: ToolBarLayout {
		ButtonRow {
			platformStyle: TabButtonStyle { }
			TabButton {
				text: qsTr("Overview")
				tab: tab1
			}
			TabButton {
				text: qsTr("Details")
				tab: tab2
			}
		}
		ToolIcon {
			platformIconId: "toolbar-view-menu"
			anchors.right: parent.right
			onClicked: toolsMenu.open()
		}
	}

	TabGroup {
		currentTab: tab1
		ZBasicTab {
			id: tab1
			zmodel: sModel.zramInfoModel
			width: mainpage.width
			anchors.fill: parent
		}
		ZDetailedStatisticsTab {
			id: tab2
			statModel: sModel
			width: mainpage.width
			anchors.fill: parent
		}
	}
}
