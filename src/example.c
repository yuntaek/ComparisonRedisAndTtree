#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "header/hirdis.h"

int main(int argc, char **argv) {
    unsigned int j;
    redisContext *c;

    int *sampleKey;
    int *sampleValue;

    int count = 10000;
    redisReply *reply;


    sampleKey = calloc(10000,sizeof(int));
    sampleValue = calloc(10000,sizeof(int));

    const char *hostname = (argc > 1) ? argv[1] : "127.0.0.1";
    int port = (argc > 2) ? atoi(argv[2]) : 6379;

    //struct timeval timeout = { 1, 500000 }; // 1.5 seconds
    c = redisConnect(hostname, port);
    if (c == NULL || c->err) {
        if (c) {
            printf("Connection error: %s\n", c->errstr);
            redisFree(c);
        } else {
            printf("Connection error: can't allocate redis context\n");
        }
        exit(1);
    }



    /* PING server */
    reply = redisCommand(c,"PING");
    printf("PING: %s\n", reply->str);
    freeReplyObject(reply);

    /* Set a key */
    while (count>0){
    	sampleKey[count] = count;
    	sampleValue[count] = 10000-count;
    	count--;
    }

    for (int cnt= 0; cnt <10000 ; cnt++){
    	//reply =
    	redisCommand(c,"SET key:%d %d", sampleKey[cnt], sampleValue[cnt]);
    	printf("SET: %lld\n", reply->integer);
    	freeReplyObject(reply);
    }

    /* Set a key using binary safe API */
    reply = redisCommand(c,"SET %b %b", "bar", (size_t) 3, "hello", (size_t) 5);
    printf("SET (binary API): %s\n", reply->str);
    freeReplyObject(reply);

    /* Try a GET and two INCR */
    for (int cnt= 0; cnt <10000 ; cnt++){
        	reply = redisCommand(c,"DEL %d", sampleKey[cnt]);
        	printf("DEL %d: %s\n",sampleKey[cnt], reply->str);
        	freeReplyObject(reply);
        }

    redisFree(c);

    return 0;
}
