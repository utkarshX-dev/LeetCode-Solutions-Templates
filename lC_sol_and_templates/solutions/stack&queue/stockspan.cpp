#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class StockSpanner {
public:
    stack<pair<int, int>> st;
    int i = 0;
    StockSpanner() {
        
    }
    
    int next(int price) {
        while(!st.empty() && st.top().first <= price){
            st.pop();
        }
        int res = st.empty() ? i + 1 : i - st.top().second;
        st.push({price, i});
        i++;
        return res;
    }
};
