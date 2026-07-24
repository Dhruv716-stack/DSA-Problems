class MedianFinder {
public:
    priority_queue<int> left_mx_hp;
    priority_queue<int,vector<int>,greater<int>> right_mn_hp;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left_mx_hp.empty() || num<left_mx_hp.top()) left_mx_hp.push(num);
        else right_mn_hp.push(num);

        if(abs((int)left_mx_hp.size()-(int)right_mn_hp.size())>1){
            right_mn_hp.push(left_mx_hp.top());
            left_mx_hp.pop();
        }

        else if(right_mn_hp.size()>left_mx_hp.size()){
            left_mx_hp.push(right_mn_hp.top());
            right_mn_hp.pop();
        }
        return;
    }
    
    double findMedian() {
        double mean;
        if(left_mx_hp.size()==right_mn_hp.size()) mean=(left_mx_hp.top()+right_mn_hp.top())/2.0;
        else mean=left_mx_hp.top();
        return mean;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */