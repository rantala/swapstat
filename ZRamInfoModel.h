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

#ifndef ZRAMINFOMODEL_H
#define ZRAMINFOMODEL_H

#include <QObject>
#include <QAbstractListModel>

class ZRamInfoModel : public QAbstractListModel
{
	Q_OBJECT
	Q_PROPERTY(bool initOK READ initOK);
	Q_PROPERTY(QString compressionFactor READ compressionFactor NOTIFY compressionFactorChanged);
	Q_PROPERTY(QString backingSwapName READ backingSwapName NOTIFY backingSwapNameChanged)
	Q_PROPERTY(quint64 originalDataSize READ originalDataSize NOTIFY originalDataSizeChanged)
	Q_PROPERTY(quint64 compressedDataSize READ compressedDataSize NOTIFY compressedDataSizeChanged)
	Q_PROPERTY(quint64 diskSize READ diskSize NOTIFY diskSizeChanged)
	Q_PROPERTY(quint64 memlimit READ memlimit NOTIFY memlimitChanged)

public:
	ZRamInfoModel(QObject *parent = 0);
	~ZRamInfoModel() {}
	QVariant data(const QModelIndex &index, int role) const;
	int rowCount(const QModelIndex &parent = QModelIndex()) const { Q_UNUSED(parent); return 19; }
	Q_INVOKABLE void update();
	bool initOK() const;
	QString compressionFactor() const;
	QString backingSwapName() const;
	quint64 originalDataSize() const;
	quint64 compressedDataSize() const;
	quint64 diskSize() const;
	quint64 memlimit() const;

signals:
	void backingSwapNameChanged();
	void compressionFactorChanged();
	void originalDataSizeChanged();
	void compressedDataSizeChanged();
	void diskSizeChanged();
	void memlimitChanged();

private:
	void *stats;
};

#endif /* ZRAMINFOMODEL_H */
