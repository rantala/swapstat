TEMPLATE = app
TARGET = swapstat
VERSION = 1.0
DEPENDPATH += .
HEADERS += \
	ZRamInfoModel.h \
	MemInfoModel.h \
	StatisticsModel.h \
	ramzswap_ioctl.h
SOURCES += \
	ZRamInfoModel.cpp \
	MemInfoModel.cpp \
	StatisticsModel.cpp \
	main.cpp
RESOURCES += qmlfiles.qrc
QT += declarative

target.path = /opt/rantala-swapstat
icon.path = /opt/rantala-swapstat
icon.files = swapstat.svg
qm.path = /opt/rantala-swapstat
qm.files = \
	swapstat_fi.qm
desktop.path = /usr/share/applications
desktop.files = rantala-swapstat.desktop

INSTALLS += target icon qm desktop
#DEFINES += QT_NO_DEBUG_OUTPUT
#CONFIG += debug
#CONFIG += qdeclarative-boostable
