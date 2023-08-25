#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// 比较函数，用于排序
bool compare(const pair<string, int> &a, const pair<string, int> &b) {
    return a.second == b.second ? a.first < b.first : a.second > b.second;
}

// 将句子中的所有字母转换为小写
string toLowerCase(const string &str) {
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

// 统计单词出现次数并输出结果
void wordFrequency(const string &sentence) {
    string loweredSentence = toLowerCase(sentence);

    map<string, int> wordCount;// 用于存储单词和其出现次数的映射

    size_t pos = 0;
    while (pos < loweredSentence.length()) {
        // 找到下一个单词的起始位置
        while (pos < loweredSentence.length() && !isalpha(loweredSentence[pos])) {
            pos++;
        }

        // 找到单词的结束位置
        size_t endPos = pos;
        while (endPos < loweredSentence.length() && (isalpha(loweredSentence[endPos]) || loweredSentence[endPos] == '.')) {
            endPos++;
        }

        // 提取单词
        string word = loweredSentence.substr(pos, endPos - pos);

        if (!word.empty()) {
            if (word.back() == '.') {
                word.pop_back();// 去除句号
            }
            wordCount[word]++;// 统计单词出现次数
        }

        pos = endPos;
    }

    // 将单词和次数存储到向量中，并按要求排序
    vector<pair<string, int>> sortedWords(wordCount.begin(), wordCount.end());
    sort(sortedWords.begin(), sortedWords.end(), compare);

    // 输出结果
    for (const auto &entry: sortedWords) {
        cout << entry.first << ":" << entry.second << endl;
    }
}

int main() {
    string sentence;
    getline(cin, sentence);// 输入句子
    wordFrequency(sentence);

    return 0;
}
