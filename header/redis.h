/*
 * redis.h
 *
 *  Created on: 2014. 1. 27.
 *      Author: yunta_000
 */
#include <stdio.h>
#include "hiredis.h"


//redisAsyncContext *c;
extern redisContext *c;
//int asyncConnect();
int connectFunc();
long int set(int key, int value);
long int get(int key);
void disconnect();


