#include "listInterface.h"
#include "arrayList.h"

/*
Description:
Resize the arraylist if the capcaity is not enough
*/
template<class TYPE>
void ArrayList<TYPE>::resize()
{
	TYPE temp[] = *dataListPtr;
	TYPE* newlist = new TYPE[capacity * 2];
	for (int i = 0; i < capacity; i++) {
		newlist[i] = dataListPtr[i];
	}
	capacity *= 2;
	delete[] dataListPtr;
	dataListPtr = newlist;
}


/*
Description:
create the arraylist and allocate the memory, default 100 capcaity
*/
template<class TYPE>
ArrayList<TYPE>::ArrayList()
{
	NumAccess = 0;
	NumSwap = 0;
	NumRemove = 0;
	NumInsertAt = 0;
	NumAppends = 0;
	dataListPtr = new TYPE[DEFAULT_CAPACITY];
	size = 0;
	capacity = DEFAULT_CAPACITY;
}

/*
Description:
Delete the arraylist and deallocate all the memory we use
*/
template<class TYPE>
ArrayList<TYPE>::~ArrayList()
{
	delete[] dataListPtr;
	dataListPtr = nullptr;
}

/*
Description:
create the arraylist and allocate the memory, default 100 capcaity
*/
template<class TYPE>
ArrayList<TYPE>::ArrayList(int a)throw (std::out_of_range)
{
	if (a < 0)
	{
		throw std::out_of_range("Invalid index on insert");
	}
	NumAccess = 0;
	NumSwap = 0;
	NumRemove = 0;
	NumInsertAt = 0;
	NumAppends = 0;
	dataListPtr = new TYPE[a];
	size = 0;
	capacity = a;
}

/*
Description:
Gets a List data given the List index.
Parameters:
index: The index of the data to retrieve.
Returns:
The address of requested data.
Exceptions:
out_of_range: If the user trying to access something outside the allocated data
*/
template<class TYPE>
TYPE& ArrayList<TYPE>::operator[](int index) const throw(std::out_of_range)
{
	if (index >= size || index < 0)
	{
		throw std::out_of_range("Invalid index on insert");
	}
	return dataListPtr[index];
}

/*
Description:
Gets a List data given the List index.
Parameters:
index: The index of the data to retrieve.
Returns:
The true or false result of identify if it is empty, 
*/
template<class TYPE>
bool ArrayList<TYPE>::isEmpty() const
{
	return size == 0;
}

template<class TYPE>
int ArrayList<TYPE>::getSize() const
{
	return size;
}

/*
Description:
Insert a data at the index position.
Parameters:
index: The index of the data to insert at.
newEntry: direct copy of the data
Exceptions:
out_of_range: If the user trying to access something outside the allocated data
*/
template<class TYPE>
void ArrayList<TYPE>::insertAt(int index, const TYPE& newEntry) throw(std::out_of_range)
{
	//out of range
	if (index > size || index < 0)
	{
		throw std::out_of_range("Invalid index on insert");
	}
	//resize if full
	if (size == capacity)
		resize();
	//from back to data, shift one out, create a space for new data
	for (int i = size - 1; i >= index; i--)
	{
		dataListPtr[i + 1] = dataListPtr[i];
	}
	//copy data to the space create by above
	dataListPtr[index] = newEntry;
	//size fix
	size++;
}

/*
Description:
Remove a data at the index position.
Parameters:
index: The index of the data to remove.
Exceptions:
out_of_range: If the user trying to access something outside the allocated data
*/
template<class TYPE>
void ArrayList<TYPE>::removeAt(int index) throw(std::out_of_range)
{
	//out of range
	if (index >= size || index < 0)
	{
		throw std::out_of_range("Invalid index on insert");
	}
	//then it will not able to access the last element
	size--;
	//shift the data
	for (int i = index; i < size; i++)
	{
		dataListPtr[i] = dataListPtr[i+1];
	}
}

/*
Description:
Add a data at end of the list.
Parameters:
newEntry: direct copy of the data
*/
template<class TYPE>
void ArrayList<TYPE>::append(const TYPE& newEntry)
{
	if (size == capacity)
		resize();
	dataListPtr[size] = newEntry;
	size++;
}

template<class TYPE>
void ArrayList<TYPE>::swap(int from, int to) throw(std::out_of_range)
{
	int temp = dataListPtr[from];//place holder
	dataListPtr[from] = dataListPtr[to];
	dataListPtr[to] = temp;
}

template<class TYPE>
TYPE& ArrayList<TYPE>::getAt(int index) const throw(std::out_of_range)
{
	if (index >= size || index < 0)
	{
		throw std::out_of_range("Invalid index on insert");
	}
	return dataListPtr[index];
}

template<class TYPE>
void ArrayList<TYPE>::clearAll()
{
	delete[] dataListPtr;
	ArrayList();
}

template<class TYPE>
void ArrayList<TYPE>::clearStatistics()
{
	NumAccess = 0;
	NumSwap = 0;
	NumRemove = 0;
	NumInsertAt = 0;
	NumAppends = 0;
}

template<class TYPE>
int ArrayList<TYPE>::getNumAccess() const
{
	return NumAccess;
}

template<class TYPE>
int ArrayList<TYPE>::getNumSwap() const
{
	return NumSwap;
}

template<class TYPE>
int ArrayList<TYPE>::getNumRemove() const
{
	return NumRemove;
}

template<class TYPE>
int ArrayList<TYPE>::getNumInsertAt() const
{
	return NumInsertAt;
}

template<class TYPE>
int ArrayList<TYPE>::getNumAppends() const
{
	return NumAppends;
}
