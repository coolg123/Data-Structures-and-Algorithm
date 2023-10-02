// Task Scheduler fastest solution (LeetCode)

#include<bits/stdc++.h>
using namespace std;

int leastInterval(vector<char>& tasks, int n) 
{
    int freq[26] = {0}; // yeh array 26 size ka hai, jisme har character ki frequency store hogi
    for(char c : tasks) freq[c - 'A']++; // har character ki frequency store kardi
    sort(freq, freq + 26); // sort kardi array ko
    int maxFreq = freq[25] - 1; // maxFreq mein sabse zyada frequency wala character store kardi
    int idleSlots = maxFreq * n; // idleSlots mein maxFreq ko n se multiply kardi
    for(int i = 24; i >= 0; i--)  // ab maxFreq se kam frequency wale characters ko dekha
    {
        idleSlots -= min(freq[i], maxFreq);
    }
    return idleSlots > 0 ? idleSlots + tasks.size() : tasks.size(); // agar idleSlots 0 se zyada hai toh idleSlots + tasks.size() return kardi, nahi toh tasks.size() return kardi
}