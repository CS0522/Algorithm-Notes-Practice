<!-- Authorized by Frank -->
- [vector (P191)](#vector-p191)
  - [vector defination (P191)](#vector-defination-p191)
  - [vector iterator \& traversal (P192)](#vector-iterator--traversal-p192)
  - [common function (P193)](#common-function-p193)
    - [.push\_back(element) (P193)](#push_backelement-p193)
    - [.pop\_back() (P194)](#pop_back-p194)
    - [.size() (P194)](#size-p194)
    - [.clear() (P195)](#clear-p195)
    - [.insert(iterator, element) (P195)](#insertiterator-element-p195)
    - [.erase(iterator) (P196)](#eraseiterator-p196)
    - [.erase(start\_it, last\_it) (P196)](#erasestart_it-last_it-p196)
- [set (P197)](#set-p197)
  - [defination (P197)](#defination-p197)
  - [vector iterator \& traversal (P198)](#vector-iterator--traversal-p198)
  - [common function (P199)](#common-function-p199)
    - [.insert(element)](#insertelement)
    - [.find(element)](#findelement)
    - [.erase(iterator)](#eraseiterator)
    - [.erase(element)](#eraseelement)
    - [.erase(start\_it, last\_it)](#erasestart_it-last_it)
    - [.size()](#size)
    - [.clear()](#clear)
  - [multiset, unordered\_set](#multiset-unordered_set)
- [string (P202)](#string-p202)
  - [common function (P204)](#common-function-p204)
    - [operator+=](#operator)
    - [==, \>, \<, !=](#---)
    - [.length(), .size()](#length-size)
    - [.insert(pos, str) (P205)](#insertpos-str-p205)
    - [.insert(str1\_it, str2\_it\_start, str2\_it\_end)](#insertstr1_it-str2_it_start-str2_it_end)
    - [.erase(it) (P206)](#eraseit-p206)
    - [.erase(first\_it, last\_it)](#erasefirst_it-last_it)
    - [.erase(pos, length)](#erasepos-length)
    - [.clear()](#clear-1)
    - [.substr(pos, length) (P207)](#substrpos-length-p207)
    - [.find(str2, pos) (P208)](#findstr2-pos-p208)
    - [.replace(pos, length, str2) (P209)](#replacepos-length-str2-p209)
    - [.replace(it\_start, it\_end, str2)](#replaceit_start-it_end-str2)
- [map (P213)](#map-p213)
  - [defination (P213)](#defination-p213)
  - [traversal (P213)](#traversal-p213)
  - [common function (P215)](#common-function-p215)
    - [.insert(pair)](#insertpair)
    - [.find(key)](#findkey)
    - [.erase(it)](#eraseit)
    - [.erase(key)](#erasekey)
    - [.erase(first\_it, last\_it)](#erasefirst_it-last_it-1)
    - [.size()](#size-1)
    - [.clear()](#clear-2)
  - [multimap, unordered\_map](#multimap-unordered_map)
- [queue (P218)](#queue-p218)
  - [defination (P218)](#defination-p218)
  - [traversal (P218)](#traversal-p218)
  - [common function (P219)](#common-function-p219)
    - [.push(element) (P219)](#pushelement-p219)
    - [.pop() (P219)](#pop-p219)
    - [.front(), .back() (P219)](#front-back-p219)
    - [.empty()](#empty)
    - [.size()](#size-2)
- [stack (P227)](#stack-p227)
  - [defination](#defination)
  - [traversal \&\& visit](#traversal--visit)
  - [common functon](#common-functon)
    - [.push(element)](#pushelement)
    - [.top()](#top)
    - [.pop()](#pop)
    - [.empty()](#empty-1)
    - [.size()](#size-3)
- [pair (P230)](#pair-p230)
  - [defination (P230)](#defination-p230)
  - [use \&\& visit (P231)](#use--visit-p231)
  - [common function (P231)](#common-function-p231)
    - [map.insert(pair) (P232)](#mapinsertpair-p232)
- [Algorithm (P233)](#algorithm-p233)
  - [max(), min(), abs(), fabs(), swap()](#max-min-abs-fabs-swap)
  - [reverse(it1, it2) ](#reverseit1-it2-)
  - [next\_permutation(it1, it2) (P234)](#next_permutationit1-it2-p234)
  - [fill(it1, it2, value) (P235)](#fillit1-it2-value-p235)
  - [sort(it1, it2, cmp) (P235) ](#sortit1-it2-cmp-p235-)
  - [lower\_bound(first, last, value), upper\_bound() (P242)](#lower_boundfirst-last-value-upper_bound-p242)


# vector (P191)
* 可变长数组

## vector defination (P191)
```cpp
vector<type> name;

// 二维
// 一维二维均变长
vector<vector<int> > name;
// 一维定长，二维变长
vector<int> arrayName[arraySize];
```

## vector iterator & traversal (P192)
```cpp
vector<type>::iterator it;
```

```cpp
// 通过下标
for (int i = 0; i <= 5; i++)
{
    // code
}

// 通过迭代器
for (it = vc.begin(); it != vc.end(); it++)
{
    cout << *it;
}
```

* vc[i] 等价于 *(vc.begin() + i)
* 只有在 vector & string 中，才能使用 vc.begin() + i 的写法

## common function (P193)

### .push_back(element) (P193)

### .pop_back() (P194)
* 无返回值，无参数

### .size() (P194)
* 返回 unsigned 类型，vector 元素的个数

### .clear() (P195)

### .insert(iterator, element) (P195)

### .erase(iterator) (P196)
* 删除 iterator 处的元素

### .erase(start_it, last_it) (P196)
* 删除区间 `[start_it, last_it)`


# set (P197)
容器
* 内部自动有序
* 不含重复元素

## defination (P197)
```cpp
set<type> name;

set<set<int> > name;

set<int> arrayName[arraySize];
```

## vector iterator & traversal (P198)
set 只能通过 iterator 迭代器进行访问
```cpp
set<int>::iterator it;

for (it = st.begin(); it != st.end(); it++)
{
    // code
}
```

## common function (P199)

### .insert(element)
* 插入后自动进行排序和去重

### .find(element)
* 返回 iterator 迭代器

### .erase(iterator)

### .erase(element)

### .erase(start_it, last_it)

### .size()

### .clear()

## multiset, unordered_set
* multiset 允许重复，自动排序
* unordered_set 不排序，自动去重


# string (P202)
* 使用 `getline(cin, str)` 获取包含空格的字符串

## common function (P204)

### operator+= 
```cpp
string str1;
string str2;
string str3;

str1 += str2;

str3 = str1 + str2;
```

### ==, >, <, !=
* 按字典顺序比大小

### .length(), .size()
* 都是返回 string 的长度

### .insert(pos, str) (P205)
* 在 [pos] 处插入 str

### .insert(str1_it, str2_it_start, str2_it_end)
* 在 str1 的 str1_it 位置，插入 str2 的 `[str2_it_start, str2_it_end)` 区间的子字符串

### .erase(it) (P206)
* 删除迭代器 it 位置的字符

### .erase(first_it, last_it)
* `[first_it, last_it)` 区间

### .erase(pos, length)
* 删除 [pos] 处开始 length 个字符

### .clear()

### .substr(pos, length) (P207)
* 返回从 [pos] 处开始，长度为 length 的子串

### .find(str2, pos) (P208)
* 从 [pos] 处开始查找字符串 str2，并返回 str2 开始的下标

### .replace(pos, length, str2) (P209)
* 从 [pos] 处开始长度为 length 的子串，替换为 str2

### .replace(it_start, it_end, str2)
* `[it_start, it_end)` 区间的子串替换为 str2


# map (P213)
* 映射，建立 type1 类型到 type2 类型的映射
* Map 会以 Key 从小到大的顺序自动排序 (因为内部是红黑树)

## defination (P213)
```cpp
map<type1, type2> mp;

map<string, int> mp1;

map<set<int>, string> mp2;
```

## traversal (P213)
```cpp
map<char, int> mp1;
// 通过下标
mp1['c'] = 20;
mp1['c'] = 30;
cout << mp1['c'];
//  output: 30

// 通过迭代器
// it->first 获得 Key
// it->second 获得 Value
mp1['a'] = 1;
mp1['b'] = 2;
mp1['c'] = 3;

map<char, int>::iterator it;
for (it = mp1.begin(); it != mp1.end(); it++)
{
    cout << it->first << " " << it->second << endl;
}
// output: a 1 b 2 c 3
```

## common function (P215)

### .insert(pair)
* 见 [pair 的 map.insert(pair)](#mapinsertpair-p232)

### .find(key)
* 返回 键 == key 的迭代器

### .erase(it)
* 删除迭代器 it 位置的键值对

### .erase(key)
* key 为要删除的键

### .erase(first_it, last_it)
* 删除区间 `[first_it, last_it)` 

### .size()
* map中的映射对数

### .clear()
* 清空 map

## multimap, unordered_map
* multimap 允许键重复，自动排序
* unordered_map 不排序，自动去重


# queue (P218)
队列，适用于广度优先搜索

## defination (P218)
```cpp
queue<type> qe;
```

## traversal (P218)
```cpp
// 访问队首元素
q.front()

// 访问队尾元素
q.back()
```

## common function (P219)

### .push(element) (P219)
* 入队 (队尾)

### .pop() (P219)
* 出队 (队首)

### .front(), .back() (P219)
* 返回队首和队尾的元素

### .empty()
* 返回 true, false

### .size()
* 返回 queue 内的元素个数


# stack (P227)

## defination 
```cpp
stack<type> sk;
```

## traversal && visit
只能通过 `top()` 访问栈顶
```cpp
stack<int> sk;
sk.push(1);
int a = sk.top()
```

## common functon

### .push(element)

### .top()
* 返回栈顶元素

### .pop()

### .empty()

### .size()


# pair (P230)

## defination (P230)
```cpp
#include <utility>
// 或者
#include <map>

pair<type1, type2> name;

pair<string, int> p;
```

## use && visit (P231)
```cpp
pair<string, int> p;
p.first = "hello1";
p.second = 1;

p = make_pair("hello2", 2);

p = pair<string, int>("hello3", 3);

cout << p.first << " " << p.second;
```

## common function (P231)
* 可以直接使用 `<`, `==`, `!=` 等进行比较大小
* 先比较 `p.first`；若不相等，再比较 `p.second`

### map.insert(pair) (P232)
```cpp
map<string, int> mp;

mp.insert(make_pair("hello1", 1));

mp.insert(pair<string, int>("hello2", 2));
```


# Algorithm (P233)

## max(), min(), abs(), fabs(), swap() 

## <font color="red">reverse(it1, it2) </font>
* 将 `[it1, it2)` 区间内的元素进行反转
* it1，it2 可以是数组指针，容器的迭代器

## next_permutation(it1, it2) (P234)
* 给出 `[it1, it2)` 区间内的序列的下一个全排列
* 返回值为 true 或者 false
```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a[10] = {1, 2, 3};
    // a[0] ~ a[2] 之间进行全排列
    do
    {
        cout << a[0] << " " << a[1] << " " << a[2];
    }
    while (next_permutation(a, a + 3));
}
```

## fill(it1, it2, value) (P235)
* 将区间 `[it1, it2)` 赋予相同的值
```cpp
int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    // a[0] ~ a[4] = 233
    fill(a, a + 5, 233);

    return 0;
}
```

## <font color="red">sort(it1, it2, cmp) (P235) </font>
* 将区间 `[it1, it2)` 进行排序，排序规则可根据第三个参数 `cmp` 函数进行
* 默认进行递增排序
* `vector`, `string`, `deque` 可以使用 sort。`map`, `set` 红黑树实现，已经自动有序
```cpp
#include <iostream>
#include <Algorithm>
using namespace std;

int main()
{
    int a[6] = {9, 4, 2, 5, 6, -1};
    // a[0] ~ a[3] 从小到大排序
    sort(a, a + 4);

    return 0;
}
```
* `cmp` 函数的写法
```cpp
bool cmp(int a, int b)
{
    // 从大到小
    return a > b;
}

bool cmp(node a, node b)
{
    return a.x > b.x;
}

bool cmp(node a, node b)
{
    if (a.x != b.x)
    {
        return a.x > b.x;
    }
    return a.y > b.y;
}
```

## lower_bound(first, last, value), upper_bound() (P242)
* lower_bound(first, last, value): 寻找数组或者容器内 `[first, last)` 范围内第一个`大于等于` value 元素的位置。返回指针或者迭代器

* upper_bound(first, last, value): 寻找数组或者容器内 `[first, last)` 范围内第一个`大于` value 元素的位置。返回指针或者迭代器