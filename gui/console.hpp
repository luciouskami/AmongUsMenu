#pragma once
#include <vector>

namespace ConsoleGui {
	const std::vector<const char*> BY_TYPE = { u8"", u8"击杀", u8"通风口", u8"任务", u8"报告", u8"会议", u8"投票" };
	extern int selectedType;

	void Init();
	void Render();
};