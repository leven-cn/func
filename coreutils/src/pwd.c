/**
 * pwd - Print current directory.
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
 
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

static char *logical_pwd(void);   // get from environment variable

int main(int args, char *argv[])
{
    /* Determine logical (-L) or physical (-P) path */
    bool is_logical = true; // "-L" by POSIX default
    if (args != 1) {
        if (strcmp(argv[1], "-P") == 0) {
            is_logical = false;
        }
    }
    
    char *pwd = NULL;
    if (is_logical) {
        pwd = logical_pwd();
        if (pwd == NULL) {
            return -1;
        }
    } else { // "-P": physical path
        if ((pwd=getcwd(NULL, 0)) == NULL) {
            return -1;
        }
    }
    
    assert(pwd != NULL);
    puts(pwd);
    
    /* free memory allocated by getcwd() */
    if (!is_logical) {
        free(pwd);
    }
    
    return 0;
}

static char *logical_pwd(void)
{
    char *pwd = getenv("PWD");
    
    /* Textual validation first */
    if (!pwd || pwd[0]!= '/') {
        return NULL;
    }
    for (char *p=pwd; (p=strstr(p,"/.")); p++) {
        /* Following cases are NOT allowed:
         *
         *     1) xxx/.
         *     2) xxx/./xxx
         *     3) xxx/..
         *     4) xxx/../xxx
         */
        if (!p[2] || p[2] == '/' || (p[2] == '.' && (!p[3] || p[3] == '/'))) {
            return NULL;
        }
    }
    
    /* System call validation */
    struct stat st1;
    struct stat st2;
    if (stat(pwd,&st1)==0 && stat(".",&st2)==0 && (st1.st_ino==st2.st_ino)) {
        return pwd;
    }
    
    return NULL;
    
}