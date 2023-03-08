#pragma once
#include "Component.h"
#include <string>
namespace dae
{
	class Font;
	class TextComponent final : public Component
	{
	public:
		TextComponent(std::weak_ptr<GameObject> pParent, const std::string& text, std::shared_ptr<Font> font);
		~TextComponent();
		TextComponent(const TextComponent& other) = delete;
		TextComponent(TextComponent&& other) = delete;
		TextComponent& operator=(const TextComponent& other) = delete;
		TextComponent& operator=(TextComponent&& other) = delete;

		void Update(float deltaTime) override;
		void SetText(const std::string& text);

	private:
		std::string m_Text;
		std::shared_ptr<Font> m_Font;

		bool m_NeedsUpdate;

	};
}


