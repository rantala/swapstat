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

#ifndef MEMINFOMODEL_H
#define MEMINFOMODEL_H

#include <QStringListModel>

class MeminfoModel : public QStringListModel
{
	Q_OBJECT

public:
	MeminfoModel(QObject *parent = 0);
	~MeminfoModel() {}
	QVariant data(const QModelIndex &index, int role) const;

public slots:
	void update();
};

#endif /* MEMINFOMODEL_H */
