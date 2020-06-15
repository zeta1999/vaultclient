#ifndef vcVerticalMeasureTool_h__
#define vcVerticalMeasureTool_h__

#include "vcSceneItem.h"
#include "vcCamera.h"
#include "vdkRenderContext.h"
#include "vdkError.h"
#include "vcFenceRenderer.h"
#include "vcLabelRenderer.h"
#include "vcImageRenderer.h"
#include "vcLineRenderer.h"
#include "vcGLState.h"
#include "vcSettings.h"

class vcVerticalMeasureTool : public vcSceneItem
{
public:
  vcVerticalMeasureTool(vcProject *pProject, vdkProjectNode *pNode, vcState *pProgramState);
  virtual ~vcVerticalMeasureTool();

  void Preview(const udDouble3 &position);
  void EndMeasure(vcState *pProgramState, const udDouble3 &position);

  virtual void OnNodeUpdate(vcState *pProgramState);
  virtual void AddToScene(vcState *pProgramState, vcRenderData *pRenderData);
  virtual void ApplyDelta(vcState *pProgramState, const udDouble4x4 &delta);
  virtual void HandleImGui(vcState *pProgramState, size_t *pItemID);
  virtual void Cleanup(vcState *pProgramState);
  virtual void ChangeProjection(const udGeoZone &newZone);
  virtual udDouble3 GetLocalSpacePivot();
  virtual bool IsValid() const { return !m_markDelete; }

private:
  void UpdateIntersectionPosition(vcState *pProgramState);
  bool HasLine();
  void ClearPoints();
  void UpdateSetting(vcState *pProgramState);

private:
  static const int POINTSIZE = 3;
  bool m_done;
  bool m_pickStart;
  bool m_pickEnd;
  bool m_markDelete;

  udDouble3 m_points[POINTSIZE];

  vcLabelInfo m_labelInfo;
  vcLineInstance *m_pLineInstance;

  uint32_t m_textColourBGRA;
  uint32_t m_textBackgroundBGRA;
  uint32_t m_lineColour;
  float m_lineWidth;

  char m_description[vcMaxPathLength];

};

#endif

