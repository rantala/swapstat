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

#include "ZRamInfo.h"
#define u64 quint64
#define u32 quint32
#include "ramzswap_ioctl.h"
#include <sys/ioctl.h>

int ramzswap0_fd;

static struct ramzswap_ioctl_stats stats1;
static struct ramzswap_ioctl_stats stats2;

ZRamInfo::ZRamInfo(QObject *parent)
	: QObject(parent)
	, stats(&stats1)
{
	update();
}

bool ZRamInfo::initOK() const
{
	return ramzswap0_fd != -1;
}

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
