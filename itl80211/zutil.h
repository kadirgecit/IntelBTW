#ifndef zutil_h
#define zutil_h

#include <IOKit/IOLib.h>
#include <IOKit/IOTypes.h>

extern "C" {
void *zcalloc(void *opaque, uint items, uint size);

void zcfree(void *opaque, void *ptr);
}

#endif /* zutil_h */
