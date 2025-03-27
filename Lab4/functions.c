// Lab 4 - 2/6/2025

#include "Header.h"

void initPost(Post* p)
{
	p->pTop = NULL;
}

int postIsEmpty(const Post* p)
{
	return p->pTop == NULL;
}

int pushToPost(Post* p, DiskData d)
{
	int success = 0;
	Disk* newDisk = malloc(sizeof(Disk));
	newDisk->diskData.diameter = d.diameter;

	if (newDisk != NULL) {
		success = 1;

		newDisk->pNext = p->pTop;
		p->pTop = newDisk;
	}

	return success;
}

DiskData popFromPost(Post* p)
{
	Disk* pTop = p->pTop;
	DiskData tempData = pTop->diskData;

	p->pTop = p->pTop->pNext;
	free(pTop);

	return tempData;
}

DiskData peekFromPost(const Post* p)
{
	return p->pTop->diskData;
}

int checkDiskWithPost(const Post* p, DiskData d)
{
	return p->pTop->diskData.diameter > d.diameter;
}


