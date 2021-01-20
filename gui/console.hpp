#pragma once
#include <vector>

namespace ConsoleGui {
	const std::vector<const char*> BY_TYPE = { u8"", u8"��ɱ", u8"ͨ���", u8"����", u8"����", u8"����", u8"ͶƱ" };
	extern int selectedType;

	void Init();
	void Render();
};