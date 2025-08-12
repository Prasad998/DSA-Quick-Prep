This file contains the snippets I can use for the corresponding coding patterns.

 ⚡ **Prefix Sum Pattern — Range Sum Optimization**

The Prefix Sum technique is used to **preprocess an array** so that **range sum queries** can be answered in `O(1)` time.

---

✅ **Code Example: Leetcode 303 - Range Sum Query – Immutable**

```cpp
#include <bits/stdc++.h>
using namespace std;

class NumArray {
public:
    NumArray(vector<int>& nums) {
        vec = nums;
        for (int i = 1; i < nums.size(); i++) {
            vec[i] = vec[i - 1] + nums[i];  // prefix sum computation
        }
    }

    int sumRange(int left, int right) {
        if (left == 0) return vec[right];
        return vec[right] - vec[left - 1];
    }

private:
    vector<int> vec;
};
```

---

 🔥 When to Use

- You get **multiple range sum queries**
- Constraints allow **preprocessing**
- No or few updates (or use Binary Indexed Tree for updates)

---

📌 **Popular Leetcode Problems Using Prefix Sum**

| Problem Title                                      | Leetcode No. | Notes                                        |
|---------------------------------------------------|--------------|----------------------------------------------|
| Range Sum Query - Immutable                       | 303          | Classic prefix sum use case                  |
| Subarray Sum Equals K                             | 560          | Prefix sum + hashmap                         |
| Maximum Size Subarray Sum Equals k                | 325          | Prefix sum + index tracking                  |
| Find Pivot Index                                  | 724          | Total sum - prefix = suffix                  |
| Contiguous Array                                  | 525          | Convert binary to +1/-1, use prefix sum      |
| Range Sum Query 2D – Immutable                    | 304          | 2D prefix sum                                |
| Number of Subarrays with Bounded Maximum          | 795          | Transform into sub-problems with prefix sum  |
| Sum of All Odd Length Subarrays                   | 1588         | Math + prefix sum                            |

---

## 💡 Pro Tip

Prefix Sum can be extended to:
- **2D matrices** (e.g. sum of sub-rectangles)
- **Prefix XOR / Min / Max**
- **Sliding window hybrids**
- Used inside binary search on sums (e.g. Leetcode 410)

---
## 🔧 `canForm()` — Character-Frequency Match Code

### ✅ Helper Function
**Reusable CODE to check if a `target` word can be formed using characters from a `source` string.**

```cpp
bool canForm(const string& word, const string& source) {
    unordered_map<char, int> freq;
    for (char c : source) freq[c]++;
    for (char c : word) {
        if (freq[c] == 0) return false;
        freq[c]--;
    }
    return true;
}
```

---

### 📌 Use Cases & Leetcode Examples

### 1. Leetcode 383 – Ransom Note

```cpp
// Can ransomNote be constructed from magazine?
bool canConstruct(string ransomNote, string magazine) {
    return canForm(ransomNote, magazine);
}
```

---

### 2. Leetcode 242 – Valid Anagram

```cpp
// Are two strings anagrams of each other?
bool isAnagram(string s, string t) {
    return canForm(s, t) && canForm(t, s);
}
```

---

### 3. Custom Problem – Word from Jumbled String

```cpp
// Return the first word that can be formed from jumbled characters
string findWord(const vector<string>& words, const string& jumbled) {
    for (const string& word : words) {
        if (canForm(word, jumbled)) return word;
    }
    return "-";
}
```

---

## 🧠 When to Use `canForm()`

| Problem Type               | Use                      |
|---------------------------|--------------------------|
| Anagram check             | Bi-directional `canForm` |
| Ransom note               | One-directional          |
| Jumbled string match      | One-directional          |
| Subword validation        | One-directional          |
| Frequency-based matching  | Validates char counts    |

---

## 💡 Pro Tip

You can easily adapt `canForm()` for:
- Case-insensitive comparison
- Sliding window logic
- Wildcard support (`?`)
- Multisets or char arrays


# 🚀 Interview Prep: Core Patterns & Company Formats

## Company Comparison

| Company                          | Duration         | Format                         | Offer (LPA)    |
|----------------------------------|------------------|--------------------------------|----------------|
| Microsoft SDE-1                  | 45 mins          | 2 Medium LeetCode              | 35+            |
| Google SWE-1                     | 60 mins          | 1 Hard + 1 Medium              | 40+            |
| Amazon / Atlassian / Meta / Uber | High pressure    | No extra time                  | —              |

> In that room, there’s no:
> - “I’ll figure it out later”
> - “I know the logic but can’t recall”
> - “Give me more time”
>
> It’s **you vs. the clock** — you must instantly recall and apply these patterns.

---

## 📌 Core Patterns You Must Master

Solve **2–3 timed problems per pattern** to train recall under real interview stress.

---

### 1. Dynamic Programming
- [<span style="color:blue">Dynamic Programming Patterns 1</span>](https://leetcode.com/discuss/post/458695/dynamic-programming-patterns-by-aatalyk-pmgr)  
- [<span style="color:blue">Dynamic Programming Patterns 2</span>](https://leetcode.com/discuss/post/1986802/dynamic-programming-by-anonymous_user-45td)  
- [<span style="color:blue">Dynamic Programming Patterns 3</span>](https://leetcode.com/discuss/post/662866/dp-for-beginners-problems-patterns-sampl-atdb)  
- [<span style="color:blue">Dynamic Programming Patterns 4</span>](https://leetcode.com/discuss/post/1000929/solved-all-dynamic-programming-dp-proble-8m82)  

### 2. Linked List
- [<span style="color:blue">Linked List Guide 1</span>](https://leetcode.com/discuss/post/1800120/become-master-in-linked-list-by-hi-malik-qvdr)  
- [<span style="color:blue">Linked List Guide 2</span>](https://leetcode.com/discuss/post/2725900/linked-list-study-guide-by-sunyingbao-yi2w)  

### 3. Prefix Sum
- [<span style="color:blue">Prefix Sum Guide</span>](https://leetcode.com/problems/subarray-sum-equals-k/solutions/867435/detailed-explanation-of-math-behind-o-n-solution-python3/)  

### 4. Bits Manipulation
- [<span style="color:blue">Bits Manipulation Patterns</span>](https://leetcode.com/discuss/post/3695233/all-types-of-patterns-for-bits-manipulat-qezp)  

### 5. Strings
- [<span style="color:blue">String Problems Collection</span>](https://leetcode.com/discuss/post/2001789/collections-of-important-string-question-pc6y)  

### 6. Sliding Window
- [<span style="color:blue">Sliding Window Cheatsheet</span>](https://leetcode.com/problems/frequency-of-the-most-frequent-element/solutions/1175088/C++-Maximum-Sliding-Window-Cheatsheet-Template/)  

### 7. Backtracking
- [<span style="color:blue">Backtracking Basics</span>](https://leetcode.com/discuss/post/2244368/backtracking-for-beginners-problems-by-x-xni4)  
- [<span style="color:blue">General Backtracking Approach</span>](https://leetcode.com/discuss/post/680269/a-general-approach-to-backtracking-probl-n5zd)  

### 8. Two Pointers
- [<span style="color:blue">Two Pointers Mastery 1</span>](https://leetcode.com/discuss/post/1688903/solved-all-two-pointers-problems-in-100-z56cn)  
- [<span style="color:blue">Two Pointers Mastery 2</span>](https://leetcode.com/discuss/post/1905453/master-in-two-pointer-by-rakibhasan1030-ku1j)  

### 9. Stack & Queue
- [<span style="color:blue">Stack Problem Patterns</span>](https://leetcode.com/discuss/post/3168516/a-general-approach-to-stack-problems-in-xsba0)  
- [<span style="color:blue">Monotonic Stack & Queue Templates</span>](https://leetcode.com/discuss/post/5085517/templates-for-monotonic-stacks-and-queue-2lfq)  

### 10. Heap
- [<span style="color:blue">Heap Patterns 1</span>](https://leetcode.com/discuss/post/1127238/master-heap-understanding-4-patterns-whe-fb8z)  
- [<span style="color:blue">Heap Patterns 2</span>](https://leetcode.com/discuss/post/2773740/important-patterns-in-heappriority-queue-5jdw)  

### 11. Binary Search
- [<span style="color:blue">Binary Search Guide 1</span>](https://leetcode.com/discuss/post/1233854/a-guide-to-the-binary-search-algorithm-b-r944)  
- [<span style="color:blue">Binary Search Guide 2</span>](https://leetcode.com/discuss/post/786126/python-powerful-ultimate-binary-search-t-rwv8)  

### 12. Graphs
- [<span style="color:blue">Graph Algorithms Practice</span>](https://leetcode.com/discuss/post/1326900/graph-algorithms-problems-to-practice-by-9u6j)  
- [<span style="color:blue">Graph Mastery</span>](https://leetcode.com/discuss/post/2360573/become-master-in-graph-by-hi-malik-o4xy)  
- [<span style="color:blue">Disjoint Set Union Guide</span>](https://leetcode.com/discuss/post/1072418/disjoint-set-union-dsuunion-find-a-compl-2oqn)  

### 13. Tree
- [<span style="color:blue">Tree Patterns 1</span>](https://leetcode.com/discuss/post/1337373/tree-question-pattern-2021-placement-by-t65qm)  
- [<span style="color:blue">Tree Patterns 2</span>](https://leetcode.com/discuss/post/5020529/master-tree-patterns-by-mercer80-8b0z)  
- [<span style="color:blue">Binary Trees Study Guide</span>](https://leetcode.com/discuss/post/1212004/binary-trees-study-guide-by-ag_piyush-x3mj)  

### 14. Recursion
- [<span style="color:blue">Recursion Mastery</span>](https://leetcode.com/discuss/post/1733447/become-master-in-recursion-by-hi-malik-sau4)  

### 15. Greedy
- [<span style="color:blue">Greedy Algorithm Basics</span>](https://leetcode.com/discuss/post/1061059/abcs-of-greedy-by-sapphire_skies-hbo3)  

---

## 📝 Preparation Strategy
- **Don’t just learn** — solve **timed problems per pattern**.
- Build **instant recall** and **quick application** under pressure.

---

