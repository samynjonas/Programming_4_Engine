#include <string>
#include <algorithm>
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"

#include "RenderComponent.h"
#include "TransformComponent.h"



dae::GameObject::GameObject()
{
	m_pTransformComponent	= std::make_shared<TransformComponent>(weak_from_this());
	m_vecComponents.push_back(m_pTransformComponent);
	m_pRenderComponent		= std::make_shared<RenderComponent>(weak_from_this());
	m_vecComponents.push_back(m_pRenderComponent);
}

dae::GameObject::~GameObject() = default;

void dae::GameObject::Update(float deltaTime)
{
	for (auto& component : m_vecComponents)
	{
		component->Update(deltaTime);
	}
}

void dae::GameObject::Render() const
{
	if (m_pRenderComponent)
	{
		m_pRenderComponent->Render();
	}
}

template<typename T> std::shared_ptr<T> dae::GameObject::AddComponent()
{
	//Check if component already exist
	const auto checkComponent = GetComponent<T>();
	if (checkComponent != nullptr)
	{
		return checkComponent;
	}
	m_vecComponents.push_back(make_unique<T>(weak_from_this()));

	return m_vecComponents.back();
}


template <typename T> std::shared_ptr<T> dae::GameObject::GetComponent()
{
	for (auto component : m_vecComponents)
	{
		auto ptr = std::dynamic_pointer_cast<T>(component);
		if (ptr) 
		{
			return ptr;
		}
	}
	return nullptr;
}

template <typename T> void dae::GameObject::RemoveComponent()
{
	for (auto iterator{ m_vecComponents.begin() }; iterator < m_vecComponents.end(); ++iterator)
	{
		const auto& casted = std::dynamic_pointer_cast<T>(*iterator);
		if (casted)
		{
			m_vecComponents.erase(iterator);
		}
	}
}