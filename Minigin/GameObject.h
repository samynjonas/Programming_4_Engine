#pragma once
#include <memory>
#include <vector>
#include <algorithm>

#include "Transform.h"
#include "Component.h"

namespace dae
{
	class Texture2D;
	class RenderComponent;
	class TransformComponent;

	// todo: this should become final.
	class GameObject final : public std::enable_shared_from_this<GameObject>
	{
	public:
		virtual void Update(float deltaTime);
		virtual void Render() const;

		GameObject();
		virtual ~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

		template <typename T> std::shared_ptr<T> AddComponent();
		template <typename T> void RemoveComponent();
		template <typename T> std::shared_ptr<T> GetComponent();

		TransformComponent* GetTransform()
		{
			return m_pTransformComponent.get();
		}
		RenderComponent* GetRenderer()
		{
			return m_pRenderComponent.get();
		}

	private:
		//Components
		std::vector<std::shared_ptr<Component>> m_vecComponents;
		std::shared_ptr<TransformComponent> m_pTransformComponent{ nullptr };	//Will be needed alot so caching
		std::shared_ptr<RenderComponent> m_pRenderComponent{ nullptr };			//Will be needed alot so caching
	};
}
