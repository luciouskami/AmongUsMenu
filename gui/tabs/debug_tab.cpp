#include "pch-il2cpp.h"
#include "debug_tab.h"
#include "imgui/imgui.h"
#include "state.hpp"
#include "main.h"

namespace DebugTab {

	void Render() {
		if (ImGui::BeginTabItem(u8"测试")) {
			ImGui::Dummy(ImVec2(4, 4));
#ifndef _VERSION
			if (ImGui::Button("Unload DLL"))
			{
				SetEvent(hUnloadEvent);
			}
			ImGui::Dummy(ImVec2(4, 4));
#endif
			if (ImGui::Button(u8"强制导入设置"))
			{
				State.Load();
			}
			if (ImGui::Button(u8"强制保存设置"))
			{
				State.Save();
			}
			ImGui::EndTabItem();
		}
	}
}