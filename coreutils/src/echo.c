/**
 * echo - Display a line of text.
 *
 * This program will be useless, and, of course, WITHOUT ANY WARRANTY.
 *
 * The official source codes could be found in any source listed below:
 *
 *     * git://git.sv.gnu.org/coreutils.git
 *     * ssh://git.sv.gnu.org/srv/git/coreutils.git
 *     * http://git.savannah.gnu.org/r/coreutils.git
 *
 *
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
 
#include <stdio.h>

int main(int argc, char *argv[])
{
    while (argc > 1) {
        fputs(argv[1], stdout);
        argc--;
        argv++;
        if (argc > 0) {
            putchar(' ');
        }
    }
    putchar('\n'); // trailing line
    return 0;
}