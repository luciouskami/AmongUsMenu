#include "pch-il2cpp.h"
#include "debug_tab.h"
#include "imgui/imgui.h"
#include "state.hpp"
#include "main.h"

namespace DebugTab {

	void Render() {
		if (ImGui::BeginTabItem(u8"����")) {
			ImGui::Dummy(ImVec2(4, 4));
#ifndef _VERSION
			if (ImGui::Button("Unload DLL"))
			{
				SetEvent(hUnloadEvent);
			}
			ImGui::Dummy(ImVec2(4, 4));
#endif
			if (ImGui::Button(u8"ǿ�Ƶ�������"))
			{
				State.Load();
			}
			if (ImGui::Button(u8"ǿ�Ʊ�������"))
			{
				State.Save();
			}
			ImGui::EndTabItem();
		}
	}
}