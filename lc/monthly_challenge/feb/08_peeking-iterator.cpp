#include <iostream>
#include <vector>
using namespace std;

/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 */
class Iterator {
    struct Data;
	Data* data;
    Iterator(const vector<int>& nums);
 	Iterator(const Iterator& iter);

 	// Returns the next element in the iteration.
	int next();

	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
    int nowNumber = 0;
    int nextNumber = 0;
    int isFinal = false;
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
        nowNumber = next();
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return nextNumber;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        nowNumber = nextNumber;
        if(Iterator::hasNext())nextNumber = Iterator::next();
        else isFinal = true;
	    return nowNumber;
	}

	bool hasNext() const {
        return !isFinal;
	}
};