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

#ifndef ___ALLOC_H
#define ___ALLOC_H

#include <stddef.h>

/* Memory boundary */
#define _MEMBND (3) // 4-bytes boundary, for 32-bit machine

/* memory cell */
typedef struct _cell {
    size_t size;
    struct _cell *next;
} _cell;
#define _CELL_OFF  (sizeof(size_t) + ((_MEMBND) & (~(_MEMBND))))
#define _CELL_SIZE ((sizeof(_cell) + ((_MEMBND) & (~(_MEMBND)))) - (_CELL_OFF))

/* available memory */
typedef struct _avail_space {
	_cell *head;
	_cell **freed; // address of ponter to next list element to consider
} _avail_space;

extern const size_t _BLK_SIZE; // minimal block size
extern _avail_space _space;

extern _cell *_sbrk(size_t size); // System API wrapper

#endif /* ___ALLOC_H */
