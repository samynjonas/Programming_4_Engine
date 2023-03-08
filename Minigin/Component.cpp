#include "Component.h"
#include "GameObject.h"

#include "TransformComponent.h"

dae::Component::Component(std::weak_ptr<GameObject> pParent)
	: m_pOwner{ pParent }
{

}

dae::Component::~Component()
{

}

void dae::Component::Start()
{

}