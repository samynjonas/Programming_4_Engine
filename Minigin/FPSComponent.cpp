#include "FPSComponent.h"
#include <sstream>

#include "TextComponent.h"
#include "GameObject.h"



dae::FPSComponent::FPSComponent(std::weak_ptr<GameObject> pParent, std::weak_ptr<TextComponent> textComp)
	: Component(pParent)
	, m_pTextComp{ textComp }
	, m_FPS{ 0 }
	, m_NrFramesPassed{ 0 }
	, m_TimeElapsed{ 0.f }
	, m_UpdateInterval{ 0.f }
{
}

dae::FPSComponent::~FPSComponent()
{

}


void dae::FPSComponent::Start()
{
	//m_pTextComponent = GetOwner()->GetComponent<TextComponent>().get(); //TODO Fix getComponent
}

void dae::FPSComponent::Update(float deltaTime)
{
	m_TimeElapsed += deltaTime;
	++m_NrFramesPassed;
	if (m_TimeElapsed >= m_UpdateInterval)
	{
		m_FPS = static_cast<int>(m_NrFramesPassed / m_TimeElapsed);

		std::stringstream s;
		s << m_FPS;
		s << " FPS";
		m_pTextComp.lock()->SetText(s.str());
		m_NrFramesPassed = 0;
		m_TimeElapsed = 0.f;
	}
}

int dae::FPSComponent::GetFPS() const
{
	return m_FPS;
}