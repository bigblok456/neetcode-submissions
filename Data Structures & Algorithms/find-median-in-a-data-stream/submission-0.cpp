class MedianFinder {
public:
    priority_queue<int> left;
    priority_queue<int,vector<int>,greater<int>> right;
    //basically find the largest of the left half  and the smallest of the right half
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        left.push(num);
        if(!right.empty() && (left.top()>right.top())){
            right.push(left.top());
            left.pop();
        }
        if(left.size()>right.size()+1){
            right.push(left.top());
            left.pop();
        }
        if(right.size()>left.size()){
            left.push(right.top());
            right.pop();
        }
        
    }
    
    double findMedian() {
        if(left.size()==right.size()+1){
            return left.top();
        }
        return (left.top()+right.top())/2.0;
        
    }
};
