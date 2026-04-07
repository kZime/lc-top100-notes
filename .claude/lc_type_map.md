# LeetCode 类型映射

## C++

| LeetCode 类型 | C++ 类型 |
|---|---|
| `integer` | `int` |
| `integer[]` | `vector<int>` |
| `integer[][]` / `list<list<integer>>` | `vector<vector<int>>` |
| `string` | `string` |
| `string[]` | `vector<string>` |
| `string[][]` / `list<list<string>>` | `vector<vector<string>>` |
| `boolean` | `bool` |
| `double` / `float` | `double` |
| `long` | `long long` |
| `character` | `char` |
| `character[]` | `vector<char>` |
| `TreeNode` | `TreeNode*`（需在 Solution 上方定义结构体） |
| `ListNode` | `ListNode*`（需在 Solution 上方定义结构体） |
| `void` | `void` |

## Go

| LeetCode 类型 | Go 类型 |
|---|---|
| `integer` | `int` |
| `integer[]` | `[]int` |
| `integer[][]` / `list<list<integer>>` | `[][]int` |
| `string` | `string` |
| `string[]` | `[]string` |
| `boolean` | `bool` |
| `double` / `float` | `float64` |
| `long` | `int64` |
| `TreeNode` | `*TreeNode` |
| `ListNode` | `*ListNode` |
| `void` | 无返回值 |

## 标准结构体定义

```cpp
// C++
struct TreeNode { int val; TreeNode *left, *right; TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} };
struct ListNode { int val; ListNode *next; ListNode(int x) : val(x), next(nullptr) {} };
```

```go
// Go
type TreeNode struct { Val int; Left, Right *TreeNode }
type ListNode struct { Val int; Next *ListNode }
```