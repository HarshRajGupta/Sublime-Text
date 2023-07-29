#pragma GCC optimize("O3", "fast-math", "unroll-loops", "no-stack-protector", \
                         "omit-frame-pointer")
#pragma GCC target("sse", "sse2", "sse3", "sse4", "abm", "mmx", "avx", "avx2")

#ifdef _GLIBCXX_IOSTREAM

#ifndef __MAIN__
#define __MAIN__                                                              \
    signed main ()                                                            \
    {                                                                         \
        std::cerr.tie (NULL);                                                 \
        std::clog.tie (NULL);                                                 \
        std::clog << std::fixed << std::setprecision (6)                      \
                  << "✅ Compiled Successfully ✅\n";                         \
        auto __STARTING_TIME__ = std::chrono::high_resolution_clock::now ();  \
        preCompute ();                                                        \
        signed __TEST_CASES__;                                                \
        std::cin >> __TEST_CASES__;                                           \
        std::clog << "   🎯 Test Cases: #" << __TEST_CASES__ << " 🎯\n"     \
                  << std::endl;                                               \
        for (signed __TEST_CASE__ = 1; __TEST_CASE__ <= __TEST_CASES__;       \
             ++__TEST_CASE__)                                                 \
            {                                                                 \
                std::clog << "\t<== "                                         \
                          << "TestCase: #" << __TEST_CASE__ << " ==>\n";      \
                std::cout << "#" << __TEST_CASE__ << ": ";                    \
                solve ();                                                     \
                std::cout << '\n';                                            \
            }                                                                 \
        std::clog                                                             \
            << "\n🤖 RunTime: "                                             \
            << ((long double)                                                 \
                    std::chrono::duration_cast<std::chrono::nanoseconds> (    \
                        std::chrono::high_resolution_clock::now ()            \
                        - __STARTING_TIME__)                                  \
                        .count ())                                            \
                   / 1e9                                                      \
            << " sec 🤖";                                                     \
        return 0;                                                             \
    }
#endif

#ifndef __SOLVE__
#define __SOLVE__                                                             \
    signed main ()                                                            \
    {                                                                         \
        std::clog << std::fixed << std::setprecision (6)                      \
                  << "  <== Compilation: ✅ ==>" << '\n'                      \
                  << std::endl;                                               \
        auto __STARTING_TIME__ = std::chrono::high_resolution_clock::now ();  \
        solve ();                                                             \
        std::clog                                                             \
            << "\n<==🤖 RunTime: "                                          \
            << ((long double)                                                 \
                    std::chrono::duration_cast<std::chrono::nanoseconds> (    \
                        std::chrono::high_resolution_clock::now ()            \
                        - __STARTING_TIME__)                                  \
                        .count ())                                            \
                   / 1e9                                                      \
            << " 🤖==>";                                                      \
        return 0;                                                             \
    }
#endif

#ifndef __TEST__
#define __TEST__                                                              \
    signed main ()                                                            \
    {                                                                         \
        srand (time (NULL));                                                  \
        std::clog << std::fixed << std::setprecision (6)                      \
                  << "  <== Compilation: ✅ ==>" << '\n'                      \
                  << std::endl;                                               \
        auto __STARTING_TIME__ = std::chrono::high_resolution_clock::now ();  \
        Solution ().test ();                                                  \
        std::clog                                                             \
            << "\n<==🤖 RunTime: "                                          \
            << ((long double)                                                 \
                    std::chrono::duration_cast<std::chrono::nanoseconds> (    \
                        std::chrono::high_resolution_clock::now ()            \
                        - __STARTING_TIME__)                                  \
                        .count ())                                            \
                   / 1e9                                                      \
            << " 🤖==>";                                                      \
        return 0;                                                             \
    }
#endif

namespace __gnu_debug
{
struct ListNode
{
    int val;
    ListNode *next;
    ListNode (int x = 0, ListNode *next = NULL) : val (x), next (next) {}
};

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode (int x = 0, TreeNode *left = NULL, TreeNode *right = NULL)
        : val (x), left (left), right (right)
    {
    }
};

void
__PRINT_VARIABLE (__gnu_debug::ListNode *x)
{
    std::cerr << '[';
    unsigned int f = 0;
    for (__gnu_debug::ListNode *i = x; i != nullptr; i = i->next, ++f)
        {
            if (f)
                std::cerr << ", ";
            std::cerr << i->val;
        }
    std::cerr << ']';
}

void
__PRINT_VARIABLE (__gnu_debug::TreeNode *x)
{
    std::function<void (__gnu_debug::TreeNode * root)> inOrder
        = [&] (__gnu_debug::TreeNode *root) {
              if (root == nullptr)
                  return;
              inOrder (root->left);
              std::cerr << ' ' << root->val;
              inOrder (root->right);
          };
    std::function<void (__gnu_debug::TreeNode * root)> preOrder
        = [&] (__gnu_debug::TreeNode *root) {
              if (root == nullptr)
                  return;
              std::cerr << ' ' << root->val;
              preOrder (root->left);
              preOrder (root->right);
          };
    std::function<void (__gnu_debug::TreeNode * root)> postOrder
        = [&] (__gnu_debug::TreeNode *root) {
              if (root == nullptr)
                  return;
              postOrder (root->left);
              postOrder (root->right);
              std::cerr << ' ' << root->val;
          };
    std::cerr << "{\n\tinOrder:";
    inOrder (x);
    std::cerr << ",\n\tpreOrder:";
    preOrder (x);
    std::cerr << ",\n\tpostOrder:";
    postOrder (x);
    std::cerr << "\n\t}";
}
} // namespace __gnu_debug

namespace LOCAL_DEBUG
{

template <typename T> void __PRINT_VARIABLE (const T &x);

void
__PRINT_VARIABLE (const int &x)
{
    std::cerr << x;
}

void
__PRINT_VARIABLE (const long &x)
{
    std::cerr << x;
}

void
__PRINT_VARIABLE (const long long &x)
{
    std::cerr << x;
}

void
__PRINT_VARIABLE (const unsigned &x)
{
    std::cerr << x;
}

void
__PRINT_VARIABLE (const unsigned long &x)
{
    std::cerr << x;
}

void
__PRINT_VARIABLE (const unsigned long long &x)
{
    std::cerr << x;
}

void
__PRINT_VARIABLE (const float &x)
{
    std::cerr << x;
}

void
__PRINT_VARIABLE (const double &x)
{
    std::cerr << x;
}

void
__PRINT_VARIABLE (const long double &x)
{
    std::cerr << x;
}

void
__PRINT_VARIABLE (const char &x)
{
    std::cerr << '\'' << x << '\'';
}

void
__PRINT_VARIABLE (const char *x)
{
    std::cerr << '\"' << x << '\"';
}

void
__PRINT_VARIABLE (const bool &x)
{
    std::cerr << std::boolalpha << x;
}

#ifdef _GLIBCXX_STRING // header file of string
void
__PRINT_VARIABLE (const std::string &x)
{
    std::cerr << '\"' << x << '\"';
}
#endif

#ifdef _GLIBCXX_UTILITY // header file of pair
template <typename T, typename V>
void
__PRINT_VARIABLE (const std::pair<T, V> &x)
{ // pair
    std::cerr << '(';
    __PRINT_VARIABLE (x.first);
    std::cerr << ", ";
    __PRINT_VARIABLE (x.second);
    std::cerr << ')';
}
#endif

#ifdef _GLIBCXX_QUEUE // header file of queue
template <typename T>
void
__PRINT_VARIABLE (const std::queue<T> &x) // queue
{
    auto f = x;
    std::cerr << '[';
    while (!f.empty ())
        {
            __PRINT_VARIABLE (f.front ());
            f.pop ();
            if (!f.empty ())
                std::cerr << ", ";
        }
    std::cerr << ']';
}

template <typename T>
void
__PRINT_VARIABLE (const std::priority_queue<T> &x) // max heap
{
    auto f = x;
    std::cerr << '[';
    while (!f.empty ())
        {
            __PRINT_VARIABLE (f.top ());
            f.pop ();
            if (!f.empty ())
                std::cerr << ", ";
        }
    std::cerr << ']';
}

template <typename T>
void
__PRINT_VARIABLE (const std::priority_queue<T, std::vector<T>,
                                            std::greater<T> > &x) // min heap
{
    auto f = x;
    std::cerr << '[';
    while (!f.empty ())
        {
            __PRINT_VARIABLE (f.top ());
            f.pop ();
            if (!f.empty ())
                std::cerr << ", ";
        }
    std::cerr << ']';
}
#endif

#ifdef _GLIBCXX_STACK // header file of stack
template <typename T>
void
__PRINT_VARIABLE (const std::stack<T> &x)
{
    auto f = x;
    std::cerr << '[';
    while (!f.empty ())
        {
            __PRINT_VARIABLE (f.top ());
            f.pop ();
            if (!f.empty ())
                std::cerr << ", ";
        }
    std::cerr << ']';
}
#endif

#ifdef _GLIBCXX_MAP // header file of map
template <typename K, typename V>
void
__PRINT_VARIABLE (const std::map<K, V> &x)
{
    std::cerr << '[';
    unsigned long long f = 0;
    for (const auto &i : x)
        {
            std::cerr << (f++ ? ", " : "") << '(';
            __PRINT_VARIABLE (i.first);
            std::cerr << " : ";
            __PRINT_VARIABLE (i.second);
            std::cerr << ')';
        }
    std::cerr << ']';
}

template <typename K, typename V>
void
__PRINT_VARIABLE (const std::multimap<K, V> &x)
{
    std::cerr << '[';
    unsigned long long f = 0;
    for (const auto &i : x)
        {
            std::cerr << (f++ ? ", " : "") << '(';
            __PRINT_VARIABLE (i.first);
            std::cerr << " : ";
            __PRINT_VARIABLE (i.second);
            std::cerr << ')';
        }
    std::cerr << ']';
}
#endif

#ifdef _GLIBCXX_UNORDERED_MAP // header file of unordered_map
template <typename K, typename V>
void
__PRINT_VARIABLE (const std::unordered_map<K, V> &x)
{
    std::cerr << '[';
    unsigned long long f = 0;
    for (const auto &i : x)
        {
            std::cerr << (f++ ? ", " : "") << '(';
            __PRINT_VARIABLE (i.first);
            std::cerr << " : ";
            __PRINT_VARIABLE (i.second);
            std::cerr << ')';
        }
    std::cerr << ']';
}

template <typename K, typename V>
void
__PRINT_VARIABLE (const std::unordered_multimap<K, V> &x)
{
    std::cerr << '[';
    unsigned long long f = 0;
    for (const auto &i : x)
        {
            std::cerr << (f++ ? ", " : "") << '(';
            __PRINT_VARIABLE (i.first);
            std::cerr << " : ";
            __PRINT_VARIABLE (i.second);
            std::cerr << ')';
        }
    std::cerr << ']';
}
#endif

template <typename T>
void
__PRINT_VARIABLE (const T &x)
{
    std::cerr << '[';
    unsigned long long f = 0;
    for (const auto &i : x)
        std::cerr << (f++ ? ", " : ""), __PRINT_VARIABLE (i);
    std::cerr << ']';
}

void
__DEBUG_VAR (std::queue<std::string> &s)
{
    std::cerr << "\n}\n";
}

template <typename T, typename... V>
void
__DEBUG_VAR (std::queue<std::string> &s, T t, V... v)
{
    std::cerr << '\t' << s.front () << ": ";
    s.pop ();
    __PRINT_VARIABLE (t);
    if (sizeof...(v))
        std::cerr << ",  \n";
    __DEBUG_VAR (s, v...);
}
} // namespace LOCAL_DEBUG

#ifndef debug
#define debug(x...)                                                           \
    {                                                                         \
        std::queue<std::string> __VARIABLES_LIST;                             \
        std::string CURR_VARIABLE = "", ALL_VARIABLE = #x;                    \
        for (auto &i : ALL_VARIABLE)                                          \
            {                                                                 \
                if (i == ',')                                                 \
                    {                                                         \
                        __VARIABLES_LIST.push (CURR_VARIABLE);                \
                        CURR_VARIABLE = "";                                   \
                    }                                                         \
                else if (i != ' ')                                            \
                    CURR_VARIABLE.push_back (i);                              \
            }                                                                 \
        __VARIABLES_LIST.push (CURR_VARIABLE);                                \
        std::cerr << "{ " << #x << " } => {\n";                               \
        LOCAL_DEBUG::__DEBUG_VAR (__VARIABLES_LIST, x);                       \
    }
#endif

#endif

/*
#ifdef _GLIBCXX_VECTOR // header file of vector
template <typename T>
void __PRINT_VARIABLE(const std::vector<T>& x) {
    std::cerr << '[';
    unsigned long long f = 0;
    for (const auto& i : x)
        std::cerr << (f++ ? ", " : ""),
            __PRINT_VARIABLE(i);
    std::cerr << ']';
}
#endif

#ifdef _GLIBCXX_ARRAY // header file of array
template <typename T, std::size_t SIZE>
void __PRINT_VARIABLE(const std::array<T, SIZE>& x) {
    std::cerr << '[';
    unsigned long long f = 0;
    for (const auto& i : x)
        std::cerr << (f++ ? ", " : ""),
            __PRINT_VARIABLE(i);
    std::cerr << ']';
}
#endif

#ifdef _GLIBCXX_FORWARD_LIST
template <typename T>
void __PRINT_VARIABLE(const std::forward_list<T>& x) {
    std::cerr << '[';
    unsigned long long f = 0;
    for (const auto& i : x)
        std::cerr << (f++ ? ", " : ""),
            __PRINT_VARIABLE(i);
    std::cerr << ']';
}
#endif

#ifdef _GLIBCXX_LIST
template <typename T>
void __PRINT_VARIABLE(const std::list<T>& x) {
    std::cerr << '[';
    unsigned long long f = 0;
    for (const auto& i : x)
        std::cerr << (f++ ? ", " : ""),
            __PRINT_VARIABLE(i);
    std::cerr << ']';
}
#endif

#ifdef _GLIBCXX_SET // header file of set
template <typename T>
void __PRINT_VARIABLE(const std::set<T>& x) {
    std::cerr << '[';
    unsigned long long f = 0;
    for (const auto& i : x)
        std::cerr << (f++ ? ", " : ""),
            __PRINT_VARIABLE(i);
    std::cerr << ']';
}

template <typename T>
void __PRINT_VARIABLE(const std::multiset<T>& x) {
    std::cerr << '[';
    unsigned long long f = 0;
    for (const auto& i : x)
        std::cerr << (f++ ? ", " : ""),
            __PRINT_VARIABLE(i);
    std::cerr << ']';
}
#endif

#ifdef _GLIBCXX_UNORDERED_SET // header file of unordered_set
template <typename T>
void __PRINT_VARIABLE(const std::unordered_set<T>& x) {
    std::cerr << '[';
    unsigned long long f = 0;
    for (const auto& i : x)
        std::cerr << (f++ ? ", " : ""),
            __PRINT_VARIABLE(i);
    std::cerr << ']';
}

template <typename T>
void __PRINT_VARIABLE(const std::unordered_multiset<T>& x) {
    std::cerr << '[';
    unsigned long long f = 0;
    for (const auto& i : x)
        std::cerr << (f++ ? ", " : ""),
            __PRINT_VARIABLE(i);
    std::cerr << ']';
}
#endif
*/
