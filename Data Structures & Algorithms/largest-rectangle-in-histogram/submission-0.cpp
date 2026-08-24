class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int max_area = 0;
        int n = heights.size();
        for(int i = 0; i<n; i++){
            while(!st.empty() && heights[i]<heights[st.top()]){
                int h = heights[st.top()];
                st.pop();

                int right = i;
                int left = st.empty() ? -1 : st.top();

                int width = right - left -1;
                max_area = max(max_area, width*h);
            }
            st.push(i);
        }
        while(!st.empty()){
            int h = heights[st.top()];
            st.pop();

            int right = n;
            int left = st.empty() ? -1 : st.top();
            
            int width = right - left - 1;
            max_area = max(max_area, h * width);
        }
        return max_area;
        
    }
};
