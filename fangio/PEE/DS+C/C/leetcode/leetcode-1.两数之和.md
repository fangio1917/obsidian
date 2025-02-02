
## 题目描述

- 给定一个整数数组 `nums` 和一个整数目标值 `target`，请你在该数组中找出 **和为目标值** _`target`_  的那 **两个** 整数，并返回它们的数组下标。
- 你可以假设每种输入只会对应一个答案，并且你不能使用两次相同的元素。
- [题目连接](https://leetcode.cn/problems/two-sum/description/)

## 示例

### **示例 1：**

- **输入：** nums = [2,7,11,15], target = 9
- **输出：**[0,1]
- **解释：** 因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。

### 示例 2：

- **输入：** nums = [3,2,4], target = 6
- **输出：**[1,2]

### **示例 3：**

- **输入：** nums = [3,3], target = 6
- **输出：**[0,1]

## 解答

### C （暴力破解）

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
**/

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * 2);
    if (result == NULL) {
        *returnSize = 0;
        return NULL;
    }

    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }
    free(result);
    *returnSize = 0;
    return NULL;
}
```

## C++ (哈希查找差值)

```cpp
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        auto hash = new unordered_map<int,int>;
        vector<int> result;
        {
            int i = 0;
            for (auto num : nums) {
                int remained = target - num;
                auto index = hash->find(remained);
                if (index != hash->end()) {
                    result.push_back(index->second);
                    result.push_back(i);
                    return result;
                }else{
                    hash->insert({num,i});
                }
                i++;
            }
        }
        delete hash;
        return result;
    }
};
```
