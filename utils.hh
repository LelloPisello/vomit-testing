#ifndef UTILS_h_
#define UTILS_h_

/*
i: intero con segno + / -
u: intero solo positivo
f: virgola mobile con precisione singola
d: virgola mobile con doppia precisione
*/

using i8 = char;
using u8 = unsigned char;
using i16 = short;
using u16 = unsigned short;
using i32 = int;
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using f32 = float;
using f64 = double;
using d64 = long double;

template <typename _type>
struct binary_tree_t
{
  binary_tree_t<_type> *left = nullptr, *right = nullptr;
  _type data;
};

template <typename _type>
struct container_t
{
  unsigned num_users;
  _type data;
};

#endif
