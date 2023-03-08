#pragma once
#include <memory>


namespace dae
{
	class GameObject;	
	class Component
	{
	public:
		Component(std::weak_ptr<GameObject> pParent);
		virtual ~Component();
		Component(const Component& other) = delete;
		Component(Component&& other) = delete;
		Component& operator=(const Component& other) = delete;
		Component& operator=(Component&& other) = delete;

		virtual void Start();
		virtual void Update(float deltaTime) = 0;
		
		std::weak_ptr<GameObject> GetOwner() const { return m_pOwner; }

	protected:

	private:
		std::weak_ptr<GameObject> m_pOwner;

	};
}


