#include "pch-il2cpp.h"
#include "self_tab.h"
#include "game.h"
#include "gui-helpers.hpp"
#include "utility.h"
#include "state.hpp"

namespace SelfTab {
    void Render() {
        if (ImGui::BeginTabItem(u8"自身")) {
            ImGui::Dummy(ImVec2(4, 4));
            if (ImGui::Checkbox(u8"最大视觉", &State.MaxVision)) {
                State.Save();
            }
            if (ImGui::Checkbox(u8"透视", &State.Wallhack)) {
                State.Save();
            }

            if (ImGui::Checkbox(u8"自由视角", &State.FreeCam)) {
                if (IsInGame()) {
                    State.playerToFollow = PlayerSelection();
                }
            }
            ImGui::SameLine();
            if (HotKey(State.KeyBinds.Toggle_Freecam)) {
                State.Save();
            }

            ImGui::SameLine(145.0f);
            SteppedSliderFloat(u8"  ", &State.FreeCamSpeed, 0.5f, 3.f, 0.25f, u8"%.2fx 速度", ImGuiSliderFlags_Logarithmic | ImGuiSliderFlags_NoInput);

            ImGui::Checkbox(u8"视距", &State.EnableZoom);
            ImGui::SameLine();
            HotKey(State.KeyBinds.Toggle_Zoom);

            ImGui::SameLine(145.0f);
            SteppedSliderFloat(u8"   ", &State.CameraHeight, 1.0f, 20.0f, 1.0f, u8"%.2fx 视距", ImGuiSliderFlags_Logarithmic | ImGuiSliderFlags_NoInput);

            ImGui::Dummy(ImVec2(7, 7));
            ImGui::Separator();
            ImGui::Dummy(ImVec2(7, 7));

            if (ImGui::Checkbox(u8"总是显示聊天按钮", &State.ChatAlwaysActive)) {
                State.Save();
            }
            if (ImGui::Checkbox(u8"显示鬼魂聊天", &State.ReadGhostMessages)) {
                State.Save();
            }

            ImGui::Dummy(ImVec2(7, 7));
            ImGui::Separator();
            ImGui::Dummy(ImVec2(7, 7));

            if (ImGui::Checkbox(u8"显示内鬼", &State.RevealImpostors)) {
                State.Save();
            }
            if (ImGui::Checkbox(u8"显示鬼魂", &State.ShowGhosts)) {
                State.Save();
            }
            if (ImGui::Checkbox(u8"解锁通风口", &State.UnlockVents)) {
                State.Save();
            }

            if (ImGui::Checkbox(u8"穿墙", &State.NoClip)) {
                if (State.LobbyTimer == 0 || !IsInLobby()) {
                    if (!IsInGame() && !IsInLobby()) State.NoClip = false;
                    else {
                        if (!(GetPlayerData(*Game::pLocalPlayer)->fields.IsDead)) {
                            if (State.NoClip)
                                app::GameObject_set_layer(app::Component_get_gameObject((Component*)(*Game::pLocalPlayer), NULL), app::LayerMask_NameToLayer(convert_to_string("Ghost"), NULL), NULL);
                            else
                                app::GameObject_set_layer(app::Component_get_gameObject((Component*)(*Game::pLocalPlayer), NULL), app::LayerMask_NameToLayer(convert_to_string("Players"), NULL), NULL);
                        }
                    }
                } else State.NoClip = false;
            }
            ImGui::SameLine();
            HotKey(State.KeyBinds.Toggle_Noclip);

            if (ImGui::Checkbox(u8"在通风口中移动", &State.MoveInVent) && IsInGame()) {
                if (!State.MoveInVent && (State.InMeeting || (*Game::pLocalPlayer)->fields.inVent)) {
                    (*Game::pLocalPlayer)->fields.moveable = false;
                }
            }

            ImGui::EndTabItem();
        }
    }
}