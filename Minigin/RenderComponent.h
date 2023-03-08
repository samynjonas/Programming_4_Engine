#pragma once
#include "Component.h"
#include <string>
namespace dae
{
	class Texture2D;

	class RenderComponent final : public Component
	{
	public:
		RenderComponent(std::weak_ptr<GameObject> pParent);
		~RenderComponent();
		RenderComponent(const RenderComponent& other) = delete;
		RenderComponent(RenderComponent&& other) = delete;
		RenderComponent& operator=(const RenderComponent& other) = delete;
		RenderComponent& operator=(RenderComponent&& other) = delete;

		void Update(float deltaTime) override;
		void Render();

		void SetTexture(const std::string& filename);

	private:
		std::shared_ptr<Texture2D> m_texture{};
	};
}