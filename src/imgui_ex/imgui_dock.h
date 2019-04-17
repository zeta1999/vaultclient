#pragma once

namespace ImGui
{
  IMGUI_API void ShutdownDock();
  IMGUI_API void RootDock(const ImVec2& pos, const ImVec2& size);
  IMGUI_API bool BeginDock(const char* label, bool* opened = nullptr, ImGuiWindowFlags extra_flags = 0);
  IMGUI_API void EndDock();
  IMGUI_API void SetDockActive();
  IMGUI_API void CaptureDefaults();
  IMGUI_API bool IsDockActive(const char *pLabel);
} // namespace ImGui