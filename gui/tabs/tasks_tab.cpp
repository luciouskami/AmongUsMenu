#include "pch-il2cpp.h"
#include "tasks_tab.h"
#include "game.h"
#include "state.hpp"
#include "utility.h"

namespace TasksTab {
	void Render() {
		if (IsInGame() && GetPlayerData(*Game::pLocalPlayer)->fields.Tasks != NULL) {
			if (ImGui::BeginTabItem(u8"任务")) {
				ImGui::Dummy(ImVec2(4, 4));
				if (!GetPlayerData(*Game::pLocalPlayer)->fields.IsImpostor) {
					auto tasks = GetNormalPlayerTasks(*Game::pLocalPlayer);

					if (ImGui::Button(u8"完成所有任务")) {
						for (auto task : tasks) {
							if (task->fields.taskStep != task->fields.MaxStep)
								State.rpcQueue.push(new RpcCompleteTask(task->fields._._Id_k__BackingField));
						}
					}

					ImGui::NewLine();

					for (auto task : tasks) {
						if (ImGui::Button(("Complete##Button" + std::to_string(task->fields._._Id_k__BackingField)).c_str()) && !NormalPlayerTask_get_IsComplete(task, NULL)) {
							State.rpcQueue.push(new RpcCompleteTask(task->fields._._Id_k__BackingField));
						}

						ImGui::SameLine();

						ImGui::TextColored(NormalPlayerTask_get_IsComplete(task, NULL)
							? ImVec4(0.0F, 1.0F, 0.0F, 1.0F)
							: AmongUsColorToImVec4(app::Palette__TypeInfo->static_fields->White)
							, TranslateTaskTypes(task->fields._.TaskType));
					}

					ImGui::Dummy(ImVec2(7, 7));
					ImGui::Separator();
					ImGui::Dummy(ImVec2(7, 7));
				}

				if (ImGui::Button(u8"玩护盾任务"))
				{
					State.rpcQueue.push(new RpcPlayAnimation(1));
				}

				if (ImGui::Button(u8"玩清理小行星任务"))
				{
					State.rpcQueue.push(new RpcPlayAnimation(6));
				}

				if(ImGui::Button(u8"玩清理垃圾任务"))
				{
					State.rpcQueue.push(new RpcPlayAnimation(10));
				}

				if (ImGui::Checkbox(u8"玩身体扫描任务(金水)", &State.PlayMedbayScan))
				{
					if (State.PlayMedbayScan)
					{
						State.rpcQueue.push(new RpcSetScanner(true));
					}
					else
					{
						State.rpcQueue.push(new RpcSetScanner(false));
					}
				}

				ImGui::EndTabItem();
			}
		}
	}
}