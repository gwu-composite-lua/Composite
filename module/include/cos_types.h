#ifndef TYPES_H
#define TYPES_H

struct cos_sched_next_thd {
	unsigned short int next_thd_id, next_thd_flags;
	unsigned int next_thd_urgency;
};

#define COS_SCHED_EXCL_YIELD 0x40  /* do not modify without modifying thread.h */

struct cos_sched_events {
	struct cos_sched_events *next_thd;
	unsigned int cpu_consumption;
};

struct cos_synchronization_atom {
	unsigned short int owner_thread, num_queued;
} __attribute__((packed));

struct cos_sched_data_area {
	struct cos_sched_next_thd cos_next; //[NUM_CPUS];
	struct cos_synchronization_atom locks[32]; //[NUM_CPUS];
	struct cos_sched_events cos_events[256]; // maximum of PAGE_SIZE/sizeof(struct cos_sched_events) - ceil(sizeof(struct cos_sched_curr_thd)/(sizeof(struct cos_sched_events)+sizeof(locks)))
};

#define MNULL ((void*)0)

/* 
 * These types are for addresses that are never meant to be
 * dereferenced.  They will generally be used to set up page table
 * entries.
 */
typedef unsigned long phys_addr_t;
typedef unsigned long vaddr_t;
typedef unsigned int page_index_t;

/* operations for cos_brand */
enum { 
	COS_BRAND_CREATE, 
	COS_BRAND_ADD_THD 
};

/* operations for cos_sched_cntl */
enum { 
	COS_SCHED_EVT_REGION, 
	COS_SCHED_GRANT_SCHED, 
	COS_SCHED_REVOKE_SCHED
};

struct mpd_split_ret {
	short int new, old;
} __attribute__((packed));

static inline int mpd_split_error(struct mpd_split_ret ret)
{
	return (ret.new < 0) ? 1 : 0;
}

/* operations for manipulating mpds */
enum {
//	COS_MPD_START_TRANSACTION,
//	COS_MPD_END_TRANSACTION,
	COS_MPD_SPLIT,
	COS_MPD_MERGE,
	COS_MPD_SPLIT_MERGE
//	COS_MPD_ISOLATE
};

#define COS_THD_SCHED_RETURN 0x20 /* do not modify without modifying thread.h */

#define IL_INV_UNMAP (0x1) // when invoking, should we be unmapped?
#define IL_RET_UNMAP (0x2) // when returning, should we unmap?
#define MAX_ISOLATION_LVL_VAL (IL_INV_UNMAP|IL_RET_UNMAP)

/*
 * Note on Symmetric Trust, Symmetric Distruct, and Asym trust: 
 * ST  iff (flags & (CAP_INV_UNMAP|CAP_RET_UNMAP) == 0)
 * SDT iff (flags & CAP_INV_UNMAP && flags & CAP_RET_UNMAP)
 * AST iff (!(flags & CAP_INV_UNMAP) && flags & CAP_RET_UNMAP)
 */
#define IL_ST  (0)
#define IL_SDT (IL_INV_UNMAP|IL_RET_UNMAP)
#define IL_AST (IL_RET_UNMAP)
/* invalid type, can NOT be used in data structures, only for return values. */
#define IL_INV (~0) 
typedef unsigned int isolation_level_t;

#define CAP_SAVE_REGS 0x1

#ifdef __KERNEL__
#include <asm/atomic.h>
#else

typedef struct { volatile unsigned int counter; } atomic_t;

#endif /* __KERNEL__ */

#endif /* TYPES_H */
