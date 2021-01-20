#include "pch-il2cpp.h"
#include "game_tab.h"
#include "game.h"
#include "gui-helpers.hpp"
#include "imgui/imgui.h"
#include "state.hpp"
#include "utility.h"

namespace GameTab {
	void Render() {
		if (ImGui::BeginTabItem(u8"游戏")) {
			ImGui::Dummy(ImVec2(4, 4));
			if (SteppedSliderFloat(u8"玩家速度", &State.PlayerSpeed, 0.5f, 3.f, 0.25f, "%.2fx", ImGuiSliderFlags_Logarithmic | ImGuiSliderFlags_NoInput)) {
				if (!IsInGame()) State.PlayerSpeed = State.PrevPlayerSpeed;
				else {
					(*Game::pGameOptionsData)->fields.PlayerSpeedMod = State.PlayerSpeed;
					State.PrevPlayerSpeed = State.PlayerSpeed;
				}
			}
			if (CustomListBoxInt(u8"击杀距离", &State.KillDistance, KILL_DISTANCE)) {
				if (!IsInGame()) State.KillDistance = State.PrevKillDistance;
				else {
					(*Game::pGameOptionsData)->fields.KillDistance = State.KillDistance;
					State.PrevKillDistance = State.KillDistance;
				}
			}
			if (CustomListBoxInt(u8"任务状态更新", &State.TaskBarUpdates, TASKBARUPDATES)) {
				if (!IsInGame()) State.TaskBarUpdates = State.PrevTaskBarUpdates;
				else {
					(*Game::pGameOptionsData)->fields.TaskBarUpdates = (TaskBarUpdates__Enum)State.TaskBarUpdates;
					State.PrevTaskBarUpdates = State.TaskBarUpdates;
				}
			}

			ImGui::Dummy(ImVec2(7, 7));
			ImGui::Separator();
			ImGui::Dummy(ImVec2(7, 7));
			
			if (ImGui::Button(u8"设置角色颜色") && !State.AntiBan && IsInGame())
			{
				bool colorAvailable = true;

				for (PlayerControl* player : GetAllPlayerControl())
				{
					if (State.SelectedColorId == GetPlayerData(player)->fields.ColorId)
					{
						colorAvailable = false;
						break;
					}
				}

				if(colorAvailable)
				State.rpcQueue.push(new RpcSetColor(State.SelectedColorId));
			}

			ImGui::SameLine(87);
			CustomListBoxInt(u8" ", &State.SelectedColorId, COLORS, 85.0f);

			ImGui::SameLine(215);
			if (ImGui::Button(u8"随机角色颜色"))
			{
				if (IsInGame() || IsInLobby())
				{
					auto players = GetAllPlayerControl();
					std::vector<int> availableColors = { };
					for (int i = 0; i < 12; i++)
					{
						bool colorAvailable = true;
						for (PlayerControl* player : players)
						{
							if (i == GetPlayerData(player)->fields.ColorId)
							{
								colorAvailable = false;
								break;
							}
						}

						if (colorAvailable)
							availableColors.push_back(i);
					}

					State.SelectedColorId = availableColors.at(randi(0, availableColors.size() - 1));
				}
				else
				{
					State.SelectedColorId = randi(0, 11);
				}
			}

			if (ImGui::Checkbox(u8"防踢/防封", &State.AntiBan))
			{
				if (IsInLobby() || IsInGame())
				{
					State.AntiBan = !State.AntiBan;
				}
			}
			if (ImGui::Checkbox(u8"控制台", &State.ShowConsole)) {
				State.Save();
			}

			ImGui::EndTabItem();
		}
	}
}
