#include <bits/stdc++.h>
using namespace std;

#define GRN "\033[32m"
#define RED "\033[31m"
#define BLD "\033[1m"
#define RST "\033[0m"

// ─── Solution ────────────────────────────────────────────────────────────────
class Solution {
    string s;
    int memo[12][12]; // memo[i][cnt1] 记录状态

public:
    int countDigitOne(int n) {
        s = to_string(n);
        // 初始化备忘录为 -1，表示未计算
        memset(memo, -1, sizeof(memo));

        // 参数含义：当前位索引, 当前 1 的个数, 是否受上界限制, 是否为合法数字(用于处理前导零)
        return dfs(0, 0, true, false);
    }

    /**
     * @param i        当前处理到的字符串下标
     * @param cnt1     从最高位到当前位已经出现的 '1' 的个数
     * @param is_limit 当前位是否受到限制（如果为 true，当前位最大只能到 s[i]）
     * @param is_num   前面是否已经填入过非零数字（处理前导零，本题中 0 不含 1，其实可简化）
     */
    int dfs(int i, int cnt1, bool is_limit, bool is_num) {
        // 递归终点：枚举完所有位数
        if (i == s.size()) {
            return cnt1; // 返回这一条路径上产生的 1 的总数
        }

        // 记忆化：只有在不受限制且不是前导零状态下才缓存（或者全缓存，但状态需包含 limit）
        // 通常做法是只对 !is_limit 的状态进行记忆化
        if (!is_limit && is_num && memo[i][cnt1] != -1) {
            return memo[i][cnt1];
        }

        int res = 0;

        // 如果前面全是前导零，当前位可以继续选 0（跳过
        if (!is_num) {
            res = dfs(i + 1, 0, false, false); // 这一位取 0，并且前面都是 0, 下一位没有限制，因此上限可以取到 9， no limit;
        }

        // 确定当前位能选的数字范围
        int up = is_limit ? s[i] - '0' : 9;
        int low = is_num ? 0 : 1; // 如果还没开始填数字，从 1 开始（0 已在上面 if 处理）

        for (int d = low; d <= up; ++d) {
            res += dfs(i + 1,
                       cnt1 + (d == 1),           // 如果当前位是 1，计数器加 1
                       is_limit && (d == up),     // 更新限制状态
                       true);                     // 标记已经开始填入数字
        }

        if (!is_limit && is_num) { // 无上限 且 前面有数，相当于 后面的 0~9 随便取
            memo[i][cnt1] = res;
        }
        return res;
    }
};

// ─── Test Harness ─────────────────────────────────────────────────────────────

int main() {
    Solution sol;
    int passed = 0, total = 0;

    auto check = [&](int got, int want, const string& label) {
        total++;
        if (got == want) {
            printf(GRN "✓" RST "  %-36s →  %d\n", label.c_str(), got);
            passed++;
        } else {
            printf(RED "✗" RST "  " BLD "%-36s" RST "    want=%d  got=%d\n",
                   label.c_str(), want, got);
        }
    };

    check(sol.countDigitOne(256), 156, "example1: n=256");
    check(sol.countDigitOne(314112313), 354582708, "random big number");
    check(sol.countDigitOne(13), 6, "example1: n=13");
    check(sol.countDigitOne(0), 0, "example2: n=0");
    check(sol.countDigitOne(1), 1, "single one");
    check(sol.countDigitOne(10), 2, "crossing ten");
    check(sol.countDigitOne(99), 20, "double digits all range");
    check(sol.countDigitOne(100), 21, "exact power of ten");

    printf("\n%s\n", string(44, '-').c_str());
    if (passed == total)
        printf(GRN "%d / %d passed\n" RST, passed, total);
    else
        printf(RED "%d / %d passed\n" RST, passed, total);
    return (passed == total) ? 0 : 1;
}
