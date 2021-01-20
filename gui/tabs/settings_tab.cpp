#include "pch-il2cpp.h"
#include "settings_tab.h"
#include "utility.h"
#include "gui-helpers.hpp"
#include "state.hpp"

namespace SettingsTab {
	void Render() {
		if (ImGui::BeginTabItem(u8"设置")) {
			ImGui::Dummy(ImVec2(4, 4));
			ImGui::Text(u8"显示/隐藏 菜单 按钮:");
			ImGui::SameLine();
			if (HotKey(State.KeyBinds.Toggle_Menu)) {
				State.Save();
			}

			ImGui::Text(u8"显示/隐藏 控制台 按钮:");
			ImGui::SameLine();
			if (HotKey(State.KeyBinds.Toggle_Console)) {
				State.Save();
			}
#ifdef _DEBUG
			ImGui::Dummy(ImVec2(7, 7));
			ImGui::Separator();
			ImGui::Dummy(ImVec2(7, 7));
			if (ImGui::Checkbox(u8"显示 测试 选项卡", &State.showDebugTab)) {
				State.Save();
			}
#endif
			ImGui::EndTabItem();
		}
	}
} 