/*
 * OCILIB - C Driver for Oracle (C Wrapper for Oracle OCI)
 *
 * Website: http://www.ocilib.net
 *
 * Copyright (c) 2007-2020 Vincent ROGIER <vince.rogier@ocilib.net>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef OCILIB_LIST_H_INCLUDED
#define OCILIB_LIST_H_INCLUDED

#include "types.h"

OCI_List* OcilibListCreate
(
    int type
);

boolean OcilibListFree
(
    OCI_List* list
);

void* OcilibListAppend
(
    OCI_List* list,
    int       size
);

boolean OcilibListClear
(
    OCI_List* list
);

typedef void (*POCI_LIST_FOR_EACH)
(
    void* data
);

boolean OcilibListForEach
(
    OCI_List         * list,
    POCI_LIST_FOR_EACH proc
);

typedef void (*POCI_LIST_FOR_EACH_WITH_PARAM)
(
    void* data,
    void* param
);

boolean OcilibListForEachWithParam
(
    OCI_List                    * list,
    void                        * param,
    POCI_LIST_FOR_EACH_WITH_PARAM proc
);

boolean OcilibListRemove
(
    OCI_List* list,
    void    * data
);

boolean OcilibListExists
(
    OCI_List* list,
    void    * data
);

typedef boolean (*POCI_LIST_FIND)
(
    void* data,
    void* param
);

void* OcilibListFind
(
    OCI_List     * list,
    POCI_LIST_FIND proc,
    void         * param
);

#endif /* OCILIB_LIST_H_INCLUDED */
