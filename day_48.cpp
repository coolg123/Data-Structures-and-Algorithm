// Find all validanagram leeetcode fastest solution

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> findAnagrams(string s, string p) 
{
    vector<int> result;
    unordered_map<char, int> freq;
    for (char c : p) {
        freq[c]++;
    }
    int left = 0, right = 0, count = p.size();
    while (right < s.size()) 
    {
        if (freq[s[right++]]-- > 0)
        {
            count--;
        }
        if (count == 0) {
            result.push_back(left);
        }
        if (right - left == p.size() && freq[s[left++]]++ >= 0) {
            count++;
        }
    }
    return result;
}

int main() {
    string s = "cbaebabacd";
    string p = "abc";
    vector<int> result = findAnagrams(s, p);
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}