#include <stdlib.h>
#include <getopt.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "pageTable.h"

#define DEFAULT_NUM_PHYSICAL_FRAMES 999999
#define DEFAULT_AGE_RECENT_CUTOFF   10

#define BITMASKS    "bitmasks"
#define VA2PA       "va2pa"
#define VPNS_PFN    "vpns_pfn"
#define VPN2PFN_PR  "vpn2pfn_pr"
#define OFFSET      "offset"
#define SUMMARY     "summary"

#define MAX_LEVEL_BITS  28

int main(int argc, char **argv){

    int numAddressesToProcess = -1;
    int numAvailablePhysicalFrames = DEFAULT_NUM_PHYSICAL_FRAMES;
    int ageRecentCutoff = DEFAULT_AGE_RECENT_CUTOFF;
    char *logMode = SUMMARY;

    char* memFileTracePath = NULL;
    char* accessModeFilePath = NULL;
    int levels[MAX_LEVEL_BITS];
    int numLevels = 0;

    int opt;
    int argsParsed = 1;

    while((opt = getopt(argc, argv, "n:f:a:l:")) != -1){
        argsParsed += 2;

        switch(opt){
            case 'n':
                numAddressesToProcess = atoi(optarg);
                if(numAddressesToProcess < 1){
                    printf("Number of memory accesses must be a number, greater than 0\n");
                    exit(-1);
                }
                break;

            case 'f':
                numAvailablePhysicalFrames = atoi(optarg);
                if(numAvailablePhysicalFrames < 1){
                    printf("Number of available frames must be a number, greater than 0\n");
                    exit(-1);
                }
                break;

            case 'a':
                ageRecentCutoff = atoi(optarg);
                if(ageRecentCutoff < 1){
                    printf("Age of last access considered recent must be a number, greater than 0\n");
                    exit(-1);
                }
                break;

            case 'l':
                logMode = optarg;
                break;
            
            default:
                break;
        }
    }

    memFileTracePath = argv[argsParsed++];
    accessModeFilePath = argv[argsParsed++];

    numLevels = argc - argsParsed + 1;
    for(int i = 0; i < numLevels; i++){
        levels[i] = atoi(argv[argsParsed + i]);
    }


}