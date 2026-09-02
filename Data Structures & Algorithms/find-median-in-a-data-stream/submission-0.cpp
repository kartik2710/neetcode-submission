class MedianFinder {
public:
 
    priority_queue<int> maxHeap;

    priority_queue<int, vector<int>, greater<int>> minHeap;

    MedianFinder() {}

    void addNum(int num) {
        maxHeap.push(num);

        // Move largest from smaller half to larger half
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        // maxHeap should have equal or one more element
        if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return ((double)maxHeap.top() + minHeap.top()) / 2.0;
        }

        return maxHeap.top();
    }
};