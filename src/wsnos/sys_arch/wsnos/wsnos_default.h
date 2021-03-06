/**
 * @brief       : wsnos的默认配置文件
 *
 * @file        : wsnos_default.h
 * @author      : gang.cheng
 * @version     : v0.0.1
 * @date        : 2015/9/29
 *
 * Change Logs  :
 *
 * Date        Version      Author      Notes
 * 2015/9/29    v0.0.1      gang.cheng    first version
 */
#ifndef __WSNOS_DEFAULT_H__
#define __WSNOS_DEFAULT_H__

#ifndef OSEL_EQUEUE_CTR_SIZE
#define OSEL_EQUEUE_CTR_SIZE    1       //*< 任务的事件队列记录索引的字节数
#endif

#ifndef OSEL_MEM_ALIGNMENT
#define OSEL_MEM_ALIGNMENT      2       //*< 内存以几字节方式对齐
#endif

#ifndef OSEL_MAX_PRIO
#define OSEL_MAX_PRIO           (8u) 	//*< 最大优先级
#endif

#ifndef OSEL_ETIMER_SOFTWARE
#define OSEL_ETIMER_SOFTWARE    (1)     //*< ETIMER是软件驱动还是硬件驱动
#endif

#if ((OSEL_MAX_PRIO == 0) || (OSEL_MAX_PRIO > 64))
#error "OSEL_MAX_PRIO 必须在1-64之间选择。"
#endif

#ifndef OSEL_NULL
#define OSEL_NULL               (void *)0
#endif

#ifndef OSEL_DBG_EN
#define OSEL_DBG_EN             (0)
#endif

#ifndef OSEL_NAME_MAX
#define OSEL_NAME_MAX           (8u)
#endif

#ifndef TICK_PRECISION
#define TICK_PRECISION          (10u)
#endif

#ifndef HAVE_LONG_LONG
#define HAVE_LONG_LONG      	(1u)
#endif

#ifndef IS_LITTLE_ENDIAN
#define IS_LITTLE_ENDIAN       	(1u)
#endif

#ifndef CC_CONST_FUNCTION
#define CC_CONST_FUNCTION        const
#endif

/**
 * @def OSEL_ALIGN(size, align)
 * Return the most contiguous size aligned at specified width. RT_ALIGN(13, 4)
 * would return 16.
 */
#define OSEL_ALIGN(size, align)     (((size) + (align) - 1) & ~((align) - 1))


#define SOFTWARE_VER_X              (2)
#define SOFTWARE_VER_Y              (0)
#define SOFTWARE_VER_Z              (1)


#if HAVE_LONG_LONG  == 0
typedef struct {
#if IS_LITTLE_ENDIAN > 0
	uint32_t lo;
	uint32_t hi;
#else
	uint32_t hi;
	uint32_t lo;
#endif
} int64_t;
typedef int64_t uint64_t;
#endif



#endif

