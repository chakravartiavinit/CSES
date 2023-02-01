#include <iostream>
#include <vector>
#include <numeric>
#include <map>
#include <list>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
#include <cmath>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <cstdlib>
#include <iomanip>
using namespace std;

//  ████████  ██████      ████████ ██   ██ ███████     ████████  ██████  ██████
//     ██    ██    ██        ██    ██   ██ ██             ██    ██    ██ ██   ██
//     ██    ██    ██        ██    ███████ █████          ██    ██    ██ ██████
//     ██    ██    ██        ██    ██   ██ ██             ██    ██    ██ ██
//     ██     ██████         ██    ██   ██ ███████        ██     ██████  ██
//
//
#define MOD 1000000007
#define PI 3.141592653589793238462
#define int long long

/*########################################### DEBUG ###############################################################################################*/
#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x)
#endif

void _print(int t)
{
    cerr << t;
}
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.first);
    cerr << ",";
    _print(p.second);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

/*###############################################################################################################################################*/
pair<int, int> bsLess(int start, int end, int target, vector<int> &vt)
{
    int low = start, high = end;
    int index = vt.size() + 10, answer = 1e12;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (vt[mid] <= target)
        {
            answer = vt[mid];
            index = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return {answer, index};
}
pair<int, int> bsMore(int start, int end, int target, vector<int> &vt)
{
    int low = start, high = end;
    int index = vt.size() + 10, answer = 1e12;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (vt[mid] >= target)
        {
            answer = vt[mid];
            index = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return {answer, index};
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> req(n), apartment(m);
    for (int i = 0; i < n; ++i)
    {
        cin >> req[i];
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> apartment[i];
    }
    int answer = 0, current_index = -1;
    sort(req.begin(), req.end());
    sort(apartment.begin(), apartment.end());
    for (int i = 0; i < n; ++i)
    {
        auto less = bsLess(current_index + 1, m - 1, req[i] + k, apartment);
        if (less.first != 1e12)
        {
            int end = less.second;
            auto more = bsMore(current_index + 1, end, req[i] - k, apartment);
            if (more.first != 1e12 && more.second < m)
            {
                answer++;
                current_index = more.second;
            }
            if (current_index >= m)
            {
                break;
            }
        }
    }
    cout << answer << "\n";
}