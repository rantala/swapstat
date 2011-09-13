/*
 * Copyright (C) 2011 Tommi Rantala <tt.rantala@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.
 */

#include "version.h"
#include "StatisticsModel.h"
#include "ZRamInfoModel.h"
#include <QApplication>
#include <QtDeclarative>
#include <QtGlobal>
#include <QTranslator>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#ifdef USE_BOOSTING
#include <MDeclarativeCache>
#endif

extern int ramzswap0_fd;

Q_DECL_EXPORT int main(int argc, char **argv)
{
	//uid_t ruid, euid, suid;
	//getresuid(&ruid, &euid, &suid);
	//printf("real UID=%d, effective UID=%d, saved UID=%d\n", ruid, euid, suid);

	ramzswap0_fd = open("/dev/ramzswap0", O_RDONLY);
	seteuid(getuid());

	QApplication *app = NULL;
	QDeclarativeView *window = NULL;

#ifdef USE_BOOSTING
	QApplication *app = MDeclarativeCache::qApplication(argc, argv);
	QDeclarativeView *window = MDeclarativeCache::qDeclarativeView();
#endif
	if (!app) {
		app = new QApplication(argc, argv);
		if (!app)
			abort();
	}
	if (!window) {
		window = new QDeclarativeView;
		if (!window)
			abort();
	}
	QTranslator translator;
	translator.load("swapstat_" + QLocale::system().name(),
			"/opt/rantala-swapstat");
	app->installTranslator(&translator);
	app->setProperty("NoMStyle", true);
	qmlRegisterType<StatisticsModel>("rantala.ramzswap", 1, 0, "StatisticsModel");
	qmlRegisterType<ZRamInfoModel>("rantala.ramzswap", 1, 0, "ZRamInfoModel");
	if (window->rootContext()) {
		QVariant version(QLatin1String("v") + VERSION);
		if (version.isValid())
			window->rootContext()->setContextProperty(
					"VERSION_STRING", version);
	}
	window->setSource(QUrl("qrc:/qmldir/main.qml"));
	window->showFullScreen();
	return app->exec();
}
