#pragma once
#include "Component.h"
#include <memory>

namespace dae
{
	class TextComponent;
	class FPSComponent final : public Component 
	{
	public:
		FPSComponent(std::weak_ptr<GameObject> pParent, std::weak_ptr<TextComponent> textComp);
		~FPSComponent();
		FPSComponent(const FPSComponent& other) = delete;
		FPSComponent(FPSComponent&& other) = delete;
		FPSComponent& operator=(const FPSComponent& other) = delete;
		FPSComponent& operator=(FPSComponent&& other) = delete;

		void Start() override;
		void Update(float deltaTime) override;

		int GetFPS() const;

	private:
		int m_FPS;
		int m_NrFramesPassed;
		float m_TimeElapsed;
		float m_UpdateInterval;

		std::weak_ptr<TextComponent> m_pTextComp{};

	};
}



