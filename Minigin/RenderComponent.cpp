#include "RenderComponent.h"
#include "ResourceManager.h"
#include "Renderer.h"

#include "TransformComponent.h"

dae::RenderComponent::RenderComponent(std::weak_ptr<GameObject> pParent)
	: Component(pParent)
{

}


dae::RenderComponent::~RenderComponent()
{

}

void dae::RenderComponent::Update(float)
{

}

void dae::RenderComponent::Render()
{
	//const auto& pos = GetOwner()->GetTransform()->GetPosition();
	//Renderer::GetInstance().RenderTexture(*m_texture, pos.x, pos.y);
}

void dae::RenderComponent::SetTexture(const std::string& filename)
{
	m_texture = ResourceManager::GetInstance().LoadTexture(filename); 
}