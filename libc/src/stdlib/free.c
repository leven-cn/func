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

void func_free(void *p)
{
    if (p == NULL) {
        return;
    }
    
    _cell *c = (_cell *)((char *)p - (_CELL_OFF));
    if (c->size & _MEMBND) { // bad pointer
        return;
    }
    if (_space.head==NULL || c<_space.head) { // insert at head of list
        c->next = _space.head;
        _space.head = c;
    } else { // scan for insertion point
        _cell *cp = _space.head;
        for (;cp->next && c<cp->next;) {
            cp = cp->next;
        }
        char *pp = (char *)cp + _CELL_OFF + cp->size;
        if ((char *)c < pp) { // erroneous call
            return;
        } else if ((char *)c == pp) { // merge c and pp
            cp->size += _CELL_OFF + c->size;
            c = cp;
        } else { // splice c after cp
            c->next = cp->next;
            cp->next = c;
        }
    }
    
    /* merge c and c->next */
    if (c->next && (char *)c + _CELL_OFF + c->size == (char *)c->next) {
        c->size += _CELL_OFF + c->next->size;
        c->next = c->next->next;
    }
    
    /* resume scan after freed */
    _space.freed = &c->next;
}
