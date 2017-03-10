#pragma once
#include <memory>

template <typename T>
using SimpleDeletor = void(*)(T *);

template <typename T>
using CustomUniquePtr = ::std::unique_ptr<T, SimpleDeletor<T>>;