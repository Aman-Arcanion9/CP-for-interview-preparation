class ProductOfNumbers {
public:
    vector<int> A={1};
    ProductOfNumbers() {  
    }
    
    void add(int num) {
        if(num){
            A.push_back(A.back()*num);
        }else{
            A={1};
        }
    }
    
    int getProduct(int k) {
        if(k>=A.size())return 0;
        return A.back()/A[A.size()-k-1];
    }
};
