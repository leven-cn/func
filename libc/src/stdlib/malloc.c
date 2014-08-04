/**
 * Copyright 2014 Li Yun <leven.cn@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "func_stdlib.h"
#include "_alloc.h"

const size_t _BLK_SIZE = 512; // minimal block size
_avail_space _space;

static _cell **_alloc(size_t size); // allocate cell

void *func_malloc(size_t size)
{
    /* round up size */
    if (size < _CELL_SIZE) {
        size = _CELL_SIZE;
    }
    size = (size + _MEMBND) & ~_MEMBND;
    
    _cell **cp = _alloc(size);
    if (cp == NULL) {
        return NULL;
    }
    
    _cell *c = *cp;
    if (c->size < size + _CELL_OFF + _CELL_SIZE) { // use entire cell
        *cp = c->next;
    } else { // peel off a residual cell
        *cp = (_cell *)((char *)c + size + _CELL_OFF);
        (*cp)->next = c->next;
        (*cp)->size = c->size - _CELL_OFF - size;
        c->size = size;
    }
    
    _space.freed = cp ? cp : NULL; // resume here

    return (char *)c + _CELL_OFF;
}

static _cell **_alloc(size_t size)
{
    for (;;) {
        /* check freed space first */
        _cell **cp = _space.freed;
        if (cp == NULL) { // take it from the top
            for (cp=&_space.head; *cp; cp=&(*cp)->next) {
                if (size <= (*cp)->size) {
                    return cp;
                }
            }
        } else { // resume where we left off
            for (; *cp; cp=&(*cp)->next) {
                if (size <= (*cp)->size) {
                    return cp;
                }
            }
            _cell *c = *_space.freed;
            for (cp=&_space.head; *cp!=c; cp=&(*cp)->next) {
                if (size <= (*cp)->size) {
                    return cp;
                }
            }
        }
        
        /* try to request more space */
        {
            _cell *c = NULL;
            size_t blk_size = _BLK_SIZE;
            const size_t sz = size + _CELL_OFF;
            
            /* try larger block first */
            for (;; blk_size>>=1) {
                if (blk_size < sz) {
                    blk_size = sz;
                }
                if ((c=_sbrk(blk_size)) != NULL) {
                    break;
                } else if (blk_size == sz) { // no space in system
                    return NULL;
                }
            }
            
            /* got memory: add to heap and retry */
            c->size = (blk_size & ~_MEMBND) - _CELL_OFF;
            func_free((char *)(c) + _CELL_OFF);
        }
    }    
}
