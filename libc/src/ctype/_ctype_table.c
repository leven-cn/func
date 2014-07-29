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

#include "func_ctype.h"
#include "limits.h"

#ifndef EOF
#define EOF (-1)
#endif

#if UCHAR_MAX != 255
#error WRONG CTYPE TABLE: UCHAR_MAX != 255
#endif

#define _XDI (_DI|_XD)
#define _XLO (_LO|_XD)
#define _XUP (_UP|_XD)

static const short _ctype_table[UCHAR_MAX+2] = {
    EOF,
    _BB,  _BB,  _BB,  _BB,  _BB,  _BB,  _BB,  _BB,
    _BB,  _CN,  _CN,  _CN,  _CN,  _CN,  _BB,  _BB,
    _BB,  _BB,  _BB,  _BB,  _BB,  _BB,  _BB,  _BB,
    _BB,  _BB,  _BB,  _BB,  _BB,  _BB,  _BB,  _BB,
    _SP,  _PU,  _PU,  _PU,  _PU,  _PU,  _PU,  _PU,
    _PU,  _PU,  _PU,  _PU,  _PU,  _PU,  _PU,  _PU,
    _XDI, _XDI, _XDI, _XDI, _XDI, _XDI, _XDI, _XDI,
    _XDI, _XDI, _PU,  _PU,  _PU,  _PU,  _PU,  _PU,
    _PU,  _XUP, _XUP, _XUP, _XUP, _XUP, _XUP, _UP,
    _UP,  _UP,  _UP,  _UP,  _UP,  _UP,  _UP,  _UP,
    _UP,  _UP,  _UP,  _UP,  _UP,  _UP,  _UP,  _UP,
    _UP,  _UP,  _UP,  _PU,  _PU,  _PU,  _PU,  _PU,
    _PU, _XLO, _XLO, _XLO, _XLO, _XLO, _XLO,  _LO,
    _LO,  _LO,  _LO,  _LO,  _LO,  _LO,  _LO,  _LO,
    _LO,  _LO,  _LO,  _LO,  _LO,  _LO,  _LO,  _LO,
    _LO,  _LO,  _LO,  _PU,  _PU,  _PU,  _PU,  _BB,
    /* rest all match nothing */
};

const short *_ctype_tbl = &_ctype_table[1];
