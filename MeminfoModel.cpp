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

#include "MeminfoModel.h"
#include <stdio.h>
#include <QDebug>

enum ModelRoles {
	TitleRole = Qt::UserRole + 1,
	SubtitleRole
};

static QHash<int, QByteArray>
getRoles()
{
	QHash<int, QByteArray> roles;
	roles[TitleRole] = "title";
	roles[SubtitleRole] = "subtitle";
	return roles;
}

QStringList
parseProcMeminfo()
{
	QStringList ret;
	static char *line = NULL;
	static size_t line_n = 0;
	static FILE *fp = NULL;
	if (!fp)
		fp = fopen("/proc/meminfo", "r");
	if (!fp)
		goto done;
	rewind(fp);
	while (getline(&line, &line_n, fp) != -1) {
		QString l(line);
		l.chop(1);
		l.remove(' ');
		l.replace(':', ": ");
		l.replace("kB", " kB");
		ret << l;
	}
done:
	qDebug() << Q_FUNC_INFO << ":" << ret;
	return ret;
}

MeminfoModel::MeminfoModel(QObject *parent)
	: QStringListModel(parent)
{
	setRoleNames(::getRoles());
	update();
}

void MeminfoModel::update()
{
	QStringList l = parseProcMeminfo();
	if (!l.isEmpty())
		setStringList(l);
}

QVariant MeminfoModel::data(const QModelIndex &index, int role) const
{
	return QStringListModel::data(index,
			role == TitleRole ? Qt::DisplayRole : role);
}
