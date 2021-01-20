#include "pch-il2cpp.h"
#include "radar_tab.h"
#include "gui-helpers.hpp"
#include "state.hpp"
#include "utility.h"

namespace RadarTab {
	void Render() {
		if (ImGui::BeginTabItem(u8"雷达")) {
			ImGui::Dummy(ImVec2(4, 4));
			if (ImGui::Checkbox(u8"显示雷达", &State.ShowRadar)) {
				State.Save();
			}
			ImGui::SameLine();
			if (HotKey(State.KeyBinds.Toggle_Radar)) {
				State.Save();
			}

			ImGui::Dummy(ImVec2(7, 7));
			ImGui::Separator();
			ImGui::Dummy(ImVec2(7, 7));

			if (ImGui::Checkbox(u8"显示遗体", &State.ShowRadar_DeadBodies)) {
				State.Save();
			}
			if (ImGui::Checkbox(u8"显示鬼魂", &State.ShowRadar_Ghosts)) {
				State.Save();
			}
			if (ImGui::Checkbox(u8"按下右键切换至", &State.ShowRadar_RightClick_Teleport)) {
				State.Save();
			}

			ImGui::Dummy(ImVec2(7, 7));
			ImGui::Separator();
			ImGui::Dummy(ImVec2(7, 7));

			if (ImGui::Checkbox(u8"在会议时隐藏雷达", &State.HideRadar_During_Meetings)) {
				State.Save();
			}
			if (ImGui::Checkbox(u8"固定雷达位置", &State.LockRadar)) {
				State.Save();
			}
			if (ImGui::ColorEdit4(u8"雷达颜色", (float*)&State.SelectedColor, ImGuiColorEditFlags__OptionsDefault | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_AlphaPreview)) {
				State.Save();
			}

			ImGui::EndTabItem();
		}
	}
}