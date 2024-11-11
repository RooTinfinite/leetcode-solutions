class PeekingIterator : public Iterator {
public:
	int currNext = -1;
	bool currHasNext = false;
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {

		currHasNext = Iterator::hasNext();
		if(currHasNext) {
			currNext = Iterator::next();
		}
	}
	int peek() {
        return currNext;
	}
	int next() {
	    int result = currNext;
        currHasNext = Iterator::hasNext();

		if(currHasNext) {
			currNext = Iterator::next();
		}
		return result;
	}
	bool hasNext() const {
	    return currHasNext;
	}
};