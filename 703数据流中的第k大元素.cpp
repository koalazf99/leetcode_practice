class KthLargest {
public:
    int* a; 
    int hpsize=0, k_min = -2147483648, k_;
    void swap(int &x, int &y){int tmp=x; x=y; y=tmp;}
    int left(int x){return 2*x;}
    int right(int x){return 2*x+1;}
    int parent(int x){return x / 2;}
    void hpify(int i){
        int l = left(i), r = right(i), small=i;
        if (l<=hpsize && (a[l]<a[small])) small = l;
        if (r<=hpsize && (a[r]<a[small])) small = r;
        if (small != i){
            swap(a[small], a[i]);
            hpify(small);
        }
    }
    void push(int key){
        hpsize ++;
        a[hpsize] = key;
        int i = hpsize;
        while (i>1 && a[parent(i)]>a[i]){
            swap(a[i], a[parent(i)]);
            i = parent(i);
        }
    }
    KthLargest(int k, vector<int>& nums) {
        k_ = k;
        a = new int[2*k];
        for (int i=0; i<nums.size(); ++i){
            if (hpsize<k){
                push(nums[i]);
            }
            else if (nums[i]>a[1]) {
                a[1] = nums[i];
                hpify(1);
            }
        }
    }
    
    int add(int val) {
        if (hpsize<k_){
            push(val);
            return a[1];
        }
        if (val<=a[1]) return a[1];
        else{
            a[1] = val;
            hpify(1);
            return a[1];
        }
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */