/*
 * Copyright (c) 2015, Gu Feng <flygoast@126.com>
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 */


#ifndef __KNAMED_IPTABLE_H_INCLUDED__
#define __KNAMED_IPTABLE_H_INCLUDED__


#define HASH_BUCKET_SIZE    256


typedef struct knamed_iptable_slot {
    struct list_head   list;
    uint32_t           addr;
    void              *value;
} knamed_iptable_slot_t;


struct knamed_iptable_hash {
    struct list_head  *bucket;
};


typedef struct knamed_iptable {
    struct knamed_iptable_hash  hash[33];
} knamed_iptable_t;


knamed_iptable_slot_t *knamed_iptable_find(knamed_iptable_t *iptable,
    uint32_t addr);
int knamed_iptable_add(knamed_iptable_t *iptable, uint32_t addr, int mask,
    void *value);
knamed_iptable_t *knamed_iptable_create(void);
void knamed_iptable_destroy(knamed_iptable_t *iptable,
    void (*value_free)(void *value));
void knamed_iptable_dump(knamed_iptable_t *iptable);


#endif /* __KNAMED_IPTABLE_H_INCLUDED__ */