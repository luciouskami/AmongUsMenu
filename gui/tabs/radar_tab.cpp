#include "pch-il2cpp.h"
#include "radar_tab.h"
#include "gui-helpers.hpp"
#include "state.hpp"
#include "utility.h"

namespace RadarTab {
	void Render() {
		if (ImGui::BeginTabItem(u8"�״�")) {
			ImGui::Dummy(ImVec2(4, 4));
			if (ImGui::Checkbox(u8"��ʾ�״�", &State.ShowRadar)) {
				State.Save();
			}
			ImGui::SameLine();
			if (HotKey(State.KeyBinds.Toggle_Radar)) {
				State.Save();
			}

			ImGui::Dummy(ImVec2(7, 7));
			ImGui::Separator();
			ImGui::Dummy(ImVec2(7, 7));

			if (ImGui::Checkbox(u8"��ʾ����", &State.ShowRadar_DeadBodies)) {
				State.Save();
			}
			if (ImGui::Checkbox(u8"��ʾ���", &State.ShowRadar_Ghosts)) {
				State.Save();
			}
			if (ImGui::Checkbox(u8"�����Ҽ��л���", &State.ShowRadar_RightClick_Teleport)) {
				State.Save();
			}

			ImGui::Dummy(ImVec2(7, 7));
			ImGui::Separator();
			ImGui::Dummy(ImVec2(7, 7));

			if (ImGui::Checkbox(u8"�ڻ���ʱ�����״�", &State.HideRadar_During_Meetings)) {
				State.Save();
			}
			if (ImGui::Checkbox(u8"�̶��״�λ��", &State.LockRadar)) {
				State.Save();
			}
			if (ImGui::ColorEdit4(u8"�״���ɫ", (float*)&State.SelectedColor, ImGuiColorEditFlags__OptionsDefault | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_AlphaPreview)) {
				State.Save();
			}

			ImGui::EndTabItem();
		}
	}
}