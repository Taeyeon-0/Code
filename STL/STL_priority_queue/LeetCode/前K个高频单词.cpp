#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> topKFrequent(vector<string> &words, int k) {
        // 创建哈希表以存储单词频率
        unordered_map<string, int> cnt;
        for (auto &word: words) {
            cnt[word]++;
        }

        // 自定义比较函数，根据频率和字典序排序键值对
        auto cmp = [](const pair<string, int> &a, const pair<string, int> &b) {
            return a.second == b.second ? a.first < b.first : a.second > b.second;
        };

        // 使用自定义比较函数的优先队列，以维护前 k 个高频单词
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> que(cmp);

        // 遍历频率哈希表，填充优先队列
        for (auto &it: cnt) {
            que.emplace(it);
            if (que.size() > k) {
                que.pop();// 当队列大小超过 k 时，移除频率最低的单词
            }
        }

        // 反向填充结果向量，以匹配最高频单词在前
        vector<string> ret(k);
        for (int i = k - 1; i >= 0; i--) {
            ret[i] = que.top().first;// 将具有最高频率的单词存储在逆序中
            que.pop();
        }

        return ret;
    }
};
