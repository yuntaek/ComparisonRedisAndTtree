#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "redis.h"
//#include "ttree.h"
#define DEFAULT_SAMPLE 10000
#define DEFAULT_ROUND 10000
redisContext *c;

int main(int arc, char **argv){
	int numSample;
	int numRound;
	char* method;
	int *sampleKey;
	int *sampleValue;
	int roundCount=0;
	int sampleCount=0;
	int ret;
	int count;
	time_t current[2];

	if (arc==4){
		numSample = strtol(argv[2],NULL,10);
		numRound = strtol(argv[3],NULL,10);
	} else{
		numSample = DEFAULT_SAMPLE;
		numRound = DEFAULT_ROUND;
	}


	sampleKey = calloc(numSample, sizeof(int));
	sampleValue = calloc(numSample, sizeof(int));
	//Todo Check Arc and Argv
	//if(arc != 3)


	/*Todo make test sample referring thrid value of argument*/

	count = numSample;
	while(count > 0){
		sampleKey[count]=count;
		sampleValue[count]=1000000-count;
		count--;
	}

	ret = connectFunc();
	printf("result %d",ret);
	time(&current[0]);
	/*Todo If argv is Ttree, data structure is tree.
	 * Otherwise, Redis
	 */
	roundCount = numRound;

	count = 0;
	while(roundCount > 0){
		sampleCount = numSample;
		while(sampleCount > 0){
			if(!strcmp(argv[1],"get"))
				get(sampleKey[sampleCount]+10000*roundCount);
			else
				set(sampleKey[sampleCount]+10000*roundCount, sampleValue[sampleCount]*sampleCount);
			sampleCount--;
		}
		roundCount--;
	}

	time(&current[1]);

	printf("Method: %s, NumSample : %d, NumRound : %d, Elapsed time : %f", argv[1],numSample, numRound, difftime(current[1],current[0]));
	disconnect();
	return 0;

	//Todo record current time

	/*Todo Do stress test depend on fourth value of argument with selected data structure
	 *Insert the sample into the structure (set)
	 *Record current time
	 *
	 *Pull the data from the structure(get)
	 *Record current time
	 *
	 */

	//Todo record current time
	//Todo Calcualte the differece between two record time
	//Todo record the number of sample, the number of stress test and the recorded time into the file
}
