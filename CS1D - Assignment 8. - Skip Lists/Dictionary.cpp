#include "Dictionary.h"

Dictionary::Dictionary()
{
	head = NULL;
	tail = NULL;
	QuadNode *dummyHead = new QuadNode;
	QuadNode *dummyTail = new QuadNode;

	Entry headE = {0, "negInfinity"};
	Entry tailE = {999, "posInfinity"};

	dummyHead->e = headE;

	dummyTail->e = tailE;

	dummyHead->next = dummyTail;
	dummyTail->prev = dummyHead;
	dummyTail->next = tail;
	tail= dummyTail;
	head =dummyHead;
    srchHead = head;
    srchTail = tail;

    levelCount = 0;
}

Dictionary::~Dictionary()
{
    delete head;
    delete tail;
    srchHead = NULL;
    srchTail = NULL;
//    srch = NULL;
//    it = NULL;
}

void Dictionary::Insert(Entry n)
{
    QuadNode *newPtr;

    newPtr = new QuadNode;
    newPtr->e = n;
    newPtr->above = NULL;
    newPtr->below = NULL;
    newPtr->next  = NULL;
    newPtr->prev  = NULL;


	if(empty())
	{
		newPtr->next = tail;
		newPtr->prev = head;
		head->next = newPtr;
		tail->prev = newPtr;
	}
	else
	{
		QuadNode *srchPtr = head;

		while(srchPtr != tail && newPtr->e.key
			  > srchPtr->next->e.key)
		{
			srchPtr = srchPtr->next;
		}

		if(srchPtr != tail)
		{
			// PROC - will add to the middle
			newPtr -> next = srchPtr -> next;
			srchPtr -> next -> prev = newPtr;
		}
		// PROC - used for when adding to both middle and tail
		newPtr -> prev = srchPtr;
		srchPtr -> next = newPtr;
		// PROC - will point tail to the last node in the list
		if(newPtr -> next == tail)
		{
			tail->prev = newPtr;
		}
	}

    //Create a new empty double linked list and connect it with the one below
    if(NewLevel())
    {
        QuadNode *newHead = new QuadNode;
        QuadNode *newTail = new QuadNode;

        newHead->above = NULL;
        newTail->above = NULL;
        newHead->next = NULL;
        newHead->prev = NULL;
        newTail->next = NULL;
        newTail->prev = NULL;
        newHead->e.key = 0;
        newHead->e.value = "negInfinity";
        newTail->e.key = 999;
        newTail->e.value = "posInfinity";

        newTail->below = srchTail;
        srchTail->above= newTail;

        newHead->below = srchHead;
        srchHead->above = newHead;

        srchHead = newHead;
        srchTail = newTail;
    }
}

void Dictionary::LinkNodesAbove()
{
    QuadNode *srch = head->next;

    //Create new random # of copies based on how many levels exist in skip list
    //for each node in the bottom list
    while(srch->e.value != "posInfinity")
    {
        int copyNode = rand() % (levelCount);

        QuadNode *copySrch = srch;

        for(int i = 1; i <= copyNode; i++)
        {
            QuadNode *newCopy = new QuadNode;
            newCopy->e = srch->e;
            newCopy->above = NULL;
            copySrch->above = newCopy;
            newCopy->below = copySrch;

            copySrch = copySrch->above;
        }

        srch = srch->next;
    }

    LinkNodesAcross();
}

void Dictionary::LinkNodesAcross()
{
    //Link up all the nodes in each row of the skip list using 4 pointers
	//tempHead, tempTail, rowSrch, & it
    QuadNode *tempHead = head;
    QuadNode *tempTail = tail;
    QuadNode *rowSrch = tempHead->above;
    QuadNode *it = tempHead->next;

    for(int i = 1; i <= levelCount; i++)
    {
        while(rowSrch != tempTail->above)
        {
        	bool emptySlotAbove = true;

            while(emptySlotAbove)
            {
            		if(it->above == NULL)
            			it = it->next;
            		else
            			emptySlotAbove = false;
            }

            it->above->prev = rowSrch;
            rowSrch->next = it->above;

            rowSrch = rowSrch->next;
            it = it->next;
        }

        tempHead = tempHead->above;
        tempTail = tempTail->above;
        rowSrch = tempHead->above;
        it = tempHead->next;
    }
}

QuadNode *Dictionary::Find(double key) const
{
    QuadNode *it = head;

    bool found = false;

    while(!found && (it->e.value != "posInfinity"))
    {
        if(key > it->e.key && it->e.key != 0)
        {
            it = it->next;
        }
        else if(key == it->e.key)
        {
            found = true;
        }
        else
        {
        	if(it->e.key == 0 && it->next->e.key != 999)
        	{
        		it = it->next;
        	}
        	else
        	{
        		it = it->below;
        	}

        }
    }

    return it;
}

bool Dictionary::Erase(double key)
{
    QuadNode *it = Find(key);

    if(it->e.value != "posInfinity" && it != NULL)
    {
        while(it != NULL)
        {
            QuadNode *delNode = it;

            it->next->prev = it->prev;
            it->prev->next = it->next;

            if(it->below != NULL)
                it->below->above = NULL;

            it = it->below;

            delete delNode;
        }

        return true;
    }
    else
    {
        cout << "Key " << key << " was NOT ERASED because it was NOT FOUND in"
        					  << " the list!\n\n";
        return false;
    }
}

bool Dictionary::empty() {return (head->next == tail);}


