/* ------------------------------------------------------------------|
给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。

注意:

可以认为区间的终点总是大于它的起点。
区间 [1,2] 和 [2,3] 的边界相互“接触”，但没有相互重叠。
示例 1:

输入: [ [1,2], [2,3], [3,4], [1,3] ]

输出: 1

解释: 移除 [1,3] 后，剩下的区间没有重叠。
示例 2:

输入: [ [1,2], [1,2], [1,2] ]

输出: 2

解释: 你需要移除两个 [1,2] 来使剩下的区间没有重叠。
示例 3:

输入: [ [1,2], [2,3] ]

输出: 0

解释: 你不需要移除任何区间，因为它们已经是无重叠的了。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/non-overlapping-intervals
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	贪心法
*
*	执行用时：28 ms, 在所有 C++ 提交中击败了87.81%的用户
*	内存消耗：9.3 MB, 在所有 C++ 提交中击败了84.68%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    if (!intervals.size()) {
        return 0;
    }
    sort(intervals.begin(), intervals.end(), [](const vector<int>& u, const vector<int>& v) {
        return u[1] < v[1];
        });

    int res = 1;
    int right = intervals[0][1];
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] >= right) {
            res++;
            right = intervals[i][1];
        }
    }
    return intervals.size() - res;
}

int main() {
    vector<vector<int> > intervals = { {1,2},{1,3},{2,3},{3,4} };
    int res = eraseOverlapIntervals(intervals);
}