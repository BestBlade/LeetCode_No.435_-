/* ------------------------------------------------------------------|
����һ������ļ��ϣ��ҵ���Ҫ�Ƴ��������С������ʹʣ�����以���ص���

ע��:

������Ϊ������յ����Ǵ���������㡣
���� [1,2] �� [2,3] �ı߽��໥���Ӵ�������û���໥�ص���
ʾ�� 1:

����: [ [1,2], [2,3], [3,4], [1,3] ]

���: 1

����: �Ƴ� [1,3] ��ʣ�µ�����û���ص���
ʾ�� 2:

����: [ [1,2], [1,2], [1,2] ]

���: 2

����: ����Ҫ�Ƴ����� [1,2] ��ʹʣ�µ�����û���ص���
ʾ�� 3:

����: [ [1,2], [2,3] ]

���: 0

����: �㲻��Ҫ�Ƴ��κ����䣬��Ϊ�����Ѿ������ص����ˡ�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/non-overlapping-intervals
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������|
-------------------------------------------------------------------*/

/*	̰�ķ�
*
*	ִ����ʱ��28 ms, ������ C++ �ύ�л�����87.81%���û�
*	�ڴ����ģ�9.3 MB, ������ C++ �ύ�л�����84.68%���û�
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