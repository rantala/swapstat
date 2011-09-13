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

#include <sys/ioctl.h>
#include "ZRamInfoModel.h"

typedef quint64 u64;
typedef quint32 u32;
#include "ramzswap_ioctl.h"

int ramzswap0_fd;

static struct ramzswap_ioctl_stats stats1;
static struct ramzswap_ioctl_stats stats2;

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

ZRamInfoModel::ZRamInfoModel(QObject *parent)
	: QAbstractListModel(parent)
	, stats(&stats1)
{
	setRoleNames(::getRoles());
	update();
}

QString ZRamInfoModel::compressionFactor() const
{
	struct ramzswap_ioctl_stats *st = (struct ramzswap_ioctl_stats *)stats;
	if (st->mem_used_total == 0)
		return QString();
	return QString::number(double(st->orig_data_size)/double(st->mem_used_total));
}

bool ZRamInfoModel::initOK() const
{
	return ramzswap0_fd != -1;
}

void ZRamInfoModel::update()
{
	int ret;
	struct ramzswap_ioctl_stats *stats_old =
		(struct ramzswap_ioctl_stats *)stats;
	struct ramzswap_ioctl_stats *stats_new =
		(stats_old == &stats1 ? &stats2 : &stats1);
	ret = ioctl(ramzswap0_fd, RZSIO_GET_STATS, stats_new);
	stats = stats_new;
	emit dataChanged(createIndex(0, 0), createIndex(17, 0));
	emit compressionFactorChanged();
	emit originalDataSizeChanged();
	emit compressedDataSizeChanged();
	emit diskSizeChanged();
	emit memlimitChanged();
	emit backingSwapNameChanged();
}

QString ZRamInfoModel::backingSwapName() const
{
	struct ramzswap_ioctl_stats *st = (struct ramzswap_ioctl_stats *)stats;
	return st->backing_swap_name;
}

quint64 ZRamInfoModel::originalDataSize() const
{
	struct ramzswap_ioctl_stats *st = (struct ramzswap_ioctl_stats *)stats;
	return st->orig_data_size;
}

quint64 ZRamInfoModel::compressedDataSize() const
{
	struct ramzswap_ioctl_stats *st = (struct ramzswap_ioctl_stats *)stats;
	return st->compr_data_size;
}

quint64 ZRamInfoModel::diskSize() const
{
	struct ramzswap_ioctl_stats *st = (struct ramzswap_ioctl_stats *)stats;
	return st->disksize;
}

quint64 ZRamInfoModel::memlimit() const
{
	struct ramzswap_ioctl_stats *st = (struct ramzswap_ioctl_stats *)stats;
	return st->memlimit;
}

QVariant ZRamInfoModel::data(const QModelIndex &index, int role) const
{
	if (role == TitleRole) {
		switch (index.row()) {
		case 0: return tr("Backing swap: %1").arg(((struct ramzswap_ioctl_stats *)stats)->backing_swap_name);
		case 1: return tr("Memory limit: %1 MB").arg(((struct ramzswap_ioctl_stats *)stats)->memlimit / (1024*1024));
		case 2: return tr("Disk size: %1 MB").arg(((struct ramzswap_ioctl_stats *)stats)->disksize / (1024*1024));
		case 3: return tr("Reads: %1").arg(((struct ramzswap_ioctl_stats *)stats)->num_reads);
		case 4: return tr("Writes: %1").arg(((struct ramzswap_ioctl_stats *)stats)->num_writes);
		case 5: return tr("Failed reads: %1").arg(((struct ramzswap_ioctl_stats *)stats)->failed_reads);
		case 6: return tr("Failed writes: %1").arg(((struct ramzswap_ioctl_stats *)stats)->failed_writes);
		case 7: return tr("Invalid I/O requests: %1").arg(((struct ramzswap_ioctl_stats *)stats)->invalid_io);
		case 8: return tr("Free notification slots: %1").arg(((struct ramzswap_ioctl_stats *)stats)->notify_free);
		case 9: return tr("Zero filled pages: %1").arg(((struct ramzswap_ioctl_stats *)stats)->pages_zero);
		case 10: return tr("Well compressed pages: %1 %").arg(((struct ramzswap_ioctl_stats *)stats)->good_compress_pct);
		case 11: return tr("Incompressible pages: %1 %").arg(((struct ramzswap_ioctl_stats *)stats)->pages_expand_pct);
		case 12: return tr("Pages stored: %1").arg(((struct ramzswap_ioctl_stats *)stats)->pages_stored);
		case 13: return tr("Pages used: %1").arg(((struct ramzswap_ioctl_stats *)stats)->pages_used);
		case 14: return tr("Original data size: %1 MB").arg(((struct ramzswap_ioctl_stats *)stats)->orig_data_size / (1024*1024));
		case 15: return tr("Compressed data size: %1 MB").arg(((struct ramzswap_ioctl_stats *)stats)->compr_data_size / (1024*1024));
		case 16: return tr("Memory used total: %1 MB").arg(((struct ramzswap_ioctl_stats *)stats)->mem_used_total / (1024*1024));
		case 17: return tr("Backing device reads: %1").arg(((struct ramzswap_ioctl_stats *)stats)->bdev_num_reads);
		case 18: return tr("Backing device writes: %1").arg(((struct ramzswap_ioctl_stats *)stats)->bdev_num_writes);
		}
		/*
	} else if (role == SubtitleRole) {
		switch (index.row()) {
		case 1: return "Only applicable if backing swap present.";
		case 3: return "Number of reads on /dev/ramzswap0 device.";
		case 4: return "Number of writes on /dev/ramzswap0 device.";
		case 5: return "Non-zero value indicates serious error.";
		case 6: return "Non-zero value indicates that swap is full or that memory is too low.";
		case 7: return "Non-swap I/O requests.";
		case 10: return "Pages with compression ratio <= 50%.";
		}
		*/
	}
	return QVariant();
}

/*
void ZRamInfo::update()
{
	int ret;
	struct ramzswap_ioctl_stats *stats_old =
		(struct ramzswap_ioctl_stats *)stats;
	struct ramzswap_ioctl_stats *stats_new =
		(stats_old == &stats1 ? &stats2 : &stats1);
	ret = ioctl(ramzswap0_fd, RZSIO_GET_STATS, stats_new);
	stats = stats_new;
	emit memlimitChanged();
	emit disksizeChanged();
	emit numReadsChanged();
	emit numWritesChanged();
	emit failedReadsChanged();
	emit failedWritesChanged();
	emit invalidIoChanged();
	emit notifyFreeChanged();
	emit pagesZeroChanged();
	emit goodCompressPctChanged();
	emit pagesExpandPctChanged();
	emit pagesStoredChanged();
	emit pagesUsedChanged();
	emit origDataSizeChanged();
	emit comprDataSizeChanged();
	emit memUsedTotalChanged();
	emit bdevNumReadsChanged();
	emit bdevNumWritesChanged();
}

quint64 ZRamInfo::memlimit() const
{ return ((struct ramzswap_ioctl_stats *)stats)->memlimit; }
quint64 ZRamInfo::disksize() const
{ return ((struct ramzswap_ioctl_stats *)stats)->disksize; }
quint64 ZRamInfo::numReads() const
{ return ((struct ramzswap_ioctl_stats *)stats)->num_reads; }
quint64 ZRamInfo::numWrites() const
{ return ((struct ramzswap_ioctl_stats *)stats)->num_writes; }
quint64 ZRamInfo::failedReads() const
{ return ((struct ramzswap_ioctl_stats *)stats)->failed_reads; }
quint64 ZRamInfo::failedWrites() const
{ return ((struct ramzswap_ioctl_stats *)stats)->failed_writes; }
quint64 ZRamInfo::invalidIo() const
{ return ((struct ramzswap_ioctl_stats *)stats)->invalid_io; }
quint64 ZRamInfo::notifyFree() const
{ return ((struct ramzswap_ioctl_stats *)stats)->notify_free; }
quint32 ZRamInfo::pagesZero() const
{ return ((struct ramzswap_ioctl_stats *)stats)->pages_zero; }
quint32 ZRamInfo::goodCompressPct() const
{ return ((struct ramzswap_ioctl_stats *)stats)->good_compress_pct; }
quint32 ZRamInfo::pagesExpandPct() const
{ return ((struct ramzswap_ioctl_stats *)stats)->pages_expand_pct; }
quint32 ZRamInfo::pagesStored() const
{ return ((struct ramzswap_ioctl_stats *)stats)->pages_stored; }
quint32 ZRamInfo::pagesUsed() const
{ return ((struct ramzswap_ioctl_stats *)stats)->pages_used; }
quint64 ZRamInfo::origDataSize() const
{ return ((struct ramzswap_ioctl_stats *)stats)->orig_data_size; }
quint64 ZRamInfo::comprDataSize() const
{ return ((struct ramzswap_ioctl_stats *)stats)->compr_data_size; }
quint64 ZRamInfo::memUsedTotal() const
{ return ((struct ramzswap_ioctl_stats *)stats)->mem_used_total; }
quint64 ZRamInfo::bdevNumReads() const
{ return ((struct ramzswap_ioctl_stats *)stats)->bdev_num_reads; }
quint64 ZRamInfo::bdevNumWrites() const
{ return ((struct ramzswap_ioctl_stats *)stats)->bdev_num_writes; }
*/
