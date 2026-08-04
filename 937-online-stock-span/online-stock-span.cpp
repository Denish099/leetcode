class StockSpanner {
public:
    stack<pair<int,int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {

        int val  = 1;
        while(!st.empty() && st.top().first <= price){
           val += st.top().second;
           st.pop();  
           
        }


        st.push({price, val});

        return val;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */