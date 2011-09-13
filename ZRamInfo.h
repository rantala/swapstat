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

#ifndef ZRAMINFO_H
#define ZRAMINFO_H

#include <QObject>

class ZRamInfo : public QObject
{
	Q_OBJECT
	Q_PROPERTY(bool initOK READ initOK);
	Q_PROPERTY(quint64 memlimit
	              READ memlimit
	            NOTIFY memlimitChanged);
	Q_PROPERTY(quint64 disksize
	              READ disksize
	            NOTIFY disksizeChanged);
	Q_PROPERTY(quint64 numReads
	              READ numReads
	            NOTIFY numReadsChanged);
	Q_PROPERTY(quint64 numWrites
	              READ numWrites
	            NOTIFY numWritesChanged);
	Q_PROPERTY(quint64 failedReads
	              READ failedReads
	            NOTIFY failedReadsChanged);
	Q_PROPERTY(quint64 failedWrites
	              READ failedWrites
	            NOTIFY failedWritesChanged);
	Q_PROPERTY(quint64 invalidIo
	              READ invalidIo
	            NOTIFY invalidIoChanged);
	Q_PROPERTY(quint64 notifyFree
	              READ notifyFree
	            NOTIFY notifyFreeChanged);
	Q_PROPERTY(quint32 pagesZero
	              READ pagesZero
	            NOTIFY pagesZeroChanged);
	Q_PROPERTY(quint32 goodCompressPct
	              READ goodCompressPct
	            NOTIFY goodCompressPctChanged);
	Q_PROPERTY(quint32 pagesExpandPct
	              READ pagesExpandPct
	            NOTIFY pagesExpandPctChanged);
	Q_PROPERTY(quint32 pagesStored
	              READ pagesStored
	            NOTIFY pagesStoredChanged);
	Q_PROPERTY(quint32 pagesUsed
	              READ pagesUsed
	            NOTIFY pagesUsedChanged);
	Q_PROPERTY(quint64 origDataSize
	              READ origDataSize
	            NOTIFY origDataSizeChanged);
	Q_PROPERTY(quint64 comprDataSize
	              READ comprDataSize
	            NOTIFY comprDataSizeChanged);
	Q_PROPERTY(quint64 memUsedTotal
	              READ memUsedTotal
	            NOTIFY memUsedTotalChanged);
	Q_PROPERTY(quint64 bdevNumReads
	              READ bdevNumReads
	            NOTIFY bdevNumReadsChanged);
	Q_PROPERTY(quint64 bdevNumWrites
	              READ bdevNumWrites
	            NOTIFY bdevNumWritesChanged);

public:
	ZRamInfo(QObject *parent = 0);
	~ZRamInfo() {}
	Q_INVOKABLE void update();

	bool initOK() const;
	quint64 memlimit() const;
	quint64 disksize() const;
	quint64 numReads() const;
	quint64 numWrites() const;
	quint64 failedReads() const;
	quint64 failedWrites() const;
	quint64 invalidIo() const;
	quint64 notifyFree() const;
	quint32 pagesZero() const;
	quint32 goodCompressPct() const;
	quint32 pagesExpandPct() const;
	quint32 pagesStored() const;
	quint32 pagesUsed() const;
	quint64 origDataSize() const;
	quint64 comprDataSize() const;
	quint64 memUsedTotal() const;
	quint64 bdevNumReads() const;
	quint64 bdevNumWrites() const;

signals:
	void memlimitChanged();
	void disksizeChanged();
	void numReadsChanged();
	void numWritesChanged();
	void failedReadsChanged();
	void failedWritesChanged();
	void invalidIoChanged();
	void notifyFreeChanged();
	void pagesZeroChanged();
	void goodCompressPctChanged();
	void pagesExpandPctChanged();
	void pagesStoredChanged();
	void pagesUsedChanged();
	void origDataSizeChanged();
	void comprDataSizeChanged();
	void memUsedTotalChanged();
	void bdevNumReadsChanged();
	void bdevNumWritesChanged();

private:
	void *stats;
};

#endif /* ZRAMINFO_H */
