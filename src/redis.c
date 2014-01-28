/*
 * redis.c
 *
 *  Created on: 2014. 1. 27.
 *      Author: yunta_000
 */
#include "redis.h"

/*int asyncConnect(){
  c = redisAsyncConnect("127.0.0.1",6379);
  if (c->err){
	  printf("Error: %s\n", c->errstr);
	  return -1;
  }
  return 0;
}*/

int connectFunc(){
	c = redisConnect("127.0.0.1", 6379);
	if (c == NULL && c->err) {
	    printf("Error: %s\n", c->errstr);
	    // handle error
	    disconnect();
	    return -1;
	}
	printf("connected\n");
	return 1;
}

long int set(int key, int value){
	redisReply *reply;
	int ret;
	reply = redisCommand(c ,"SET %d %d",key, value);
	ret = reply->integer;
	freeReplyObject(reply);
	return ret;
}

long int get(int key){
	int ret;
	redisReply *reply;
	reply = redisCommand(c,"GET %d", key);
	ret = reply->integer;
	freeReplyObject(reply);
	return ret;
}

void disconnect(){
	redisFree(c);
}
