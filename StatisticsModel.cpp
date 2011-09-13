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

#include "StatisticsModel.h"

enum ModelRoles {
	TitleRole = Qt::UserRole + 1,
	SubtitleRole,
	SectionRole
};

static QHash<int, QByteArray>
getRoles()
{
	QHash<int, QByteArray> roles;
	roles[TitleRole] = "title";
	roles[SubtitleRole] = "subtitle";
	roles[SectionRole] = "section";
	return roles;
}

StatisticsModel::StatisticsModel(QObject *parent)
	: QAbstractListModel(parent)
{
	setRoleNames(::getRoles());
}

QVariant StatisticsModel::data(const QModelIndex &index, int role) const
{
	if (role == SectionRole) {
		if (index.row() < _zramInfoModel.rowCount())
			return "/dev/ramzswap0";
		else
			return "/proc/meminfo";
	} else {
		if (index.row() < _zramInfoModel.rowCount())
			return _zramInfoModel.data(index, role);
		else {
			QModelIndex newIndex = _meminfoModel.index(
					index.row() - _zramInfoModel.rowCount());
			return _meminfoModel.data(newIndex, role);
		}
	}
}

int StatisticsModel::rowCount(const QModelIndex &parent) const
{
	return _zramInfoModel.rowCount(parent) +
		_meminfoModel.rowCount(parent);
}

void StatisticsModel::update()
{
	_zramInfoModel.update();
	_meminfoModel.update();
}
