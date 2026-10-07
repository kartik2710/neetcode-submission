class MedianFinder {
public:
    MedianFinder() {
        
    }
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;

    void addNum(int num) {
        left.push(num);
        
        int ele=left.top();

        left.pop();

        right.push(ele);
        
        if(right.size()>left.size())
        {
            ele=right.top();
            right.pop();
            left.push(ele);

        }
    }
    
    double findMedian() {
        if(left.size()!=right.size()) return (double)left.top();
        else
        return (double)(left.top()+right.top())/2;
    }
};
