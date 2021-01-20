#pragma once
#include <vector>

namespace HostTab {
	const std::vector<const char*> MAP_NAMES = { u8"骷髅舰", u8"米拉总部", u8"波鲁斯", u8"德拉克斯"};
	const std::vector<const char*> IMPOSTOR_AMOUNTS = { u8"一", u8"二", u8"三" };
	void Render();
}