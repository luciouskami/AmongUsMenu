#include "pch-il2cpp.h"
#include "settings_tab.h"
#include "utility.h"
#include "gui-helpers.hpp"
#include "state.hpp"

namespace SettingsTab {
	void Render() {
		if (ImGui::BeginTabItem(u8"����")) {
			ImGui::Dummy(ImVec2(4, 4));
			ImGui::Text(u8"��ʾ/���� �˵� ��ť:");
			ImGui::SameLine();
			if (HotKey(State.KeyBinds.Toggle_Menu)) {
				State.Save();
			}

			ImGui::Text(u8"��ʾ/���� ����̨ ��ť:");
			ImGui::SameLine();
			if (HotKey(State.KeyBinds.Toggle_Console)) {
				State.Save();
			}
#ifdef _DEBUG
			ImGui::Dummy(ImVec2(7, 7));
			ImGui::Separator();
			ImGui::Dummy(ImVec2(7, 7));
			if (ImGui::Checkbox(u8"��ʾ ���� ѡ�", &State.showDebugTab)) {
				State.Save();
			}
#endif
			ImGui::EndTabItem();
		}
	}
} 