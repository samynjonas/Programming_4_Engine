#include "TransformComponent.h"

dae::TransformComponent::TransformComponent(std::weak_ptr<GameObject> pParent)
	: Component(pParent)
{

}


dae::TransformComponent::~TransformComponent()
{

}

void dae::TransformComponent::Update(float)
{

}

void dae::TransformComponent::SetPosition(const float x, const float y, const float z)
{
	m_Position.x = x;
	m_Position.y = y;
	m_Position.z = z;
}

void dae::TransformComponent::SetRotation(float angle)
{
	m_Rotation = angle;
}