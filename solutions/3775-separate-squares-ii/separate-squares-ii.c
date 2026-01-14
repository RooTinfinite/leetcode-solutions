typedef struct {
    int* count;
    int* covered;
    int* xs;
    int n;
} SegmentTree;

typedef struct {
    int y;
    int delta;
    int xl;
    int xr;
} Event;

// create a segment tree
SegmentTree* createSegmentTree(int* xs, int xsSize) {
    SegmentTree* st = (SegmentTree*)malloc(sizeof(SegmentTree));
    st->xs = (int*)malloc(sizeof(int) * xsSize);
    memcpy(st->xs, xs, sizeof(int) * xsSize);
    st->n = xsSize - 1;
    int size = 4 * st->n;
    st->count = (int*)calloc(size, sizeof(int));
    st->covered = (int*)calloc(size, sizeof(int));
    return st;
}

void freeSegmentTree(SegmentTree* st) {
    free(st->count);
    free(st->covered);
    free(st->xs);
    free(st);
}

// modify the segment tree
void modify(SegmentTree* st, int qleft, int qright, int qval, int left,
            int right, int pos) {
    if (st->xs[right + 1] <= qleft || st->xs[left] >= qright) {
        return;
    }
    if (qleft <= st->xs[left] && st->xs[right + 1] <= qright) {
        st->count[pos] += qval;
    } else {
        int mid = (left + right) / 2;
        modify(st, qleft, qright, qval, left, mid, pos * 2 + 1);
        modify(st, qleft, qright, qval, mid + 1, right, pos * 2 + 2);
    }

    if (st->count[pos] > 0) {
        st->covered[pos] = st->xs[right + 1] - st->xs[left];
    } else {
        if (left == right) {
            st->covered[pos] = 0;
        } else {
            st->covered[pos] =
                st->covered[pos * 2 + 1] + st->covered[pos * 2 + 2];
        }
    }
}

// update the segment tree
void updateSegmentTree(SegmentTree* st, int qleft, int qright, int qval) {
    modify(st, qleft, qright, qval, 0, st->n - 1, 0);
}

// query the segment tree
int querySegmentTree(SegmentTree* st) { return st->covered[0]; }

// compare function
int compareEvents(const void* a, const void* b) {
    Event* e1 = (Event*)a;
    Event* e2 = (Event*)b;
    return e1->y - e2->y;
}

// compare function
int compareInts(const void* a, const void* b) { return *(int*)a - *(int*)b; }

// binary search - search in double array
int binarySearch(long long* arr, int size, long long target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left - 1;  // return the last position less than targe
}

// remove duplicates
int unique(int* arr, int arrSize) {
    if (arrSize <= 1) {
        return arrSize;
    }
    int j = 0;
    for (int i = 1; i < arrSize; i++) {
        if (arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    }
    return j + 1;
}

double separateSquares(int** squares, int squaresSize, int* squaresColSize) {
    Event* events = (Event*)malloc(sizeof(Event) * squaresSize * 2);
    int* xs = (int*)malloc(sizeof(int) * squaresSize * 4);
    int eventsSize = 0, xsSize = 0;

    // collect all events and x coordinates
    for (int i = 0; i < squaresSize; i++) {
        int x = squares[i][0];
        int y = squares[i][1];
        int l = squares[i][2];
        int xr = x + l;

        xs[xsSize++] = x;
        xs[xsSize++] = xr;
        events[eventsSize++] = (Event){y, 1, x, xr};
        events[eventsSize++] = (Event){y + l, -1, x, xr};
    }

    // sort events by y-coordinate
    qsort(events, eventsSize, sizeof(Event), compareEvents);
    // sort and remove duplicates x-coordinate
    qsort(xs, xsSize, sizeof(int), compareInts);
    xsSize = unique(xs, xsSize);

    // create a segment tree
    SegmentTree* segTree = createSegmentTree(xs, xsSize);

    // save prefix sums and widths
    long long* psum = (long long*)malloc(sizeof(long long) * eventsSize);
    int* widths = (int*)malloc(sizeof(int) * eventsSize);
    long long totalArea = 0LL;
    int prev = events[0].y;
    int pos = 0;

    // scan: calculate total area and record intermediate states
    for (int i = 0; i < eventsSize; i++) {
        int y = events[i].y;
        int delta = events[i].delta;
        int xl = events[i].xl;
        int xr = events[i].xr;

        totalArea += (double)querySegmentTree(segTree) * (y - prev);
        updateSegmentTree(segTree, xl, xr, delta);
        // record prefix sums and widths
        psum[i] = totalArea;
        widths[i] = querySegmentTree(segTree);
        prev = y;
    }

    // calculate the target area (half rounded up)
    long long target = (long long)(totalArea + 1) / 2;
    // find the first position greater than or equal to target using binary
    // search
    int idx = binarySearch(psum, eventsSize, (double)target);
    // get the corresponding area, width, and height
    double area = psum[idx];
    int width = widths[idx];
    int height = events[idx].y;

    double result = height + (totalArea - area * 2) / (width * 2.0);

    // release memory
    free(events);
    free(xs);
    free(psum);
    free(widths);
    freeSegmentTree(segTree);

    return result;
}