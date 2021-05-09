#include "nonreentrant_lock.h"

nonreentrant_lock::nonreentrant_lock() : locked(false)
{

}

nonreentrant_lock::~nonreentrant_lock()
{

}

void nonreentrant_lock::lock()
{
	while (InterlockedCompareExchange(&this->locked, true, false));
}

void nonreentrant_lock::unlock()
{
	this->locked = false;
}
