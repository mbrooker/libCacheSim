#pragma once

#include "evictionAlgo/ARC.h"
#include "evictionAlgo/Belady.h"
#include "evictionAlgo/BeladySize.h"
#include "evictionAlgo/CR_LFU.h"
#include "evictionAlgo/Cacheus.h"
#include "evictionAlgo/Clock.h"
#include "evictionAlgo/FIFO.h"
#include "evictionAlgo/GDSF.h"
#include "evictionAlgo/Hyperbolic.h"
#include "evictionAlgo/LFU.h"
#include "evictionAlgo/LFUCpp.h"
#include "evictionAlgo/LFUDA.h"
#include "evictionAlgo/LHD.h"
#include "evictionAlgo/LRU.h"
#include "evictionAlgo/LRUv0.h"
#include "evictionAlgo/LeCaR.h"
#include "evictionAlgo/LeCaRv0.h"
#include "evictionAlgo/MRU.h"
#include "evictionAlgo/Random.h"
#include "evictionAlgo/SLRU.h"
#include "evictionAlgo/SLRUv0.h"
#include "evictionAlgo/SR_LRU.h"

#ifdef INCLUDE_PRIV
#include "evictionAlgo/FIFO_Merge.h"
#include "evictionAlgo/FIFO_Reinsertion.h"
#include "evictionAlgo/LRU_Belady.h"
#include "evictionAlgo/SFIFO.h"
#include "evictionAlgo/SFIFO_Belady.h"
#include "evictionAlgo/priv.h"
#endif

#if defined(ENABLE_GLCACHE) && ENABLE_GLCACHE == 1
#include "evictionAlgo/GLCache.h"
#endif
