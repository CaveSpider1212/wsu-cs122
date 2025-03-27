#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>

// TOWERS OF HANOI
typedef struct diskData {
	int diameter;
} DiskData;

typedef struct disk {
	DiskData diskData;
	struct disk* pNext;
} Disk;

typedef struct post {
	Disk* pTop;
} Post;

void initPost(Post* p);
int postIsEmpty(const Post* p);
int pushToPost(Post* p, DiskData d);
DiskData popFromPost(Post* p);
DiskData peekFromPost(const Post* p);
int checkDiskWithPost(const Post* p, DiskData d);




// MAZE

#endif