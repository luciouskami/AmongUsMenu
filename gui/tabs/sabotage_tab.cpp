#include "pch-il2cpp.h"
#include "sabotage_tab.h"
#include "utility.h"
#include "gui-helpers.hpp"
#include "_rpc.h"
#include "game.h"
#include "state.hpp"

namespace SabotageTab {
    void Render() {
        if (IsInGame()) {
            if (ImGui::BeginTabItem(u8"ÆÆ»µ")) {
                ImGui::Dummy(ImVec2(4, 4));
                if (ImGui::Button(u8"ÐÞ¸´ÆÆ»µ")) {
                    RepairSabotage(*Game::pLocalPlayer);
                }
                ImGui::SameLine();
                if (HotKey(State.KeyBinds.Repair_Sabotage)) {
                    State.Save();
                }
                ImGui::NewLine();
                if (ImGui::Button(u8"ÆÆ»µµÆ¹â")) {
                    State.rpcQueue.push(new RpcRepairSystem(SystemTypes__Enum_Sabotage, SystemTypes__Enum_Electrical));
                }
                if ((*Game::pShipStatus)->fields.Type == ShipStatus_MapType__Enum_Ship || (*Game::pShipStatus)->fields.Type == ShipStatus_MapType__Enum_Hq) {
                    if (ImGui::Button(u8"ÆÆ»µºË·´Ó¦¶Ñ")) {
                        State.rpcQueue.push(new RpcRepairSystem(SystemTypes__Enum_Sabotage, SystemTypes__Enum_Reactor));
                    }
                } else if ((*Game::pShipStatus)->fields.Type == ShipStatus_MapType__Enum_Pb) {
                    if (ImGui::Button(u8"ÆÆ»µÎÈ¶¨Æ÷")) {
                        State.rpcQueue.push(new RpcRepairSystem(SystemTypes__Enum_Sabotage, SystemTypes__Enum_Laboratory));
                    }
                }
                if ((*Game::pShipStatus)->fields.Type == ShipStatus_MapType__Enum_Ship || (*Game::pShipStatus)->fields.Type == ShipStatus_MapType__Enum_Hq) {
                    if (ImGui::Button(u8"ÆÆ»µÑõÆø¹©¸ø×°ÖÃ")) {
                        State.rpcQueue.push(new RpcRepairSystem(SystemTypes__Enum_Sabotage, SystemTypes__Enum_LifeSupp));
                    }
                }
                if (ImGui::Button(u8"ÆÆ»µÍ¨Ñ¶×°ÖÃ")) {
                    State.rpcQueue.push(new RpcRepairSystem(SystemTypes__Enum_Sabotage, SystemTypes__Enum_Comms));
                }

                ImGui::Dummy(ImVec2(7, 7));
                ImGui::Separator();
                ImGui::Dummy(ImVec2(7, 7));

                if (ImGui::Checkbox(u8"¹ØµÆ", &State.DisableLights)) {
                    if (State.DisableLights) {
                        SwitchSystem* switchSystem = nullptr;
                        std::vector<std::pair<SystemTypes__Enum, ISystemType*>> systems = GetEntriesFromDictionary<Dictionary_2_SystemTypes_ISystemType_*, SystemTypes__Enum, ISystemType*>((*Game::pShipStatus)->fields.Systems);

                        for (auto system : systems) {
                            if (system.first == SystemTypes__Enum_Electrical) {
                                switchSystem = (SwitchSystem*)system.second;
                            }
                        }

                        if (switchSystem != nullptr) {
                            auto actualSwitches = switchSystem->fields.ActualSwitches;
                            auto expectedSwitches = switchSystem->fields.ExpectedSwitches;

                            auto switchMask = 1 << (0 & 0x1F);

                            if ((actualSwitches & switchMask) != (~expectedSwitches & switchMask))
                                State.rpcQueue.push(new RpcRepairSystem(SystemTypes__Enum_Electrical, 5));
                        }
                    } else {
                        SwitchSystem* switchSystem = nullptr;
                        std::vector<std::pair<SystemTypes__Enum, ISystemType*>> systems = GetEntriesFromDictionary<Dictionary_2_SystemTypes_ISystemType_*, SystemTypes__Enum, ISystemType*>((*Game::pShipStatus)->fields.Systems);

                        for (auto system : systems) {
                            if (system.first == SystemTypes__Enum_Electrical) {
                                switchSystem = (SwitchSystem*)system.second;
                            }
                        }

                        if (switchSystem != nullptr) {
                            auto actualSwitches = switchSystem->fields.ActualSwitches;
                            auto expectedSwitches = switchSystem->fields.ExpectedSwitches;

                            auto switchMask = 1 << (5 & 0x1F);

                            if ((actualSwitches & switchMask) != (expectedSwitches & switchMask))
                                State.rpcQueue.push(new RpcRepairSystem(SystemTypes__Enum_Electrical, 5));
                        }
                    }
                }

                ImGui::EndTabItem();
            }
        }
    }
}