// i have passes 93 out of 99 test cases but got timelimit error so using chatgpt to optimise

// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         int n=heights.size();
//         int nextSmallerVal;
//         int prevSmallerVal=-1;
//         int area;
//         int maxArea=INT_MIN;
//         for(int i=0;i<n;i++){
//             int l=heights[i];
//             prevSmallerVal = -1;

//             for(int j = i - 1; j >= 0; j--) {

//                 if(heights[j] < heights[i]) {
//                     prevSmallerVal = j;
//                     break;
//                 }
//             }

//             nextSmallerVal = n;

//             for(int j = i + 1; j < n; j++) {

//                 if(heights[j] < heights[i]) {
//                     nextSmallerVal = j;
//                     break;
//                 }
//             }
//             int b=nextSmallerVal-prevSmallerVal-1;
//             area=l*b;
//             if(area>maxArea){
//                 maxArea=area;
//             }
//         }
//         return maxArea;

//     }
// };

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();

        stack<int> st;

        int maxArea = 0;

        for(int i = 0; i < n; i++) {

            // Current element is smaller than stack top
            while(!st.empty() && heights[st.top()] > heights[i]) {

                int index = st.top();
                st.pop();

                int height = heights[index];

                // Previous smaller
                int prevSmallerVal;

                if(st.empty()) {
                    prevSmallerVal = -1;
                }
                else {
                    prevSmallerVal = st.top();
                }

                // Current i is the next smaller
                int nextSmallerVal = i;

                // Width
                int b = nextSmallerVal - prevSmallerVal - 1;

                // Area
                int area = height * b;

                if(area > maxArea) {
                    maxArea = area;
                }
            }

            st.push(i);
        }

        // Process remaining elements
        while(!st.empty()) {

            int index = st.top();
            st.pop();

            int height = heights[index];

            int prevSmallerVal;

            if(st.empty()) {
                prevSmallerVal = -1;
            }
            else {
                prevSmallerVal = st.top();
            }

            // No smaller element on right
            int nextSmallerVal = n;

            int b = nextSmallerVal - prevSmallerVal - 1;

            int area = height * b;

            if(area > maxArea) {
                maxArea = area;
            }
        }

        return maxArea;
    }
};