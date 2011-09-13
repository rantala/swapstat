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

#ifndef STATISTICSMODEL_H
#define STATISTICSMODEL_H

#include "MeminfoModel.h"
#include "ZRamInfoModel.h"
#include <QAbstractListModel>

class StatisticsModel : public QAbstractListModel
{
	Q_OBJECT
	Q_PROPERTY(MeminfoModel *meminfoModel
			READ meminfoModel)
	Q_PROPERTY(ZRamInfoModel *zramInfoModel
			READ zramInfoModel)

public:
	StatisticsModel(QObject *parent = 0);
	~StatisticsModel() {}
	QVariant data(const QModelIndex &index, int role) const;
	int rowCount(const QModelIndex &parent = QModelIndex()) const;

	ZRamInfoModel *zramInfoModel() { return &_zramInfoModel; }
	MeminfoModel *meminfoModel() { return &_meminfoModel; }

public slots:
	void update();

private:
	ZRamInfoModel _zramInfoModel;
	MeminfoModel _meminfoModel;
};

#endif /* STATISTICSMODEL_H */
