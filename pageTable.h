

struct PageTable;
struct Level;

typedef struct PageTable {
    int levelCount;
    unsigned int *bitMaskArr;
    unsigned int *shiftArr;
    unsigned int *entryCount;
    Level *top;
} PageTable;

typedef struct Level {
    PageTable *pageTable;
    unsigned int depth;
    
}