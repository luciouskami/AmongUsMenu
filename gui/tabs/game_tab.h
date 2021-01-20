#pragma once
#include <vector>

namespace GameTab {
	const std::vector<const char*> KILL_DISTANCE = { u8"短", u8"中", u8"长" };
	const std::vector<const char*> TASKBARUPDATES = { u8"总是", u8"会议", u8"从不" };
	const std::vector<const char*> COLORS = { u8"红", u8"蓝", u8"暗绿", u8"粉红", u8"橙", u8"黄", u8"黑", u8"白", u8"紫", u8"棕", u8"青", u8"青绿"};
	void Render();
}