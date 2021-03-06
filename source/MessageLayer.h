#pragma once

#include "Interactionlayer.h"

class GLTexture2;

class MessageLayer : public InteractionLayer {
public:
  MessageLayer(const Vector3f& initialEyePos);
  //virtual ~MessageLayer ();

  virtual void Update(TimeDelta real_time_delta) override {}
  virtual void Render(TimeDelta real_time_delta) const override;
  EventHandlerAction HandleKeyboardEvent(const SDL_KeyboardEvent &ev) override;

  void SetVisible(int index, bool value) { m_Visible[index] = value; }
  bool GetVisible(int index) const { return m_Visible[index]; }

  EIGEN_MAKE_ALIGNED_OPERATOR_NEW

private:
  static const int NUM_MESSAGES = 3;
  void DrawMessage(int index) const;

  std::shared_ptr<GLTexture2> m_HelpTexture;
  std::shared_ptr<GLTexture2> m_LowFPSTexture;
  std::shared_ptr<GLTexture2> m_NoOculusTexture;

  bool m_Visible[NUM_MESSAGES];
};
