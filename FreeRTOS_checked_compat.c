#include "FreeRTOS_checked.h"
#ifdef CHECKED2
OMAP omap checked[MAX_OBJECTS];
int used;
int calls; 
ptr<void> getObjectFromHandle(ptr<void> handle) {
		unchecked {
        if ((handle >= omap) && (handle <= &omap[MAX_OBJECTS])) {
                OMAP * map = (OMAP *) handle;
                return map->object;
        }
        return handle;
		}
}
#endif
extern ptr<unsigned char> _skernsyms;
extern ptr<unsigned char> _ekernsyms;
int isKernelObject(ptr<void> handle) {
		unchecked {
				unsigned long addr = (unsigned long) handle;
				if ((addr >= (unsigned long)&_skernsyms) && (addr <= (unsigned long)&_ekernsyms))
						return 1;
		}
		return 0;
}
