#pragma once

template <template T = unsigned>
struct Rect {
	T w, h;
};

template <template T = unsigned>
struct Pos {
	T x, y;
};

template <template T = unsigned>
struct PosRect : Pos<T>, Rect<T> {
};